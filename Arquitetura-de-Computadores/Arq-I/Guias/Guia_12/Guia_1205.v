/**
    821811
    Felipe Rivetti Mizher
    Questão 5:
*/

module jkff(output q, 
            output qnot,
            input j, 
            input k,
            input clk, 
            input preset, 
            input clear);

    reg q, qnot;
    always @(posedge clk or posedge preset or posedge clear)begin
        if(clear)begin
            q <= 0; qnot <= 1;
        end
        else if(preset)begin
            q <= 1;     
            qnot <= 0; 
        end
        else if(j & ~k)begin 
            q <= 1;
            qnot <= 0; 
        end
        else if(~j & k)begin 
            q <= 0; 
            qnot <= 1; 
        end
        else if(j & k)begin 
            q <= ~q; 
            qnot <= ~qnot; 
        end
    end
    
endmodule // end jkff

module memoria_RAM_2x8(
                        input wire clk,
                        input wire reset,
                        input wire [1:0] endereco,
                        input wire [7:0] dado_in,
                        output reg [7:0] dado_out);

    memoria_RAM_1x8 mem0(
        .clk(clk),
        .reset(reset),
        .endereco(endereco[0]),
        .dado_in(dado_in),
        .dado_out(dado_out)
    );

    memoria_RAM_1x8 mem1(
        .clk(clk),
        .reset(reset),
        .endereco(endereco[1]),
        .dado_in(dado_in),
        .dado_out(dado_out)
    );

    always @(posedge clk) begin
        if (reset)
            dado_out <= 8'b0;
        else begin
            case (endereco)
                2'b00: dado_out <= mem0.dado_out;
                2'b01: dado_out <= mem1.dado_out;
                default: dado_out <= 8'b0;
            endcase
        end
    end

endmodule // end memoria_RAM_2x8

module memoria_RAM_4x8(
                        input wire clk,
                        input wire reset,
                        input wire [3:0] endereco,
                        input wire [7:0] dado_in,
                        output reg [7:0] dado_out);

    memoria_RAM_2x8 mem0(
        .clk(clk),
        .reset(reset),
        .endereco(endereco[1:0]),
        .dado_in(dado_in),
        .dado_out(dado_out)
    );

    memoria_RAM_2x8 mem1(
        .clk(clk),
        .reset(reset),
        .endereco(endereco[3:2]),
        .dado_in(dado_in),
        .dado_out(dado_out)
    );

    always @(posedge clk) begin
        if (reset)
            dado_out <= 8'b0;
        else begin
            case (endereco)
                4'b0000: dado_out <= mem0.dado_out;
                4'b0001: dado_out <= mem1.dado_out;
                default: dado_out <= 8'b0;
            endcase
        end
    end

endmodule // end memoria_RAM_4x8

module memoria_RAM_8x8( input wire clk,
                        input wire reset,
                        input wire [2:0] endereco,
                        input wire [7:0] dado_in,
                        output reg [7:0] dado_out);

    memoria_RAM_4x8 mem0(
        .clk(clk),
        .reset(reset),
        .endereco(endereco[1:0]),
        .dado_in(dado_in),
        .dado_out(dado_out)
    );

    memoria_RAM_4x8 mem1(
        .clk(clk),
        .reset(reset),
        .endereco(endereco[2]),
        .dado_in(dado_in),
        .dado_out(dado_out)
    );

    always @(posedge clk) begin
        if (reset)
            dado_out <= 8'b0;
        else begin
            case (endereco)
                3'b000: dado_out <= mem0.dado_out;
                3'b001: dado_out <= mem1.dado_out;
                default: dado_out <= 8'b0;
            endcase
        end
    end

endmodule // end memoria_RAM_8x8

module teste_memoria_RAM_8x8;

    parameter PERIOD = 10; 

    reg clk = 0;            
    reg reset = 1;          
    reg [2:0] endereco = 0;      
    reg [7:0] dado_in = 0;  

    memoria_RAM_8x8 memoria_ram(
        .clk(clk),
        .reset(reset),
        .endereco(endereco),
        .dado_in(dado_in),
        .dado_out()
    );

    always #((PERIOD/2)) clk = ~clk;

    initial begin
        $display("Inicializando teste.");
        $display("Escrevendo na memória.");
        dado_in = 8'b10101010; 
        endereco = 3'b001;           
        #20;                    
        $display("Lendo da memória.");
        endereco = 3'b000;           
        #20;                   
        $display("Teste finalizado.");
        $finish;
    end

endmodule // end teste_memoria_RAM_8x8

