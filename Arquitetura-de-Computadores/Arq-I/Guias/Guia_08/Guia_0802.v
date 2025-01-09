/*  821811 
    Felipe Rivetti Mizher
    Guia_0802
*/

module half_subtractor(
    input A, 
    input B, 
    output diff, borrow
);

    wire not_A;
    not NOT1 (not_A, A);
    xor XOR1 (diff, A, B);
    and AND1 (borrow, not_A, B);
    
endmodule

module full_subtractor(
    input A, B, Bin,
    output diff, Bout 
);
    wire borrow1, borrow2, diff1;

    half_subtractor HS1(A, B, diff1, borrow1);
    half_subtractor HS2(Bin, diff1, diff, borrow2);

    assign Bout = borrow1 | borrow2;
endmodule

module Guia_0802(
    input[5:0] operand_a,
    input[5:0] operand_b,
    output[5:0] difference,
    output borrow_out
);
    wire[5:0] diff;
    wire borrow;

    full_subtractor FS0(operand_a[5], operand_b[5], 1'b0, diff[5], borrow);
    full_subtractor FS1(operand_a[4], operand_b[4], borrow, diff[4], borrow);
    full_subtractor FS2(operand_a[3], operand_b[3], borrow, diff[3], borrow);
    full_subtractor FS3(operand_a[2], operand_b[2], borrow, diff[2], borrow);
    full_subtractor FS4(operand_a[1], operand_b[1], borrow, diff[1], borrow);
    full_subtractor FS5(operand_a[0], operand_b[0], borrow, diff[0], borrow_out);

    assign difference = diff;
endmodule

module Guia_0802_tb;
    reg[5:0] operand_a;
    reg[5:0] operand_b;
    wire[5:0] difference;
    wire borrow_out;

    Guia_0802 uut(operand_a, operand_b, difference, borrow_out);

    initial begin
        $monitor("operand_a=%b, operand_b=%b, difference=%b, borrow_out=%b", operand_a, operand_b, difference, borrow_out);
        operand_a = 6'b001010; operand_b = 6'b000100;
        #10;
        operand_a = 6'b000001; operand_b = 6'b000001;
        #10;
        operand_a = 6'b000010; operand_b = 6'b000010;
        #10;
        operand_a = 6'b000100; operand_b = 6'b000100;
        #10;
        operand_a = 6'b001000; operand_b = 6'b001000;
        #10;
        operand_a = 6'b010000; operand_b = 6'b000001;
        #10;
        operand_a = 6'b100000; operand_b = 6'b000001;
        #10;
        $finish();
    end
endmodule
