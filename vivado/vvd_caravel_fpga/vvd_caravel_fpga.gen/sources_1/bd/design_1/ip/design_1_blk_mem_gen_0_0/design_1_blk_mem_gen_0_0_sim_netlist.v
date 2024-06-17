// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2022.1 (lin64) Build 3526262 Mon Apr 18 15:47:01 MDT 2022
// Date        : Mon Jun 17 12:01:43 2024
// Host        : ubuntu2004 running 64-bit Ubuntu 20.04.4 LTS
// Command     : write_verilog -force -mode funcsim
//               /home/ubuntu/SoC_Design/homework/ASOC/ASoC-Final_project-optical_flow/vivado/vvd_caravel_fpga/vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_blk_mem_gen_0_0/design_1_blk_mem_gen_0_0_sim_netlist.v
// Design      : design_1_blk_mem_gen_0_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "design_1_blk_mem_gen_0_0,blk_mem_gen_v8_4_5,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_5,Vivado 2022.1" *) 
(* NotValidForBitStream *)
module design_1_blk_mem_gen_0_0
   (clka,
    rsta,
    ena,
    wea,
    addra,
    dina,
    douta,
    clkb,
    rstb,
    enb,
    web,
    addrb,
    dinb,
    doutb,
    rsta_busy,
    rstb_busy);
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA CLK" *) (* x_interface_parameter = "XIL_INTERFACENAME BRAM_PORTA, MEM_SIZE 8192, MEM_WIDTH 32, MEM_ECC NONE, MASTER_TYPE BRAM_CTRL, READ_WRITE_MODE READ_WRITE, READ_LATENCY 1" *) input clka;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA RST" *) input rsta;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA EN" *) input ena;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA WE" *) input [3:0]wea;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA ADDR" *) input [31:0]addra;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA DIN" *) input [31:0]dina;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA DOUT" *) output [31:0]douta;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB CLK" *) (* x_interface_parameter = "XIL_INTERFACENAME BRAM_PORTB, MEM_SIZE 8192, MEM_WIDTH 32, MEM_ECC NONE, MASTER_TYPE BRAM_CTRL, READ_WRITE_MODE READ_WRITE, READ_LATENCY 1" *) input clkb;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB RST" *) input rstb;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB EN" *) input enb;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB WE" *) input [3:0]web;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB ADDR" *) input [31:0]addrb;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB DIN" *) input [31:0]dinb;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB DOUT" *) output [31:0]doutb;
  output rsta_busy;
  output rstb_busy;

  wire [31:0]addra;
  wire [31:0]addrb;
  wire clka;
  wire clkb;
  wire [31:0]dina;
  wire [31:0]dinb;
  wire [31:0]douta;
  wire [31:0]doutb;
  wire ena;
  wire enb;
  wire rsta;
  wire rsta_busy;
  wire rstb;
  wire rstb_busy;
  wire [3:0]wea;
  wire [3:0]web;
  wire NLW_U0_dbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_arready_UNCONNECTED;
  wire NLW_U0_s_axi_awready_UNCONNECTED;
  wire NLW_U0_s_axi_bvalid_UNCONNECTED;
  wire NLW_U0_s_axi_dbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_rlast_UNCONNECTED;
  wire NLW_U0_s_axi_rvalid_UNCONNECTED;
  wire NLW_U0_s_axi_sbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_wready_UNCONNECTED;
  wire NLW_U0_sbiterr_UNCONNECTED;
  wire [31:0]NLW_U0_rdaddrecc_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_bid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_bresp_UNCONNECTED;
  wire [31:0]NLW_U0_s_axi_rdaddrecc_UNCONNECTED;
  wire [31:0]NLW_U0_s_axi_rdata_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_rid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_rresp_UNCONNECTED;

  (* C_ADDRA_WIDTH = "32" *) 
  (* C_ADDRB_WIDTH = "32" *) 
  (* C_ALGORITHM = "1" *) 
  (* C_AXI_ID_WIDTH = "4" *) 
  (* C_AXI_SLAVE_TYPE = "0" *) 
  (* C_AXI_TYPE = "1" *) 
  (* C_BYTE_SIZE = "8" *) 
  (* C_COMMON_CLK = "0" *) 
  (* C_COUNT_18K_BRAM = "0" *) 
  (* C_COUNT_36K_BRAM = "2" *) 
  (* C_CTRL_ECC_ALGO = "NONE" *) 
  (* C_DEFAULT_DATA = "0" *) 
  (* C_DISABLE_WARN_BHV_COLL = "0" *) 
  (* C_DISABLE_WARN_BHV_RANGE = "0" *) 
  (* C_ELABORATION_DIR = "./" *) 
  (* C_ENABLE_32BIT_ADDRESS = "1" *) 
  (* C_EN_DEEPSLEEP_PIN = "0" *) 
  (* C_EN_ECC_PIPE = "0" *) 
  (* C_EN_RDADDRA_CHG = "0" *) 
  (* C_EN_RDADDRB_CHG = "0" *) 
  (* C_EN_SAFETY_CKT = "1" *) 
  (* C_EN_SHUTDOWN_PIN = "0" *) 
  (* C_EN_SLEEP_PIN = "0" *) 
  (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     10.7492 mW" *) 
  (* C_FAMILY = "zynq" *) 
  (* C_HAS_AXI_ID = "0" *) 
  (* C_HAS_ENA = "1" *) 
  (* C_HAS_ENB = "1" *) 
  (* C_HAS_INJECTERR = "0" *) 
  (* C_HAS_MEM_OUTPUT_REGS_A = "0" *) 
  (* C_HAS_MEM_OUTPUT_REGS_B = "0" *) 
  (* C_HAS_MUX_OUTPUT_REGS_A = "0" *) 
  (* C_HAS_MUX_OUTPUT_REGS_B = "0" *) 
  (* C_HAS_REGCEA = "0" *) 
  (* C_HAS_REGCEB = "0" *) 
  (* C_HAS_RSTA = "1" *) 
  (* C_HAS_RSTB = "1" *) 
  (* C_HAS_SOFTECC_INPUT_REGS_A = "0" *) 
  (* C_HAS_SOFTECC_OUTPUT_REGS_B = "0" *) 
  (* C_INITA_VAL = "0" *) 
  (* C_INITB_VAL = "0" *) 
  (* C_INIT_FILE = "NONE" *) 
  (* C_INIT_FILE_NAME = "no_coe_file_loaded" *) 
  (* C_INTERFACE_TYPE = "0" *) 
  (* C_LOAD_INIT_FILE = "0" *) 
  (* C_MEM_TYPE = "2" *) 
  (* C_MUX_PIPELINE_STAGES = "0" *) 
  (* C_PRIM_TYPE = "1" *) 
  (* C_READ_DEPTH_A = "2048" *) 
  (* C_READ_DEPTH_B = "2048" *) 
  (* C_READ_LATENCY_A = "1" *) 
  (* C_READ_LATENCY_B = "1" *) 
  (* C_READ_WIDTH_A = "32" *) 
  (* C_READ_WIDTH_B = "32" *) 
  (* C_RSTRAM_A = "0" *) 
  (* C_RSTRAM_B = "0" *) 
  (* C_RST_PRIORITY_A = "CE" *) 
  (* C_RST_PRIORITY_B = "CE" *) 
  (* C_SIM_COLLISION_CHECK = "ALL" *) 
  (* C_USE_BRAM_BLOCK = "1" *) 
  (* C_USE_BYTE_WEA = "1" *) 
  (* C_USE_BYTE_WEB = "1" *) 
  (* C_USE_DEFAULT_DATA = "0" *) 
  (* C_USE_ECC = "0" *) 
  (* C_USE_SOFTECC = "0" *) 
  (* C_USE_URAM = "0" *) 
  (* C_WEA_WIDTH = "4" *) 
  (* C_WEB_WIDTH = "4" *) 
  (* C_WRITE_DEPTH_A = "2048" *) 
  (* C_WRITE_DEPTH_B = "2048" *) 
  (* C_WRITE_MODE_A = "WRITE_FIRST" *) 
  (* C_WRITE_MODE_B = "WRITE_FIRST" *) 
  (* C_WRITE_WIDTH_A = "32" *) 
  (* C_WRITE_WIDTH_B = "32" *) 
  (* C_XDEVICEFAMILY = "zynq" *) 
  (* downgradeipidentifiedwarnings = "yes" *) 
  (* is_du_within_envelope = "true" *) 
  design_1_blk_mem_gen_0_0_blk_mem_gen_v8_4_5 U0
       (.addra({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,addra[12:2],1'b0,1'b0}),
        .addrb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,addrb[12:2],1'b0,1'b0}),
        .clka(clka),
        .clkb(clkb),
        .dbiterr(NLW_U0_dbiterr_UNCONNECTED),
        .deepsleep(1'b0),
        .dina(dina),
        .dinb(dinb),
        .douta(douta),
        .doutb(doutb),
        .eccpipece(1'b0),
        .ena(ena),
        .enb(enb),
        .injectdbiterr(1'b0),
        .injectsbiterr(1'b0),
        .rdaddrecc(NLW_U0_rdaddrecc_UNCONNECTED[31:0]),
        .regcea(1'b0),
        .regceb(1'b0),
        .rsta(rsta),
        .rsta_busy(rsta_busy),
        .rstb(rstb),
        .rstb_busy(rstb_busy),
        .s_aclk(1'b0),
        .s_aresetn(1'b0),
        .s_axi_araddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arburst({1'b0,1'b0}),
        .s_axi_arid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arready(NLW_U0_s_axi_arready_UNCONNECTED),
        .s_axi_arsize({1'b0,1'b0,1'b0}),
        .s_axi_arvalid(1'b0),
        .s_axi_awaddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awburst({1'b0,1'b0}),
        .s_axi_awid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awready(NLW_U0_s_axi_awready_UNCONNECTED),
        .s_axi_awsize({1'b0,1'b0,1'b0}),
        .s_axi_awvalid(1'b0),
        .s_axi_bid(NLW_U0_s_axi_bid_UNCONNECTED[3:0]),
        .s_axi_bready(1'b0),
        .s_axi_bresp(NLW_U0_s_axi_bresp_UNCONNECTED[1:0]),
        .s_axi_bvalid(NLW_U0_s_axi_bvalid_UNCONNECTED),
        .s_axi_dbiterr(NLW_U0_s_axi_dbiterr_UNCONNECTED),
        .s_axi_injectdbiterr(1'b0),
        .s_axi_injectsbiterr(1'b0),
        .s_axi_rdaddrecc(NLW_U0_s_axi_rdaddrecc_UNCONNECTED[31:0]),
        .s_axi_rdata(NLW_U0_s_axi_rdata_UNCONNECTED[31:0]),
        .s_axi_rid(NLW_U0_s_axi_rid_UNCONNECTED[3:0]),
        .s_axi_rlast(NLW_U0_s_axi_rlast_UNCONNECTED),
        .s_axi_rready(1'b0),
        .s_axi_rresp(NLW_U0_s_axi_rresp_UNCONNECTED[1:0]),
        .s_axi_rvalid(NLW_U0_s_axi_rvalid_UNCONNECTED),
        .s_axi_sbiterr(NLW_U0_s_axi_sbiterr_UNCONNECTED),
        .s_axi_wdata({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_wlast(1'b0),
        .s_axi_wready(NLW_U0_s_axi_wready_UNCONNECTED),
        .s_axi_wstrb({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_wvalid(1'b0),
        .sbiterr(NLW_U0_sbiterr_UNCONNECTED),
        .shutdown(1'b0),
        .sleep(1'b0),
        .wea(wea),
        .web(web));
endmodule
`pragma protect begin_protected
`pragma protect version = 1
`pragma protect encrypt_agent = "XILINX"
`pragma protect encrypt_agent_info = "Xilinx Encryption Tool 2022.1"
`pragma protect key_keyowner="Synopsys", key_keyname="SNPS-VCS-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
RgPKnWr9n0dGgttm3akiFhAlfB96usOQYxnEmPhGyTGg1AbizYAjGPWLXBWl50n/d0IA71ci4aJB
wt6mtfyNADm3ZReK7D3mKu037BOgxryoEwwf1kiC6q/PllxsdAgEMfQrfHJ3E2AzSpdYjoxVYito
y0JW6CUDcWvWa4WV0EA=

`pragma protect key_keyowner="Aldec", key_keyname="ALDEC15_001", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
M0l6KpOGH3jL8eRt3NCD7e2USYnkg5H9GAnE1PKmnjiouFN3Y8kjWA2PZDAQLm9UW+TsC1HeVlzO
WjNCHkjR/6ubCsIcWfpPZWdIuAenlsyq8Y9l6b8vMj8JSbDEOiFF/GHSbKsn22MJdDJKEhHFK6GV
s8gR2vywRFwG69gIRE4qGhVB+WIg8GJrDpDMYH6lCjMkTrjXuKDUcNlJN3NPLuhJ7tsditwf1pr5
moJRmGpJnip/rGm0g4o4A6ev4CtePjoao8C1wFtzHkERX9oenhh7cGjDMejU5IrLv8NxFnLj1FpB
9MuF1beTU20NI5oAn6zLiLiOtXjf0ghU3AN4DA==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VELOCE-RSA", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
hAsrUfp6Qgjm8yBjNYTEtQmVQmMxzL8TE/3oiQSxSI3+yEkXAbQCXkT9mo+LCdv+fGECOB0istHd
eLtbsiYbxjxNxYkXiUrRE5O+aSxynIray+uF9DJigTEUZu8JJXUbzxK4DDUu1Lm9tpGps4+Prz1m
0gkj13RT/Y/418s2VTw=

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VERIF-SIM-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
BP/54Wm/GJmb1jy0bxWJJX4aiKyiWPVh4X3VL30BQrmX4PlEsNKzBJH3Qu8IIYERfnFP0ifAgboa
vypMQ5Ed0BrMePGkWIgT6I8hxJCMFpHdkSK7m1giSKyZzFfTOrVqoNFXE+qdzLfY1J5hBWCvouYo
jllavK4N3gF9FLScH2AUWYVMcVth2QPaTAU2NLnAUNH8kgtBjBfc8/KbPPTznD1QNVqvFstzcbTA
hGQ1ETVPvINQ0KqxxAG5PRhtQD4+pC+hr/Tvk+RSvGyBOfy9zE86OXkJiYs9dSFhNiMFmCPL9DBO
se4OxNNC0/7aBtb1mkSEA9YFDYEb9jS7Jasy2A==

`pragma protect key_keyowner="Real Intent", key_keyname="RI-RSA-KEY-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
SnzT9DVH3xlEN8nrr2YrlvTO5qj7L22d7WaBcuKyTaiHoIwwFHrC4HQbfs0TAwkdWcOgmJoATPSF
F6qm0KiddbrlERF3MfKUldeGBJtqLdX+zGw7+3JD7S+HB9dIMOFOHy+IiCZp1/Pz8epKpi238cel
rcVoJQKz406wmXDvOo8KsT+XhRLs9BVCrBErPGGXKYDk6NXAp0duOgQE9DbslzMU83M/kUC7uERV
tQW02240peKQFp2elEZC7Tetvgp0TaFTtJiKN45REi8GQUCKGa85JjNIk1qb/+k95TIIP1xrHirc
6iX7qbwnPetv8TVu2NjkZ0WDEK5RXdOXcxBwHA==

`pragma protect key_keyowner="Xilinx", key_keyname="xilinxt_2021_07", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
erkR82V0jX8ytva+9MzEs0c75Z7j7TsgxWRLNAUfbbU28i+U9YzuZlSfYU75M0f9jx1gvxtBrfKv
cNHVdkR+i5zfHDZsDwfMEEBhs8wzDCKqe+eex6BBEvlIOesCPXrr2RozQgaQ1PBh/os2Arfu+873
BjsVxFJkbhpzIqlddOo/XZV9Yi+eih7A7pXXEBR6IL7Poo4Ka49MiVQU0xJrDTm+ddOuMPDRRD7g
dsxS/uzdcBcO2myV6g/7YH/C2Ce9s6+UywJN/0JeXSqwA7bsBqqnfFicVAT0lckLopMLiuzK7dsN
EwhFeqoetciFrDIj9+o0xDMWBZhgNP1u68vURA==

`pragma protect key_keyowner="Metrics Technologies Inc.", key_keyname="DSim", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
R+BI65BKLT0I9hEtsxGnDyM5XY9gzULeTPOSDXvd3KWOzZJAx6C0xlbyZcFZhAEG/QIK2yd0wAi6
IUWxyF/sx3HsqKjhVi5KxnpuXDBOZVoj811O7JukedFVmDW7OHGtBkuiJ5X5irw7mfsEKRQmF/1i
V6lj9HYHZEjxtDeZjACsLY4y1QxWalSKT4HIMOHznBLL8dLbGMlS+ZmFuFn0gcwZavVl7gTkTtkf
W0gn01A9ru7NKsf+iLX0kj4dgItPu9N2g02M1vWQ9UUQEVvfV7lUc7GY1suibrD8aEkhH9S7lZ7n
bFsT4qxyvzg8ML6v4g4v7N6VuyhEtgFgNd725Q==

`pragma protect key_keyowner="Atrenta", key_keyname="ATR-SG-RSA-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=384)
`pragma protect key_block
jNUVKiwH68vHsU54idgvKwaVJcoxTUuxfgrQpbpmM/IpesWA3wHsGzYClwAxkKzw3KRnFyQqTWcZ
yj1EQ2CMBxlJ0kyNbZW8OK8pXzeigToZ0U6Aq3Gy+j7wBbhe83wE1Ygn82sK8dHTEulvaRLn/c5r
ispy1s7jMKIvYNzoUuZrgyBQyfaYmdqUia8XlQjFd+VwzhTXKwzvmaqHWyaHjfBKeCooO7+oUxMG
OJg83W54EVe9ronFQ8Wr9EOL8ia7qelCAgyQe/bC0HHCoMAm8apI7sX23iMR/wMiPP5V2bQzycy+
rBX/+SWkqSeIE1FLm+muFPvrE7iLwJaW8d1fzdFFjAZ5aIXArbWNfwbK8S0TczXc9lEzmpb69rwA
UJIrs4alo81qGQ32UFhjuMQjX75O9Od1HWHDj5PFaT/Ja5Ly+bK8Cc3gfO6dCE81m7d+B2JBZ/Hl
tBA19QuOAYwT2EIPOdpaVtCULb33cWODWu3qQFhZMmDzKTb3kwpcr0LL

`pragma protect key_keyowner="Cadence Design Systems.", key_keyname="CDS_RSA_KEY_VER_1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
MnzcA2swaxH1LRacKDou0ZmiiMRETbWIdHgeBgyQz7ILronsXLoB/C20WuFNGEVSiL2/51EZ6MXZ
vMHI8fFcMQCJcuTBDBibUMKv6bXI9s8fTbtrBZppbF/R1icG5JYhqmX4aRnv4W/dxJRjI2L35nLN
Y48E9OfgfkD1sr+IRwx8WEKFmUhuk8dLe0VOK7ywe3XEcneYvrz+HhPj16bGmNfMwNnDgZ3gKKZD
hRnys+jzvAX3HyISrErWXhMKrhWMxXeTNFJCqNQ0LWAVHQYwyKnF5xVpyXSuGNSIrva+QXqOrZBG
3VNLirNVtMRiKLfwZeMaqvswkqBDAa53utlAAA==

`pragma protect key_keyowner="Synplicity", key_keyname="SYNP15_1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
d0xXkKtsKM8GvXhDZr16p1+oE3uBtD04BJ76eGGIEj/CFECfHVy9qsJ43oSKjas0+AJr4GFFnVb6
X7gJV6MmX/OboC9ier5joUCGz0mxVzkRZK9a+LPEDcg0K6+cLE36kr+FfxW9Uk2816EHBCMCf5mK
A4eAhSmAb5Nq74F/q0quiG416npbny7faiQ+xmPDfYYiM3UuMKaD4iE8ODlz1w5xThPllWESf3LZ
NTkw6fozyTqZ47vvE21O3dgIGAY1v+C6BwlCK24VwPJa1xs9csY+qTk31j5jjAc1ExlB6QF7t9UH
lk70qdNPWxT87OH7kFT8UvPO1D6BTC3/WkDZfA==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-PREC-RSA", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
LYhdzKTvo93uJrAaiP5OfCDuOnu2BSvPnxlv6I7h2n1+xHtj34LNNKzWEgOg9dUV9cYDaHYUjjEt
DKdWcz6mZ61d5qyxAhpv67fc90v7JVgtOAcT94/Yb+AuLxXFcGA6Gic7uoJtUgz6JmTnb22Dxdjc
KuIewDj4IOTfP8XGXKTaF+cNp0CFrQgTAcVSQFyLFxr0I/9h3S+GZLecA7ntEeHEOfCJzPvy0ddi
7MCdQWECLb+fXC0IAn8V95TumcpINiRAX1BHi9IGJ4QoMrb3jOCrPkFhDMTJj2aiImUWdi/l/0QE
d7wcXlgIEYVeoKYUOJ4mqy+zZPUbLNeOPADUDQ==

`pragma protect data_method = "AES128-CBC"
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 59888)
`pragma protect data_block
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
`pragma protect end_protected
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
