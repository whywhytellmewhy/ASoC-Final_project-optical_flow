
#ifndef __TYPE_DEFS__
#define __TYPE_DEFS__
const int MAX_HEIGHT = 436;
const int MAX_WIDTH = 1024;

typedef float pixel_t_sw;
typedef float outer_pixel_t_sw;
typedef float vel_pixel_t_sw;

typedef struct{
	pixel_t_sw x;
	pixel_t_sw y;
	pixel_t_sw z;
}gradient_t_sw;

typedef struct{
    outer_pixel_t_sw val[6];
}outer_t_sw; 

typedef struct{
    outer_pixel_t_sw val[6];
}tensor_t_sw;

typedef struct{
    vel_pixel_t_sw x;
    vel_pixel_t_sw y;
}velocity_t_sw;

#endif


#ifndef __OPTICAL_FLOW_H__
#define __OPTICAL_FLOW_H__

#include <mc_scverify.h>

// convolution filters
const float GRAD_WEIGHTS[5] =  {1,-8,0,8,-1};
const pixel_t_sw GRAD_FILTER[7] = {0.0755, 0.133, 0.1869, 0.2903, 0.1869, 0.133, 0.0755};
const pixel_t_sw TENSOR_FILTER[3] = {0.3243, 0.3513, 0.3243};

#endif
