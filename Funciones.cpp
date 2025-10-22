#include<string>
#include<iostream>
#include"Funciones.h"
using namespace std;

std::string cargarCadena(){
std::string texto;

if (std::cin.peek()== '\n'){
    std::cin.ignore();
}

std::getline(std::cin,texto);

return texto;

}
