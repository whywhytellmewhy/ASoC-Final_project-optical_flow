#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_outer_product
  {
  public:
    OpticalFlow_outer_product() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<gradient_t> &filtered_gradient,
                        ac_channel<outer_t>    &out_product,
                        maxWType               widthIn,
                        maxHType               heightIn)
{ 
  for (int r = 0; r < MAX_HEIGHT; r ++)
  {
    for (int c = 0; c < MAX_WIDTH; c ++)
    {
      gradient_t grad = gradient[r][c];
      outer_t out;
      out.val[0] = grad.x * grad.x;
      out.val[1] = grad.y * grad.y;
      out.val[2] = grad.z * grad.z;
      out.val[3] = grad.x * grad.y;
      out.val[4] = grad.x * grad.z;
      out.val[5] = grad.y * grad.z;
      outer_product[r][c] = out;
    }
  }
}
};


