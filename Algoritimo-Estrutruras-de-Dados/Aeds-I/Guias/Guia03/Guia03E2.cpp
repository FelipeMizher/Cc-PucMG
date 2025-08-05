// 821811 - Felipe Rivetti Mizher

/*
 Guia03E2 - v0.0. - 18 / 08 / 2023
 Author: _____Felipe Rivetti Mizher_________
 Para compilar em uma janela de comandos (terminal):
 
 No Linux : g++ -o Guia03E2 ./Guia03E2.cpp
 No Windows: g++ -o Guia03E2 Guia03E2.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia03E2
 No Windows: Guia03E2
*/
// lista de dependencias
#include "karel.hpp"
#include "io.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar paredes no m4undo
    for(int i = 2; i <= 8; i++){
        world->set(i, 4, HWALL);
        world->set(i, 6, HWALL);
    }
    for(int i = 5; i <= 6; i++){
        world->set(1, i, VWALL);
        world->set(8, i, VWALL);
    }
    world->set(2, 5, HWALL);
    world->set(3, 5, HWALL);
    world->set(4, 5, HWALL);
    
    world->set(6, 5, HWALL);
    world->set(7, 5, HWALL);
    world->set(8, 5, HWALL);
  
// colocar um marcador no mundo
    world->set ( 2, 5, BEEPER );
    world->set ( 2, 5, BEEPER );
    world->set ( 8, 6, BEEPER );
    
// salvar a configuracao atual do mundo
 world->save( fileName );
} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/

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
    
    void halfPathLeft() {
        turnAround();
        halfPathRight();
        turnAround();
    }
    
    void halfPathRight(){
        moveN(3);
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
    
    void turnAround(){
        turnLeft();
        turnLeft();
    }
    
    void below(){
        turnLeft();
        move();
        turnLeft();
    }
    
    void above(){
        turnRight();
        move();
        turnRight();
    }
};

int main() {
    world->create("");
    decorateWorld("Guia03E2.txt");
    world->show();
    world->reset();
    world->read("Guia03E2.txt");
    world->show();
    set_Speed(1);

    MyRobot *robot1 = new MyRobot();
    MyRobot *robot2 = new MyRobot();

    robot1->create(8, 5, WEST, 0, "Jarel");
    robot2->create(2, 6, EAST, 0, "Karel");

// ações para os robôs
    robot1->halfPathRight();
    robot1->halfPathRight();
    robot1->pegar();
    robot1->pegar();
    robot1->turnAround();
    robot1->halfPathRight();
    robot1->below();
    robot1->largar();
    robot1->largar();
    robot1->halfPathRight();
    
    robot2->halfPathRight();
    robot2->pegar();
    robot2->pegar();
    robot2->turnRight();
    robot2->move();
    robot2->turnLeft();
    robot2->halfPathRight();
    robot2->largar();
    robot2->largar();
    
    robot2->turnAround();
    robot2->halfPathRight();
    robot2->above();
    robot2->halfPathRight();
    robot2->pegar();
    robot2->turnAround();
    robot2->halfPathRight();
    robot2->largar();
    robot2->turnLeft();
    robot2->move();
    robot2->turnRight();
    robot2->moveN(3);
    robot2->turnAround();
    
    robot1->halfPathLeft();
    robot1->pegar();
    robot1->halfPathRight();
    robot1->largar();
    robot1->turnAround();
    robot1->halfPathRight();
    robot1->halfPathRight();
    robot1->turnAround();
    
    world->close();
    getchar();
    return 0;
}
