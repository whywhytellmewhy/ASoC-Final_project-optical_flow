# ----------------------------------------------------------------------------
# Concat RTL Verilog output 'concat_sim_rtl.v' vs Untimed C++
#
#    HLS version: 2023.1/1033555 Production Release
#       HLS date: Mon Feb 13 11:32:25 PST 2023
#  Flow Packages: HDL_Tcl 8.0a, SCVerify 10.4
#
#   Generated by: m111061545@ws41
# Generated date: Mon Feb 26 23:42:25 CST 2024
#
# ----------------------------------------------------------------------------
# ===================================================
# DEFAULT GOAL is the help target
.PHONY: all
all: help

# ===================================================
# Directories (at the time this makefile was created)
#   MGC_HOME      /usr/cadtool/mentor/Catapult/2023.1/Mgc_home
#   PROJECT_HOME  /home/m111/m111061545/catapult/catapult-for-soc-course/lab2_edgedetec_fsic/01_edgedetect/catapult_work
#   SOLUTION_DIR  /home/m111/m111061545/catapult/catapult-for-soc-course/lab2_edgedetec_fsic/01_edgedetect/catapult_work/Catapult/EdgeDetect_IP_EdgeDetect_VerDer.v1
#   WORKING_DIR   /home/m111/m111061545/catapult/catapult-for-soc-course/lab2_edgedetec_fsic/01_edgedetect/catapult_work/Catapult/EdgeDetect_IP_EdgeDetect_VerDer.v1/.

# ===================================================
# VARIABLES
# 
MGC_HOME          = /usr/cadtool/mentor/Catapult/2023.1/Mgc_home
export MGC_HOME

WORK_DIR  = $(CURDIR)
WORK2PROJ = ../..
WORK2SOLN = .
PROJ2WORK = ./Catapult/EdgeDetect_IP_EdgeDetect_VerDer.v1
PROJ2SOLN = ./Catapult/EdgeDetect_IP_EdgeDetect_VerDer.v1
export WORK_DIR
export WORK2PROJ
export WORK2SOLN
export PROJ2WORK
export PROJ2SOLN

# Variables that can be overridden from the make command line
ifeq "$(INCL_DIRS)" ""
INCL_DIRS                   = ./scverify . ../.. ../../../hls_c/inc ../../../cmodel/inc ../../../bmpUtil/inc ../../../hls_c/inc ../../../cmodel/inc ../../../bmpUtil/inc
endif
export INCL_DIRS
ifeq "$(STAGE)" ""
STAGE                       = rtl
endif
export STAGE
ifeq "$(NETLIST_LEAF)" ""
NETLIST_LEAF                = concat_sim_rtl
endif
export NETLIST_LEAF
ifeq "$(SIMTOOL)" ""
SIMTOOL                     = msim
endif
export SIMTOOL
ifeq "$(NETLIST)" ""
NETLIST                     = v
endif
export NETLIST
ifeq "$(RTL_NETLIST_FNAME)" ""
RTL_NETLIST_FNAME           = /home/m111/m111061545/catapult/catapult-for-soc-course/lab2_edgedetec_fsic/01_edgedetect/catapult_work/Catapult/EdgeDetect_IP_EdgeDetect_VerDer.v1/concat_sim_rtl.v
endif
export RTL_NETLIST_FNAME
ifeq "$(GATE_FNAME_BASE)" ""
GATE_FNAME_BASE             = gate.or.v
endif
export GATE_FNAME_BASE
ifeq "$(INVOKE_ARGS)" ""
INVOKE_ARGS                 = ./image/people_gray.bmp out_algorithm.bmp out_hw.bmp
endif
export INVOKE_ARGS
export SCVLIBS
export MODELSIM
TOP_HDL_ENTITY           := EdgeDetect_IP_EdgeDetect_VerDer
TOP_DU                   := scverify_top
CXX_TYPE                 := gcc
MSIM_SCRIPT              := ./Catapult/EdgeDetect_IP_EdgeDetect_VerDer.v1/scverify_msim.tcl
TARGET                   := scverify/$(NETLIST_LEAF)_$(NETLIST)_$(SIMTOOL)
export TOP_HDL_ENTITY
export TARGET

