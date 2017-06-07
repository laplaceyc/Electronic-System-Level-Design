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
module HA_final(A, B, Sum, Carry);
  input A;
  input B;
  output reg Sum;
  output reg Carry;

  always @(*) begin : HA_prc_half_adder
      reg xor_ln4;
      reg and_ln5;
      reg read_HA_A_ln4;
      reg read_HA_B_ln4;

      begin
        read_HA_A_ln4 = A;
        read_HA_B_ln4 = B;
        xor_ln4 = ^{read_HA_B_ln4, read_HA_A_ln4};
        Sum <= xor_ln4;
        and_ln5 = &{read_HA_B_ln4, read_HA_A_ln4};
        Carry <= and_ln5;
      end
    end
endmodule


