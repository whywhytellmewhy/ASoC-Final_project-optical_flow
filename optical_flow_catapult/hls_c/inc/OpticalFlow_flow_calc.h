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
                        ac_channel<vel_pixel_t>  &denominator,
                        maxWType            widthIn,
                        maxHType            heightIn)
    {
      tensor_t tensor_value;

      //pixel_t denominator_value;
      vel_pixel_t denominator_value;

      velocity_t total_output_value;

      Flow_calc_ROW: for(maxHType y=0; ; y++) {
        Flow_calc_COLUMN: for(maxWType x=0; ; x++) {
          // read input channels
          tensor_value = tensor.read();

          if ((y >= 2) && (y < heightIn-2) && (x >= 2) && (x < widthIn-2)) {
            // Calculate total_output_value
            denominator_value = tensor_value.val[0]*tensor_value.val[1] - tensor_value.val[3]*tensor_value.val[3];
            total_output_value.x = (tensor_value.val[5]*tensor_value.val[3] - tensor_value.val[4]*tensor_value.val[1]); // / denominator_value;
            total_output_value.y = (tensor_value.val[4]*tensor_value.val[3] - tensor_value.val[5]*tensor_value.val[0]); // / denominator_value;
            //if ((x==451) && (y==62)){
            //if ((x==362) && (y==399)){
            //if ((x==317) && (y==189)){
            //if ((x==497) && (y==367)){
            if ((x==785) && (y==287)){
              cout << endl << "HLS_tensor_value[0]: " << tensor_value.val[0] << endl;
              cout << "HLS_tensor_value[1]: " << tensor_value.val[1] << endl;
              cout << "HLS_tensor_value[2]: " << tensor_value.val[2] << endl;
              cout << "HLS_tensor_value[3]: " << tensor_value.val[3] << endl;
              cout << "HLS_tensor_value[4]: " << tensor_value.val[4] << endl;
              cout << "HLS_tensor_value[5]: " << tensor_value.val[5] << endl;
              cout << "HLS_denominator_value: " << denominator_value << endl;
              cout << "HLS_total_output_value.x: " << total_output_value.x << endl;
              cout << "HLS_total_output_value.y: " << total_output_value.y << endl;
              cout << "HLS_total_output_value.x (after division): " << total_output_value.x.to_double()/denominator_value.to_double() << endl;
              cout << "HLS_total_output_value.y (after division): " << total_output_value.y.to_double()/denominator_value.to_double() << endl;
            }

            // Write output optical flow (velocity) streaming interface
            output.write(total_output_value);
            denominator.write(denominator_value);
          } else {
            total_output_value.x = 0;
            total_output_value.y = 0;
            denominator_value = 0;

            // Write output optical flow (velocity) streaming interface
            output.write(total_output_value);
            denominator.write(denominator_value);
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


