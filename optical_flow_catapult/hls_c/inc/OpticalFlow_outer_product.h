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
      gradient_t filtered_gradient_value;

      outer_t out_product_value;

      Outer_product_ROW: for (maxHType y=0; ; y++) {
        Outer_product_COLUMN: for (maxWType x=0; ; x++) {
          // read input channels
          filtered_gradient_value = filtered_gradient.read();

          // Calculate out_product_value
          out_product_value.val[0] = filtered_gradient_value.x * filtered_gradient_value.x;
          out_product_value.val[1] = filtered_gradient_value.y * filtered_gradient_value.y;
          out_product_value.val[2] = filtered_gradient_value.z * filtered_gradient_value.z;
          out_product_value.val[3] = filtered_gradient_value.x * filtered_gradient_value.y;
          out_product_value.val[4] = filtered_gradient_value.x * filtered_gradient_value.z;
          out_product_value.val[5] = filtered_gradient_value.y * filtered_gradient_value.z;

          // Write output Iz streaming interface
          out_product.write(out_product_value);

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


