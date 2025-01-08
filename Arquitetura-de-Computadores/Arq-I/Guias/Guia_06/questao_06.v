// 821811 - Felipe Rivetti Mizher

//Questão 06

module f5a(
    output s, 
    input a, 
    input b);

    wire not_a;
    wire not_b;
    wire a_and_b;

    nand NAND1(not_a, a, a);
    nand NAND2(not_b, b, b);
    nand NAND3(a_and_b, a, b);
    nand NAND4(s, not_a, not_b, a_and_b);
endmodule // f5a

module f5b(
    output s, 
    output a, 
    output b, 
    input x, 
    input y, 
    input w, 
    input z);

    assign s = ~(~x & y) | (x & ~y & ~w & ~z);
    assign a = x;
    assign b = y;        
endmodule // f5b

module test_f5;
    reg x;
    reg y;
    reg w;
    reg z;
    wire s, a, b;

    f5a moduloA(s, ~x, y);
    f5b moduloB(s, a, b, x, ~y, w, z); 

    // ------------------------- Parte principal
    initial
    begin : main
        $display("Questao_06 - Felipe Rivetti Mizher - 821811");
        $display("Test module");
        $display("   x    y    w    z    s    a    b");

        $monitor("%4b %4b %4b %4b %4b %4b %4b", x, y, w, z, s, a, b);
        #1  x = 1'b0; y = 1'b0; w = 1'b0; z = 1'b0;
        #1  x = 1'b0; y = 1'b0; w = 1'b0; z = 1'b1;
        #1  x = 1'b0; y = 1'b0; w = 1'b1; z = 1'b0;
        #1  x = 1'b0; y = 1'b0; w = 1'b1; z = 1'b1;
        #1  x = 1'b0; y = 1'b1; w = 1'b0; z = 1'b0;
        #1  x = 1'b0; y = 1'b1; w = 1'b0; z = 1'b1;
        #1  x = 1'b0; y = 1'b1; w = 1'b1; z = 1'b0;
        #1  x = 1'b0; y = 1'b1; w = 1'b1; z = 1'b1;
        #1  x = 1'b1; y = 1'b0; w = 1'b0; z = 1'b0;
        #1  x = 1'b1; y = 1'b0; w = 1'b0; z = 1'b1;
        #1  x = 1'b1; y = 1'b0; w = 1'b1; z = 1'b0;
        #1  x = 1'b1; y = 1'b0; w = 1'b1; z = 1'b1;
        #1  x = 1'b1; y = 1'b1; w = 1'b0; z = 1'b0;
        #1  x = 1'b1; y = 1'b1; w = 1'b0; z = 1'b1;
        #1  x = 1'b1; y = 1'b1; w = 1'b1; z = 1'b0;
        #1  x = 1'b1; y = 1'b1; w = 1'b1; z = 1'b1;
    end
endmodule // test_f5



