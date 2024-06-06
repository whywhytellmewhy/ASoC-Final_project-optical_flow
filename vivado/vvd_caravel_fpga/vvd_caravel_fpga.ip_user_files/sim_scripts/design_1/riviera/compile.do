vlib work
vlib riviera

vlib riviera/xilinx_vip
vlib riviera/xpm
vlib riviera/generic_baseblocks_v2_1_0
vlib riviera/axi_infrastructure_v1_1_0
vlib riviera/axi_register_slice_v2_1_26
vlib riviera/fifo_generator_v13_2_7
vlib riviera/axi_data_fifo_v2_1_25
vlib riviera/axi_crossbar_v2_1_27
vlib riviera/xil_defaultlib
vlib riviera/dist_mem_gen_v8_0_13
vlib riviera/lib_pkg_v1_0_2
vlib riviera/lib_cdc_v1_0_2
vlib riviera/lib_srl_fifo_v1_0_2
vlib riviera/lib_fifo_v1_0_16
vlib riviera/axi_lite_ipif_v3_0_4
vlib riviera/interrupt_control_v3_1_4
vlib riviera/axi_quad_spi_v3_2_25
vlib riviera/blk_mem_gen_v8_4_5
vlib riviera/axi_vip_v1_1_12
vlib riviera/processing_system7_vip_v1_0_14
vlib riviera/proc_sys_reset_v5_0_13
vlib riviera/axi_protocol_converter_v2_1_26
vlib riviera/axi_clock_converter_v2_1_25
vlib riviera/axi_dwidth_converter_v2_1_26

vmap xilinx_vip riviera/xilinx_vip
vmap xpm riviera/xpm
vmap generic_baseblocks_v2_1_0 riviera/generic_baseblocks_v2_1_0
vmap axi_infrastructure_v1_1_0 riviera/axi_infrastructure_v1_1_0
vmap axi_register_slice_v2_1_26 riviera/axi_register_slice_v2_1_26
vmap fifo_generator_v13_2_7 riviera/fifo_generator_v13_2_7
vmap axi_data_fifo_v2_1_25 riviera/axi_data_fifo_v2_1_25
vmap axi_crossbar_v2_1_27 riviera/axi_crossbar_v2_1_27
vmap xil_defaultlib riviera/xil_defaultlib
vmap dist_mem_gen_v8_0_13 riviera/dist_mem_gen_v8_0_13
vmap lib_pkg_v1_0_2 riviera/lib_pkg_v1_0_2
vmap lib_cdc_v1_0_2 riviera/lib_cdc_v1_0_2
vmap lib_srl_fifo_v1_0_2 riviera/lib_srl_fifo_v1_0_2
vmap lib_fifo_v1_0_16 riviera/lib_fifo_v1_0_16
vmap axi_lite_ipif_v3_0_4 riviera/axi_lite_ipif_v3_0_4
vmap interrupt_control_v3_1_4 riviera/interrupt_control_v3_1_4
vmap axi_quad_spi_v3_2_25 riviera/axi_quad_spi_v3_2_25
vmap blk_mem_gen_v8_4_5 riviera/blk_mem_gen_v8_4_5
vmap axi_vip_v1_1_12 riviera/axi_vip_v1_1_12
vmap processing_system7_vip_v1_0_14 riviera/processing_system7_vip_v1_0_14
vmap proc_sys_reset_v5_0_13 riviera/proc_sys_reset_v5_0_13
vmap axi_protocol_converter_v2_1_26 riviera/axi_protocol_converter_v2_1_26
vmap axi_clock_converter_v2_1_25 riviera/axi_clock_converter_v2_1_25
vmap axi_dwidth_converter_v2_1_26 riviera/axi_dwidth_converter_v2_1_26

vlog -work xilinx_vip  -sv2k12 "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
"/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
"/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm  -sv2k12 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"/tools/Xilinx/Vivado/2022.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"/tools/Xilinx/Vivado/2022.1/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"/tools/Xilinx/Vivado/2022.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -93 \
"/tools/Xilinx/Vivado/2022.1/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work generic_baseblocks_v2_1_0  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work axi_infrastructure_v1_1_0  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_26  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/0a3f/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work fifo_generator_v13_2_7  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/83df/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_7 -93 \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/83df/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_7  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/83df/hdl/fifo_generator_v13_2_rfs.v" \

vlog -work axi_data_fifo_v2_1_25  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5390/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_crossbar_v2_1_27  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/3fa0/hdl/axi_crossbar_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_xbar_1/sim/design_1_xbar_1.v" \

vlog -work dist_mem_gen_v8_0_13  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/0bf5/simulation/dist_mem_gen_v8_0.v" \

vcom -work lib_pkg_v1_0_2 -93 \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/0513/hdl/lib_pkg_v1_0_rfs.vhd" \

