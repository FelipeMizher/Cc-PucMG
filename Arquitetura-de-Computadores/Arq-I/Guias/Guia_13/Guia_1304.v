/**
    821811 
    Felipe Rivetti Mizher
    Questão_4
*/

module jkff(output reg q, 
            output reg qnot,
            input j, 
            input k,
            input clk, 
            input preset, 
            input clear);

    always @(posedge clk or posedge preset or posedge clear) 
    begin
        if(clear) 
        begin
            q <= 0; 
            qnot <= 1;
        end 
        else if(preset) 
        begin
            q <= 1; 
            qnot <= 0;
        end 
        else if(j & ~k) 
        begin
            q <= 1; 
            qnot <= 0;
        end 
        else if(~j & k) 
        begin
            q <= 0; 
            qnot <= 1;
        end 
        else if(j & k) 
        begin
            q <= ~q; 
            qnot <= ~qnot;
        end
    end
endmodule // jkff

module contador_decadico_decresc(output [3:0] count,
                                 input clk,
                                 input clear);

    wire [3:0] qnot;
    wire rst;

    assign rst = clear | (~count[3] & ~count[2] & ~count[1] & ~count[0]);

    jkff jk1(count[0], qnot[0], 1'b1, 1'b1, clk, 1'b0, rst);
    jkff jk2(count[1], qnot[1], 1'b1, 1'b1, qnot[0], 1'b0, rst);
    jkff jk3(count[2], qnot[2], 1'b1, 1'b1, qnot[1], 1'b0, rst);
    jkff jk4(count[3], qnot[3], 1'b1, 1'b1, qnot[2], 1'b0, rst);

endmodule // contador_decadico_decresc

module teste_contador;
    reg clk = 0;
    reg clear;
    wire [3:0] count;

    contador_decadico_decresc c1(count, clk, clear);

    always #5 clk = ~clk;

    initial begin
        $display("Contador decrescente decadico");
        $monitor("%b", count);

        clear = 1;
        #10 clear = 0;
        #200;
        $finish;
    end
endmodule // teste_contador
