// 821811 - Felipe Rivetti Mizher

// ------------------------- 
// Guia_0704 - GATES 
// ------------------------- 

// ------------------------- 
//  f7_gate 
// ------------------------- 
module f7(  input wire a,
            input wire b,
            input wire [1:0] chave 
            output wire result );

    wire out_or, out_nor, out_xor,  out_xnor;
	assign out_or = a | b;
	assign out_nor = ~(a | b);
	assign out_xor = a ^ b;
	assign out_xnor = ~(a ^ b);

assign result = chave[1] ? (chave[0] ? out_xnor : out_xor) : (chave[0] ? out_nor : out_or);

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
    assign not_select = ~select;
    assign sa = a & not_select;
    assign sb = b & select;
    assign s = sa | sb;

endmodule // mux 


module test_f7; 
    // ------------------------- definir dados 
    reg  a; 
    reg  b; 
    reg  [1:0] chave;  
    wire result;

    f7 modulo(a, b, chave, result);
    mux MUX1(result, out_or, out_nor, chave[1]);
    
    // ------------------------- parte principal 

    initial 
   begin : main 
        $display("Guia_0704 - Felipe Rivetti Mizher - 821811");
        $display("Testando o módulo f7 e mux");
        $display("   a    b    chave    result");

        a = 0; b = 0; chave = 2'b00; #10;
        a = 1; b = 0; chave = 2'b00; #10;
        a = 0; b = 1; chave = 2'b01; #10;
        a = 1; b = 1; chave = 2'b11; #10;

      $finish;
   end
endmodule // test_f7  
