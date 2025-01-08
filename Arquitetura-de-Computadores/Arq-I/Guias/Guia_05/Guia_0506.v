// 821811 - Felipe Rivetti Mizher
// Guia_0506.v 

module f5a ( output s, 
             input a, 
             input b );
// Definir dados locais
   wire not_a; 
   wire not_b; 
   wire a_and_b; 
   wire a_or_b;
// Descrever por portas NAND
   nand NAND1(not_a, a, a);
   nand NAND2(not_b, b, b);
   nand NAND3(a_and_b, a, b);
   nand NAND4(a_or_b, not_a, not_b);
   nand NAND5(s, a_or_b, a_and_b);
   
endmodule // f5a

module f5b ( output s,
             output a,
             output b, 
             input x,
             input y );
   // descrever por expressao
      assign s = a ^ b;
      assign a = x;
      assign b = y;        
    endmodule // f5b

    module test_f5;
   // ------------------------- definir dados
            reg x;
            reg y;
            wire s, a, b;

   f5a moduloA ( s, x, y );
   f5b moduloB ( s, a,  b, x, y );

// ------------------------- parte principal

   initial
   begin : main
      $display("Guia_0506 - Felipe Rivetti Mizher - 821811");
      $display("Test module");
      $display("   x    y    a    b");

     // projetar testes do modulo
      $monitor("%4b %4b %4b %4b", x, y, a, b);
#1       x = 1'b0; y = 1'b0;
#1       x = 1'b0; y = 1'b1;
#1       x = 1'b1; y = 1'b0;
#1       x = 1'b1; y = 1'b1;
   end
endmodule // test_f5
