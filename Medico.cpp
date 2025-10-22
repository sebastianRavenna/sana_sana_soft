#include <iostream>
#include <cstring>
using namespace std;
#include "Medico.h"

Medico::Medico() : Persona(){

}

int Medico::getIdMedico(){
    return _idMedico;
}

int Medico::getIdObraSocial(){
    return _idObraSocial;
}

int Medico::getCodEspecialidad(){
    return _codEspecialidad;
}

int Medico::getMatricula(){
    return _matricula;
}

void Medico::setIdMedico(int idMedico){
    _idMedico=idMedico;
}

void Medico::setIdObraSocial(int idObraSocial){
    _idObraSocial=idObraSocial;
}

void Medico::setCodEspecialidad(int codEspecialidad){
    _codEspecialidad=codEspecialidad;
}

void Medico::setMatricula(int matricula){
    _matricula=matricula;
}

void Medico::cargar(){
    Persona::cargar();

    cout << "ID de Medico: " << endl;
    cin >> _idMedico;
    cin.ignore();
    cout << endl;

    cout << "ID de Obra Social: " << endl;
    cin >> _idObraSocial;
    cin.ignore();
    cout << endl;

    cout << "Cod de Especialidad: " << endl;
    cin >> _codEspecialidad;
    cin.ignore();
    cout << endl;

    cout << "Matricula: " << endl;
    cin >> _matricula;
    cin.ignore();
    cout << endl;

}

void Medico::mostrar(){
    Persona::mostrar();
}
