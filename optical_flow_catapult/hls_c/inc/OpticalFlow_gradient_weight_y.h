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
  for (int r = 0; r < MAX_HEIGHT + 3; r ++)
  {
    for (int c = 0; c < MAX_WIDTH; c ++)
    {
      gradient_t acc;
      acc.x = 0;
      acc.y = 0;
      acc.z = 0;
      if (r >= 6 && r < MAX_HEIGHT)
      { 
        for (int i = 0; i < 7; i ++)
        {
          acc.x += gradient_x[r-i][c] * GRAD_FILTER[i];
          acc.y += gradient_y[r-i][c] * GRAD_FILTER[i];
          acc.z += gradient_z[r-i][c] * GRAD_FILTER[i];
        }
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


