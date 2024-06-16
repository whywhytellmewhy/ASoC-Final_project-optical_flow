// This code snippet was auto generated by xls2vlog.py from source file: ./user_project_wrapper.xlsx
// User: josh
// Date: Sep-22-23



module USER_PRJ2 #( parameter pUSER_PROJECT_SIDEBAND_WIDTH   = 5,
          parameter pADDR_WIDTH   = 12,
                   parameter pDATA_WIDTH   = 32
                 )
(
  output wire                        awready,
  output wire                        arready,
  output wire                        wready,
  output wire                        rvalid,
  output wire  [(pDATA_WIDTH-1) : 0] rdata,
  input  wire                        awvalid,
  input  wire                [11: 0] awaddr,
  input  wire                        arvalid,
  input  wire                [11: 0] araddr,
  input  wire                        wvalid,
  input  wire                 [3: 0] wstrb,
  input  wire  [(pDATA_WIDTH-1) : 0] wdata,
  input  wire                        rready,
  input  wire                        ss_tvalid,
  input  wire  [(pDATA_WIDTH-1) : 0] ss_tdata,
  input  wire                 [1: 0] ss_tuser,
    `ifdef USER_PROJECT_SIDEBAND_SUPPORT
  input  wire                 [pUSER_PROJECT_SIDEBAND_WIDTH-1: 0] ss_tupsb,
  `endif
  input  wire                 [3: 0] ss_tstrb,
  input  wire                 [3: 0] ss_tkeep,
  input  wire                        ss_tlast,
  input  wire                        sm_tready,
  output wire                        ss_tready,
  output wire                        sm_tvalid,
  output wire  [(pDATA_WIDTH-1) : 0] sm_tdata,
  output wire                 [2: 0] sm_tid,
  `ifdef USER_PROJECT_SIDEBAND_SUPPORT
  output  wire                 [pUSER_PROJECT_SIDEBAND_WIDTH-1: 0] sm_tupsb,
  `endif
  output wire                 [3: 0] sm_tstrb,
  output wire                 [3: 0] sm_tkeep,
  output wire                        sm_tlast,
  output wire                        low__pri_irq,
  output wire                        High_pri_req,
  output wire                [23: 0] la_data_o,
  input  wire                        axi_clk,
  input  wire                        axis_clk,
  input  wire                        axi_reset_n,
  input  wire                        axis_rst_n,
  input  wire                        user_clock2,
  input  wire                        uck2_rst_n
);


assign ss_tready     = 1'b0; //to be assigned by DUT
assign sm_tvalid     = 1'b0; //to be assigned by DUT


