// 8281811 - Felipe Rivetti Mizher

/*
 Guia0101 - v0.0. - 6 / 8 / 2023
 Author: ____Felipe Rivetti Mizher_____
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0115 ./Guia0115.cpp
 No Windows: g++ -o Guia0115 Guia0115.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0115
 No Windows: Guia0115
*/

#include "karel.hpp"

void decorateWorld(const char* fileName) {
    for(int x = 3; x <= 5; x++) {
    world->set(x, 6, HWALL);
    world->set(x, 3, HWALL);
    }
    
    for(int i = 4; i <= 6; i++){
        world->set(2, i, VWALL);
    }
    
    for(int i = 4; i <= 5; i++){
        world->set(5, i, VWALL);
    }
    
    world->set(6, 3, BEEPER);
    world->set(2, 6, BEEPER);
    world->set(2, 6, BEEPER);
    world->set(5, 7, BEEPER);
    world->set(5, 7, BEEPER);
    world->set(5, 7, BEEPER);
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

    void mover() {
        moveN(5);
        turnLeft();
    }
    
    void pegar(){
        if (nextToABeeper()) {
            pickBeeper();
        }
    }
    
     void largar(){
        if ( nbeepers( ) > 0 ){
            putBeeper( );
        }
    }
    
    void mover2(){
        moveN(2);
        turnRight();
        moveN(2);
        turnLeft();
        move();
        turnLeft();
        moveN(4);
        turnLeft();
        move();
        pegar();
        pegar();
        turnLeft();
        turnLeft();
        move();
        turnRight();
        moveN(4);
        turnRight();
        move();
        turnRight();
    }
    
    void mover3(){
        moveN(2);
        turnRight();
        moveN(2);
        turnLeft();
        move();
        turnLeft();
        move();
        pegar();
        pegar();
        pegar();
        turnLeft();
        turnLeft();
        move();
        turnRight();
        move();
        turnRight();
    }
    
    void finalizar(){
        moveN(2);
        turnLeft();
        moveN(2);
        turnLeft();
        turnLeft();
    }
    
    void Final(){
        moveN(2);
        turnRight();
        moveN(2);
        turnRight();
        moveN(5);
        turnRight();
        moveN(5);
        turnLeft();
        turnLeft();
    }

    void doTask() {
        mover();
        moveN(2);
        pegar();
        moveN(3);
        turnLeft();
        finalizar();
        largar();
        mover2();
        finalizar();
        largar();
        largar();
        mover3();
        finalizar();
        largar();
        largar();
        largar();
        Final(); 
        turnOff();
    }
};

int main() {
    world->create("");
    decorateWorld("Guia0115.txt");
    world->show();
    world->reset();
    world->read("Guia0115.txt");
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

    foi criado novas funções para que o robo siga as instruções do exercicio, pegue os seis Beepers, deixe no lugar correto na ordem e volte para o seu lugar de partida original. 

---------------------------------------------- notas / observacoes / comentarios

     Não houve erros na execução do programa.

---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
 */
