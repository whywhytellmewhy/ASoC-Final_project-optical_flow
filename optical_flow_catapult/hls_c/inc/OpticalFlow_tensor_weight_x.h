#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_tensor_weight_x
  {
  public:
    OpticalFlow_tensor_weight_x() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<tensor_t> &tensor_y,
                        ac_channel<tensor_t> &tensor,
                        maxWType            widthIn,
                        maxHType            heightIn)
    {
      // tensor buffers store tensor history
      tensor_t tensor_buf0 = {0,0,0,0,0,0};
      tensor_t tensor_buf1 = {0,0,0,0,0,0};

      tensor_t tensor0;
      tensor_t tensor1;
      tensor_t tensor2;


      tensor_t tensor_value;

      Tensor_weight_x_ROW: for (maxHType y=0; ; y++) {
        Tensor_weight_x_COLUMN: for (maxWType x=0; ; x++) {
          // read input value
          if (x <= widthIn-1) {
            tensor0 = tensor_y.read(); // Read from input stream
          } else {
            tensor0 = tensor_buf0;
          }

          tensor1 = tensor_buf0;
          tensor2 = tensor_buf1;

          tensor_buf1 = tensor_buf0;
          tensor_buf0 = tensor0;

          if ((x >= 2) && (x < widthIn)) {
            // Calculate tensor_value
            tensor_value.val[0] = tensor0.val[0]*TENSOR_FILTER[0] + tensor1.val[0]*TENSOR_FILTER[1] + tensor2.val[0]*TENSOR_FILTER[2];
            tensor_value.val[1] = tensor0.val[1]*TENSOR_FILTER[0] + tensor1.val[1]*TENSOR_FILTER[1] + tensor2.val[1]*TENSOR_FILTER[2];
            tensor_value.val[2] = tensor0.val[2]*TENSOR_FILTER[0] + tensor1.val[2]*TENSOR_FILTER[1] + tensor2.val[2]*TENSOR_FILTER[2];
            tensor_value.val[3] = tensor0.val[3]*TENSOR_FILTER[0] + tensor1.val[3]*TENSOR_FILTER[1] + tensor2.val[3]*TENSOR_FILTER[2];
            tensor_value.val[4] = tensor0.val[4]*TENSOR_FILTER[0] + tensor1.val[4]*TENSOR_FILTER[1] + tensor2.val[4]*TENSOR_FILTER[2];
            tensor_value.val[5] = tensor0.val[5]*TENSOR_FILTER[0] + tensor1.val[5]*TENSOR_FILTER[1] + tensor2.val[5]*TENSOR_FILTER[2];

            // Write output tensor_value streaming interface
            tensor.write(tensor_value);
          } else if (x >= 1) {
            // Calculate tensor_value
            tensor_value.val[0] = 0;
            tensor_value.val[1] = 0;
            tensor_value.val[2] = 0;
            tensor_value.val[3] = 0;
            tensor_value.val[4] = 0;
            tensor_value.val[5] = 0;

            // Write output tensor_value streaming interface
            tensor.write(tensor_value);
          }

          if ((x==TARGET_X+1) && (y==TARGET_Y)){
            cout << "HLS_tensor[0]: " << tensor_value.val[0] << endl;
            cout << "HLS_tensor[1]: " << tensor_value.val[1] << endl;
            cout << "HLS_tensor[2]: " << tensor_value.val[2] << endl;
            cout << "HLS_tensor[3]: " << tensor_value.val[3] << endl;
            cout << "HLS_tensor[4]: " << tensor_value.val[4] << endl;
            cout << "HLS_tensor[5]: " << tensor_value.val[5] << endl;
          }

          // programmable width exit condition
          if (x == widthIn) {
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


