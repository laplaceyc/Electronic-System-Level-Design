// *****************************************************************************
//                         Cadence C-to-Silicon Compiler
//          Version 14.20-s400  (32 bit), build 84938 Mon, 27 Jun 2016
// 
// File created on Tue Jun  6 02:14:01 2017
// 
// The code contained herein is generated for Cadences customer and third
// parties authorized by customer.  It may be used in accordance with a
// previously executed license agreement between Cadence and that customer.
// Absolutely no disassembling, decompiling, reverse-translations or
// reverse-engineering of the generated code is allowed.
// 
//*****************************************************************************
module FA_prc_cout(c1, c2, Cout);
  input c1;
  input c2;
  output reg Cout;

  always @(*) begin : FA_prc_cout_combinational
      reg or_ln8_z;

      or_ln8_z = c2 | c1;
      Cout = or_ln8_z;
    end
endmodule


