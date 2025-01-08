// 821811 - Felipe Rivetti Mizher

// ------------------------- 
// Guia_0702 - GATES 
// ------------------------- 

// ------------------------- 
//  f7_gate 
// ------------------------- 
module f7(  input wire a,
            input wire b,
            input wire select,
            output wire out_or,
            output wire out_nor,
            output wire selected_output );

    assign out_or = (a | b);
    assign out_nor = ~(a | b);
    assign selected_output = select ? out_nor : out_or;

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
    reg  select; 
    wire out_or; 
    wire out_nor; 
    wire s; 
    wire selected_output;

    f7 modulo( a, b, select, out_or, out_nor, selected_output ); 

    mux MUX1( s, out_or, out_nor, select );
    
    // ------------------------- parte principal 

    initial 
    begin : main 
        $display("Guia_0702 - Felipe Rivetti Mizher - 821811"); 
        $display("Test LU's module"); 
        $display("   a    b    select    out_or    out_nor    selected_output    s"); 

        a = 1'b0;  b = 1'b1;  select = 1'b0; 

    // projetar testes do modulo 
        #1    $monitor("%4b %4b %6b %10b %9b %14b %11b", a, b, select, out_or, out_nor, selected_output, s); 
        #1     select = 1'b1; 

    end 
endmodule // test_f7  
