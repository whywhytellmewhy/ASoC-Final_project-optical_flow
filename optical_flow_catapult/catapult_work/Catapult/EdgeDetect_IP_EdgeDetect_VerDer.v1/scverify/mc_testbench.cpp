// ----------------------------------------------------------------------------
// SystemC Testbench Body
//
//    HLS version: 2023.1/1033555 Production Release
//       HLS date: Mon Feb 13 11:32:25 PST 2023
//  Flow Packages: HDL_Tcl 8.0a, SCVerify 10.4
//
//   Generated by: m111061545@ws41
// Generated date: Mon Feb 26 23:42:24 CST 2024
//
// ----------------------------------------------------------------------------
// 
// -------------------------------------
// mc_testbench
// SCVerify mc_testbench SC_MODULE
// -------------------------------------
// 
#include "mc_testbench.h"
#include <mc_testbench_util.h>
#include <mc_simulator_extensions.h>

mc_testbench* mc_testbench::that;
bool testbench::enable_idle_sync_mode;
unsigned short testbench::idle_sync_stable_cycles;
void testbench::set_enable_stalls(bool flag) { mc_testbench::set_enable_stalls(flag); }
void testbench::reset_request() { mc_testbench::that->reset_request(); }
void mc_testbench_reset_request() { mc_testbench::that->reset_request(); }
void* testbench::_dut_inst = NULL;
void* testbench::dut_inst() { return _dut_inst; }
void* mc_testbench_dut_inst() { return testbench::dut_inst(); }
void* testbench::set_dut_inst( void* _inst ) { if(_dut_inst==NULL) _dut_inst=_inst; return _dut_inst; }
void* mc_testbench_set_dut_inst( void* _inst ) { return testbench::set_dut_inst(_inst); }
void mc_testbench_wait_for_idle_sync() { mc_testbench::wait_for_idle_sync(); }
bool testbench::dat_in_ignore;
void mc_testbench_dat_in_skip(bool v) { testbench::dat_in_skip = v; }
bool testbench::dat_in_skip;
bool testbench::dat_in_skip_quiet;
bool testbench::dat_in_skip_once;
bool testbench::dat_in_skip_noerr;
int  testbench::dat_in_array_comp_first;
int  testbench::dat_in_array_comp_last;
mc_wait_ctrl testbench::dat_in_wait_ctrl;
bool testbench::widthIn_ignore;
void mc_testbench_widthIn_skip(bool v) { testbench::widthIn_skip = v; }
bool testbench::widthIn_skip;
bool testbench::widthIn_skip_quiet;
bool testbench::widthIn_skip_once;
bool testbench::widthIn_skip_noerr;
int  testbench::widthIn_array_comp_first;
int  testbench::widthIn_array_comp_last;
mc_wait_ctrl testbench::widthIn_wait_ctrl;
bool testbench::heightIn_ignore;
void mc_testbench_heightIn_skip(bool v) { testbench::heightIn_skip = v; }
bool testbench::heightIn_skip;
bool testbench::heightIn_skip_quiet;
bool testbench::heightIn_skip_once;
bool testbench::heightIn_skip_noerr;
int  testbench::heightIn_array_comp_first;
int  testbench::heightIn_array_comp_last;
mc_wait_ctrl testbench::heightIn_wait_ctrl;
bool testbench::dat_out_ignore;
void mc_testbench_dat_out_skip(bool v) { testbench::dat_out_skip = v; }
bool testbench::dat_out_skip;
bool testbench::dat_out_skip_quiet;
bool testbench::dat_out_skip_once;
bool testbench::dat_out_skip_noerr;
int  testbench::dat_out_array_comp_first;
int  testbench::dat_out_array_comp_last;
bool testbench::dat_out_use_mask;
ac_int<8, false > testbench::dat_out_output_mask;
mc_wait_ctrl testbench::dat_out_wait_ctrl;
bool testbench::dy_ignore;
void mc_testbench_dy_skip(bool v) { testbench::dy_skip = v; }
bool testbench::dy_skip;
bool testbench::dy_skip_quiet;
bool testbench::dy_skip_once;
bool testbench::dy_skip_noerr;
int  testbench::dy_array_comp_first;
int  testbench::dy_array_comp_last;
bool testbench::dy_use_mask;
ac_int<9, true > testbench::dy_output_mask;
mc_wait_ctrl testbench::dy_wait_ctrl;
#ifndef CCS_SCVERIFY_USE_CCS_BLOCK
void testbench::exec_run(ac_channel<ac_int<8, false> > &dat_in, ac_int<11, false> &widthIn, ac_int<10, false> &heightIn, ac_channel<ac_int<8, false> > &dat_out, ac_channel<ac_int<9, true> > &dy) {
   return mc_testbench::exec_run(dat_in, widthIn, heightIn, dat_out, dy);
}
#endif

