/**************************************************************************
 *                                                                        *
 *  Edge Detect Design Walkthrough for HLS                                *
 *                                                                        *
 *  Software Version: 1.0                                                 *
 *                                                                        *
 *  Release Date    : Tue Jan 14 15:40:43 PST 2020                        *
 *  Release Type    : Production Release                                  *
 *  Release Build   : 1.0.0                                               *
 *                                                                        *
 *  Copyright 2020, Siemens                                               *
 *                                                                        *
 **************************************************************************
 *  Licensed under the Apache License, Version 2.0 (the "License");       *
 *  you may not use this file except in compliance with the License.      *
 *  You may obtain a copy of the License at                               *
 *                                                                        *
 *      http://www.apache.org/licenses/LICENSE-2.0                        *
 *                                                                        *
 *  Unless required by applicable law or agreed to in writing, software   *
 *  distributed under the License is distributed on an "AS IS" BASIS,     *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or       *
 *  implied.                                                              *
 *  See the License for the specific language governing permissions and   *
 *  limitations under the License.                                        *
 **************************************************************************
 *                                                                        *
 *  The most recent version of this package is available at github.       *
 *                                                                        *
 *************************************************************************/
#pragma once

#include "OpticalFlow_defs.h"
#include "OpticalFlow_framesplit.h"
#include "OpticalFlow_gradient_xy_calc.h"
#include "OpticalFlow_gradient_z_calc.h"
#include "OpticalFlow_gradient_weight_y.h"
#include "OpticalFlow_gradient_weight_x.h"
#include "OpticalFlow_outer_product.h"
#include "OpticalFlow_tensor_weight_y.h"
#include "OpticalFlow_tensor_weight_x.h"
#include "OpticalFlow_flow_calc.h"

#include <mc_scverify.h>

<<<<<<< Updated upstream
// convolution filters
const int GRAD_WEIGHTS[] =  {1,-8,0,8,-1};
const pixel_t GRAD_FILTER[] = {0.0755, 0.133, 0.1869, 0.2903, 0.1869, 0.133, 0.0755};
const pixel_t TENSOR_FILTER[] = {0.3243, 0.3513, 0.3243};

=======
>>>>>>> Stashed changes
// top-level kernel function
#pragma hls_design top
  class OpticalFlow_Top
{
  //instances
  OpticalFlow_framesplit         framesplit_inst;
  OpticalFlow_gradient_xy_calc   gradient_xy_calc_inst;
  OpticalFlow_gradient_z_calc    gradient_z_calc_inst;
  OpticalFlow_gradient_weight_y  gradient_weight_y_inst;
  OpticalFlow_gradient_weight_x  gradient_weight_x_inst;
  OpticalFlow_outer_product      outer_product_inst;
  OpticalFlow_tensor_weight_y    tensor_weight_y_inst;
  OpticalFlow_tensor_weight_x    tensor_weight_x_inst;
  OpticalFlow_flow_calc          flow_calc_inst;

  // FIFOs connecting the stages
  ac_channel<pixel_t> gradient_x;
  ac_channel<pixel_t> gradient_y;
  ac_channel<pixel_t> gradient_z;
  ac_channel<gradient_t> y_filtered;
  ac_channel<gradient_t> filtered_gradient;
  ac_channel<outer_t> out_product;
  ac_channel<tensor_t> tensor_y;
  ac_channel<tensor_t> tensor;

  // FIFOs for streaming in, just for clarity
  ac_channel<input_t> frame1_a;
  ac_channel<input_t> frame2_a;
  ac_channel<input_t> frame3_a;
  ac_channel<input_t> frame4_a;
  ac_channel<input_t> frame5_a;

  //Need to duplicate frame3 for the two calculations
  ac_channel<input_t> frame3_b;

  public:
    OpticalFlow_Top() {}
  
    //--------------------------------------------------------------------------
    // Function: run
    //   Top interface for data in/out of class. Combines vertical and
    //   horizontal derivative and magnitude/angle computation.
    #pragma hls_design interface
    void CCS_BLOCK(run)(ac_channel<frames_t>    &input_frames,
                        maxWType                widthIn,
                        maxHType                heightIn,
                        ac_channel<velocity_t>  &outputs)
    {
      // compute
      framesplit_inst.run(input_frames, frame1_a, frame2_a, frame3_a, frame3_b, frame4_a, frame5_a, widthIn, heightIn);
      gradient_xy_calc_inst.run(frame3_b, gradient_x, gradient_y, widthIn, heightIn);
      gradient_z_calc_inst.run(frame1_a, frame2_a, frame3_a, frame4_a, frame5_a, gradient_z, widthIn, heightIn);
      gradient_weight_y_inst.run(gradient_x, gradient_y, gradient_z, y_filtered, widthIn, heightIn);
      gradient_weight_x_inst.run(y_filtered, filtered_gradient, widthIn, heightIn);
      outer_product_inst.run(filtered_gradient, out_product, widthIn, heightIn);
      tensor_weight_y_inst.run(out_product, tensor_y, widthIn, heightIn);
      tensor_weight_x_inst.run(tensor_y, tensor, widthIn, heightIn);
      flow_calc_inst.run(tensor, outputs, widthIn, heightIn);
    }
  };

#endif


