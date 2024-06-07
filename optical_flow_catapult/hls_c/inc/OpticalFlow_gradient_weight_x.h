#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_gradient_weight_x
  {
  public:
    OpticalFlow_gradient_weight_x() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<gradient_t> &y_filtered,
                        ac_channel<gradient_t> &filtered_gradient,
                        maxWType            widthIn,
                        maxHType            heightIn)
{
  for (int r = 0; r < MAX_HEIGHT; r ++)
  {
    for (int c = 0; c < MAX_WIDTH + 3; c ++)
    {
      gradient_t acc;
      acc.x = 0;
      acc.y = 0;
      acc.z = 0;
      if (c >= 6 && c < MAX_WIDTH)
      {
        for (int i = 0; i < 7; i ++)
        {
          acc.x += y_filt[r][c-i].x * GRAD_FILTER[i];
          acc.y += y_filt[r][c-i].y * GRAD_FILTER[i];
          acc.z += y_filt[r][c-i].z * GRAD_FILTER[i];
        }
        filt_grad[r][c-3] = acc;
      }
      else if (c >= 3)
      {
        filt_grad[r][c-3] = acc;
      }
    }
  }
}
};


