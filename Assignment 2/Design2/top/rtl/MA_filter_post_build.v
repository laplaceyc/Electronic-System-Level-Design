// *****************************************************************************
//                         Cadence C-to-Silicon Compiler
//          Version 14.20-s400  (32 bit), build 84938 Mon, 27 Jun 2016
// 
// File created on Tue Jun  6 05:21:39 2017
// 
// The code contained herein is generated for Cadences customer and third
// parties authorized by customer.  It may be used in accordance with a
// previously executed license agreement between Cadence and that customer.
// Absolutely no disassembling, decompiling, reverse-translations or
// reverse-engineering of the generated code is allowed.
// 
//*****************************************************************************
module MA_filter_post_build(input_, rst, clk, output_);
  input [31:0] input_;
  input rst;
  input clk;
  output reg [31:0] output_;
  reg [31:0] mid0;
  reg [31:0] mid1;
  reg [31:0] mid2;
  reg [31:0] mid3;
  reg [31:0] mid4;
  reg [31:0] mid5;
  reg [31:0] mid6;
  reg [31:0] mid7;
  reg [31:0] mid8;
  reg [31:0] mid9;
  reg [31:0] mid10;
  reg [31:0] mid11;
  reg [31:0] mid12;
  reg [31:0] mid13;
  reg [31:0] mid14;
  reg [31:0] mid15;

  always begin : MA_filter_prc_MA_filter
    reg state_MA_filter;
    reg joins_MA_filter;
    reg [31:0] add_ln15;
    reg [31:0] add_ln15_0;
    reg [31:0] add_ln15_1;
    reg [31:0] add_ln15_2;
    reg [31:0] add_ln15_3;
    reg [31:0] add_ln15_4;
    reg [31:0] add_ln15_5;
    reg [31:0] add_ln15_6;
    reg [31:0] add_ln15_7;
    reg [31:0] add_ln16;
    reg [31:0] add_ln16_0;
    reg [31:0] add_ln16_1;
    reg [31:0] add_ln16_2;
    reg [31:0] add_ln16_3;
    reg [31:0] add_ln16_4;
    reg [31:0] add_ln16_5;
    reg [31:0] mul_ln16;
    reg [31:0] read_MA_filter_input_ln14;
    reg [31:0] read_MA_filter_mid0_ln15;
    reg [31:0] read_MA_filter_mid1_ln15;
    reg [31:0] read_MA_filter_mid2_ln15;
    reg [31:0] read_MA_filter_mid3_ln15;
    reg [31:0] read_MA_filter_mid4_ln15;
    reg [31:0] read_MA_filter_mid5_ln15;
    reg [31:0] read_MA_filter_mid6_ln15;
    reg [31:0] read_MA_filter_mid7_ln15;
    reg [31:0] read_MA_filter_mid8_ln16;
    reg [31:0] read_MA_filter_mid9_ln16;
    reg [31:0] read_MA_filter_mid10_ln16;
    reg [31:0] read_MA_filter_mid11_ln16;
    reg [31:0] read_MA_filter_mid12_ln16;
    reg [31:0] read_MA_filter_mid13_ln16;
    reg [31:0] read_MA_filter_mid14_ln16;
    reg [31:0] read_MA_filter_mid15_ln16;

    joins_MA_filter = 1'b0;
    if (rst) begin
      mid0 <= 32'h0;
      mid1 <= 32'h0;
      mid2 <= 32'h0;
      mid3 <= 32'h0;
      mid4 <= 32'h0;
      mid5 <= 32'h0;
      mid6 <= 32'h0;
      mid7 <= 32'h0;
      mid8 <= 32'h0;
      mid9 <= 32'h0;
      mid10 <= 32'h0;
      mid11 <= 32'h0;
      mid12 <= 32'h0;
      mid13 <= 32'h0;
      mid14 <= 32'h0;
      mid15 <= 32'h0;
      joins_MA_filter = 1'b1;
    end
    else begin
      read_MA_filter_input_ln14 = input_;
      read_MA_filter_mid0_ln15 = mid0;
      read_MA_filter_mid1_ln15 = mid1;
      read_MA_filter_mid2_ln15 = mid2;
      read_MA_filter_mid3_ln15 = mid3;
      read_MA_filter_mid4_ln15 = mid4;
      read_MA_filter_mid5_ln15 = mid5;
      read_MA_filter_mid6_ln15 = mid6;
      read_MA_filter_mid7_ln15 = mid7;
      read_MA_filter_mid8_ln16 = mid8;
      read_MA_filter_mid9_ln16 = mid9;
      read_MA_filter_mid10_ln16 = mid10;
      read_MA_filter_mid11_ln16 = mid11;
      read_MA_filter_mid12_ln16 = mid12;
      read_MA_filter_mid13_ln16 = mid13;
      read_MA_filter_mid14_ln16 = mid14;
      read_MA_filter_mid15_ln16 = mid15;
      add_ln15 = read_MA_filter_input_ln14 + read_MA_filter_mid0_ln15;
      add_ln15_0 = add_ln15 + read_MA_filter_mid1_ln15;
      add_ln15_1 = add_ln15_0 + read_MA_filter_mid2_ln15;
      add_ln15_2 = add_ln15_1 + read_MA_filter_mid3_ln15;
      add_ln15_3 = add_ln15_2 + read_MA_filter_mid4_ln15;
      add_ln15_4 = add_ln15_3 + read_MA_filter_mid5_ln15;
      add_ln15_5 = add_ln15_4 + read_MA_filter_mid6_ln15;
      add_ln15_6 = add_ln15_5 + read_MA_filter_mid7_ln15;
      add_ln15_7 = add_ln15_6 + read_MA_filter_mid8_ln16;
      add_ln16 = add_ln15_7 + read_MA_filter_mid9_ln16;
      add_ln16_0 = add_ln16 + read_MA_filter_mid10_ln16;
      add_ln16_1 = add_ln16_0 + read_MA_filter_mid11_ln16;
      add_ln16_2 = add_ln16_1 + read_MA_filter_mid12_ln16;
      add_ln16_3 = add_ln16_2 + read_MA_filter_mid13_ln16;
      add_ln16_4 = add_ln16_3 + read_MA_filter_mid14_ln16;
      add_ln16_5 = add_ln16_4 + read_MA_filter_mid15_ln16;
      mul_ln16 = add_ln16_5 * 12'hf0f;
      mid15 <= read_MA_filter_mid14_ln16;
      mid14 <= read_MA_filter_mid13_ln16;
      mid13 <= read_MA_filter_mid12_ln16;
      mid12 <= read_MA_filter_mid11_ln16;
      mid11 <= read_MA_filter_mid10_ln16;
      mid10 <= read_MA_filter_mid9_ln16;
      mid9 <= read_MA_filter_mid8_ln16;
      mid8 <= read_MA_filter_mid7_ln15;
      mid7 <= read_MA_filter_mid6_ln15;
      mid6 <= read_MA_filter_mid5_ln15;
      mid5 <= read_MA_filter_mid4_ln15;
      mid4 <= read_MA_filter_mid3_ln15;
      mid3 <= read_MA_filter_mid2_ln15;
      mid2 <= read_MA_filter_mid1_ln15;
      mid1 <= read_MA_filter_mid0_ln15;
      mid0 <= read_MA_filter_input_ln14;
      output_ <= mul_ln16;
      joins_MA_filter = 1'b1;
    end
    // while_ln12
    if (joins_MA_filter == 1'b1) begin
      joins_MA_filter = 1'b0;
      state_MA_filter <= 1'b0;
    end
    @(posedge clk);
  end
endmodule