// ============================================
// Function: wait_for_idle_sync
// --------------------------------------------

void mc_testbench::wait_for_idle_sync()
{
   if (testbench::enable_idle_sync_mode) {
      std::cout << "mc_testbench STOPPING   @ " << sc_time_stamp() << std::endl;
      that->cpp_testbench_active.write(false);
      while (that->design_is_idle.read())  that->wait(that->design_is_idle.value_changed_event());
      while (!that->design_is_idle.read()) that->wait(that->design_is_idle.value_changed_event());
      that->cpp_testbench_active.write(true);
      std::cout << "mc_testbench CONTINUING @ " << sc_time_stamp() << std::endl;
   } else {
      that->cpp_testbench_active.write(true);
   }
}
// ============================================
// Function: set_enable_stalls
// --------------------------------------------

void mc_testbench::set_enable_stalls(bool flag)
{
   if (flag) {
     std::cout << "Enabling STALL_FLAG toggling" << std::endl;
     that->enable_stalls.write(sc_dt::Log_1);
   } else {
     std::cout << "Disabling STALL_FLAG toggling" << std::endl;
     that->enable_stalls.write(sc_dt::Log_0);
   }
}
// ============================================
// Function: reset_request
// --------------------------------------------

void mc_testbench::reset_request()
{
   reset_request_event.notify(0,SC_NS);
}
// ============================================
// Function: capture_dat_in
// --------------------------------------------

void mc_testbench::capture_dat_in( ac_channel<ac_int<8, false > > &dat_in)
{
   static ac_int<8, false > dat_in_tmp;
   static int last_j_dat_in_in = 0;
   if (dat_in_iteration_count == wait_cnt)
      wait_on_input_required();
   if (_capture_dat_in && !testbench::dat_in_ignore)
   {
      if (!dat_in_pointer_set) {
         dat_in_pointer = &(dat_in);
         dat_in_pointer_set = true;
      } else if (dat_in_pointer != &(dat_in) && remaining_ccs_dat_in == 0) {
         std::ostringstream msg; msg.str("");
         msg << "Interface dat_in source switched to a different object in testbench with "
             << remaining_ccs_dat_in << " values remaining in input fifo. No data mismatch detected." <<" @ " << sc_time_stamp();
         SC_REPORT_INFO("User testbench", msg.str().c_str());
         dat_in_pointer = &(dat_in);
      } else if (dat_in_pointer != &(dat_in) && remaining_ccs_dat_in > 0 && remaining_ccs_dat_in != dat_in.ac_channel<ac_int<8, false > >::debug_size()) {
         std::ostringstream msg; msg.str("");
         msg << "Interface dat_in source switched to a different object in testbench with "
             << remaining_ccs_dat_in << " values remaining in input fifo. Simulation mismatch likely. Check golden vs DUT comparison values for errors." <<" @ " << sc_time_stamp();
         SC_REPORT_WARNING("User testbench", msg.str().c_str());
         _channel_mismatch = true;
      }
      int cur_iter = dat_in_capture_count;
      ++dat_in_iteration_count;
      unsigned int chan_factor = 1;
      unsigned int ccs_scv_i,ccs_scv_j;
      ccs_scv_i = remaining_ccs_dat_in;
      while (ccs_scv_i < dat_in.ac_channel<ac_int<8, false > >::debug_size()) {
         for (ccs_scv_j = last_j_dat_in_in; ccs_scv_j < chan_factor; ccs_scv_j++,ccs_scv_i++) {
            if (ccs_scv_i < dat_in.ac_channel<ac_int<8, false > >::debug_size()) {
               dat_in_tmp = dat_in.ac_channel<ac_int<8, false > >::chan[ccs_scv_i];
            } else {
               break;
            }
         }
         if (ccs_scv_j == chan_factor) {
            ccs_dat_in->put(dat_in_tmp);
            last_j_dat_in_in = 0;
            dat_in_capture_count += chan_factor;
         } else {
            last_j_dat_in_in = ccs_scv_j;
         }
      }
      mc_testbench_util::process_wait_ctrl("dat_in",testbench::dat_in_wait_ctrl,ccs_wait_ctrl_dat_in.operator->(),cur_iter,dat_in_capture_count,1);
   }
   testbench::dat_in_ignore = false;
}
// ============================================
// Function: capture_widthIn
// --------------------------------------------

