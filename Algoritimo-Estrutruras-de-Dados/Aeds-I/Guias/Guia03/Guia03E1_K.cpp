// 821811 - Felipe Rivetti Mizher

#include "RobotActions.hpp"

void MyRobotK::performActions() {
    robot2->halfPathRight();
    robot2->pegar();
    robot2->below();
    robot2->halfPathRight();
    robot2->largar();
    robot2->turnAround();
    robot2->halfPathRight();
    robot2->above();
    robot2->halfPathRight();
    robot2->turnAround();
}