ifeq ($(RECUR),)
ifeq ($(STAGE),mapped)
ifeq ($(RTLTOOL),)
   $(error This makefile requires specifying the RTLTOOL variable on the make command line)
endif
endif
endif
# ===================================================
# Include environment variables set by flow options
include ./ccs_env.mk

# ===================================================
# Include makefile for default commands and variables
include $(MGC_HOME)/shared/include/mkfiles/ccs_default_cmds.mk

SYNTHESIS_FLOWPKG := OasysRTL
SYN_FLOW          := OasysRTL
# ===================================================
# SOURCES
# 
# Specify list of Questa SIM libraries to create
HDL_LIB_NAMES = work
# ===================================================
# Simulation libraries required by loaded Catapult libraries or gate simulation
SIMLIBS_V   += 
SIMLIBS_VHD += 
# 
# 
# Specify list of source files - MUST be ordered properly
ifeq ($(STAGE),gate)
ifeq ($(RTLTOOL),)
# Unless overridden on make command line, GATE_*_DEP is the last item in the netlist dependency list
ifeq ($(GATE_VHDL_DEP),)
GATE_VHDL_DEP = 
endif
ifeq ($(GATE_VLOG_DEP),)
GATE_VLOG_DEP = ./concat_sim_rtl.v/concat_sim_rtl.v.vts
endif
endif
VHDL_SRC +=  $(GATE_VHDL_DEP)
VLOG_SRC +=  $(GATE_VLOG_DEP)
else
VHDL_SRC += 
VLOG_SRC += ./concat_sim_rtl.v/concat_sim_rtl.v.vts
endif
CXX_SRC  = ../../../hls_c/src/EdgeDetect_tb.cpp/EdgeDetect_tb.cpp.cxxts ../../../bmpUtil/src/bmp_io.cpp/bmp_io.cpp.cxxts ./scverify/mc_testbench.cpp/mc_testbench.cpp.cxxts ./scverify/scverify_top.cpp/scverify_top.cpp.cxxts
# Specify RTL synthesis scripts (if any)
RTL_SCRIPT = 

# Specify hold time file name (for verifying synthesized netlists)
HLD_CONSTRAINT_FNAME = top_gate_constraints.cpp

# ===================================================
# GLOBAL OPTIONS
# 
# CXXFLAGS - global C++ options (apply to all C++ compilations) except for include file search paths
CXXFLAGS += -DCCS_SCVERIFY -DSC_INCLUDE_DYNAMIC_PROCESSES -DSC_USE_STD_STRING -DTOP_HDL_ENTITY=$(TOP_HDL_ENTITY) -DCCS_DESIGN_FUNC_EdgeDetect_IP_EdgeDetect_VerDer_run -DCCS_DESIGN_TOP_$(TOP_HDL_ENTITY) -DCCS_MISMATCHED_OUTPUTS_ONLY $(F_WRAP_OPT)
# 
# If the make command line includes a definition of the special variable MC_DEFAULT_TRANSACTOR_LOG
# then define that value for all compilations as well
ifneq "$(MC_DEFAULT_TRANSACTOR_LOG)" ""
CXXFLAGS += -DMC_DEFAULT_TRANSACTOR_LOG=$(MC_DEFAULT_TRANSACTOR_LOG)
endif
# 
# CXX_INCLUDES - include file search paths
CXX_INCLUDES = ./scverify . ../.. ../../../hls_c/inc ../../../cmodel/inc ../../../bmpUtil/inc ../../../hls_c/inc ../../../cmodel/inc ../../../bmpUtil/inc
# 
# TCL shell
TCLSH_CMD = /usr/cadtool/mentor/Catapult/2023.1/Mgc_home/bin/tclsh8.5

