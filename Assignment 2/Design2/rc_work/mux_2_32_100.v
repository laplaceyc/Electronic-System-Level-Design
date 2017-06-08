module mux_2_32_100(C, A_00, A_01, Z);
    input [1 : 0] C;
    input [31 : 0] A_00;
    input [31 : 0] A_01;
    output reg [31 : 0] Z;

  always @(*) begin
      case (1'b1)// pragma parallel_case
        C[0]: Z = A_00;
        C[1]: Z = A_01;
        default: Z = 'hX;
      endcase
  end
endmodule
