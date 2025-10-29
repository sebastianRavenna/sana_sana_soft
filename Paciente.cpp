#include <iostream>
#include <cstring>
#include "Paciente.h"
#include "Funciones.h"
#include "ArchivoPaciente.h"
using namespace std;

ArchivoPaciente arcPac;

Paciente::Paciente() : Persona(){
    strcpy(_idPaciente, "P-00000000");
    _idObraSocial=0;
}

string Paciente::getIdPaciente() const{
    return _idPaciente;
}

int Paciente::getIdObraSocial(){
    return _idObraSocial;
}

void Paciente::setIdObraSocial(int idObraSocial){
    _idObraSocial=idObraSocial;
}

void Paciente::setIdPaciente(const string &idPaciente){
    strncpy(_idPaciente, idPaciente.c_str(), sizeof(_idPaciente) - 1);
    _idPaciente[sizeof(_idPaciente) - 1] = '\0';
}

void Paciente::cargar(){
    cout << "DNI: " << endl;
    setDNI(cargarCadena());
    setIdPersona(getDNI());
    cout << endl;

    string idPac = "P-" + getDNI();
    setIdPaciente(idPac);

    if (arcPac.buscarPaciente(getDNI())>=0){
        cout<<"Ya existe el usuario."<<endl;
        //return false;
    }else{
    Persona::cargar();

    cout<<"Obra Social: ";
    cin >> _idObraSocial;
    cin.ignore();
    cout << endl;

    arcPac.guardarPaciente(*this);
    }
}

void Paciente::mostrar(){
    Persona::mostrar();
    cout << "Obra Social: " << getIdObraSocial() << endl;
    cout << "Id Paciente: " << getIdPaciente() << endl;
    cout <<"======================" << endl;
}