void mc_testbench::capture_widthIn( ac_int<11, false > &widthIn)
{
   if (widthIn_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_widthIn && !testbench::widthIn_ignore)
   {
      int cur_iter = widthIn_iteration_count;
      ++widthIn_iteration_count;
      ccs_widthIn->nb_put(widthIn); // THIS
      ++widthIn_capture_count;
      if (widthIn_iteration_count > 1 && !widthIn_mismatch && widthIn_prev_value != widthIn)
         widthIn_mismatch = true;
      widthIn_prev_value = widthIn;
      if (!testbench::enable_idle_sync_mode && widthIn_mismatch && widthIn_idle_warning) {
         widthIn_idle_warning = false;
         std::ostringstream msg; msg.str("");
         msg << "Direct input \"widthIn\" had its value changed between design function calls with idle synchronization disabled.\n";
         msg << "Warning:  Potential simulation mismatch detected. Consider setting \"IDLE_SYNCHRONIZATION_MODE\" to true in the SCVerify flow.\n";
         msg << "Warning:  Further warnings for this direct input will be suppressed.";
         SC_REPORT_WARNING("User testbench", msg.str().c_str());
      }
      mc_testbench_util::process_wait_ctrl("widthIn",testbench::widthIn_wait_ctrl,ccs_wait_ctrl_widthIn.operator->(),cur_iter,widthIn_capture_count,0);
   }
   testbench::widthIn_ignore = false;
}
// ============================================
// Function: capture_heightIn
// --------------------------------------------

void mc_testbench::capture_heightIn( ac_int<10, false > &heightIn)
{
   if (heightIn_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_heightIn && !testbench::heightIn_ignore)
   {
      int cur_iter = heightIn_iteration_count;
      ++heightIn_iteration_count;
      ccs_heightIn->nb_put(heightIn); // THIS
      ++heightIn_capture_count;
      if (heightIn_iteration_count > 1 && !heightIn_mismatch && heightIn_prev_value != heightIn)
         heightIn_mismatch = true;
      heightIn_prev_value = heightIn;
      if (!testbench::enable_idle_sync_mode && heightIn_mismatch && heightIn_idle_warning) {
         heightIn_idle_warning = false;
         std::ostringstream msg; msg.str("");
         msg << "Direct input \"heightIn\" had its value changed between design function calls with idle synchronization disabled.\n";
         msg << "Warning:  Potential simulation mismatch detected. Consider setting \"IDLE_SYNCHRONIZATION_MODE\" to true in the SCVerify flow.\n";
         msg << "Warning:  Further warnings for this direct input will be suppressed.";
         SC_REPORT_WARNING("User testbench", msg.str().c_str());
      }
      mc_testbench_util::process_wait_ctrl("heightIn",testbench::heightIn_wait_ctrl,ccs_wait_ctrl_heightIn.operator->(),cur_iter,heightIn_capture_count,0);
   }
   testbench::heightIn_ignore = false;
}
// ============================================
// Function: capture_dat_out
// --------------------------------------------