vcom -work lib_cdc_v1_0_2 -93 \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work lib_srl_fifo_v1_0_2 -93 \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/51ce/hdl/lib_srl_fifo_v1_0_rfs.vhd" \

vcom -work lib_fifo_v1_0_16 -93 \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/6c82/hdl/lib_fifo_v1_0_rfs.vhd" \

vcom -work axi_lite_ipif_v3_0_4 -93 \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/66ea/hdl/axi_lite_ipif_v3_0_vh_rfs.vhd" \

vcom -work interrupt_control_v3_1_4 -93 \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/a040/hdl/interrupt_control_v3_1_vh_rfs.vhd" \

vcom -work axi_quad_spi_v3_2_25 -93 \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/67dc/hdl/axi_quad_spi_v3_2_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/ip/design_1_axi_quad_spi_0_0/sim/design_1_axi_quad_spi_0_0.vhd" \

vlog -work blk_mem_gen_v8_4_5  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/25a8/simulation/blk_mem_gen_v8_4.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_blk_mem_gen_0_0/sim/design_1_blk_mem_gen_0_0.v" \
"../../../bd/design_1/ip/design_1_caravel_0_0/sim/design_1_caravel_0_0.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/178d/hdl/verilog/caravel_ps_control_s_axi.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/178d/hdl/verilog/caravel_ps.v" \
"../../../bd/design_1/ip/design_1_caravel_ps_0_0/sim/design_1_caravel_ps_0_0.v" \
"../../../bd/design_1/ip/design_1_clk_wiz_0_0/design_1_clk_wiz_0_0_clk_wiz.v" \
"../../../bd/design_1/ip/design_1_clk_wiz_0_0/design_1_clk_wiz_0_0.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/9bff/hdl/verilog/output_pin_control_s_axi.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/9bff/hdl/verilog/output_pin.v" \
"../../../bd/design_1/ip/design_1_output_pin_0_0/sim/design_1_output_pin_0_0.v" \

vlog -work axi_vip_v1_1_12  -sv2k12 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/1033/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_14  -sv2k12 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \
"../../../bd/design_1/ip/design_1_xbar_0/sim/design_1_xbar_0.v" \
"../../../bd/design_1/ip/design_1_ps_axil_0_0/sim/design_1_ps_axil_0_0.v" \

vcom -work proc_sys_reset_v5_0_13 -93 \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_1/ip/design_1_rst_ps7_0_10M_0/sim/design_1_rst_ps7_0_10M_0.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_spiflash_0_0/sim/design_1_spiflash_0_0.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_control_s_axi.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_entry_proc.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_fifo_w1_d2_S.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_fifo_w1_d3_S.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_fifo_w32_d2_S.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_fifo_w32_d64_A.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_fifo_w33_d1024_A.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_fifo_w40_d1024_A.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_fifo_w64_d3_S.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_flow_control_loop_pipe_sequential_init.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_getinstream.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_getinstream_Pipeline_VITIS_LOOP_50_1.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_gmem0_m_axi.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_gmem1_m_axi.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_hls_deadlock_detection_unit.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_hls_deadlock_idx0_monitor.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_paralleltostreamwithburst.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_paralleltostreamwithburst_Pipeline_VITIS_LOOP_110_2.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_regslice_both.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_sendoutstream.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_sendoutstream_Pipeline_VITIS_LOOP_154_2.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_start_for_sendoutstream_U0.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_start_for_streamtoparallelwithburst_U0.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_streamtoparallelwithburst.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma_streamtoparallelwithburst_Pipeline_VITIS_LOOP_23_2.v" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog/userdma.v" \
"../../../bd/design_1/ip/design_1_userdma_0_0/sim/design_1_userdma_0_0.v" \

vlog -work axi_protocol_converter_v2_1_26  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/90c8/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work axi_clock_converter_v2_1_25  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/e893/hdl/axi_clock_converter_v2_1_vl_rfs.v" \

vlog -work axi_dwidth_converter_v2_1_26  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/b3c7/hdl/axi_dwidth_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/4e49" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/5765/hdl" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ipshared/d805/hdl/verilog" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_caravel_ps_0_0/drivers/caravel_ps_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_output_pin_0_0/drivers/output_pin_v0_0/src" "+incdir+../../../../vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_userdma_0_0/drivers/userdma_v1_0/src" "+incdir+/tools/Xilinx/Vivado/2022.1/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_auto_us_0/sim/design_1_auto_us_0.v" \
"../../../bd/design_1/ip/design_1_auto_us_1/sim/design_1_auto_us_1.v" \
"../../../bd/design_1/ip/design_1_auto_us_2/sim/design_1_auto_us_2.v" \
"../../../bd/design_1/ip/design_1_auto_pc_0/sim/design_1_auto_pc_0.v" \
"../../../bd/design_1/ip/design_1_auto_pc_1/sim/design_1_auto_pc_1.v" \
"../../../bd/design_1/sim/design_1.v" \

vlog -work xil_defaultlib \
"glbl.v"

