// 821811 - Felipe Rivetti Mizher

#include "WorldDecorator.hpp"
#include "RobotActions.hpp"

int main() {
    world->create("");
    decorateWorld("Guia03E1.txt");
    world->show();
    world->reset();
    world->read("Guia03E1.txt");
    world->show();
    set_Speed(1);

    // Configurações e criação dos robôs
    MyRobotJ *robotJ = new MyRobotJ();
    MyRobotK *robotK = new MyRobotK();

    // Chamar as ações específicas do robô 'J'
    robotJ->performActions();

    // Chamar as ações específicas do robô 'K'
    robotK->performActions();

    world->close();
    getchar();
    return 0;
}