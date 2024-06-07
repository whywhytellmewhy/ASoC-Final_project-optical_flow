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
                        ac_channel<input_t>  &frame4_a,
                        ac_channel<input_t>  &frame5_a,
                        maxWType             widthIn,
                        maxHType             heightIn)
{
        frames_t frames;
        // stream in and organize the inputs
        FRAMES_CP_OUTER: for (int r=0; r<MAX_HEIGHT; r++) 
        {
            FRAMES_CP_INNER: for (int c=0; c<MAX_WIDTH; c++) 
            {
            // one wide read
            frames = input_frames.read();
            // assign values to different stream channels (FIFO)
            frame1_a.write((input_t)(frames(7 ,  0)));
            frame2_a.write((input_t)(frames(15,  8)));
            frame3_a.write((input_t)(frames(23, 16)));
            frame3_b.write((input_t)(frames(23, 16)));
            frame4_a.write((input_t)(frames(31, 24)));
            frame5_a.write((input_t)(frames(39, 32)));
            }
        }
}
};


