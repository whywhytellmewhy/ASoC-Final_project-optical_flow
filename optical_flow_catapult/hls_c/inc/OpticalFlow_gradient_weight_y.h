#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_gradient_weight_y
  {
  public:
    OpticalFlow_gradient_weight_y() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<pixel_t>    &gradient_x,
                        ac_channel<pixel_t>    &gradient_y,
                        ac_channel<pixel_t>    &gradient_z,
                        ac_channel<gradient_t> &y_filtered,
                        maxWType            widthIn,
                        maxHType            heightIn)
    {
      // Line buffers store pixel line history - Mapped to RAM
      pixel2x_t line_buf6_Ix[MAX_WIDTH/2];
      pixel2x_t line_buf5_Ix[MAX_WIDTH/2];
      pixel2x_t line_buf4_Ix[MAX_WIDTH/2];
      pixel2x_t line_buf3_Ix[MAX_WIDTH/2];
      pixel2x_t line_buf2_Ix[MAX_WIDTH/2];
      pixel2x_t line_buf1_Ix[MAX_WIDTH/2];
      pixel2x_t line_buf0_Ix[MAX_WIDTH/2];
      pixel2x_t line_buf6_Iy[MAX_WIDTH/2];
      pixel2x_t line_buf5_Iy[MAX_WIDTH/2];
      pixel2x_t line_buf4_Iy[MAX_WIDTH/2];
      pixel2x_t line_buf3_Iy[MAX_WIDTH/2];
      pixel2x_t line_buf2_Iy[MAX_WIDTH/2];
      pixel2x_t line_buf1_Iy[MAX_WIDTH/2];
      pixel2x_t line_buf0_Iy[MAX_WIDTH/2];
      pixel2x_t line_buf6_Iz[MAX_WIDTH/2];
      pixel2x_t line_buf5_Iz[MAX_WIDTH/2];
      pixel2x_t line_buf4_Iz[MAX_WIDTH/2];
      pixel2x_t line_buf3_Iz[MAX_WIDTH/2];
      pixel2x_t line_buf2_Iz[MAX_WIDTH/2];
      pixel2x_t line_buf1_Iz[MAX_WIDTH/2];
      pixel2x_t line_buf0_Iz[MAX_WIDTH/2];
      pixel2x_t rdbuf0_Ix, rdbuf1_Ix, rdbuf2_Ix, rdbuf3_Ix, rdbuf4_Ix, rdbuf5_Ix, rdbuf6_Ix;
      pixel2x_t rdbuf0_Iy, rdbuf1_Iy, rdbuf2_Iy, rdbuf3_Iy, rdbuf4_Iy, rdbuf5_Iy, rdbuf6_Iy;
      pixel2x_t rdbuf0_Iz, rdbuf1_Iz, rdbuf2_Iz, rdbuf3_Iz, rdbuf4_Iz, rdbuf5_Iz, rdbuf6_Iz;
      pixel2x_t wrbuf0_Ix;
      pixel2x_t wrbuf0_Iy;
      pixel2x_t wrbuf0_Iz;
      pixel_t Ix0, Ix1, Ix2, Ix3, Ix4, Ix5, Ix6;
      pixel_t Iy0, Iy1, Iy2, Iy3, Iy4, Iy5, Iy6;
      pixel_t Iz0, Iz1, Iz2, Iz3, Iz4, Iz5, Iz6;

      gradient_t acc_value;

      Gradient_weight_y_ROW: for (int r = 0; r < MAX_HEIGHT + 3; r ++) {
        Gradient_weight_y_COLUMN: for (int c = 0; c < MAX_WIDTH; c ++) {
          
          
          if (r >= 6 && r < MAX_HEIGHT)
          { 
            acc_value.x = gradient_x[r][c]*GRAD_FILTER[0] + gradient_x[r-1][c]*GRAD_FILTER[1] + gradient_x[r-2][c]*GRAD_FILTER[2] + gradient_x[r-3][c]*GRAD_FILTER[3] + gradient_x[r-4][c]*GRAD_FILTER[4] + gradient_x[r-5][c]*GRAD_FILTER[5] + gradient_x[r-6][c]*GRAD_FILTER[6] + gradient_x[r-7][c]*GRAD_FILTER[7];
            acc_value.y = gradient_y[r][c]*GRAD_FILTER[0] + gradient_y[r-1][c]*GRAD_FILTER[1] + gradient_y[r-2][c]*GRAD_FILTER[2] + gradient_y[r-3][c]*GRAD_FILTER[3] + gradient_y[r-4][c]*GRAD_FILTER[4] + gradient_y[r-5][c]*GRAD_FILTER[5] + gradient_y[r-6][c]*GRAD_FILTER[6] + gradient_y[r-7][c]*GRAD_FILTER[7];
            acc_value.z = gradient_z[r][c]*GRAD_FILTER[0] + gradient_z[r-1][c]*GRAD_FILTER[1] + gradient_z[r-2][c]*GRAD_FILTER[2] + gradient_z[r-3][c]*GRAD_FILTER[3] + gradient_z[r-4][c]*GRAD_FILTER[4] + gradient_z[r-5][c]*GRAD_FILTER[5] + gradient_z[r-6][c]*GRAD_FILTER[6] + gradient_z[r-7][c]*GRAD_FILTER[7];

            filt_grad[r-3][c] = acc;            
          }
          else if (r >= 3)
          {
            filt_grad[r-3][c] = acc;
          }
        }
      }
    }
};


