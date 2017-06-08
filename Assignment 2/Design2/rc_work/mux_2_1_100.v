module mux_2_1_100(C, A_00, A_01, Z);
    input [1 : 0] C;
    input A_00;
    input A_01;
    output reg Z;

  always @(*) begin
      case (1'b1)// pragma parallel_case
        C[0]: Z = A_00;
        C[1]: Z = A_01;
        default: Z = 'hX;
      endcase
  end
endmodule
