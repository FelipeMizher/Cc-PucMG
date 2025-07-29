// 8281811 - Felipe Rivetti Mizher

/*
 Guia0101 - v0.0. - 13 / 8 / 2023
 Author: ____Felipe Rivetti Mizher_____
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0211 ./Guia0211.cpp
 No Windows: g++ -o Guia0211 Guia0211.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0211
 No Windows: Guia0211
*/

#include "karel.hpp"

void decorateWorld(const char* fileName) {
    world->set(2, 1, VWALL);
    world->set(3, 1, HWALL);
    world->set(3, 2, VWALL);
    world->set(4, 2, HWALL);
    world->set(4, 3, VWALL);
    world->set(4, 2, HWALL);
    world->set(5, 3, HWALL);
    world->set(6, 3, HWALL);
    world->set(6, 3, VWALL);
    world->set(7, 2, HWALL);
    world->set(7, 2, VWALL);
    world->set(8, 1, HWALL);
    world->set(8, 1, VWALL);
    
    world->set(9, 1, BEEPER);
    world->set(8, 2, BEEPER);
    world->set(8, 2, BEEPER);
    world->set(7, 3, BEEPER);
    world->set(7, 3, BEEPER);
    world->set(7, 3, BEEPER);
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
    
    void stepUpRight(){
        turnLeft();
        move();
        turnRight();
        move();
    }
    
    void stepDownRight(){
        move();
        turnRight();
        move();
        turnLeft();
    }
    
    void stepUpLeft(){
        move();
        turnLeft();
        move();
        turnRight();
    }
    
    void stepDownLeft(){
        move();
        turnLeft();
        move();
        turnRight();
    }
    
    void Final(){
        move();
        turnLeft();
        turnLeft();
    }

    void doTask() {
        move();
        stepUpRight();
        stepUpRight();
        stepUpRight();
        move();
        stepDownRight();
        stepDownRight();
        stepDownRight();
        pickBeepers(1);
        turnLeft();
        stepUpLeft();
        pickBeepers(2);
        stepUpLeft();
        pickBeepers(3);
        stepUpLeft();
        turnLeft();
        move();
        stepDownLeft();
        putBeepers(3);
        stepDownLeft();
        putBeepers(2);
        stepDownLeft();
        putBeepers(1);
        Final();
           
        turnOff();
    }
};

int main() {
    world->create("");
    decorateWorld("Guia0211.txt");
    world->show();
    world->reset();
    world->read("Guia0211.txt");
    world->show();
    set_Speed(3);

    MyRobot *robot = new MyRobot();
    robot->create(1, 1, EAST, 0, "Karel");
    robot->doTask();

    world->close();
    getchar();
    return 0;
}

