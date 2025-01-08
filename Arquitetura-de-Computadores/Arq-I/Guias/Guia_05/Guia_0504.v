// 821811 - Felipe Rivetti Mizher
// Guia_0504.v 

module f5a ( output s, 
             input  a, 
             input  b ); 
// definir dado local 
   wire not_b; 
   wire a_en_not_b;
// descrever por portas 
   nand NAND1(not_b, b, b);
   nand NAND2(a_and_not_b, a, not_b);
   nand NAND3(s, a_and_not_b, a_and_not_b); 
endmodule // f5a

module f5b ( output s, 
             input  a, 
             input  b ); 
// descrever por expressao 
   assign s = ~(a & ~b); 
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
          $display("Guia_0504 - Felipe Rivetti Mizher - 821811"); 
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