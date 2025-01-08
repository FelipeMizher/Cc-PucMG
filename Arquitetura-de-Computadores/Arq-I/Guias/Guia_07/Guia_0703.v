// 821811 - Felipe Rivetti Mizher

// ------------------------- 
// Guia_0703 - GATES 
// ------------------------- 

// ------------------------- 
//  f7_gate 
// ------------------------- 
module f7(  input wire a,
            input wire b,
            input wire chave1,            
            input wire chave2,
            output wire result );

    wire out_or, out_nor, out_and,  out_nand;
	assign out_and = a & b;
	assign out_nand = ~(a & b);
	assign out_or = a | b;
	assign out_nor = ~(a | b);

    assign result = chave1 ? (chave2 ? out_nor : out_nand) : (chave2 ? out_or : out_and);

endmodule // end f7

// ------------------------- 
//  multiplexer 
// ------------------------- 
module mux( 
    output wire s, 
    input  wire a, 
    input  wire b, 
    input  wire select ); 

// definir dados locais 
    wire not_select; 
    wire sa; 
    wire sb; 

// descrever por portas 
    not NOT1( not_select, select ); 

    and AND1( sa, a, not_select ); 
    and AND2( sb, b,    select  ); 

    or  OR1     ( s , sa, sb ); 
endmodule // mux 


module test_f7; 
    // ------------------------- definir dados 
    reg  a; 
    reg  b; 
    reg  chave1;
    reg  chave2;  
    wire result;

    f7 modulo( a, b, chave1, chave2, select ); 

    mux MUX1( s, out_or, out_nor, chave1 );
    mux MUX2( out, out_and, out_nand, chave2 );
    mux MUX3( final_result, out, result, chave1 );
    
    // ------------------------- parte principal 

    initial 
   begin : main 
      $display("Guia_0703 - Felipe Rivetti Mizher - 821811");
      $display("Testando o módulo f7 e mux"); 
      $display("   a    b    chave1    chave2    result"); 

      a = 0; b = 0; chave1 = 0; chave2 = 0; #10;
      a = 1; b = 0; chave1 = 0; chave2 = 0; #10;
      a = 0; b = 1; chave1 = 1; chave2 = 0; #10;
      a = 1; b = 1; chave1 = 1; chave2 = 1; #10;

      $finish;
   end
endmodule // test_f7  
