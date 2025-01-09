/*  821811 
    Felipe Rivetti Mizher
    Guia_0801
*/
module halfAdder(
    input a, b,
    output sum, carry
);
    xor XOR1( sum, a, b );
    and AND1( carry, a, b );
endmodule

module fullAdder(
    input a, b, cin,
    output sum, carry
);
    wire c1;
    halfAdder HA0(a, b, sum, c1);
    halfAdder HA1(c1, cin, sum, carry);
endmodule

module Guia_0801(
    input [4:0] operand_a,
    input [4:0] operand_b,
    output [4:0] result,
    output carry_out
);
    wire [4:0] sum;
    wire carry;

    fullAdder FA0(operand_a[0], operand_b[0], 1'b0, sum[0], carry);
    fullAdder FA1(operand_a[1], operand_b[1], sum[0], sum[1], carry);
    fullAdder FA2(operand_a[2], operand_b[2], sum[1], sum[2], carry);
    fullAdder FA3(operand_a[3], operand_b[3], sum[2], sum[3], carry);
    fullAdder FA4(operand_a[4], operand_b[4], sum[3], sum[4], carry);

    assign result = sum;
    assign carry_out = carry;
endmodule

module Guia_0801_tb;
    reg [4:0] operand_a, operand_b;
    wire [4:0] result;
    wire carry_out;

    Guia_0801 uut(operand_a, operand_b, result, carry_out);

    initial begin
        $monitor("operand_a=%b, operand_b=%b, result=%b, carry_out=%b", operand_a, operand_b, result, carry_out);
        operand_a = 5'b00011; operand_b = 5'b00011;
        #10;
        operand_a = 5'b00001; operand_b = 5'b00001;
        #10;
        operand_a = 5'b00010; operand_b = 5'b00010;
        #10;
        operand_a = 5'b00100; operand_b = 5'b00100;
        #10;
        operand_a = 5'b01000; operand_b = 5'b01000;
        #10;
        operand_a = 5'b10000; operand_b = 5'b10000;
        #10;
        $finish();
    end
endmodule
