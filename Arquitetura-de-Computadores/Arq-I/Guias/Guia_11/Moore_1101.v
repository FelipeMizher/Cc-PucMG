// 821811 - Felipe Rivetti Mizher


`define found 1
`define notfound 0

module Moore_1101(y, x, clk, reset);
    output y;
    input x;
    input clk;
    input reset;
    reg y;

    parameter 
        start = 3'b000,
        id1 = 3'b001,
        id11 = 3'b011,
        id110 = 3'b010,
        id1101 = 3'b110; 
        reg [2:0] E1;
        reg [2:0] E2;

    always @(x or E1)
        begin
            case( E1 )
            start:
                if ( x )
                    E2 = id1;
                else
                    E2 = start;
                    id1:
                if ( x )
                    E2 = id11;
                else
                    E2 = start;
                    id11:
                if ( x )
                    E2 = id11;
                else
                    E2 = id110;
                    id110:
                if ( x )
                    E2 = id1101;
                else
                    E2 = start;
                    id1101:
                if ( x )
                    E2 = id11;
                else
                    E2 = start;
                default:
                    E2 = 3'bxxx;
            endcase
        end

    always @( posedge clk or negedge reset )
        begin
            if ( reset )
                E1 = E2; 
            else
                E1 = 0; 
        end 

    always @( E1 )
        begin
            y = E1[2];
        end 
endmodule // moore_1101

module Guia_1102;
    reg x, clk, reset;
    wire y;

    moore_1101 moore (y, x, clk, reset);

    initial
    begin
        $monitor("clock = %b / y = %b / x = %b / res = %b", clk, y, x, reset);
        clk = 0;
        reset = 1;
        #5 reset = 0;
        #10 x = 1;
        #5 x = 0;
        #10 x = 1;
        #5 x = 1;
        #5 x = 0;
        #100 $finish;
    end
    always #5 clk = ~clk;
endmodule // end Guia_1102