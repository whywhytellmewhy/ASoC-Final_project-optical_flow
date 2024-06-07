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
  for (int r = 0; r < MAX_HEIGHT; r ++)
  {
    for (int c = 0; c < MAX_WIDTH + 1; c ++)
    {
      tensor_t acc;
      for(int k = 0; k < 6; k++)
      {
        acc.val[k] = 0;
      }
      if (c >= 2 && c < MAX_WIDTH) 
      {
        for (int i = 0; i < 3; i ++)
        {
          for (int component = 0; component < 6; component ++)
          {
            acc.val[component] += tensor_y[r][c-i].val[component] * TENSOR_FILTER[i];
          }
        }
      }
      if (c >= 1)
      {
        tensor[r][c-1] = acc;
      }
    }
  }
}
};


