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
module FA_rtl(A, B, Cin, S, Cout);
  input A;
  input B;
  input Cin;
  output S;
  output Cout;
  wire c1;
  wire s1;
  wire c2;

  HA_rtl ha1_ptr(.A(A), .B(B), .Sum(s1), .Carry(c1));
  HA_rtl ha2_ptr(.A(s1), .B(Cin), .Sum(S), .Carry(c2));
  FA_prc_cout FA_prc_cout(.c1(c1), .c2(c2), .Cout(Cout));
endmodule


