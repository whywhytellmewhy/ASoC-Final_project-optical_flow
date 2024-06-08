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

      Gradient_weight_y_ROW: for (maxHType y=0; ; y++) {
        Gradient_weight_y_COLUMN: for (maxWType x=0; ; x++) {
          // read input channel
          if (y <= heightIn-1) {
            Ix0 = gradient_x.read();
            Iy0 = gradient_y.read();
            Iz0 = gradient_z.read();
          }
          // Write data cache, write lower 32 on even iterations of COL loop, upper 32 on odd
          if ( (x&1) == 0 ) {
            wrbuf0_Ix.set_slc(0,Ix0);
            wrbuf0_Iy.set_slc(0,Iy0);
            wrbuf0_Iz.set_slc(0,Iz0);
          } else {
            wrbuf0_Ix.set_slc(32,Ix0);
            wrbuf0_Iy.set_slc(32,Iy0);
            wrbuf0_Iz.set_slc(32,Iz0);
          }
          // Read line buffers into read buffer caches on even iterations of COL loop
          if ( (x&1) == 0 ) {
            // vertical window of pixels
            rdbuf6_Ix = line_buf6_Ix[x/2];
            rdbuf5_Ix = line_buf5_Ix[x/2];
            rdbuf4_Ix = line_buf4_Ix[x/2];
            rdbuf3_Ix = line_buf3_Ix[x/2];
            rdbuf2_Ix = line_buf2_Ix[x/2];
            rdbuf1_Ix = line_buf1_Ix[x/2];
            rdbuf0_Ix = line_buf0_Ix[x/2];
            rdbuf6_Iy = line_buf6_Iy[x/2];
            rdbuf5_Iy = line_buf5_Iy[x/2];
            rdbuf4_Iy = line_buf4_Iy[x/2];
            rdbuf3_Iy = line_buf3_Iy[x/2];
            rdbuf2_Iy = line_buf2_Iy[x/2];
            rdbuf1_Iy = line_buf1_Iy[x/2];
            rdbuf0_Iy = line_buf0_Iy[x/2];
            rdbuf6_Iz = line_buf6_Iz[x/2];
            rdbuf5_Iz = line_buf5_Iz[x/2];
            rdbuf4_Iz = line_buf4_Iz[x/2];
            rdbuf3_Iz = line_buf3_Iz[x/2];
            rdbuf2_Iz = line_buf2_Iz[x/2];
            rdbuf1_Iz = line_buf1_Iz[x/2];
            rdbuf0_Iz = line_buf0_Iz[x/2];
          } else { // Write line buffer caches on odd iterations of COL loop
            line_buf6_Ix[x/2] = rdbuf5_Ix; // copy previous line
            line_buf5_Ix[x/2] = rdbuf4_Ix; // copy previous line
            line_buf4_Ix[x/2] = rdbuf3_Ix; // copy previous line
            line_buf3_Ix[x/2] = rdbuf2_Ix; // copy previous line
            line_buf2_Ix[x/2] = rdbuf1_Ix; // copy previous line
            line_buf1_Ix[x/2] = rdbuf0_Ix; // copy previous line
            line_buf0_Ix[x/2] = wrbuf0_Ix; // store current line
            line_buf6_Iy[x/2] = rdbuf5_Iy; // copy previous line
            line_buf5_Iy[x/2] = rdbuf4_Iy; // copy previous line
            line_buf4_Iy[x/2] = rdbuf3_Iy; // copy previous line
            line_buf3_Iy[x/2] = rdbuf2_Iy; // copy previous line
            line_buf2_Iy[x/2] = rdbuf1_Iy; // copy previous line
            line_buf1_Iy[x/2] = rdbuf0_Iy; // copy previous line
            line_buf0_Iy[x/2] = wrbuf0_Iy; // store current line
            line_buf6_Iz[x/2] = rdbuf5_Iz; // copy previous line
            line_buf5_Iz[x/2] = rdbuf4_Iz; // copy previous line
            line_buf4_Iz[x/2] = rdbuf3_Iz; // copy previous line
            line_buf3_Iz[x/2] = rdbuf2_Iz; // copy previous line
            line_buf2_Iz[x/2] = rdbuf1_Iz; // copy previous line
            line_buf1_Iz[x/2] = rdbuf0_Iz; // copy previous line
            line_buf0_Iz[x/2] = wrbuf0_Iz; // store current line
          }
          // Get 17-bit data from read buffer caches, lower 17 on even iterations of COL loop
          pix4 = ((x&1)==0) ? rdbuf3_pix.slc<17>(0) : rdbuf3_pix.slc<17>(17);
          pix3 = ((x&1)==0) ? rdbuf2_pix.slc<17>(0) : rdbuf2_pix.slc<17>(17);
          pix2 = ((x&1)==0) ? rdbuf1_pix.slc<17>(0) : rdbuf1_pix.slc<17>(17);
          pix1 = ((x&1)==0) ? rdbuf0_pix.slc<17>(0) : rdbuf0_pix.slc<17>(17);





          
          
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

          // programmable width exit condition
          if (x == widthIn-1) {
            break;
          }
        }
        // programmable height exit condition
        if (y == heightIn+2) {
          break;
        }
      }
    }
};


