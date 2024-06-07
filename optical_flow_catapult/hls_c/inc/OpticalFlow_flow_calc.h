#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_flow_calc
  {
  public:
    OpticalFlow_flow_calc() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<tensor_t> &tensor,
                        ac_channel<velocity_t>  &output,
                        maxWType            widthIn,
                        maxHType            heightIn)
{
  for(int r = 0; r < MAX_HEIGHT; r ++)
  {
    for(int c = 0; c < MAX_WIDTH; c ++)
    {
      if (r >= 2 && r < MAX_HEIGHT - 2 && c >= 2 && c < MAX_WIDTH - 2)
      {
        pixel_t denom = tensors[r][c].val[0] * tensors[r][c].val[1] -
                        tensors[r][c].val[3] * tensors[r][c].val[3];
        output[r][c].x = (tensors[r][c].val[5] * tensors[r][c].val[3] -
                          tensors[r][c].val[4] * tensors[r][c].val[1]) / denom;
        output[r][c].y = (tensors[r][c].val[4] * tensors[r][c].val[3] -
                          tensors[r][c].val[5] * tensors[r][c].val[0]) / denom;
      }
      else
      {
        output[r][c].x = 0;
        output[r][c].y = 0;
      }
    }
  }
}
};


