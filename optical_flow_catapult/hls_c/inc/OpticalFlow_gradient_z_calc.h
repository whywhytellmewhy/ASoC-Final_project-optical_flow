#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_gradient_z_calc
  {
  public:
    OpticalFlow_gradient_z_calc() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<input_t> &frame1_a,
                        ac_channel<input_t> &frame2_a,
                        ac_channel<input_t> &frame3_a,
                        ac_channel<input_t> &frame4_a,
                        ac_channel<input_t> &frame5_a,
                        ac_channel<pixel_t> &gradient_z,
                        maxWType            widthIn,
                        maxHType            heightIn)
{
  for (int r = 0; r < MAX_HEIGHT; r ++)
  {
    for (int c = 0; c < MAX_WIDTH; c ++)
    {
      gradient_z[r][c] = 0.0f;
      gradient_z[r][c] += frame0[r][c] * GRAD_WEIGHTS[0]; 
      gradient_z[r][c] += frame1[r][c] * GRAD_WEIGHTS[1]; 
      gradient_z[r][c] += frame2[r][c] * GRAD_WEIGHTS[2]; 
      gradient_z[r][c] += frame3[r][c] * GRAD_WEIGHTS[3]; 
      gradient_z[r][c] += frame4[r][c] * GRAD_WEIGHTS[4]; 
      gradient_z[r][c] /= 12.0f;
    }
  }
}
};


