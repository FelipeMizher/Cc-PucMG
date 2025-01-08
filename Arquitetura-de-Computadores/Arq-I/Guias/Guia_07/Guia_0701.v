// 821811 - Felipe Rivetti Mizher

// ------------------------- 
// Guia_0701 - GATES 
// ------------------------- 

// ------------------------- 
//  f7_gate 
// ------------------------- 
module f7(  input wire a,
            input wire b,
            input wire select,
            output wire out1_and,
            output wire out2_nand,
            output wire selected_output );

    assign out1_and = a & b;
    assign out2_nand = ~(a & b);
    assign selected_output = select ? out2_nand : out1_and;

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
    reg  x; 
    reg  y; 
    reg  s; 
    wire w; 
    wire z; 
    wire out1_and;
    wire out2_nand;
    wire selected_output;

    f7 modulo( x, y, s, out1_and, out2_nand, selected_output ); 

    mux MUX1( z, out1_and, out2_nand, s ); 

    // ------------------------- parte principal 

    initial 
    begin : main 
        $display("Guia_0701 - Felipe Rivetti Mizher - 821811"); 
        $display("Test LU's module"); 
        $display("   x    y    s    z"); 

        x = 1'b0;  y = 1'b1;  s = 1'b0; 

    // projetar testes do modulo 
        #1    $monitor("%4b %4b %4b %4b", x, y, s, z); 
        #1     s = 1'b1; 

    end 
endmodule // test_f7 
