// 821811 - Felipe Rivetti Mizher

// ------------------------- 
// Guia_0705 - GATES 
// ------------------------- 

// ------------------------- 
//  f7_gate 
// ------------------------- 
module f7(  input wire a,
            input wire b,
            input wire [2:0] select,
            input wire negate_b,
            output wire result );

wire not_b, selected_gate;

assign not_b = negate_b ? ~b : b;

assign selected_gate = (select == 3'b000) ? (~a) :
                       (select == 3'b001) ? (a & not_b) :
                       (select == 3'b010) ? ~(a & not_b) :
                       (select == 3'b011) ? (a | not_b) :
                       (select == 3'b100) ? ~(a | not_b) :
                       (select == 3'b101) ? (a ^ not_b) :
                       (select == 3'b110) ? ~(a ^ not_b) :
                       1'b0;

assign result = selected_gate;

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
    reg a;
    reg b;
    reg [2:0] select;
    reg negate_b;
    wire result;

    f7 modulo(a, b, select, negate_b, result);
    mux MUX1(result, out_or, out_nor, select[2]);
    
    // ------------------------- parte principal 

    initial 
   begin : main 
        $display("Guia_0704 - Felipe Rivetti Mizher - 821811");
        $display("Testando o módulo f7 e mux");
        $display("   a    b    select    negate_b    result");

        a = 0; b = 0; select = 3'b000; negate_b = 0; #10;
        a = 1; b = 0; select = 3'b000; negate_b = 0; #10;
        a = 0; b = 1; select = 3'b000; negate_b = 0; #10;
        a = 1; b = 1; select = 3'b000; negate_b = 0; #10;
        // Teste com diferentes seleções e negações de b
        a = 0; b = 0; select = 3'b100; negate_b = 0; #10;
        a = 1; b = 0; select = 3'b101; negate_b = 1; #10;
        a = 0; b = 1; select = 3'b110; negate_b = 0; #10;
        a = 1; b = 1; select = 3'b011; negate_b = 1; #10;

      $finish;
   end
endmodule // test_f7  
