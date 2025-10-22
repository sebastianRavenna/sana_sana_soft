#include <iostream>
#include <string>
#include "Hora.h"
using namespace std;

Hora::Hora(){
    _hora = 0;
    _minuto = 0;
}

Hora::Hora(int hora, int minuto){
    _hora = hora;
    _minuto = minuto;
}
void Hora::Cargar(){
    bool horaValida = false;

    while (!horaValida){
        cout<<"Hora ";
        cin>>_hora;
        cout<<"Minutos ";
        cin>>_minuto;
        if (_hora<1||_hora>24){
        cout<<"Indique una hora V lida entre 01 y 24"<<endl;
        }else if (_minuto<1||_minuto>60){
        cout<<"Indique minutos V lidos entre 1 y 60"<<endl;
        } else horaValida=true;
        if(!horaValida) cout<<"Intente nuevamente: "<<endl;
    }
}
int Hora::getHora(){
    return _hora;
}

int Hora::getMinuto(){
    return _minuto;
}

void Hora::setHora(int hora){
    _hora = hora;
}

void Hora::setMinuto(int minuto){
    _minuto = minuto;
}

std::string Hora::toString(){
    return std::to_string(_hora) + ":" + std::to_string(_minuto);
}
void Hora::Mostrar(){
        cout<<_hora<<":"<<_minuto<<endl;
    }
