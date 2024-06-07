// ----------------------------------------------------------------------------
// SystemC Testbench Header
//
//    HLS version: 2023.1/1033555 Production Release
//       HLS date: Mon Feb 13 11:32:25 PST 2023
//  Flow Packages: HDL_Tcl 8.0a, SCVerify 10.4
//
//   Generated by: m111061545@ws41
// Generated date: Mon Feb 26 23:43:38 CST 2024
//
// ----------------------------------------------------------------------------
#ifdef CCS_SCVERIFY

// 
// -------------------------------------
// mc_testbench
// SCVerify mc_testbench SC_MODULE
// -------------------------------------
// 
#ifndef INCLUDED_MC_TESTBENCH_H
#define INCLUDED_MC_TESTBENCH_H

#ifdef __SYNTHESIS__
#error __SYNTHESIS__ is a predefined, reserved Catapult macro and cannot be user defined.
#endif

#ifndef SC_USE_STD_STRING
#define SC_USE_STD_STRING
#endif

#include "../../../hls_c/inc/EdgeDetect.h"
#include "ccs_testbench.h"
#include <systemc.h>
#include <tlm.h>
#include <ac_int.h>
#include <ac_fixed.h>
#include <ac_channel.h>
#include <mc_container_types.h>
#include <mc_typeconv.h>
#include <mc_transactors.h>
#include <mc_comparator.h>
#include <mc_end_of_testbench.h>
#include <vector>
#include <ac_read_env.h>


class mc_testbench : public sc_module
{
public:
   // Module instance pointers
   mc_comparator< ac_int<9, false > , MaskPacket< 1, 9 > > *magn_comp;
   mc_comparator< ac_fixed<8, 3, true, AC_TRN, AC_WRAP > , MaskPacket< 1, 8 > > *angle_comp;
   
   // Interface Ports
   sc_in< bool > clk;
   sc_port< tlm::tlm_fifo_put_if< ac_int<9, true > > > ccs_dx_in;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_dx_in;
   sc_port< tlm::tlm_fifo_put_if< int > > ccs_sizecount_dx_in;
   sc_port< tlm::tlm_fifo_put_if< ac_int<9, true > > > ccs_dy_in;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_dy_in;
   sc_port< tlm::tlm_fifo_put_if< int > > ccs_sizecount_dy_in;
   sc_port< tlm::tlm_fifo_put_if< ac_int<11, false > > > ccs_widthIn;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_widthIn;
   sc_port< tlm::tlm_fifo_put_if< ac_int<10, false > > > ccs_heightIn;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_heightIn;
   sc_port< tlm::tlm_fifo_get_if< ac_int<9, false > > > ccs_magn;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_magn;
   sc_port< tlm::tlm_fifo_get_if< ac_fixed<8, 3, true, AC_TRN, AC_WRAP > > > ccs_angle;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_angle;
   sc_in< bool > design_is_idle;
   sc_out< sc_logic > enable_stalls;
   sc_in< unsigned short > stall_coverage;
   
   // Named Objects
   
   // Data objects
   int end_of_sim_wait_count;
   bool testbench_ended;
   int main_exit_code;
   bool atleast_one_active_input;
   sc_time last_event_time;
   sc_time last_event_time2;
   sc_signal< bool >                          cpp_testbench_active;
   sc_event testbench_end_event;
   sc_event testbench_aw_event;
   sc_event reset_request_event;
   bool _checked_results;
   bool _failed;
   static mc_testbench* that;
   bool _channel_mismatch;
   unsigned int remaining_ccs_dx_in;
   bool _capture_dx_in;
   int dx_in_capture_count;
   int dx_in_iteration_count;
   ac_channel<ac_int<9, true > > * dx_in_pointer;
   bool dx_in_pointer_set;
   unsigned int remaining_ccs_dy_in;
   bool _capture_dy_in;
   int dy_in_capture_count;
   int dy_in_iteration_count;
   ac_channel<ac_int<9, true > > * dy_in_pointer;
   bool dy_in_pointer_set;
   bool _capture_widthIn;
   int widthIn_capture_count;
   int widthIn_iteration_count;
   bool _capture_heightIn;
   int heightIn_capture_count;
   int heightIn_iteration_count;
   unsigned int remaining_magn_golden;
   tlm::tlm_fifo< mc_golden_info< ac_int<9, false >, MaskPacket<1, 9> > > magn_golden;
   bool _capture_magn;
   int magn_capture_count;
   int magn_iteration_count;
   ac_channel<ac_int<9, false > > * magn_pointer;
   bool magn_pointer_set;
   unsigned int remaining_angle_golden;
   tlm::tlm_fifo< mc_golden_info< ac_fixed<8, 3, true, AC_TRN, AC_WRAP >, MaskPacket<1, 8> > > angle_golden;
   bool _capture_angle;
   int angle_capture_count;
   int angle_iteration_count;
   ac_channel<ac_fixed<8, 3, true, AC_TRN, AC_WRAP > > * angle_pointer;
   bool angle_pointer_set;
   int wait_cnt;
   sc_time previous_timestamp;
   sc_time average_period;
   unsigned int period_counter;
   bool calculate_period;
   
   // Declare processes (SC_METHOD and SC_THREAD)
   void wait_for_end();
   void run();
   
