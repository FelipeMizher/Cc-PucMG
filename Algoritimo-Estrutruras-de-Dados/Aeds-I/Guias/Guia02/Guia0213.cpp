// 8281811 - Felipe Rivetti Mizher

/*
 Guia0101 - v0.0. - 13 / 8 / 2023
 Author: ____Felipe Rivetti Mizher_____
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0213 ./Guia0213.cpp
 No Windows: g++ -o Guia0213 Guia0213.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0213
 No Windows: Guia0213
*/

#include "karel.hpp"

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
    world->set(4, 3, BEEPER);
    world->set(4, 3, BEEPER);
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
        pickBeepers(1);
        meiaVolta();
        moveN(5);
        turnLeft();
        move();
        turnLeft();
        moveN(5);
        pickBeepers(2);
        meiaVolta();
        moveN(5);
        turnLeft();
        move();
        turnLeft();
        moveN(5);
        pickBeepers(3);
        meiaVolta();
        moveN(5);
        turnRight();
        move();
        turnLeft();
        move();
        turnRight();
        moveN(5);
        turnRight();
        moveN(8);
        if (areYouHere(9, 1) && beepersInBag()) {
            putBeepers(6);
        }
        
        turnRight();
        moveN(8);
        meiaVolta();
        turnOff();
    }
};

int main() {
    world->create("");
    decorateWorld("Guia0213.txt");
    world->show();
    world->reset();
    world->read("Guia0213.txt");
    world->show();
    set_Speed(3);

    MyRobot *robot = new MyRobot();
    robot->create(1, 1, EAST, 0, "Karel");
    robot->doTask();

    world->close();
    getchar();
    return 0;
}