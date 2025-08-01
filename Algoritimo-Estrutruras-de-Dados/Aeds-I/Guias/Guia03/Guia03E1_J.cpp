// 821811 - Felipe Rivetti Mizher

#include "RobotActions.hpp"

void MyRobotJ::performActions() {
    robot1->halfPathRight();
    robot1->turnLeft();
    robot1->move();
    robot1->turnLeft();
    robot1->halfPathRight();
    robot1->pegar();
    robot1->halfPathLeft();
    robot1->largar();
    robot1->halfPathRight();
    robot1->turnAround();
}