void mc_testbench::capture_dat_out( ac_channel<ac_int<8, false > > &dat_out)
{
   static mc_golden_info< ac_int<8, false >, MaskPacket<1, 8> > dat_out_tmp(testbench::dat_out_ignore, false, dat_out_iteration_count);
   dat_out_tmp._ignore = testbench::dat_out_ignore;
   dat_out_tmp._iteration = dat_out_iteration_count;
   // BEGIN: testbench output_mask control for field_name dat_out
   if ( testbench::dat_out_use_mask ) {
      sc_lv<8> tmp_mask_lv;
      type_to_vector(testbench::dat_out_output_mask, 8, tmp_mask_lv);
      dat_out_tmp._use_mask = true;
      dat_out_tmp._packet._mask = tmp_mask_lv;
   }
   // END: testbench output_mask control for field_name dat_out
   static int last_j_dat_out_out = 0;
   if (_capture_dat_out)
   {
      int cur_iter = dat_out_capture_count;
      ++dat_out_iteration_count;
      unsigned int chan_factor = 1;
      unsigned int ccs_scv_i,ccs_scv_j;
      ccs_scv_i = remaining_dat_out_golden;
      while (ccs_scv_i < dat_out.ac_channel<ac_int<8, false > >::debug_size()) {
         for (ccs_scv_j = last_j_dat_out_out; ccs_scv_j < chan_factor; ccs_scv_j++,ccs_scv_i++) {
            if (ccs_scv_i < dat_out.ac_channel<ac_int<8, false > >::debug_size()) {
               dat_out_tmp._data = dat_out.ac_channel<ac_int<8, false > >::chan[ccs_scv_i];
            } else {
               break;
            }
         }
         if (ccs_scv_j == chan_factor) {
            dat_out_golden.put(dat_out_tmp);
            last_j_dat_out_out = 0;
            dat_out_capture_count += chan_factor;
         } else {
            last_j_dat_out_out = ccs_scv_j;
         }
      }
      mc_testbench_util::process_wait_ctrl("dat_out",testbench::dat_out_wait_ctrl,ccs_wait_ctrl_dat_out.operator->(),cur_iter,dat_out_capture_count,1);
      testbench::dat_out_use_mask = false;
   }
   testbench::dat_out_ignore = false;
   testbench::dat_out_skip = false;
}
// ============================================
// Function: capture_dy
// --------------------------------------------

void mc_testbench::capture_dy( ac_channel<ac_int<9, true > > &dy)
{
   static mc_golden_info< ac_int<9, true >, MaskPacket<1, 9> > dy_tmp(testbench::dy_ignore, false, dy_iteration_count);
   dy_tmp._ignore = testbench::dy_ignore;
   dy_tmp._iteration = dy_iteration_count;
   // BEGIN: testbench output_mask control for field_name dy
   if ( testbench::dy_use_mask ) {
      sc_lv<9> tmp_mask_lv;
      type_to_vector(testbench::dy_output_mask, 9, tmp_mask_lv);
      dy_tmp._use_mask = true;
      dy_tmp._packet._mask = tmp_mask_lv;
   }
   // END: testbench output_mask control for field_name dy
   static int last_j_dy_out = 0;
   if (_capture_dy)
   {
      int cur_iter = dy_capture_count;
      ++dy_iteration_count;
      unsigned int chan_factor = 1;
      unsigned int ccs_scv_i,ccs_scv_j;
      ccs_scv_i = remaining_dy_golden;
      while (ccs_scv_i < dy.ac_channel<ac_int<9, true > >::debug_size()) {
         for (ccs_scv_j = last_j_dy_out; ccs_scv_j < chan_factor; ccs_scv_j++,ccs_scv_i++) {
            if (ccs_scv_i < dy.ac_channel<ac_int<9, true > >::debug_size()) {
               dy_tmp._data = dy.ac_channel<ac_int<9, true > >::chan[ccs_scv_i];
            } else {
               break;
            }
         }
         if (ccs_scv_j == chan_factor) {
            dy_golden.put(dy_tmp);
            last_j_dy_out = 0;
            dy_capture_count += chan_factor;
         } else {
            last_j_dy_out = ccs_scv_j;
         }
      }
      mc_testbench_util::process_wait_ctrl("dy",testbench::dy_wait_ctrl,ccs_wait_ctrl_dy.operator->(),cur_iter,dy_capture_count,1);
      testbench::dy_use_mask = false;
   }
   testbench::dy_ignore = false;
   testbench::dy_skip = false;
}
// ============================================
// Function: wait_on_input_required
// --------------------------------------------

