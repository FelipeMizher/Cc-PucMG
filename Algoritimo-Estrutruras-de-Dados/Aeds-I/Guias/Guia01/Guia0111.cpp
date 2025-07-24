// 821811 - Felipe Rivetti Mizher

/*
 Guia0101 - v0.0. - 6 / 8 / 2023
 Author: ____Felipe Rivetti Mizher_____
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0111 ./Guia0111.cpp
 No Windows: g++ -o Guia0111 Guia0111.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0111
 No Windows: Guia0111
*/

#include "karel.hpp"

void decorateWorld(const char* fileName) {
    world->save(fileName);
}

class MyRobot : public Robot {
public:
    void turnRight() {
        if (checkStatus()) {
            turnLeft();
            turnLeft();
            turnLeft();
        }
    }

    void moveN(int steps) {
        int step = 0;
        for (step = 1; step <= steps; step = step + 1) {
            move();
        }
    }
    
    void soltar(){
        if (nbeepers() > 0) {
            putBeeper();
        }
    }

    void doPartialTask() {
        moveN(2);
    }
    
    void mover(){
        moveN(3);
        turnRight();
    }
    
    void mover2(){
        moveN(5);
        turnLeft();
    }

    void doTask() {
        doPartialTask();
        turnLeft();
        doPartialTask();
        soltar();
        mover();
        soltar();
        mover();
        soltar();
        mover();
        mover2();
        doPartialTask();
        turnLeft();
        turnOff();
    }
};

int main() {
    world->create("");
    decorateWorld("Guia0111.txt");
    world->show();
    world->reset();
    world->read("Guia0111.txt");
    world->show();
    set_Speed(3);

    MyRobot *robot = new MyRobot();
    robot->create(1, 1, EAST, 3, "Karel");
    robot->doTask();

    world->close();
    getchar();
    return 0;
}

// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar

    Foi adicionado novas funções para ações do robo, como a função soltar, que faz o robo soltar os Beepers, e a função finalizar, que ajuda as outras funções a fazer o robo chegar ao seu ponto de partida na posição correta.

---------------------------------------------- notas / observacoes / comentarios

    Houve erros de digitação na hora de adicionar ações ao codigo, mas foi corrigido e esta funcionando. 

---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco