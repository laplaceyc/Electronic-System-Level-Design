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
module FA_final(A, B, Cin, S, Cout);
  input A;
  input B;
  input Cin;
  output S;
  output reg Cout;
  wire c1;
  wire s1;
  wire c2;

  always @(*) begin : FA_prc_cout
      reg or_ln8;
      reg read_FA_c1_ln8;
      reg read_FA_c2_ln8;

      begin
        read_FA_c1_ln8 = c1;
        read_FA_c2_ln8 = c2;
        or_ln8 = |{read_FA_c2_ln8, read_FA_c1_ln8};
        Cout <= or_ln8;
      end
    end
  HA_final ha1_ptr(.A(A), .B(B), .Sum(s1), .Carry(c1));
  HA_final ha2_ptr(.A(s1), .B(Cin), .Sum(S), .Carry(c2));
endmodule


