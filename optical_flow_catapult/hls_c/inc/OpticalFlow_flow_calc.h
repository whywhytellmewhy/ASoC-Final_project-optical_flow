#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_flow_calc
  {
  public:
    OpticalFlow_flow_calc() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<tensor_t> &tensor,
                        ac_channel<velocity_t>  &output,
                        maxWType            widthIn,
                        maxHType            heightIn)
    {
      tensor_t tensor_value;

      pixel_t denominator;

      velocity_t total_output_value;

      Flow_calc_ROW: for(maxHType y=0; ; y++) {
        Flow_calc_COLUMN: for(maxWType x=0; ; x++) {
          // read input channels
          tensor_value = tensor.read();

          if ((y >= 2) && (y < heightIn-2) && (x >= 2) && (x < widthIn-2)) {
            // Calculate total_output_value
            denominator = tensor_value.val[0]*tensor_value.val[1] - tensor_value.val[3]*tensor_value.val[3];
            total_output_value.x = (tensor_value.val[5]*tensor_value.val[3] - tensor_value.val[4]*tensor_value.val[1]) / denominator;
            total_output_value.y = (tensor_value.val[4]*tensor_value.val[3] - tensor_value.val[5]*tensor_value.val[0]) / denominator;

            // Write output optical flow (velocity) streaming interface
            output.write(total_output_value);
          } else {
            total_output_value.x = 0;
            total_output_value.y = 0;

            // Write output optical flow (velocity) streaming interface
            output.write(total_output_value);
          }

          // programmable width exit condition
          if (x == widthIn-1) {
            break;
          }
        }
        // programmable height exit condition
        if (y == heightIn-1) {
          break;
        }
      }
    }
};