# Pass along SCVerify_DEADLOCK_DETECTION option
ifneq "$(SCVerify_DEADLOCK_DETECTION)" "false"
CXXFLAGS += -DDEADLOCK_DETECTION
endif
# ===================================================
# PER SOURCE FILE SPECIALIZATIONS
# 
# Specify source file paths
ifeq ($(STAGE),gate)
ifneq ($(GATE_VHDL_DEP),)
$(TARGET)/$(notdir $(GATE_VHDL_DEP)): $(dir $(GATE_VHDL_DEP))
endif
ifneq ($(GATE_VLOG_DEP),)
$(TARGET)/$(notdir $(GATE_VLOG_DEP)): $(dir $(GATE_VLOG_DEP))
endif
endif
$(TARGET)/concat_sim_rtl.v.vts: ./concat_sim_rtl.v
$(TARGET)/EdgeDetect_tb.cpp.cxxts: ../../../hls_c/src/EdgeDetect_tb.cpp
$(TARGET)/bmp_io.cpp.cxxts: ../../../bmpUtil/src/bmp_io.cpp
$(TARGET)/mc_testbench.cpp.cxxts: ./scverify/mc_testbench.cpp
$(TARGET)/scverify_top.cpp.cxxts: ./scverify/scverify_top.cpp
# 
# Specify additional C++ options per C++ source by setting CXX_OPTS
$(TARGET)/bmp_io.cpp.cxxts: CXX_OPTS=
$(TARGET)/scverify_top.cpp.cxxts: CXX_OPTS=
$(TARGET)/mc_testbench.cpp.cxxts: CXX_OPTS=$(F_WRAP_OPT)
$(TARGET)/EdgeDetect_tb.cpp.cxxts: CXX_OPTS=
# 
# Specify dependencies
$(TARGET)/EdgeDetect_tb.cpp.cxxts: .ccs_env_opts/SCVerify_USE_CCS_BLOCK.ts
$(TARGET)/bmp_io.cpp.cxxts: .ccs_env_opts/SCVerify_USE_CCS_BLOCK.ts
$(TARGET)/mc_testbench.cpp.cxxts: .ccs_env_opts/SCVerify_USE_CCS_BLOCK.ts
$(TARGET)/scverify_top.cpp.cxxts: .ccs_env_opts/SCVerify_USE_CCS_BLOCK.ts .ccs_env_opts/SCVerify_DEADLOCK_DETECTION.ts
# 
# Specify compilation library for HDL source
$(TARGET)/concat_sim_rtl.v.vts: HDL_LIB=work
ifeq ($(STAGE),gate)
ifneq ($(GATE_VHDL_DEP),)
$(TARGET)/$(notdir $(GATE_VHDL_DEP)): HDL_LIB=work
$(TARGET)/$(notdir $(GATE_VHDL_DEP)): VHDL_TOP=1
$(TARGET)/$(notdir $(GATE_VHDL_DEP)): DUT_E=my_func
$(TARGET)/$(notdir $(GATE_VHDL_DEP)): DUT_E=EdgeDetect_IP_EdgeDetect_VerDer
endif
ifneq ($(GATE_VLOG_DEP),)
$(TARGET)/$(notdir $(GATE_VLOG_DEP)): HDL_LIB=work
$(TARGET)/$(notdir $(GATE_VLOG_DEP)): VLOG_TOP=1
$(TARGET)/$(notdir $(GATE_VLOG_DEP)): DUT_E=my_func
$(TARGET)/$(notdir $(GATE_VLOG_DEP)): DUT_E=EdgeDetect_IP_EdgeDetect_VerDer
endif
endif
# 
# Specify additional HDL source compilation options if any
$(TARGET)/concat_sim_rtl.v.vts: VLOG_F_OPTS=
$(TARGET)/concat_sim_rtl.v.vts: NCVLOG_F_OPTS=
$(TARGET)/concat_sim_rtl.v.vts: VCS_F_OPTS=
# 
# Specify top design unit for HDL source
$(TARGET)/concat_sim_rtl.v.vts: DUT_E=EdgeDetect_IP_EdgeDetect_VerDer

# Specify top design unit
$(TARGET)/concat_sim_rtl.v.vts: VLOG_TOP=1

ifneq "$(RTLTOOL)" ""
# ===================================================
# Include makefile for RTL synthesis
include $(MGC_HOME)/shared/include/mkfiles/ccs_$(RTLTOOL).mk
else
# ===================================================
# Include makefile for simulator
include $(MGC_HOME)/shared/include/mkfiles/ccs_questasim.mk
endif

