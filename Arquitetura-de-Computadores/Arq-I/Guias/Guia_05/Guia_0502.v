// 821811 - Felipe Rivetti Mizher
// Guia_0502.v

module f5a ( output s, 
             input  a, 
             input  b ); 
// definir dado local 
   wire not_a; 
   wire a_nand_b;
// descrever por portas 
   nand NAND1(not_a, a, a);
   nand NAND2(a_nand_b, not_a, b);
   nand NAND3(s, a_nand_b, a_nand_b); 
endmodule // f5a

module f5b ( output s, 
             input  a, 
             input  b ); 
// descrever por expressao 
   assign s = ~a + b; 
endmodule // f5b 

module test_f5; 
// ------------------------- definir dados 
       reg  x; 
       reg  y; 
       wire a, b; 
 
       f5a moduloA ( a, x, y ); 
       f5b moduloB ( b, x, y ); 
 
// ------------------------- parte principal 
 
   initial 
   begin : main 
          $display("Guia_0502 - Felipe Rivetti Mizher - 821811"); 
          $display("Test module"); 
          $display("   x    y    a    b"); 
 
       // projetar testes do modulo 
         $monitor("%4b %4b %4b %4b", x, y, a, b); 
   #1      x = 1'b0;  y = 1'b0; 
   #1      x = 1'b0;  y = 1'b1; 
   #1      x = 1'b1;  y = 1'b0; 
   #1      x = 1'b1;  y = 1'b1; 
 
   end 
 
endmodule // test_f5