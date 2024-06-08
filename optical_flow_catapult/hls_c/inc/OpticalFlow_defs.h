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

#include <ac_int.h>
#include <ac_fixed.h>
#include <ac_channel.h>
#include <ac_math/ac_sqrt_pwl.h>
#include <ac_math/ac_atan2_cordic.h>

const int MAX_HEIGHT = 436;
const int MAX_WIDTH = 1024;
const int INPUT_BIT_WIDTH = 17;


// basic typedefs
<<<<<<< Updated upstream
typedef ac_fixed<17,9,true> input_t;
typedef ac_fixed<32,13,true> pixel_t;
typedef ac_fixed<32,27,true> outer_pixel_t;
typedef ac_fixed<64,56,true> calc_pixel_t;
typedef ac_fixed<32,13,true> vel_pixel_t;
=======
typedef ac_fixed<INPUT_BIT_WIDTH, 9, true, AC_TRN, AC_WRAP> input_t; // Integer part: 9 ; Decimal part: 8 ; signed
typedef ac_fixed<34,18, true, AC_TRN, AC_WRAP> input2x_t; // For ping-pong buffer
typedef ac_fixed<32,13, true, AC_TRN, AC_WRAP> pixel_t; // Integer part: 13 ; Decimal part: 19 ; signed
typedef ac_fixed<64,26, true, AC_TRN, AC_WRAP> pixel2x_t; // For ping-pong buffer
typedef ac_fixed<32,27, true, AC_TRN, AC_WRAP> outer_pixel_t; // Integer part: 27 ; Decimal part: 5 ; signed
typedef ac_fixed<64,56, true, AC_TRN, AC_WRAP> calc_pixel_t; // Integer part: 56 ; Decimal part: 8 ; signed
typedef ac_fixed<32,13, true, AC_TRN, AC_WRAP> vel_pixel_t; // Integer part: 13 ; Decimal part: 19 ; signed
>>>>>>> Stashed changes

typedef struct{
	pixel_t x;
	pixel_t y;
	pixel_t z;
}gradient_t;

typedef struct{
    outer_pixel_t val[6];
}outer_t; 

typedef struct{
    outer_pixel_t val[6];
}tensor_t;

typedef struct{
    vel_pixel_t x;
    vel_pixel_t y;
}velocity_t;

// for data packing
typedef ac_int<64> frames_t;

// Compute number of bits for max image size count, used internally and in testbench
typedef ac_int<ac::nbits<MAX_WIDTH+1>::val,false> maxWType;
typedef ac_int<ac::nbits<MAX_HEIGHT+1>::val,false> maxHType;

// convolution filters
/////const int GRAD_WEIGHTS[] =  {1,-8,0,8,-1};
const input_t GRAD_WEIGHTS[5] =  {1/12,-8/12,0/12,8/12,-1/12};
const pixel_t GRAD_FILTER[7] = {0.0755, 0.133, 0.1869, 0.2903, 0.1869, 0.133, 0.0755};
const pixel_t TENSOR_FILTER[3] = {0.3243, 0.3513, 0.3243};

