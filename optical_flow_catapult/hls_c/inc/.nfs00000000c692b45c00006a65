#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_gradient_xy_calc
  {
  public:
    OpticalFlow_gradient_xy_calc() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<input_t> &frame3_b,
                        ac_channel<pixel_t> &gradient_x,
                        ac_channel<pixel_t> &gradient_y,
                        maxWType            widthIn,
                        maxHType            heightIn)
{
  pixel_t x_grad, y_grad;
  for (int r = 0; r < MAX_HEIGHT + 2; r ++ )
  {
    for (int c = 0; c < MAX_WIDTH + 2; c ++)
    {
      frame = frame3_b.read(); // input channel

      x_grad = 0;
      y_grad = 0;
      if (r >= 4 && r < MAX_HEIGHT && c >= 4 && c < MAX_WIDTH)
      {
        for (int i = 0; i < 5; i++)
        {
          x_grad += frame[r-2][c-i] * GRAD_WEIGHTS[4-i];
          y_grad += frame[r-i][c-2] * GRAD_WEIGHTS[4-i];
        }
        gradient_x[r-2][c-2] = x_grad / 12;
        gradient_y[r-2][c-2] = y_grad / 12;
      }
      else if (r >= 2 && c >= 2)
      {
        gradient_x[r-2][c-2] = 0;
        gradient_y[r-2][c-2] = 0;
      }
    }
  }
}
};


