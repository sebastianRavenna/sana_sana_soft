#include <iostream>
#include <cstring>
#include "Medico.h"
#include "Funciones.h"
#include "ArchivoMedico.h"
#include "Especialidad.h"
#include "ArchivoEspecialidad.h"
using namespace std;

ArchivoMedico archivoMedico;
ArchivoEspecialidad archivoEspecialidad;

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

void Medico::cargar(std::string &idMedico){
    //cout << "DNI: ";
    setDNI(idMedico);
    setIdPersona(getDNI());
    cout << endl;

    string idMed = "M-" + getDNI();
    setIdMedico(idMed);

    //if(archivoMedico.buscarRegistro(getDNI())>=0){
     //   cout << "Ya existe el usuario." << endl;
    //}
   // else{
    Persona::cargar();

    int codEspecialidad;
    cout << "Cod de Especialidad: ";
    cin >> codEspecialidad;

    while(archivoEspecialidad.buscarRegistro(codEspecialidad) < 0){
        cout<<"El codigo de especialidad ingresado no existe. Por favor, vuelva a intentarlo..."<<endl;
        cout << "Cod de Especialidad: ";
        cin >> codEspecialidad;
    }

    setCodEspecialidad(codEspecialidad);
    cin.ignore();
    cout << endl;

    int matricula;
    cout << "Matricula: ";
    cin >> matricula;
    while(archivoMedico.buscarPorMatricula(matricula) >= 0){
        cout<<"La matricula ingresada ya esta registrada. Por favor, vuelva a intentarlo..."<<endl;
        cout << "Matricula: ";
        cin >> matricula;
    }
    setMatricula(matricula);
    cin.ignore();
    cout << endl;
}
//}
void Medico::mostrar(){
    cout << "Id Medico: " << getIdMedico() << endl;
    Persona::mostrar();
    cout << "Cod. Especialidad: " << getCodEspecialidad() << endl;
    cout << "Matricula: " << getMatricula() << endl;
    cout <<"======================" << endl;
}
