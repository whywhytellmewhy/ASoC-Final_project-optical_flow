#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_flow_calc
  {
  public:
    OpticalFlow_flow_calc() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(//ac_channel<tensor_t> &tensor,
                        ac_channel<tensor_int_t> &tensor_shift,
                        ac_channel<velocity_t>  &output,
                        ac_channel<vel_pixel_t>  &denominator,
                        ///////ac_channel<shift_t>  &shift,
                        maxWType            widthIn,
                        maxHType            heightIn)
    {
      /////tensor_t tensor_value;

      //pixel_t denominator_value;
      vel_pixel_t denominator_value;

      tensor_int_t tensor_shift_value;

      velocity_t total_output_value;
      /////shift_t shift_value;

      Flow_calc_ROW: for(maxHType y=0; ; y++) {
        Flow_calc_COLUMN: for(maxWType x=0; ; x++) {
          // read input channels
          /////tensor_value = tensor.read();
          tensor_shift_value = tensor_shift.read();

          // reset shift_value
          /////shift_value = 0;
            
          if ((y >= 2) && (y < heightIn-2) && (x >= 2) && (x < widthIn-2)) {
            //if ((x==302) && (y==116)){
            //if ((x==785) && (y==287)){
            //if ((x==354) && (y==277)){
            /*if ((x==TARGET_X) && (y==TARGET_Y)){
              cout << endl << "HLS_tensor_value[0]: " << tensor_value.val[0] << endl;
              cout << "HLS_tensor_value[1]: " << tensor_value.val[1] << endl;
              cout << "HLS_tensor_value[2]: " << tensor_value.val[2] << endl;
              cout << "HLS_tensor_value[3]: " << tensor_value.val[3] << endl;
              cout << "HLS_tensor_value[4]: " << tensor_value.val[4] << endl;
              cout << "HLS_tensor_value[5]: " << tensor_value.val[5] << endl;
            
              for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
                cout << tensor_value.val[0][k];
              }
              printf("\n");
              
              for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
                cout << tensor_value.val[1][k];
              }
              printf("\n");
              
              for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
                cout << tensor_value.val[2][k];
              }
              printf("\n");
              
              for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
                cout << tensor_value.val[3][k];
              }
              printf("\n");
              
              for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
                cout << tensor_value.val[4][k];
              }
              printf("\n");
              
              for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
                cout << tensor_value.val[5][k];
              }
              printf("\n");
            }

            // shift left until MSB has non-zero value
            while ((tensor_value.val[0][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor_value.val[0][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor_value.val[1][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor_value.val[1][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor_value.val[3][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor_value.val[3][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor_value.val[4][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor_value.val[4][OUTER_PIXEL_T_BIT_WIDTH-1]) && (tensor_value.val[5][OUTER_PIXEL_T_BIT_WIDTH-2]==tensor_value.val[5][OUTER_PIXEL_T_BIT_WIDTH-1])) { // if we choose tensor_value.val[0][OUTER_PIXEL_T_BIT_WIDTH-1], then after multiplication and add, it will become 32*2+1=65 bits, but we have only 64 bits, thus overflow may happen. Therefore, here we choose tensor_value.val[0][OUTER_PIXEL_T_BIT_WIDTH-2], then we will have 31*2+1=63 bits after multiplication and add
              tensor_value.val[0] = tensor_value.val[0]<<1;
              tensor_value.val[1] = tensor_value.val[1]<<1;
              tensor_value.val[3] = tensor_value.val[3]<<1;
              tensor_value.val[4] = tensor_value.val[4]<<1;
              tensor_value.val[5] = tensor_value.val[5]<<1;
              shift_value = shift_value + 1;
              //cout << x << "," << y << " :" << shift_value <<endl;
              if (shift_value==OUTER_PIXEL_T_BIT_WIDTH-1){
                break;
              }
            }
            //cout << "type: " << typeid(tensor_value.val[0]).name() << endl;
            //cout << x << "," << y << endl;

            // Transform into 32-bit int
            tensor_shift_value.val[0] = tensor_value.val[0].to_int();
            tensor_shift_value.val[1] = tensor_value.val[1].to_int();
            tensor_shift_value.val[2] = tensor_value.val[2].to_int();
            tensor_shift_value.val[3] = tensor_value.val[3].to_int();
            tensor_shift_value.val[4] = tensor_value.val[4].to_int();
            tensor_shift_value.val[5] = tensor_value.val[5].to_int();*/

            // Calculate total_output_value
            denominator_value = (tensor_shift_value.val[0]*tensor_shift_value.val[1] - tensor_shift_value.val[3]*tensor_shift_value.val[3]);
            total_output_value.x = (tensor_shift_value.val[5]*tensor_shift_value.val[3] - tensor_shift_value.val[4]*tensor_shift_value.val[1]); // / denominator_value;
            total_output_value.y = (tensor_shift_value.val[4]*tensor_shift_value.val[3] - tensor_shift_value.val[5]*tensor_shift_value.val[0]); // / denominator_value;
            //if ((x==451) && (y==62)){
            //if ((x==362) && (y==399)){
            //if ((x==317) && (y==189)){
            //if ((x==497) && (y==367)){
            //if ((x==785) && (y==287)){
            //if ((x==354) && (y==277)){
            /*if ((x==TARGET_X) && (y==TARGET_Y)){
              //cout << endl << "HLS_tensor_value[0]: " << tensor_value.val[0] << endl;
              //cout << "HLS_tensor_value[1]: " << tensor_value.val[1] << endl;
              //cout << "HLS_tensor_value[2]: " << tensor_value.val[2] << endl;
              //cout << "HLS_tensor_value[3]: " << tensor_value.val[3] << endl;
              //cout << "HLS_tensor_value[4]: " << tensor_value.val[4] << endl;
              //cout << "HLS_tensor_value[5]: " << tensor_value.val[5] << endl;

              //for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
              //  cout << tensor_value.val[0][k];
              //}
              //printf("\n");
              //
              //for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
              //  cout << tensor_value.val[1][k];
              //}
              //printf("\n");
              //
              //for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
              //  cout << tensor_value.val[2][k];
              //}
              //printf("\n");
              //
              //for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
              //  cout << tensor_value.val[3][k];
              //}
              //printf("\n");
              //
              //for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
              //  cout << tensor_value.val[4][k];
              //}
              //printf("\n");
              //
              //for (int k=OUTER_PIXEL_T_BIT_WIDTH-1;k>0;k=k-1){
              //  cout << tensor_value.val[5][k];
              //}
              //printf("\n");

              cout << endl << "HLS_tensor_shift_value[0]: " << tensor_shift_value.val[0] << endl;
              cout << "HLS_tensor_shift_value[1]: " << tensor_shift_value.val[1] << endl;
              cout << "HLS_tensor_shift_value[2]: " << tensor_shift_value.val[2] << endl;
              cout << "HLS_tensor_shift_value[3]: " << tensor_shift_value.val[3] << endl;
              cout << "HLS_tensor_shift_value[4]: " << tensor_shift_value.val[4] << endl;
              cout << "HLS_tensor_shift_value[5]: " << tensor_shift_value.val[5] << endl;

              cout << "HLS_denominator_value: " << denominator_value << endl;
              //cout << "HLS_shift_value: " << shift_value << endl;
              cout << "HLS_total_output_value.x: " << total_output_value.x << endl;
              cout << "HLS_total_output_value.y: " << total_output_value.y << endl;
              cout << "HLS_total_output_value.x (after division): " << total_output_value.x.to_double()/denominator_value.to_double() << endl;
              cout << "HLS_total_output_value.y (after division): " << total_output_value.y.to_double()/denominator_value.to_double() << endl;
            }*/

            // Write output optical flow (velocity) streaming interface
            output.write(total_output_value);
            denominator.write(denominator_value);
            ///////shift.write(shift_value);
          } else {
            total_output_value.x = 0;
            total_output_value.y = 0;
            denominator_value = 0;

            // Write output optical flow (velocity) streaming interface
            output.write(total_output_value);
            denominator.write(denominator_value);
            ///////shift.write(shift_value);
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


