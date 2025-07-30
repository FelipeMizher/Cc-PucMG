// 8281811 - Felipe Rivetti Mizher

/*
 Guia0101 - v0.0. - 13 / 8 / 2023
 Author: ____Felipe Rivetti Mizher_____
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0214 ./Guia0214.cpp
 No Windows: g++ -o Guia0214 Guia0214.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0214
 No Windows: Guia0214
*/

#include "karel.hpp"
#include <fstream>
#include <iostream>

void decorateWorld(const char* fileName) {
    for(int i = 3; i <= 8; i++){
        world->set(2, i, VWALL);
    }
    for(int i = 3; i <= 8; i++){
        world->set(5, i, VWALL);
    }
    for(int i = 3; i <= 7; i++){
        world->set(3, i, VWALL);
    }
    for(int i = 3; i <= 7; i++){
        world->set(4, i, VWALL);
    }
    
    for(int i = 3; i <= 5; i++ ){
        world->set(i, 2, HWALL);
    }
    
    world->set(3, 8, HWALL);
    world->set(5, 8, HWALL);
    
    world->set(3, 3, BEEPER);
    world->set(3, 3, BEEPER);
    world->set(3, 3, BEEPER);
    world->set(3, 4, BEEPER);
    world->set(3, 4, BEEPER);
    world->set(3, 5, BEEPER);
    world->set(4, 3, BEEPER);
    world->set(4, 3, BEEPER);
    world->set(4, 3, BEEPER);
    world->set(4, 4, BEEPER);
    world->set(4, 4, BEEPER);
    world->set(5, 3, BEEPER);
    world->set(5, 3, BEEPER);
    world->set(5, 3, BEEPER);
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
    
     void savePosition(int x, int y) {
        std::ofstream arquivo("Tarefa0214b.txt", std::ios_base::app);
        if (arquivo.is_open()) {
            arquivo << x << " " << y << std::endl;
            arquivo.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo." << std::endl;
        }
    }
    
    void putBeepers(int n){
        for(int i = 0; i < n; i++){
            putBeeper();
        }
    }
    
    void pickBeepers(int n){
        for(int i = 0; i < n; i++){
            pickBeeper();
        }
    }
    
    void meiaVolta(){
        turnLeft();
        turnLeft();
    }

    void doTask() {
        move();
        turnLeft();
        moveN(8);
        turnRight();
        moveN(2);
        turnRight();
        move();
        turnLeft();
        move();
        turnRight();
        moveN(5);
        pickBeepers(3);
        meiaVolta();
        moveN(5);
        turnLeft();
        move();
        turnLeft();
        moveN(5);
        pickBeepers(3);
        meiaVolta();
        move();
        pickBeepers(2);
        moveN(4);
        turnLeft();
        move();
        turnLeft();
        moveN(5);
        pickBeepers(3);
        meiaVolta();
        move();
        pickBeepers(2);
        move();
        pickBeepers(1);
        moveN(3);
        turnRight();
        move();
        turnLeft();
        move();
        turnRight();
        moveN(5);
        turnRight();
        moveN(8);
        if (areYouHere(9, 1) && beepersInBag()) {
            putBeepers(14);
        }
        
        turnRight();
        moveN(8);
        meiaVolta();
        turnOff();
    }
};

int main() {
    world->create("");
    decorateWorld("Guia0214.txt");
    world->show();
    world->reset();
    world->read("Guia0214.txt");
    world->show();
    set_Speed(3);

    MyRobot *robot = new MyRobot();
    robot->create(1, 1, EAST, 0, "Karel");
    robot->doTask();

    world->close();
    getchar();
    return 0;
}