#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_gradient_y_calc
{
  public:
    OpticalFlow_gradient_y_calc() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<input_t> &frame3_c,
                        ac_channel<pixel_t> &gradient_y,
                        maxWType            widthIn,
                        maxHType            heightIn)
    {
      // Line buffers store pixel line history - Mapped to RAM
      //input2x_t line_buf3[MAX_WIDTH/2];
      //input2x_t line_buf2[MAX_WIDTH/2];
      //input2x_t line_buf1[MAX_WIDTH/2];
      //input2x_t line_buf0[MAX_WIDTH/2];
      ac_int<34> line_buf3[MAX_WIDTH/2];
      ac_int<34> line_buf2[MAX_WIDTH/2];
      ac_int<34> line_buf1[MAX_WIDTH/2];
      ac_int<34> line_buf0[MAX_WIDTH/2];
      
      //input2x_t rdbuf0_pix, rdbuf1_pix, rdbuf2_pix, rdbuf3_pix;
      //input2x_t wrbuf0_pix; //, wrbuf1_pix, wrbuf2_pix, wrbuf3_pix;
      ac_int<34> rdbuf0_pix, rdbuf1_pix, rdbuf2_pix, rdbuf3_pix;
      ac_int<34> wrbuf0_pix;
      
      input_t pix0, pix1, pix2, pix3, pix4;
      ac_int<17> pix0_buf, pix1_buf, pix2_buf, pix3_buf, pix4_buf;

      pixel_t gradient_y_value;

      Gradient_y_calc_ROW: for (maxHType y=0; ; y++) {
        Gradient_y_calc_COLUMN: for (maxWType x=0; ; x++) {
          // read input channel
          if (y <= heightIn-1) {
            pix0 = frame3_c.read();
            for(uint i=0; i<INPUT_BIT_WIDTH; i++){
                pix0_buf[i] = pix0[i];
            }
          }
          // Write data cache, write lower 17 on even iterations of COL loop, upper 17 on odd
          if ( (x&1) == 0 ) {
            wrbuf0_pix.set_slc(0,pix0_buf);
          } else {
            wrbuf0_pix.set_slc(17,pix0_buf);

          }
          // Read line buffers into read buffer caches on even iterations of COL loop
          if ( (x&1) == 0 ) {
            // vertical window of pixels
            rdbuf3_pix = line_buf3[x/2];
            rdbuf2_pix = line_buf2[x/2];
            rdbuf1_pix = line_buf1[x/2];
            rdbuf0_pix = line_buf0[x/2];
          } else { // Write line buffer caches on odd iterations of COL loop
            line_buf3[x/2] = rdbuf2_pix; // copy previous line
            line_buf2[x/2] = rdbuf1_pix; // copy previous line
            line_buf1[x/2] = rdbuf0_pix; // copy previous line
            line_buf0[x/2] = wrbuf0_pix; // store current line
          }
          // Get 17-bit data from read buffer caches, lower 17 on even iterations of COL loop
          pix4_buf = ((x&1)==0) ? rdbuf3_pix.slc<17>(0) : rdbuf3_pix.slc<17>(17);
          pix3_buf = ((x&1)==0) ? rdbuf2_pix.slc<17>(0) : rdbuf2_pix.slc<17>(17);
          pix2_buf = ((x&1)==0) ? rdbuf1_pix.slc<17>(0) : rdbuf1_pix.slc<17>(17);
          pix1_buf = ((x&1)==0) ? rdbuf0_pix.slc<17>(0) : rdbuf0_pix.slc<17>(17);
          
          for(uint i=0; i<INPUT_BIT_WIDTH; i++){
            pix4[i] = pix4_buf[i];
            pix3[i] = pix3_buf[i];
            pix2[i] = pix2_buf[i];
            pix1[i] = pix1_buf[i];
          }

          // Boundary condition
          // Here we do NOT care about the value of pix0 when "y >= heightIn"

          // Calculate Iy
          gradient_y_value = (pix0*GRAD_WEIGHTS[4] + pix1*GRAD_WEIGHTS[3] + pix2*GRAD_WEIGHTS[2] + pix3*GRAD_WEIGHTS[1] + pix4*GRAD_WEIGHTS[0]) / 12.0;

          // Write output Iy streaming interface
          if ((y >= 4) && (y < heightIn)) {
            gradient_y.write(gradient_y_value);
          } else if (y >= 2) {
            gradient_y.write(0);
          }

          // programmable width exit condition
          if (x == widthIn-1) {
            break;
          }
        }
        // programmable height exit condition
        if (y == heightIn+1) {
          break;
        }
      }
    }
};


