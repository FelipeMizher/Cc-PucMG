// 821811 - Felipe Rivetti Mizher
// Guia_0505.v 

module f5a ( output s, 
             input a, 
             input b );
// Definir dados locais
   wire not_a; 
   wire not_b; 
   wire a_nor_b;
// Descrever por portas NAND
   nor NOR1(not_a, a, a);
   nor NOR2(not_b, b, b);
   nor NOR3(a_nor_b, a, b);
   nor NOR4(s, not_a, not_b, a_nor_b);
   
endmodule // f5a

module f5b ( output s,
             output a,
             output b, 
             input x,
             input y );
   // descrever por expressao
      assign s = ~(x ^ y);
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
      $display("Guia_0505 - Felipe Rivetti Mizher - 821811");
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
