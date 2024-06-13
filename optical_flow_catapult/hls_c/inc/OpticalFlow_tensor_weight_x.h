#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_tensor_weight_x
  {
  public:
    OpticalFlow_tensor_weight_x() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<tensor_t> &tensor_y,
                        //ac_channel<tensor_t> &tensor,
                        ac_channel<tensor_int_t> &tensor_shift,
                        maxWType            widthIn,
                        maxHType            heightIn)
    {
      // tensor buffers store tensor history
      tensor_t tensor_buf0 = {0,0,0,0,0,0};
      tensor_t tensor_buf1 = {0,0,0,0,0,0};

      tensor_t tensor0;
      tensor_t tensor1;
      tensor_t tensor2;

      shift_t shift_value;

      tensor_int_half_t tensor_shift0;
      tensor_int_half_t tensor_shift1;
      tensor_int_half_t tensor_shift2;

      ac_int<OUTER_PIXEL_T_INTEGER_PART/2, false> TENSOR_FILTER_int_version[3];

      /////tensor_t tensor_value;
      tensor_int_t tensor_shift_value;

      // transform into ac_int type
      for(uint i=0; i<OUTER_PIXEL_T_INTEGER_PART/2; i++){
          TENSOR_FILTER_int_version[0][i] = TENSOR_FILTER[0][i];
          TENSOR_FILTER_int_version[1][i] = TENSOR_FILTER[1][i];
          TENSOR_FILTER_int_version[2][i] = TENSOR_FILTER[2][i];
      }

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

          if ((x==TARGET_X+1) && (y==TARGET_Y)){
            printf("Before shift:\n");
            printf("tensor0\n");
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor0.val[0][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor0.val[1][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor0.val[2][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor0.val[3][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor0.val[4][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor0.val[5][k];
            }
            printf("\n\n");
            printf("tensor1\n");
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor1.val[0][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor1.val[1][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor1.val[2][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor1.val[3][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor1.val[4][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor1.val[5][k];
            }
            printf("\n\n");
            printf("tensor2\n");
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor2.val[0][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor2.val[1][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor2.val[2][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor2.val[3][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor2.val[4][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>=0;k=k-1){
              cout << tensor2.val[5][k];
            }
            printf("\n\n");
          }

          // reset shift_value
          shift_value = 0;

          // shift left until MSB has non-zero value
          while (((tensor0.val[0][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor0.val[0][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor0.val[1][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor0.val[1][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor0.val[3][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor0.val[3][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor0.val[4][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor0.val[4][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor0.val[5][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor0.val[5][OUTER_PIXEL_T_BIT_WIDTH-1])) && ((tensor1.val[0][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor1.val[0][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor1.val[1][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor1.val[1][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor1.val[3][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor1.val[3][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor1.val[4][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor1.val[4][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor1.val[5][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor1.val[5][OUTER_PIXEL_T_BIT_WIDTH-1])) && ((tensor2.val[0][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor2.val[0][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor2.val[1][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor2.val[1][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor2.val[3][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor2.val[3][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor2.val[4][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor2.val[4][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor2.val[5][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor2.val[5][OUTER_PIXEL_T_BIT_WIDTH-1]))) { // if we choose tensorXX.val[0][OUTER_PIXEL_T_BIT_WIDTH-1], then after multiplication and add, it will become 32*2+1=65 bits, but we have only 64 bits, thus overflow may happen. Therefore, here we choose tensorXX.val[0][OUTER_PIXEL_T_BIT_WIDTH-2], then we will have 31*2+1=63 bits after multiplication and add
            tensor0.val[0] = tensor0.val[0]<<1;
            tensor0.val[1] = tensor0.val[1]<<1;
            tensor0.val[3] = tensor0.val[3]<<1;
            tensor0.val[4] = tensor0.val[4]<<1;
            tensor0.val[5] = tensor0.val[5]<<1;
            tensor1.val[0] = tensor1.val[0]<<1;
            tensor1.val[1] = tensor1.val[1]<<1;
            tensor1.val[3] = tensor1.val[3]<<1;
            tensor1.val[4] = tensor1.val[4]<<1;
            tensor1.val[5] = tensor1.val[5]<<1;
            tensor2.val[0] = tensor2.val[0]<<1;
            tensor2.val[1] = tensor2.val[1]<<1;
            tensor2.val[3] = tensor2.val[3]<<1;
            tensor2.val[4] = tensor2.val[4]<<1;
            tensor2.val[5] = tensor2.val[5]<<1;
            shift_value = shift_value + 1;
            //cout << x << "," << y << " :" << shift_value <<endl;
            if (shift_value==OUTER_PIXEL_T_BIT_WIDTH-1){
              break;
            }
          }

          // Transform into 16-bit int
          tensor_shift0.val[0] = tensor0.val[0].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift0.val[1] = tensor0.val[1].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift0.val[2] = tensor0.val[2].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift0.val[3] = tensor0.val[3].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift0.val[4] = tensor0.val[4].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift0.val[5] = tensor0.val[5].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift1.val[0] = tensor1.val[0].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift1.val[1] = tensor1.val[1].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift1.val[2] = tensor1.val[2].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift1.val[3] = tensor1.val[3].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift1.val[4] = tensor1.val[4].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift1.val[5] = tensor1.val[5].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift2.val[0] = tensor2.val[0].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift2.val[1] = tensor2.val[1].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift2.val[2] = tensor2.val[2].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift2.val[3] = tensor2.val[3].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift2.val[4] = tensor2.val[4].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();
          tensor_shift2.val[5] = tensor2.val[5].slc<OUTER_PIXEL_T_INTEGER_PART/2>(OUTER_PIXEL_T_BIT_WIDTH-OUTER_PIXEL_T_INTEGER_PART/2); //.to_int();

          if ((x==TARGET_X+1) && (y==TARGET_Y)){
            printf("After shift and slicing:\n");
            printf("tensor_shift0\n");
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift0.val[0][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift0.val[1][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift0.val[2][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift0.val[3][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift0.val[4][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift0.val[5][k];
            }
            printf("\n\n");
            printf("tensor_shift1\n");
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift1.val[0][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift1.val[1][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift1.val[2][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift1.val[3][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift1.val[4][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift1.val[5][k];
            }
            printf("\n\n");
            printf("tensor_shift2\n");
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift2.val[0][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift2.val[1][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift2.val[2][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift2.val[3][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift2.val[4][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << tensor_shift2.val[5][k];
            }
            printf("\n\n");
            printf("TENSOR_FILTER_int_version\n");
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << TENSOR_FILTER_int_version[0][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << TENSOR_FILTER_int_version[1][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART/2-1;k>=0;k=k-1){
              cout << TENSOR_FILTER_int_version[2][k];
            }
            printf("\n\n");
          }

          if ((x >= 2) && (x < widthIn)) {
            // Calculate tensor_shift_value
            tensor_shift_value.val[0] = tensor_shift0.val[0]*TENSOR_FILTER_int_version[0] + tensor_shift1.val[0]*TENSOR_FILTER_int_version[1] + tensor_shift2.val[0]*TENSOR_FILTER_int_version[2];
            tensor_shift_value.val[1] = tensor_shift0.val[1]*TENSOR_FILTER_int_version[0] + tensor_shift1.val[1]*TENSOR_FILTER_int_version[1] + tensor_shift2.val[1]*TENSOR_FILTER_int_version[2];
            tensor_shift_value.val[2] = tensor_shift0.val[2]*TENSOR_FILTER_int_version[0] + tensor_shift1.val[2]*TENSOR_FILTER_int_version[1] + tensor_shift2.val[2]*TENSOR_FILTER_int_version[2];
            tensor_shift_value.val[3] = tensor_shift0.val[3]*TENSOR_FILTER_int_version[0] + tensor_shift1.val[3]*TENSOR_FILTER_int_version[1] + tensor_shift2.val[3]*TENSOR_FILTER_int_version[2];
            tensor_shift_value.val[4] = tensor_shift0.val[4]*TENSOR_FILTER_int_version[0] + tensor_shift1.val[4]*TENSOR_FILTER_int_version[1] + tensor_shift2.val[4]*TENSOR_FILTER_int_version[2];
            tensor_shift_value.val[5] = tensor_shift0.val[5]*TENSOR_FILTER_int_version[0] + tensor_shift1.val[5]*TENSOR_FILTER_int_version[1] + tensor_shift2.val[5]*TENSOR_FILTER_int_version[2];

            // Write output tensor_shift_value streaming interface
            tensor_shift.write(tensor_shift_value);
          } else if (x >= 1) {
            // Calculate tensor_shift_value
            tensor_shift_value.val[0] = 0;
            tensor_shift_value.val[1] = 0;
            tensor_shift_value.val[2] = 0;
            tensor_shift_value.val[3] = 0;
            tensor_shift_value.val[4] = 0;
            tensor_shift_value.val[5] = 0;

            // Write output tensor_shift_value streaming interface
            tensor_shift.write(tensor_shift_value);
          }

          if ((x==TARGET_X+1) && (y==TARGET_Y)){
            /////cout << "HLS_tensor[0]: " << tensor_value.val[0] << endl;
            /////cout << "HLS_tensor[1]: " << tensor_value.val[1] << endl;
            /////cout << "HLS_tensor[2]: " << tensor_value.val[2] << endl;
            /////cout << "HLS_tensor[3]: " << tensor_value.val[3] << endl;
            /////cout << "HLS_tensor[4]: " << tensor_value.val[4] << endl;
            /////cout << "HLS_tensor[5]: " << tensor_value.val[5] << endl;
            cout << "HLS_tensor[0]: " << tensor_shift_value.val[0] << endl;
            cout << "HLS_tensor[1]: " << tensor_shift_value.val[1] << endl;
            cout << "HLS_tensor[2]: " << tensor_shift_value.val[2] << endl;
            cout << "HLS_tensor[3]: " << tensor_shift_value.val[3] << endl;
            cout << "HLS_tensor[4]: " << tensor_shift_value.val[4] << endl;
            cout << "HLS_tensor[5]: " << tensor_shift_value.val[5] << endl;
            cout << "HLS_shift_value: " << shift_value << endl;
          }

          if ((x==TARGET_X+1) && (y==TARGET_Y)){
            printf("tensor_shift_value\n");
            for (int k=OUTER_PIXEL_T_INTEGER_PART-1;k>=0;k=k-1){
              cout << tensor_shift_value.val[0][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART-1;k>=0;k=k-1){
              cout << tensor_shift_value.val[1][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART-1;k>=0;k=k-1){
              cout << tensor_shift_value.val[2][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART-1;k>=0;k=k-1){
              cout << tensor_shift_value.val[3][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART-1;k>=0;k=k-1){
              cout << tensor_shift_value.val[4][k];
            }
            printf("\n");
            
            for (int k=OUTER_PIXEL_T_INTEGER_PART-1;k>=0;k=k-1){
              cout << tensor_shift_value.val[5][k];
            }
            printf("\n");
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