`ifdef USER_PROJECT_SIDEBAND_SUPPORT
wire [33:0] dat_in_rsc_dat = {ss_tupsb[1:0], ss_tdata[31:0]};
`else
wire [33:0] dat_in_rsc_dat = {2'b00,         ss_tdata[31:0]};
`endif

wire [33:0] dat_out_rsc_dat;

/* //for outer spram interface
wire        ram0_en;
wire [63:0] ram0_q;
wire        ram0_we;
wire [63:0] ram0_d;
wire [6:0]  ram0_adr;
wire        ram1_en;
wire [63:0] ram1_q;
wire        ram1_we;
wire [63:0] ram1_d;
wire [6:0]  ram1_adr;
*/

reg  [9:0]  reg_widthIn;
reg  [8:0]  reg_heightIn;
reg         reg_rst;

wire        opticalflow_done;
reg         reg_opticalflow_done;

wire awvalid_in;
wire wvalid_in;

//write addr channel
assign awvalid_in	= awvalid; 
wire   awready_out;
assign awready = awready_out;

//write data channel
assign wvalid_in	= wvalid;
wire   wready_out;
assign wready = wready_out;

// if both awvalid_in=1 and wvalid_in=1 then output awready_out = 1 and wready_out = 1
assign awready_out = (awvalid_in && wvalid_in) ? 1 : 0;
assign wready_out  = (awvalid_in && wvalid_in) ? 1 : 0;

//write register
always @(posedge axi_clk or negedge axi_reset_n)  begin
  if ( !axi_reset_n ) begin
    reg_widthIn         <= 1024;
    reg_heightIn        <= 436;
    reg_rst             <= 0;
  end else begin
    if ( awvalid_in && wvalid_in ) begin		//when awvalid_in=1 and wvalid_in=1 means awready_out=1 and wready_out=1
      if          (awaddr[11:2] == 10'h000 ) begin //offset 0
        if ( wstrb[0] == 1) reg_rst           <= wdata[0];
      end else if (awaddr[11:2] == 10'h001 ) begin //offset 1
        if ( wstrb[0] == 1) reg_widthIn[7:0]  <= wdata[7:0];
        if ( wstrb[1] == 1) reg_widthIn[9:8]  <= wdata[9:8];
      end else if (awaddr[11:2] == 10'h002 ) begin //offset 2
        if ( wstrb[0] == 1) reg_heightIn[7:0] <= wdata[7:0];
        if ( wstrb[1] == 1) reg_heightIn[8]   <= wdata[8];
      end
    end
  end
end

//read register
reg [(pDATA_WIDTH-1) : 0] rdata_tmp;
assign arready = 1;
assign rvalid  = 1;
assign rdata   = rdata_tmp;

always @* begin
  if      (araddr[11:2] == 10'h000) rdata_tmp = reg_rst;
  else if (araddr[11:2] == 10'h001) rdata_tmp = reg_widthIn;
  else if (araddr[11:2] == 10'h002) rdata_tmp = reg_heightIn;
  else                              rdata_tmp = 0;
end

//DUT
assign sm_tdata  = dat_out_rsc_dat[31: 0]; 

`ifdef USER_PROJECT_SIDEBAND_SUPPORT
assign sm_tupsb = dat_out_rsc_dat[33:32];
`endif

assign {sm_tstrb, sm_tkeep, sm_tlast} = 0;

EdgeDetect_Top U_EdgeDetect (
.clk                     (axi_clk           ), //user_clock2 ?
.rst                     (reg_rst           ), 
.arst_n                  (axi_reset_n       ), //~uck2_rst_n ? 
.widthIn                 (reg_widthIn       ), //I 
.heightIn                (reg_heightIn      ), //I
.dat_in_rsc_dat          (dat_in_rsc_dat    ), //I
.dat_in_rsc_vld          (ss_tvalid         ), //I
.dat_in_rsc_rdy          (ss_tready         ), //O
.dat_out_rsc_dat         (dat_out_rsc_dat   ), //O
.dat_out_rsc_vld         (sm_tvalid         ), //O
.dat_out_rsc_rdy         (sm_tready         ), //I
.line_buf0_rsc_en        (ram0_en           ), //O
.line_buf0_rsc_q         (ram0_q            ), //I
.line_buf0_rsc_we        (ram0_we           ), //O
.line_buf0_rsc_d         (ram0_d            ), //O
.line_buf0_rsc_adr       (ram0_adr          ), //O
.line_buf1_rsc_en        (ram1_en           ), //O
.line_buf1_rsc_q         (ram1_q            ), //I 
.line_buf1_rsc_we        (ram1_we           ), //O 
.line_buf1_rsc_d         (ram1_d            ), //O 
.line_buf1_rsc_adr       (ram1_adr          )  //O
);

always @(posedge axi_clk or negedge axi_reset_n)  begin
  if ( !axi_reset_n ) begin
    reg_crc32_stream_in  <= 0;
    reg_crc32_stream_out <= 0;
  end else if (edgedetect_done) begin
    reg_crc32_stream_in  <= crc32_stream_in ;
    reg_crc32_stream_out <= crc32_stream_out;
  end
end

//assign low__pri_irq  = 1'b0;
//assign High_pri_req  = 1'b0;
//assign la_data_o     = 24'b0;
//assign sm_tid        = 3'b0;

endmodule // USER_PRJ2
