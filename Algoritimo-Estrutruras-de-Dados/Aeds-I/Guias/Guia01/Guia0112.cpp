/*
 Guia0101 - v0.0. - 6 / 8 / 2023
 Author: ____Felipe Rivetti Mizher_____
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0112 ./Guia0112.cpp
 No Windows: g++ -o Guia0112 Guia0112.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0112
 No Windows: Guia0112
*/

#include "karel.hpp"

void decorateWorld(const char* fileName) {
    world->set(3, 3, BEEPER);
    world->set(3, 6, BEEPER);
    world->set(6, 6, BEEPER);
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

    void doPartialTask() {
        moveN(5);
        turnLeft();
    }
    
    void pegar(){
        if (nextToABeeper()) {
            pickBeeper();
        }
    }
    
    void mover(){
        moveN(3);
    }
    
    void finalizar(){
        turnRight();
        moveN(2);
        turnLeft();
        moveN(2);
    }

    void doTask() {
        doPartialTask();
        doPartialTask();
        pegar();
        mover();
        pegar();
        turnLeft();
        mover();
        pegar();
        finalizar();
        turnLeft();
        turnOff();
    }
};

int main() {
    world->create("");
    decorateWorld("Guia0112.txt");
    world->show();
    world->reset();
    world->read("Guia0112.txt");
    world->show();
    set_Speed(3);

    MyRobot *robot = new MyRobot();
    robot->create(1, 1, EAST, 0, "Karel");
    robot->doTask();

    world->close();
    getchar();
    return 0;
}

// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar

    foi criado uma nova função para pegar os Beepers e foi adicionado movimentos para que o robo siga as instruções do exercicio. 

---------------------------------------------- notas / observacoes / comentarios

     Não houve erros na execução do programa.

---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
