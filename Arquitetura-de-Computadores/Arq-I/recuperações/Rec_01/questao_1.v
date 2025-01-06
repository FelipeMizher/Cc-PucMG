/** 
    821811 - Felipe Rivetti Mizher
    Recuperação 01
    Questão 1:
*/

module Q01a(output S1, 
            input a, 
            input b, 
            input c, 
            input d);

    assign S1 = (~a & ~b & ~c & ~d) | 
                (~a & ~b & ~c & d)  | 
                (~a & ~b & c & ~d)  | 
                (~a & ~b & c & d)   |
                (~a & b & ~c & d)   | 
                (a & ~b & ~c & ~d)  | 
                (a & b & ~c & d);

endmodule // end Q01a

module Q01b(output S2, 
            input A, 
            input B, 
            input C, 
            input D);

    assign S2 = (A | ~B | C | D)   & 
                (A | ~B | ~C | D)  & 
                (A | ~B | ~C | ~D) & 
                (~A | B | C | ~D)  &
                (~A | B | ~C | D)  & 
                (~A | B | ~C | ~D) & 
                (~A | ~B | C | D)  & 
                (~A | ~B | ~C | D) & 
                (~A | ~B | ~C | ~D);

endmodule // end Q01b

module Q01c(output S3, 
            input a, 
            input b, 
            input c, 
            input d);

    assign S3 = (~a & ~b)    | 
                (b & ~c & d) | 
                (~b & ~c & ~d);

endmodule // end Q01c

module Q01d(output S4, 
            input A, 
            input B, 
            input C,
            input D);

    assign S4 = (~B | ~C)     & 
                (~A | B | ~C) & 
                (~A | B | ~D) & 
                (~B | C | D);

endmodule // end Q01d

module Q01e(output s,
            input a, 
            input b,
            input c,
            input d);

    wire nand1, nand2, nand3, nand4, nand5, nand6, nand7, nand8;

    assign nand1 = ~(~a & ~b & ~c & ~d);
    assign nand2 = ~(~a & ~b & ~c & d);
    assign nand3 = ~(~a & ~b & c & ~d);
    assign nand4 = ~(~a & ~b & c & d);
    assign nand5 = ~(~a & b & ~c & d);
    assign nand6 = ~(a & ~b & ~c & ~d);
    assign nand7 = ~(a & b & ~c & d);

    assign s = nand1 | nand2 | nand3 | nand4 | nand5 | nand6 | nand7;

endmodule // end Q01e

module Q01f(output s,
            input A, 
            input B,
            input C, 
            input D);

    wire nor1, nor2, nor3, nor4, nor5, nor6, nor7, nor8, nor9;

    assign nor1 = ~(A | ~B | C | D);
    assign nor2 = ~(A | ~B | ~C | D);
    assign nor3 = ~(A | ~B | ~C | ~D);
    assign nor4 = ~(~A | B | C | ~D);
    assign nor5 = ~(~A | B | ~C | D);
    assign nor6 = ~(~A | B | ~C | ~D);
    assign nor7 = ~(~A | ~B | C | D);
    assign nor8 = ~(~A | ~B | ~C | D);
    assign nor9 = ~(~A | ~B | ~C | ~D);

    assign s = nor1 & nor2 & nor3 & nor4 & nor5 & nor6 & nor7 & nor8 & nor9; 

endmodule // end Q01f 

module test_brench;
    reg a, b, c, d;
    wire s1, s2, s3, s4, s5, s6;

    Q01a QA(s1, a, b, c, d);
    Q01b QB(s2, a, b, c, d);
    Q01c QC(s3, a, b, c, d);
    Q01d QD(s4, a, b, c, d);
    Q01e QE(s5, a, b, c, d);
    Q01f QF(s6, a, b, c, d);


    initial begin

        $display("a / b / c / d / s1/ s2/ s3/ s4/ s5");
        $monitor("%b  %b  %b  %b  %b  %b  %b  %b  %b  %b", a, b, c, d, s1, s2, s3, s4, s5, s6);
        a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b0;
        #1
        a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b1;
        #1
        a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b0;
        #1
        a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b1;
        #1
        a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b0;
        #1
        a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b1;
        #1
        a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b0;
        #1
        a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b1;
        #1
        a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b0;
        #1
        a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b1;
        #1
        a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b0;
        #1
        a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b1;
        #1
        a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b0;
        #1
        a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b1;
        #1
        a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b0;
        #1
        a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b1;
    end
endmodule // end test_brench