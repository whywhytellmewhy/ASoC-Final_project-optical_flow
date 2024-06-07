#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_tensor_weight_y
  {
  public:
    OpticalFlow_tensor_weight_y() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<outer_t>  &out_product,
                        ac_channel<tensor_t> &tensor_y,
                        maxWType            widthIn,
                        maxHType            heightIn)
{
  for (int r = 0; r < MAX_HEIGHT + 1; r ++)
  {
    for(int c = 0; c < MAX_WIDTH; c ++)
    {
      tensor_t acc;
      for (int k = 0; k < 6; k ++)
      {
        acc.val[k] = 0;
      }

      if (r >= 2 && r < MAX_HEIGHT) 
      {
        for (int i = 0; i < 3; i ++)
        {
          for(int component = 0; component < 6; component ++)
          {
            acc.val[component] += outer[r-i][c].val[component] * TENSOR_FILTER[i];
          }
        }
      }
      if (r >= 1)
      { 
        tensor_y[r-1][c] = acc;            
      }
    }
  }
}
};


