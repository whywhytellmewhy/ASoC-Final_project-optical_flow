
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#include "bmpUtil/bmp_io.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <mc_scverify.h>

//////////////// When doing only "algorithm" simulaion, without HLS simulation //////////////////////
//#include "OpticalFlow_defs.h"
//////////////////////////////////////

#include "OpticalFlow.h"
#include "OpticalFlow_Algorithm.h"


CCS_MAIN(int argc, char *argv[])
{
  const int iW = 1024;
  const int iH = 436;
  OpticalFlow_Algorithm<iW,iH> ref_inst;
  OpticalFlow_Top               dut;

  unsigned long int width = iW;
  long int height         = iH;

  maxWType widthIn = iW;
  maxHType heightIn = iH;
  

  unsigned char *rarray1 = new unsigned char[iH*iW];
  unsigned char *garray1 = new unsigned char[iH*iW];
  unsigned char *barray1 = new unsigned char[iH*iW];
  unsigned char *rarray2 = new unsigned char[iH*iW];
  unsigned char *garray2 = new unsigned char[iH*iW];
  unsigned char *barray2 = new unsigned char[iH*iW];
  unsigned char *rarray3 = new unsigned char[iH*iW];
  unsigned char *garray3 = new unsigned char[iH*iW];
  unsigned char *barray3 = new unsigned char[iH*iW];
  unsigned char *rarray4 = new unsigned char[iH*iW];
  unsigned char *garray4 = new unsigned char[iH*iW];
  unsigned char *barray4 = new unsigned char[iH*iW];
  unsigned char *rarray5 = new unsigned char[iH*iW];
  unsigned char *garray5 = new unsigned char[iH*iW];
  unsigned char *barray5 = new unsigned char[iH*iW];

  cout << "Loading Input File" << endl;

  if (argc < 11) {
    cout << "Usage: " << argv[0] << " <inputbmp 1~5> <outputbmp_algorithm_u> <outputbmp_algorithm_v> <outputbmp_algorithm_magnitude> <outputbmp_HLS_u> <outputbmp_HLS_v> <outputbmp_HLS_magnitude>" << endl;
    CCS_RETURN(-1);
  }

  std::string input_location1(argv[1]);  // input bitmap file
  std::string input_location2(argv[2]);  // input bitmap file
  std::string input_location3(argv[3]);  // input bitmap file
  std::string input_location4(argv[4]);  // input bitmap file
  std::string input_location5(argv[5]);  // input bitmap file
  std::string bmpAlg_u(argv[6]); // output bitmap (algorithm)
  std::string bmpAlg_v(argv[7]); // output bitmap (algorithm)
  std::string bmpAlg_magnitude(argv[8]); // output bitmap (algorithm)
  std::string bmpHLS_u(argv[9]);  // output bitmap (bit-accurate)
  std::string bmpHLS_v(argv[10]);  // output bitmap (bit-accurate)
  std::string bmpHLS_magnitude(argv[11]);  // output bitmap (bit-accurate)

  //std::string input_location1="./image/frame1.png";
  //std::string input_location2="./image/frame2.png";
  //std::string input_location3="./image/frame3.png";
  //std::string input_location4="./image/frame4.png";
  //std::string input_location5="./image/frame5.png";

  bmp_read((char*)input_location1.c_str(), &width, &height, &rarray1, &garray1, &barray1);
  bmp_read((char*)input_location2.c_str(), &width, &height, &rarray2, &garray2, &barray2);
  bmp_read((char*)input_location3.c_str(), &width, &height, &rarray3, &garray3, &barray3);
  bmp_read((char*)input_location4.c_str(), &width, &height, &rarray4, &garray4, &barray4);
  bmp_read((char*)input_location5.c_str(), &width, &height, &rarray5, &garray5, &barray5);
  assert(width==iW);
  assert(height==iH);

  //ac_channel<input_t> frame1_channel;
  //ac_channel<input_t> frame2_channel;
  //ac_channel<input_t> frame3_channel;
  //ac_channel<input_t> frame4_channel;
  //ac_channel<input_t> frame5_channel;
  ac_channel<frames_t> frames_channel;
  /////ac_channel<pixel_t> gradient_x_HLS; // <-----------------------------------------------------------------------------------
  /////ac_channel<gradient_t> gradient_x_HLS;
  /////ac_channel<outer_t> gradient_x_HLS;
  /////ac_channel<tensor_t> gradient_x_HLS;
  ac_channel<velocity_t> output_HLS_channel;
  //ac_channel<pixel_t> denominator_HLS_channel;
  ac_channel<vel_pixel_t> denominator_HLS_channel;
  ac_channel<shift_t> shift_HLS_channel;

  static float frame1[iH][iW];
  static float frame2[iH][iW];
  static float frame3[iH][iW];
  static float frame4[iH][iW];
  static float frame5[iH][iW];
  /////static float gradient_x_algorithm[iH][iW]; // <-----------------------------------------------------------------------------------
  /////static gradient_t_sw gradient_x_algorithm[iH][iW];
  /////static outer_t_sw gradient_x_algorithm[iH][iW];
  /////static tensor_t_sw gradient_x_algorithm[iH][iW];
  static velocity_t_sw output_algorithm[iH][iW];
  static pixel_t_sw denom_algorithm[iH][iW];

  unsigned  cnt = 0;
  for (int y = 0; y < iH; y++) {
    for (int x = 0; x < iW; x++) {
      // input for HLS
      ///////////////////////////////frame1_channel.write((input_t)(rarray1[cnt])); // just using red component (pseudo monochrome)
      ///////////////////////////////frame2_channel.write((input_t)(rarray2[cnt]));
      ///////////////////////////////frame3_channel.write((input_t)(rarray3[cnt]));
      ///////////////////////////////frame4_channel.write((input_t)(rarray4[cnt]));
      ///////////////////////////////frame5_channel.write((input_t)(rarray5[cnt]));
      frames_channel.write((((frames_t)rarray5[cnt]) << 32) + (((frames_t)rarray4[cnt]) << 24) + (((frames_t)rarray3[cnt]) << 16) + (((frames_t)rarray2[cnt]) << 8) + (frames_t)rarray1[cnt]);
      //printf("%x\n", rarray1[cnt]);
      //printf("%x\n", rarray2[cnt]);
      //printf("%x\n", rarray3[cnt]);
      //printf("%x\n", rarray4[cnt]);
      //printf("%x\n", rarray5[cnt]);
      //printf("%x\n", (((frames_t)rarray5[cnt]) << 32) + (((frames_t)rarray4[cnt]) << 24) + (((frames_t)rarray3[cnt]) << 16) + (((frames_t)rarray2[cnt]) << 8) + (frames_t)rarray1[cnt]);
      
      // input for algorithm
      frame1[y][x] = float(rarray1[cnt]);
      frame2[y][x] = float(rarray2[cnt]);
      frame3[y][x] = float(rarray3[cnt]);
      frame4[y][x] = float(rarray4[cnt]);
      frame5[y][x] = float(rarray5[cnt]);
      cnt++;
    }
  }

#ifdef CCS_SCVERIFY
//  dat_in_wait_ctrl.mode     = mc_wait_ctrl::RANDOM;
//  dat_in_wait_ctrl.cycles   = 5;
//  dat_in_wait_ctrl.elements = mc_wait_ctrl::ALL;
//  dat_in_wait_ctrl.interval = 0;
#endif

  cout << "Running" << endl;

  /////ref_inst.run(frame1,frame2,frame3,frame4,frame5,output_algorithm);
  ref_inst.run(frame1,frame2,frame3,frame4,frame5,denom_algorithm,output_algorithm);
  /////ref_inst.run(frame1,frame2,frame3,frame4,frame5,gradient_x_algorithm,output_algorithm); // <-----------------------------------------------------------------------------------
  /////dut.run(frames_channel,widthIn,heightIn,output_HLS_channel);
  dut.run(frames_channel,widthIn,heightIn,denominator_HLS_channel,shift_HLS_channel,output_HLS_channel);
  /////dut.run(frames_channel,widthIn,heightIn,denominator_HLS_channel,output_HLS_channel);
  /////dut.run(frames_channel,widthIn,heightIn,gradient_x_HLS,output_HLS_channel); // <-----------------------------------------------------------------------------------

  cnt = 0;
  float sumErr_magnitude = 0;
  //double magnitude_algorithm;
  for (int y = 0; y < heightIn; y++) {
    for (int x = 0; x < iW; x++) {
      //velocity_t algorithm = *(output_algorithm+cnt);
      ///////////////velocity_t_sw algorithm = output_algorithm[y][x];
      ///////////////////////////////velocity_t HLS = output_HLS_channel.read()
      ///////////////float u_algorithm = (double)(algorithm.x);
      ///////////////////////////////float u_HLS = (HLS.x).to_double();
      ///////////////////////////////float Absdiff_u = abs(u_algorithm-u_HLS);
      ///////////////////////////////sumErr_u += Absdiff_u;
      ///////////////float v_algorithm = (double)(algorithm.y);
      ///////////////////////////////float v_HLS = (HLS.y).to_double();
      ///////////////////////////////float Absdiff_v = abs(v_algorithm-v_HLS);
      ///////////////////////////////sumErr_v += Absdiff_v;
      //cnt++;
      ///////////////double magnitude_algorithm = sqrt(u_algorithm*u_algorithm + v_algorithm*v_algorithm);
      //if ((u_algorithm == 0.0) && (v_algorithm == 0.0)){
      //  magnitude_algorithm = 0;
      //  if ((x==299) && (y==115)) {
      //    printf("2222222222222\n");
      //  }
      //} else {
      //  magnitude_algorithm = sqrt(u_algorithm*u_algorithm + v_algorithm*v_algorithm); // https://blog.csdn.net/ten_k/article/details/106576818
      //  if ((x==299) && (y==115)) {
      //    //printf("%0.32f\n",u_algorithm*u_algorithm+v_algorithm*v_algorithm);
      //    printf("%0.32f\n",u_algorithm);
      //    printf("%0.32f\n",v_algorithm);
      //    cout << (u_algorithm*u_algorithm+v_algorithm*v_algorithm == 0.0) << endl;
      //  }
      //}
      
      ///////////////////////////////double magnitude_HLS = sqrt(u_HLS*u_HLS + v_HLS*v_HLS);
      ///////////////////////////////rarray1[cnt] = (int)u_HLS;   // repurposing 'red' array to the bit-accurate monochrome output
      ///////////////////////////////rarray2[cnt] = (int)v_HLS;
      ///////////////////////////////rarray3[cnt] = (int)magnitude_HLS;
      ///////////////garray1[cnt] = (int)u_algorithm;  // repurposing 'green' array to the original algorithmic output
      ///////////////garray2[cnt] = (int)v_algorithm;
      ///////////////garray3[cnt] = (int)magnitude_algorithm;

      //cout << magnitude_algorithm << ", ";
      //if (x==50) {
      //  printf("%f, ", frame3[y][x]);
      //}
      //printf("[algorithm] gradient_x = %f\n", gradient_x_algorithm[y][x]);
      //printf("[   HLS   ] gradient_x = %f\n", gradient_x_HLS.read().to_double());
      

      ////////////////////////////////////////////////////////////////////////////////////// (version 1: test intermediate output values) //////////////////////////////////////////////////////////////////////////////////////
      //double test = gradient_x_HLS.read().to_double();

      //gradient_t out_test = gradient_x_HLS.read();
      //double test = out_test.z.to_double();

      //outer_t out_test = gradient_x_HLS.read();
      //double test = out_test.val[3].to_double();

      //tensor_t out_test = gradient_x_HLS.read();
      //for (int index = 0; index < 6; index++) {
      //  double test = out_test.val[index].to_double();
      //  if (abs(gradient_x_algorithm[y][x].val[index]-test) > 1) { // We can set "threshold=0.1" before OpticalFlow_gradient_weight_x.h, and set "threshold=1" after OpticalFlow_outer_product.h
      //  if (x>5 && x<1020 && y>5 && y<430) {
      //    printf("(%d, %d), index = %d, ", x, y, index);
      //    //cout << gradient_x_algorithm[y-3][x] << ", " << gradient_x_algorithm[y-2][x] << ", " << gradient_x_algorithm[y-1][x] << ", " << gradient_x_algorithm[y][x] << ", " << gradient_x_algorithm[y+1][x] << ", " << gradient_x_algorithm[y+2][x] << ", " << gradient_x_algorithm[y+3][x] << endl;
      //    printf("(algorithm, HLS) = (%f, %f), error = %f\n", gradient_x_algorithm[y][x].val[index], test, abs(gradient_x_algorithm[y][x].val[index]-test)); // <-----------------------------------------------------------------------------------
      //  }
      //  }
      //}

      ////////////////////////////////////////////////////////////////////////////////////// (version 2: output velocity with non-shift) //////////////////////////////////////////////////////////////////////////////////////
      double tolerable_error_threshold = 1;
      double denominator_threshold = 1e-15;
      
      velocity_t final_velocity_HLS = output_HLS_channel.read();
      double final_velocity_x_HLS = final_velocity_HLS.x.to_double();
      double final_velocity_y_HLS = final_velocity_HLS.y.to_double();
      
      double denominator_HLS = denominator_HLS_channel.read().to_double();
      int shift_HLS = shift_HLS_channel.read().to_int();
      shift_HLS = shift_HLS*2; // This is because in OpticalFlow_flow_calc.h, we have "tensor_shift_value.val[0]*tensor_shift_value.val[1]," so the effect of shifting will become square.
      //printf("%f * %f --> ", final_velocity_x_HLS,denominator_HLS);
      if (abs(denominator_HLS/pow(2,shift_HLS))<denominator_threshold){
        final_velocity_x_HLS = 0;
        final_velocity_y_HLS = 0;
      } else {
        final_velocity_x_HLS = final_velocity_x_HLS/denominator_HLS;
        final_velocity_y_HLS = final_velocity_y_HLS/denominator_HLS;
      }
      //printf("%f\n", final_velocity_x_HLS);

      if (abs(denom_algorithm[y][x])<denominator_threshold){
        output_algorithm[y][x].x = 0;
        output_algorithm[y][x].y = 0;
      }

      if ((x==0) && (y==0)) {
        printf("\n\nReport those pixels with error value > %f as following:\n", tolerable_error_threshold);
      }
      if (x>5 && x<1020 && y>5 && y<430) {
      if (abs(output_algorithm[y][x].x-final_velocity_x_HLS) > tolerable_error_threshold) { // We can set "threshold=0.1" before OpticalFlow_gradient_weight_x.h, and set "threshold=1" after OpticalFlow_outer_product.h
        printf("(%d, %d), ", x, y);
        printf("u: (algorithm, HLS) = (%f, %f), error = %f\n", output_algorithm[y][x].x, final_velocity_x_HLS, abs(output_algorithm[y][x].x-final_velocity_x_HLS));
      }
      if (abs(output_algorithm[y][x].y-final_velocity_y_HLS) > tolerable_error_threshold) { // We can set "threshold=0.1" before OpticalFlow_gradient_weight_x.h, and set "threshold=1" after OpticalFlow_outer_product.h
        printf("(%d, %d), ", x, y);
        printf("v: (algorithm, HLS) = (%f, %f), error = %f\n", output_algorithm[y][x].y, final_velocity_y_HLS, abs(output_algorithm[y][x].y-final_velocity_y_HLS));
      }
      if ((output_algorithm[y][x].x==0) && (output_algorithm[y][x].y==0) && (final_velocity_x_HLS!=0) && (final_velocity_y_HLS!=0)){
        printf("denominator: (algorithm, HLS (after shift))  = (%0.32f, %0.32f)\n", denom_algorithm[y][x], denominator_HLS/pow(2,shift_HLS));
      }
      }


      float u_algorithm = (double)(output_algorithm[y][x].x);
      float v_algorithm = (double)(output_algorithm[y][x].y);
      double magnitude_algorithm = sqrt(u_algorithm*u_algorithm + v_algorithm*v_algorithm);
      
      float u_HLS = final_velocity_x_HLS;
      float v_HLS = final_velocity_y_HLS;
      double magnitude_HLS = sqrt(u_HLS*u_HLS + v_HLS*v_HLS);

      float Absdiff_magnitude = abs(magnitude_algorithm-magnitude_HLS);
      sumErr_magnitude += Absdiff_magnitude;
      //printf("(%d,%d), sumErr_magnitude = %f\n",x,y,sumErr_magnitude); //299 115
      //if ((x==299) && (y==115)) { // We can set "threshold=0.1" before OpticalFlow_gradient_weight_x.h, and set "threshold=1" after OpticalFlow_outer_product.h
      //  printf("(%d, %d), ", x, y);
      //  printf("u: (algorithm, HLS) = (%0.32f, %f), error = %f\n", output_algorithm[y][x].x, final_velocity_x_HLS, abs(output_algorithm[y][x].x-final_velocity_x_HLS));
      //  printf("v: (algorithm, HLS) = (%0.32f, %f), error = %f\n", output_algorithm[y][x].y, final_velocity_y_HLS, abs(output_algorithm[y][x].y-final_velocity_y_HLS));
      //  printf("magnitude: (algorithm, HLS) = (%f, %f)\n", magnitude_algorithm, magnitude_HLS);
      //  printf("Absdiff_magnitude = %f\n",Absdiff_magnitude);
      //  printf("sumErr_magnitude = %f\n",sumErr_magnitude);
      //}

      garray1[cnt] = (int)u_algorithm;  // repurposing 'green' array to the original algorithmic output
      garray2[cnt] = (int)v_algorithm;
      garray3[cnt] = (int)magnitude_algorithm;

      rarray1[cnt] = (int)u_HLS;  // repurposing 'red' array to the original HLS output
      rarray2[cnt] = (int)v_HLS;
      rarray3[cnt] = (int)magnitude_HLS;

      ////////////////////////////////////////////////////////////////////////////////////// (version 3: output velocity with shift channel) //////////////////////////////////////////////////////////////////////////////////////
      ///// Use the same testbench as version 2

      cnt++;
    }
  }

  printf("Magnitude: Manhattan norm per pixel %f\n",sumErr_magnitude/(iH*iW));

  cout << "Writing algorithmic bitmap output to: " << bmpAlg_u << endl;
  bmp_24_write((char*)bmpAlg_u.c_str(), iW,  iH, garray1, garray1, garray1);
  cout << "Writing algorithmic bitmap output to: " << bmpAlg_v << endl;
  bmp_24_write((char*)bmpAlg_v.c_str(), iW,  iH, garray2, garray2, garray2);
  cout << "Writing algorithmic bitmap output to: " << bmpAlg_magnitude << endl;
  bmp_24_write((char*)bmpAlg_magnitude.c_str(), iW,  iH, garray3, garray3, garray3);

  cout << "Writing bit-accurate bitmap output to: " << bmpHLS_u << endl;
  bmp_24_write((char*)bmpHLS_u.c_str(), iW,  iH, rarray1, rarray1, rarray1);
  cout << "Writing bit-accurate bitmap output to: " << bmpHLS_v << endl;
  bmp_24_write((char*)bmpHLS_v.c_str(), iW,  iH, rarray2, rarray2, rarray2);
  cout << "Writing bit-accurate bitmap output to: " << bmpHLS_magnitude << endl;
  bmp_24_write((char*)bmpHLS_magnitude.c_str(), iW,  iH, rarray3, rarray3, rarray3);

  //delete (frame1);
  //delete (frame2);
  //delete (frame3);
  //delete (frame4);
  //delete (frame5);
  //delete (output_algorithm);
  delete (rarray1);
  delete (garray1);
  delete (barray1);
  delete (rarray2);
  delete (garray2);
  delete (barray2);
  delete (rarray3);
  delete (garray3);
  delete (barray3);
  delete (rarray4);
  delete (garray4);
  delete (barray4);
  delete (rarray5);
  delete (garray5);
  delete (barray5);

  cout << "Finished" << endl;

  CCS_RETURN(0);
}
