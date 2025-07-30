// 8281811 - Felipe Rivetti Mizher

/*
 Guia0101 - v0.0. - 13 / 8 / 2023
 Author: ____Felipe Rivetti Mizher_____
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0212 ./Guia0212.cpp
 No Windows: g++ -o Guia0212 Guia0212.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0212
 No Windows: Guia0212
*/

#include "karel.hpp"

void decorateWorld(const char* fileName) {
    world->set(4, 5, VWALL);
    world->set(5, 5, VWALL);
    world->set(5, 2, VWALL);
    world->set(5, 3, VWALL);
    world->set(4, 2, VWALL);
    world->set(4, 3, VWALL);
    for(int i = 2; i <= 4; i++){
        world->set(2, i, VWALL);
    }
    for(int i = 2; i <= 4; i++){
        world->set(7, i, VWALL);
    }
    for(int i = 6; i <= 8; i++){
        world->set(2, i, VWALL);
    }
    for(int i = 6; i <= 8; i++){
        world->set(7, i, VWALL);
    }
    world->set(4, 7, VWALL);
    world->set(4, 8, VWALL);
    world->set(5, 7, VWALL);
    world->set(5, 8, VWALL);
    
    world->set(5, 6, HWALL);
    world->set(5, 3, HWALL);
    world->set(6, 1, HWALL);
    world->set(7, 1, HWALL);
    world->set(3, 1, HWALL);
    world->set(4, 1, HWALL);
    world->set(3, 4, HWALL);
    world->set(4, 4, HWALL);
    world->set(6, 4, HWALL);
    world->set(7, 4, HWALL);
    world->set(3, 5, HWALL);
    world->set(4, 5, HWALL);
    world->set(6, 5, HWALL);
    world->set(7, 5, HWALL);
    world->set(3, 8, HWALL);
    world->set(4, 8, HWALL);
    world->set(6, 8, HWALL);
    world->set(7, 8, HWALL);
    
    world->set(4, 5, BEEPER);
    world->set(5, 7, BEEPER);
    world->set(6, 5, BEEPER);
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

    void doTask() {
        move();
        turnLeft();
        moveN(4);
        turnRight();
        moveN(2);
        if (nextToABeeper()) {
            pickBeeper();
        }
        if (leftIsClear()) {
            turnLeft();
            move();
        } else if (rightIsClear()) {
            turnRight();
            move();
        }
        turnLeft();
        turnLeft();
        moveN(2);
        turnRight();
        moveN(4);
        turnRight();
        moveN(3);
        turnRight();
        moveN(2);
        if (nextToABeeper()) {
            pickBeeper();
        }
        if (leftIsClear()) {
            turnLeft();
            move();
        } else if (rightIsClear()) {
            turnRight();
            move();
        }
        turnLeft();
        turnLeft();
        moveN(2);
        turnRight();
        moveN(3);
        turnRight();
        moveN(4);
        turnRight();
        moveN(2);
        if (nextToABeeper()) {
            pickBeeper();
        }
        if (leftIsClear()) {
            turnLeft();
            move();
        } else if (rightIsClear()) {
            turnRight();
            move();
        }
        turnLeft();
        turnLeft();
        moveN(2);
        turnRight();
        moveN(4);
        turnRight();
        moveN(3);
        turnRight();
        moveN(2);
        if(nextToABeeper()){
            pickBeeper();
        }
        if (leftIsClear()) {
            turnLeft();
            move();
        } else if (rightIsClear()) {
            turnRight();
            move();
        }
        turnLeft();
        turnLeft();
        moveN(2);
        turnRight();
        moveN(4);
        turnLeft();
        turnLeft();
        turnOff();
    }
};

int main() {
    world->create("");
    decorateWorld("Guia0212.txt");
    world->show();
    world->reset();
    world->read("Guia0212.txt");
    world->show();
    set_Speed(3);

    MyRobot *robot = new MyRobot();
    robot->create(1, 1, EAST, 0, "Karel");
    robot->doTask();

    world->close();
    getchar();
    return 0;
}