void mc_testbench::wait_on_input_required()
{
   ++wait_cnt;
   wait(SC_ZERO_TIME); // get fifos a chance to update
   ++period_counter;
   sc_time timeout = sc_time_stamp() - previous_timestamp;
   if (calculate_period && sc_time_stamp() > SC_ZERO_TIME && sc_time_stamp() != previous_timestamp && sc_time_stamp() != timeout) {
      average_period = (average_period + timeout) / 2;
   }
   previous_timestamp = sc_time_stamp();
   while (atleast_one_active_input) {
      if (_capture_dat_in && ccs_dat_in->used() == 0) return;
      that->cpp_testbench_active.write(false);
      if (average_period > SC_ZERO_TIME && sc_time_stamp() != timeout)
         wait(average_period * 10, ccs_dat_in->ok_to_put());
      else
         wait(ccs_dat_in->ok_to_put());
      that->cpp_testbench_active.write(true);
      if (timed_out()) {
         calculate_period = false;
         return;
      }
   }
}
// ============================================
// Function: capture_IN
// --------------------------------------------

void mc_testbench::capture_IN(ac_channel<ac_int<8, false> > &dat_in, ac_int<11, false> &widthIn, ac_int<10, false> &heightIn, ac_channel<ac_int<8, false> > &dat_out, ac_channel<ac_int<9, true> > &dy)
{
   that->capture_dat_in(dat_in);
   that->capture_widthIn(widthIn);
   that->capture_heightIn(heightIn);
   that->remaining_dat_out_golden =  dat_out.ac_channel<ac_int<8, false > >::debug_size();
   that->remaining_dy_golden =  dy.ac_channel<ac_int<9, true > >::debug_size();
}
// ============================================
// Function: capture_OUT
// --------------------------------------------

void mc_testbench::capture_OUT(ac_channel<ac_int<8, false> > &dat_in, ac_int<11, false> &widthIn, ac_int<10, false> &heightIn, ac_channel<ac_int<8, false> > &dat_out, ac_channel<ac_int<9, true> > &dy)
{
   that->remaining_ccs_dat_in =  dat_in.ac_channel<ac_int<8, false > >::debug_size();
   if (testbench::enable_idle_sync_mode && that->remaining_ccs_dat_in != 0) {
      cout << "Warning: Testbench input channel 'dat_in' not empty. Remaining size: " << that->remaining_ccs_dat_in << endl;
   }
   that->capture_dat_out(dat_out);
   that->capture_dy(dy);
   static bool default_idle_sync_mode = ac_env::read_bool("SCVerify_IDLE_SYNCHRONIZATION_MODE",false);
   testbench::enable_idle_sync_mode = default_idle_sync_mode;
}
// ============================================
// Function: exec_run
// --------------------------------------------

