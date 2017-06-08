// *****************************************************************************
//                         Cadence C-to-Silicon Compiler
//          Version 14.20-s400  (32 bit), build 84938 Mon, 27 Jun 2016
// 
// File created on Tue Jun  6 05:25:35 2017
// 
// The code contained herein is generated for Cadences customer and third
// parties authorized by customer.  It may be used in accordance with a
// previously executed license agreement between Cadence and that customer.
// Absolutely no disassembling, decompiling, reverse-translations or
// reverse-engineering of the generated code is allowed.
// 
//*****************************************************************************
module MA_filter_rtl(input_, rst, clk, output_);
  input [31:0] input_;
  input rst;
  input clk;
  output reg [31:0] output_;
  reg [31:0] mid0;
  reg [31:0] mid10;
  reg [31:0] mid11;
  reg [31:0] mid12;
  reg [31:0] mid13;
  reg [31:0] mid14;
  reg [31:0] mid15;
  reg [31:0] mid1;
  reg [31:0] mid2;
  reg [31:0] mid3;
  reg [31:0] mid4;
  reg [31:0] mid5;
  reg [31:0] mid6;
  reg [31:0] mid7;
  reg [31:0] mid8;
  reg [31:0] mid9;
  reg [31:0] mid0_d;
  reg [31:0] mid10_d;
  reg [31:0] mid11_d;
  reg [31:0] mid12_d;
  reg [31:0] mid13_d;
  reg [31:0] mid14_d;
  reg [31:0] mid15_d;
  reg [31:0] mid1_d;
  reg [31:0] mid2_d;
  reg [31:0] mid3_d;
  reg [31:0] mid4_d;
  reg [31:0] mid5_d;
  reg [31:0] mid6_d;
  reg [31:0] mid7_d;
  reg [31:0] mid8_d;
  reg [31:0] mid9_d;
  reg [31:0] output__d;

  // pragma sync_set_reset_local MA_filter_seq_block rst
  always @(posedge clk) // MA_filter_sequential
    begin : MA_filter_seq_block
      if (rst) // Initialize state and outputs
      begin
        mid0 <= 32'h0;
        mid10 <= 32'h0;
        mid11 <= 32'h0;
        mid12 <= 32'h0;
        mid13 <= 32'h0;
        mid14 <= 32'h0;
        mid15 <= 32'h0;
        mid1 <= 32'h0;
        mid2 <= 32'h0;
        mid3 <= 32'h0;
        mid4 <= 32'h0;
        mid5 <= 32'h0;
        mid6 <= 32'h0;
        mid7 <= 32'h0;
        mid8 <= 32'h0;
        mid9 <= 32'h0;
      end
      else // Update Q values
      begin
        mid0 <= mid0_d;
        mid10 <= mid10_d;
        mid11 <= mid11_d;
        mid12 <= mid12_d;
        mid13 <= mid13_d;
        mid14 <= mid14_d;
        mid15 <= mid15_d;
        mid1 <= mid1_d;
        mid2 <= mid2_d;
        mid3 <= mid3_d;
        mid4 <= mid4_d;
        mid5 <= mid5_d;
        mid6 <= mid6_d;
        mid7 <= mid7_d;
        mid8 <= mid8_d;
        mid9 <= mid9_d;
      end
    end
  always @(posedge clk) // MA_filter_0_sequential
    output_ <= output__d;
  always @(*) begin : MA_filter_combinational
      reg [31:0] add_ln15_z;
      reg [31:0] add_ln15_0_z;
      reg [31:0] add_ln15_1_z;
      reg [31:0] add_ln15_2_z;
      reg [31:0] add_ln15_3_z;
      reg [31:0] add_ln15_4_z;
      reg [31:0] add_ln15_5_z;
      reg [31:0] add_ln15_6_z;
      reg [31:0] add_ln15_7_z;
      reg [31:0] add_ln16_z;
      reg [31:0] add_ln16_0_z;
      reg [31:0] add_ln16_1_z;
      reg [31:0] add_ln16_2_z;
      reg [31:0] add_ln16_3_z;
      reg [31:0] add_ln16_4_z;
      reg [31:0] add_ln16_5_z;
      reg [31:0] mul_ln16_z;

      add_ln15_z = input_ + mid0;
      mid0_d = input_;
      mid10_d = mid9;
      mid11_d = mid10;
      mid12_d = mid11;
      mid13_d = mid12;
      mid14_d = mid13;
      mid15_d = mid14;
      mid1_d = mid0;
      mid2_d = mid1;
      mid3_d = mid2;
      mid4_d = mid3;
      mid5_d = mid4;
      mid6_d = mid5;
      mid7_d = mid6;
      mid8_d = mid7;
      mid9_d = mid8;
      add_ln15_0_z = add_ln15_z + mid1;
      add_ln15_1_z = add_ln15_0_z + mid2;
      add_ln15_2_z = add_ln15_1_z + mid3;
      add_ln15_3_z = add_ln15_2_z + mid4;
      add_ln15_4_z = add_ln15_3_z + mid5;
      add_ln15_5_z = add_ln15_4_z + mid6;
      add_ln15_6_z = add_ln15_5_z + mid7;
      add_ln15_7_z = add_ln15_6_z + mid8;
      add_ln16_z = add_ln15_7_z + mid9;
      add_ln16_0_z = add_ln16_z + mid10;
      add_ln16_1_z = add_ln16_0_z + mid11;
      add_ln16_2_z = add_ln16_1_z + mid12;
      add_ln16_3_z = add_ln16_2_z + mid13;
      add_ln16_4_z = add_ln16_3_z + mid14;
      add_ln16_5_z = add_ln16_4_z + mid15;
      mul_ln16_z = add_ln16_5_z * 32'hf0f;
      case (1'b1)// pragma parallel_case
        !rst: output__d = mul_ln16_z;
        !(!rst): output__d = output_;
        default: output__d = 32'hX;
      endcase
    end
endmodule


