module umul_c3855_32_100(A, Z);
    input [31 : 0] A;
    output [31 : 0] Z;

    assign Z = A * 32'hf0f;
endmodule
