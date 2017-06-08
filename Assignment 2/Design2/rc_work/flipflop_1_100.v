module flipflop_1_100(CLK, D, Q);
    input CLK;
    input D;
    output reg Q;

    always @(posedge CLK) begin
        Q <= D;
    end
endmodule
