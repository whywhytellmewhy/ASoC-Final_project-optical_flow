#pragma once

#include "OpticalFlow_defs.h"
#include <mc_scverify.h>

class OpticalFlow_framesplit
  {
  public:
    OpticalFlow_framesplit() {}
  
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<frames_t> &input_frames,
                        ac_channel<input_t>  &frame1_a,
                        ac_channel<input_t>  &frame2_a,
                        ac_channel<input_t>  &frame3_a,
                        ac_channel<input_t>  &frame3_b,
                        ac_channel<input_t>  &frame3_c,
                        ac_channel<input_t>  &frame4_a,
                        ac_channel<input_t>  &frame5_a,
                        maxWType             widthIn,
                        maxHType             heightIn)
    {
      frames_t input_frame;
      // stream in and split the input frames into 6 channels
      Framesplit_ROW: for (maxHType y=0; ; y++) {
        Framesplit_COLUMN: for (maxWType x=0; ; x++) {
          // read input channel
          input_frame = input_frames.read();

          // assign values to different stream channels (FIFO)
          frame1_a.write((input_t)(input_frame(7 ,  0)) >> 8);
          frame2_a.write((input_t)(input_frame(15,  8)) >> 8);
          frame3_a.write((input_t)(input_frame(23, 16)) >> 8);
          frame3_b.write((input_t)(input_frame(23, 16)) >> 8);
          frame3_c.write((input_t)(input_frame(23, 16)) >> 8);
          frame4_a.write((input_t)(input_frame(31, 24)) >> 8);
          frame5_a.write((input_t)(input_frame(39, 32)) >> 8);

          // programmable width exit condition
          if (x == widthIn-1) {
            break;
          }
        }
        // programmable height exit condition
        if (y == heightIn-1) {
          break;
        }
      }
    }
};


