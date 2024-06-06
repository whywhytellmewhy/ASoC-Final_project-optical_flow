// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2022.1 (lin64) Build 3526262 Mon Apr 18 15:47:01 MDT 2022
// Date        : Sat May 18 14:10:11 2024
// Host        : ubuntu2004 running 64-bit Ubuntu 20.04.4 LTS
// Command     : write_verilog -force -mode funcsim
//               /home/ubuntu/SoC_Design/homework/ASoC_lab4_FSIC_FPGA/vivado/vvd_caravel_fpga/vvd_caravel_fpga.gen/sources_1/bd/design_1/ip/design_1_blk_mem_gen_0_0/design_1_blk_mem_gen_0_0_sim_netlist.v
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