void mc_testbench::exec_run(ac_channel<ac_int<8, false> > &dat_in, ac_int<11, false> &widthIn, ac_int<10, false> &heightIn, ac_channel<ac_int<8, false> > &dat_out, ac_channel<ac_int<9, true> > &dy)
{
   #ifndef CCS_SCVERIFY_USE_CCS_BLOCK
   wait_for_idle_sync();
   capture_IN(dat_in, widthIn, heightIn, dat_out, dy);
   EdgeDetect_IP::EdgeDetect_VerDer::run(dat_in, widthIn, heightIn, dat_out, dy);
   // throttle ac_channel based on number of calls to chan::size() or chan::empty() or chan::nb_read() (but not chan::available()) 
   if (1) {
      int cnt=0;
      if (cnt) std::cout << "mc_testbench.cpp: CONTINUES @ " << sc_time_stamp() << std::endl;
      if (cnt) that->cpp_testbench_active.write(true);
   }
   capture_OUT(dat_in, widthIn, heightIn, dat_out, dy);
   #else
   #endif
}
// ============================================
// Function: start_of_simulation
// --------------------------------------------

void mc_testbench::start_of_simulation()
{
   set_enable_stalls(false);
   if (ac_env::read_int("SCVerify_AUTOWAIT", 0) != 0) { //explicitly 0 means off
      SC_REPORT_INFO(name(), "SCVerify AUTOWAIT is enabled for this simulation.");
   }
}
// ============================================
// Function: end_of_simulation
// --------------------------------------------

void mc_testbench::end_of_simulation()
{
   if (!_checked_results) {
      SC_REPORT_INFO(name(), "Testbench exited early or ran into deadlock");
      check_results();
   }
}
// ============================================
// Function: check_results
// --------------------------------------------

void mc_testbench::check_results()
{
   if (_checked_results) return;
   _checked_results = true;
   cout<<endl;
   cout<<"Checking results"<<endl;
   if (main_exit_code) _failed = true;
   int _num_outputs_checked = 0;
   bool _has_capture_counts = false;
   std::ostringstream mctb_msg;
   
   if (!_capture_dat_out) {
      cout<<"'dat_out' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      _failed |= dat_out_comp->check_results(dat_out_capture_count,testbench::dat_out_skip_noerr);
      _has_capture_counts |= !!(dat_out_capture_count);
   }
   if (!_capture_dy) {
      cout<<"'dy' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      _failed |= dy_comp->check_results(dy_capture_count,testbench::dy_skip_noerr);
      _has_capture_counts |= !!(dy_capture_count);
   }
   cout<<endl;
   if (_num_outputs_checked == 0) {
      cout<<"Error: All outputs were optimized away. No output values were compared."<<endl;
      _failed = _failed || (_num_outputs_checked == 0);
   }
   if (!_has_capture_counts) {
      cout<<"Error: Nothing to compare, all output capture counts are zero."<<endl;
      _failed = true;
   }
   if (main_exit_code) cout << "Error: C++ Testbench 'main()' returned a non-zero exit code ("<<main_exit_code<<"). Check your testbench." <<endl;
   mctb_msg.clear();
   if (_failed) mctb_msg << "Simulation FAILED";
   else         mctb_msg << "Simulation PASSED";
   mctb_msg << " @ " << sc_time_stamp();
   if (_channel_mismatch && _failed)
      mctb_msg << endl << "An input channel was switched before the input fifo was fully empty. Check your testbench.";
   SC_REPORT_INFO(this->name(), mctb_msg.str().c_str());
}
// ============================================
// Function: failed
// --------------------------------------------

bool mc_testbench::failed()
{
   return _failed;
}
// ============================================
// Function: set_failed
// --------------------------------------------

void mc_testbench::set_failed(bool fail)
{
   _failed = fail;
}
// ---------------------------------------------------------------
// Process: SC_METHOD wait_for_end
// Static sensitivity: sensitive << clk.pos() << testbench_end_event;

