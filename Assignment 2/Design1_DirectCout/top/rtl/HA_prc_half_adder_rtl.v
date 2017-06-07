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
module HA_prc_half_adder(A, B, Sum, Carry);
  input A;
  input B;
  output reg Sum;
  output reg Carry;

  always @(*) begin : HA_prc_half_adder_combinational
      reg and_ln5_z;
      reg xor_ln4_z;

      and_ln5_z = B & A;
      xor_ln4_z = B ^ A;
      Carry = and_ln5_z;
      Sum = xor_ln4_z;
    end
endmodule


