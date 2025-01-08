// 821811 - Felipe Rivetti Mizher

// Questão 06

module f5a(
    output s,
    input a,
    input b
);
    wire a_nor_b;

    nor NOR1(a_nor_b, a, b);
    nor NOR2(s, a_nor_b, a_nor_b);
endmodule // f5a

module f5b(
    output s,
    input a,
    input b,
    input c
);
    wire not_a;
    wire not_b;

    not NOT1(not_a, a);
    not NOT2(not_b, b);

    and AND1(s, not_a, not_b, c);
endmodule // f5b

module test_f5;
    reg x;
    reg y;
    reg z;
    wire s, a, b;

    f5a moduloA(s, x, z);
    f5b moduloB(s, ~y, ~z, s);

    // ------------------------- Parte principal
    initial
    begin : main
        $display("Guia_0505 - Felipe Rivetti Mizher - 821811");
        $display("Test module");
        $display("   x    y    z    s");

        $monitor("%4b %4b %4b %4b", x, y, z, s);
        #1  x = 1'b0; y = 1'b0; z = 1'b0;
        #1  x = 1'b0; y = 1'b0; z = 1'b1;
        #1  x = 1'b0; y = 1'b1; z = 1'b0;
        #1  x = 1'b0; y = 1'b1; z = 1'b1;
        #1  x = 1'b1; y = 1'b0; z = 1'b0;
        #1  x = 1'b1; y = 1'b0; z = 1'b1;
        #1  x = 1'b1; y = 1'b1; z = 1'b0;
        #1  x = 1'b1; y = 1'b1; z = 1'b1;
    end
endmodule // test_f5
