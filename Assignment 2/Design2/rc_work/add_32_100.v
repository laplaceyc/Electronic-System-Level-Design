module add_32_100(A, B, Z);
    input [31 : 0] A;
    input [31 : 0] B;
    output [31 : 0] Z;

    assign Z = A + B;
endmodule
