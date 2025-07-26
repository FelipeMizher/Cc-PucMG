// 8281811 - Felipe Rivetti Mizher

/*
 Guia02E1 - v0.0. - 13 / 8 / 2023
 Author: ____Felipe Rivetti Mizher_____
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia02E1 ./Guia02E1.cpp
 No Windows: g++ -o Guia02E1 Guia02E1.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia02E1
 No Windows: Guia02E1
*/

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string fileName;
    std::cout << "Digite o nome do arquivo: ";
    std::cin >> fileName;

    std::ifstream arquivo(fileName);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    int numLinhas = 0;
    std::string linha;
    while (std::getline(arquivo, linha)) {
        numLinhas++;
    }

    arquivo.close();

    std::cout << "Número de linhas do arquivo:\n" << numLinhas << std::endl;

    return 0;
}
