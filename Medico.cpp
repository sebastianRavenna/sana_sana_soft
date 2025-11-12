#include <iostream>
#include <cstring>
#include "Medico.h"
#include "Funciones.h"
#include "ArchivoMedico.h"
using namespace std;

ArchivoMedico archivoMedico;

Medico::Medico() : Persona(){
   strcpy (_idMedico,"M-00000000");
   _codEspecialidad=0;
   _matricula=0;
}

string Medico::getIdMedico()const{
    return _idMedico;
}

int Medico::getCodEspecialidad(){
    return _codEspecialidad;
}

int Medico::getMatricula(){
    return _matricula;
}

void Medico::setIdMedico(const string &idMedico){
    strncpy(_idMedico,idMedico.c_str(), sizeof(_idMedico)-1);
    _idMedico[sizeof(_idMedico)-1]= '\0';
}


void Medico::setCodEspecialidad(int codEspecialidad){
    _codEspecialidad=codEspecialidad;
}

void Medico::setMatricula(int matricula){
    _matricula=matricula;
}

void Medico::cargar(){
    cout << "DNI: " << endl;
    setDNI(cargarCadena());
    setIdPersona(getDNI());
    cout << endl;

    string idMed = "M-" + getDNI();
    setIdMedico(idMed);

    if(archivoMedico.buscarRegistro(getDNI())>=0){
        cout << "Ya existe el usuario." << endl;
    }
    else{
    Persona::cargar();

    cout << "Cod de Especialidad: " << endl;
    cin >> _codEspecialidad;
    cin.ignore();
    cout << endl;

    cout << "Matricula: " << endl;
    cin >> _matricula;
    cin.ignore();
    cout << endl;
archivoMedico.guardarMedico(*this);
}
}
void Medico::mostrar(){
    cout << "Id Medico: " << getIdMedico() << endl;
    Persona::mostrar();
    cout << "Cod. Especialidad: " << getCodEspecialidad() << endl;
    cout << "Matricula: " << getMatricula() << endl;
    cout <<"======================" << endl;
}