   // Constructor
   SC_HAS_PROCESS(mc_testbench);
   mc_testbench(
      const sc_module_name& name
   )
      : clk("clk")
      , ccs_dx_in("ccs_dx_in")
      , ccs_wait_ctrl_dx_in("ccs_wait_ctrl_dx_in")
      , ccs_sizecount_dx_in("ccs_sizecount_dx_in")
      , ccs_dy_in("ccs_dy_in")
      , ccs_wait_ctrl_dy_in("ccs_wait_ctrl_dy_in")
      , ccs_sizecount_dy_in("ccs_sizecount_dy_in")
      , ccs_widthIn("ccs_widthIn")
      , ccs_wait_ctrl_widthIn("ccs_wait_ctrl_widthIn")
      , ccs_heightIn("ccs_heightIn")
      , ccs_wait_ctrl_heightIn("ccs_wait_ctrl_heightIn")
      , ccs_magn("ccs_magn")
      , ccs_wait_ctrl_magn("ccs_wait_ctrl_magn")
      , ccs_angle("ccs_angle")
      , ccs_wait_ctrl_angle("ccs_wait_ctrl_angle")
      , design_is_idle("design_is_idle")
      , enable_stalls("enable_stalls")
      , stall_coverage("stall_coverage")
      , cpp_testbench_active("cpp_testbench_active")
      , remaining_ccs_dx_in(0)
      , remaining_ccs_dy_in(0)
      , remaining_magn_golden(0)
      , magn_golden("magn_golden",-1)
      , remaining_angle_golden(0)
      , angle_golden("angle_golden",-1)
   {
      // Instantiate other modules
      magn_comp = new mc_comparator< ac_int<9, false > , MaskPacket< 1, 9 > > (
         "magn_comp",
         "magn",
         1,
         ac_env::read_int("SCVerify_MAX_ERROR_CNT",0),
         1
      );
      magn_comp->data_in(ccs_magn);
      magn_comp->data_golden(magn_golden);
      
      angle_comp = new mc_comparator< ac_fixed<8, 3, true, AC_TRN, AC_WRAP > , MaskPacket< 1, 8 > > (
         "angle_comp",
         "angle",
         1,
         ac_env::read_int("SCVerify_MAX_ERROR_CNT",0),
         1
      );
      angle_comp->data_in(ccs_angle);
      angle_comp->data_golden(angle_golden);
      
      
      // Register processes
      SC_METHOD(wait_for_end);
      sensitive << clk.pos() << testbench_end_event;
      SC_THREAD(run);
      // Other constructor statements
      set_stack_size(64000000);
      _checked_results = false;
      that = this;
      end_of_sim_wait_count = 0;
      testbench_ended = false;
      main_exit_code = 0;
      atleast_one_active_input = true;
      _failed = false;
      _capture_dx_in = true;
      _capture_dy_in = true;
      _capture_widthIn = true;
      _capture_heightIn = true;
      _capture_magn = true;
      _capture_angle = true;
      wait_cnt = 0;
      previous_timestamp = SC_ZERO_TIME;
      average_period = SC_ZERO_TIME;
      period_counter = 0;
      calculate_period = true;
   }
   
   ~mc_testbench()
   {
      delete magn_comp;
      magn_comp = 0;
      delete angle_comp;
      angle_comp = 0;
   }
   
   // C++ class functions
   public:
      static void wait_for_idle_sync() ;
   public:
      static void set_enable_stalls(bool flag) ;
   public:
      void reset_request() ;
   public:
      void capture_dx_in( ac_channel<ac_int<9, true > > &dx_in) ;
   public:
      void capture_dy_in( ac_channel<ac_int<9, true > > &dy_in) ;
   public:
      void capture_widthIn( ac_int<11, false > &widthIn) ;
   public:
      void capture_heightIn( ac_int<10, false > &heightIn) ;
   public:
      void capture_magn( ac_channel<ac_int<9, false > > &magn) ;
   public:
      void capture_angle( ac_channel<ac_fixed<8, 3, true, AC_TRN, AC_WRAP > > &angle) ;
   protected:
      void wait_on_input_required() ;
   public:
      static void capture_IN(ac_channel<ac_int<9, true> > &dx_in, ac_channel<ac_int<9, true> > &dy_in, ac_int<11, false> &widthIn, ac_int<10, false> &heightIn, ac_channel<ac_int<9, false> > &magn, ac_channel<ac_fixed<8, 3, true, AC_TRN, AC_WRAP> > &angle) ;
   public:
      static void capture_OUT(ac_channel<ac_int<9, true> > &dx_in, ac_channel<ac_int<9, true> > &dy_in, ac_int<11, false> &widthIn, ac_int<10, false> &heightIn, ac_channel<ac_int<9, false> > &magn, ac_channel<ac_fixed<8, 3, true, AC_TRN, AC_WRAP> > &angle) ;
   public:
      static void exec_run(ac_channel<ac_int<9, true> > &dx_in, ac_channel<ac_int<9, true> > &dy_in, ac_int<11, false> &widthIn, ac_int<10, false> &heightIn, ac_channel<ac_int<9, false> > &magn, ac_channel<ac_fixed<8, 3, true, AC_TRN, AC_WRAP> > &angle) ;
   protected:
      void start_of_simulation() ;
   protected:
      void end_of_simulation() ;
   public:
      void check_results() ;
   public:
      bool failed() ;
   public:
      void set_failed(bool fail) ;
};
#endif
#endif //CCS_SCVERIFY
