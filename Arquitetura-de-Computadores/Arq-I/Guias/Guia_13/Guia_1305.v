/**
    821811 
    Felipe Rivetti Mizher
    Questão_5
*/

module tff( output reg q,
            input t,
            input clk,
            input preset,
            input clear);

    always @(posedge clk or posedge preset or posedge clear) 
    begin
        if(clear) 
        begin
            q <= 0;
        end 
        else if(preset) 
        begin
            q <= 1;
        end 
        else if(t) 
        begin
            q <= ~q;
        end
    end
endmodule // tff

module contador_modulo_7(output [2:0] count,
                         input clk,
                         input clear);

    wire [2:0] t;
    wire rst;

    assign rst = clear | (count == 3'b111);

    assign t[0] = 1;
    assign t[1] = count[0];
    assign t[2] = count[0] & count[1];

    tff tff0(count[0], t[0], clk, 1'b0, rst);
    tff tff1(count[1], t[1], clk, 1'b0, rst);
    tff tff2(count[2], t[2], clk, 1'b0, rst);

endmodule // contador_modulo_7

module teste_contador;
    reg clk = 0;
    reg clear;
    wire [2:0] count;

    contador_modulo_7 c1(count, clk, clear);

    always #5 clk = ~clk;

    initial begin
        $display("Contador modulo 7");
        $monitor("%b", count);

        clear = 1;
        #10 clear = 0;
        #200;
        $finish;
    end
endmodule // teste_contador