void mc_testbench::wait_for_end() {
   // If run() has not finished, we do nothing here
   if (!testbench_ended) return;
   // check for completed outputs
   if (dat_out_comp->get_compare_count() < dat_out_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
   if (dy_comp->get_compare_count() < dy_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
   // If we made it here, all outputs have flushed. Check the results
   testbench_aw_event.notify(SC_ZERO_TIME);
   SC_REPORT_INFO(name(), "Simulation completed");
   check_results();
   sc_stop();
}
// ---------------------------------------------------------------
// Process: SC_THREAD run
// Static sensitivity: 

void mc_testbench::run() {
   testbench::enable_idle_sync_mode = false;
   testbench::idle_sync_stable_cycles = 1;
   _channel_mismatch = false;
   testbench::dat_in_ignore = false;
   testbench::dat_in_skip = false;
   testbench::dat_in_skip_quiet = false;
   testbench::dat_in_skip_once = false;
   testbench::dat_in_skip_noerr = false;
   testbench::dat_in_array_comp_first = -1;
   testbench::dat_in_array_comp_last = -1;
   testbench::dat_in_wait_ctrl.clear();
   dat_in_capture_count = 0;
   dat_in_iteration_count = 0;
   dat_in_pointer_set = false;
   testbench::widthIn_ignore = false;
   testbench::widthIn_skip = false;
   testbench::widthIn_skip_quiet = false;
   testbench::widthIn_skip_once = false;
   testbench::widthIn_skip_noerr = false;
   testbench::widthIn_array_comp_first = -1;
   testbench::widthIn_array_comp_last = -1;
   testbench::widthIn_wait_ctrl.clear();
   widthIn_capture_count = 0;
   widthIn_iteration_count = 0;
   widthIn_idle_warning = true;
   widthIn_mismatch = false;
   testbench::heightIn_ignore = false;
   testbench::heightIn_skip = false;
   testbench::heightIn_skip_quiet = false;
   testbench::heightIn_skip_once = false;
   testbench::heightIn_skip_noerr = false;
   testbench::heightIn_array_comp_first = -1;
   testbench::heightIn_array_comp_last = -1;
   testbench::heightIn_wait_ctrl.clear();
   heightIn_capture_count = 0;
   heightIn_iteration_count = 0;
   heightIn_idle_warning = true;
   heightIn_mismatch = false;
   testbench::dat_out_ignore = false;
   testbench::dat_out_skip = false;
   testbench::dat_out_skip_quiet = false;
   testbench::dat_out_skip_once = false;
   testbench::dat_out_skip_noerr = false;
   testbench::dat_out_array_comp_first = -1;
   testbench::dat_out_array_comp_last = -1;
   testbench::dat_out_use_mask = false;
   testbench::dat_out_output_mask = (ac_int<8, false >) ~0;
   testbench::dat_out_wait_ctrl.clear();
   dat_out_capture_count = 0;
   dat_out_iteration_count = 0;
   dat_out_pointer_set = false;
   testbench::dy_ignore = false;
   testbench::dy_skip = false;
   testbench::dy_skip_quiet = false;
   testbench::dy_skip_once = false;
   testbench::dy_skip_noerr = false;
   testbench::dy_array_comp_first = -1;
   testbench::dy_array_comp_last = -1;
   testbench::dy_use_mask = false;
   testbench::dy_output_mask = (ac_int<9, true >) ~0;
   testbench::dy_wait_ctrl.clear();
   dy_capture_count = 0;
   dy_iteration_count = 0;
   dy_pointer_set = false;
   testbench testbench_inst(sc_argc(), sc_argv());
   main_exit_code = testbench_inst.main();
   cout<<"Info: Execution of user-supplied C++ testbench 'main()' has completed with exit code = " << main_exit_code << endl;
   cout<<endl;
   cout<<"Info: Collecting data completed"<<endl;
   cout<<"   captured "<<dat_in_capture_count<<" values of dat_in"<<endl;
   cout<<"   captured "<<widthIn_capture_count<<" values of widthIn"<<endl;
   cout<<"   captured "<<heightIn_capture_count<<" values of heightIn"<<endl;
   cout<<"   captured "<<dat_out_capture_count<<" values of dat_out"<<endl;
   cout<<"   captured "<<dy_capture_count<<" values of dy"<<endl;
   testbench_ended = true;
   testbench_end_event.notify(SC_ZERO_TIME);
}
#ifdef CCS_SCVERIFY_USE_CCS_BLOCK
#include "ccs_block_macros.cpp"
#endif
