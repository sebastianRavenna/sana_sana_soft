#include <iostream>
#include "Turno.h"
using namespace std;


Turno::Turno()
{
_idPaciente=0;
_idAgenda=0;
_estado=true;

}

int Turno::getIdTurno(){
return _idTurno;
}

int Turno::getAgenda(){
return _idAgenda;
}

int Turno::getPaciente(){
return _idPaciente;
}

bool Turno::getEstado(){
return _estado;
}


void Turno::setIdTurno(int idturno){
_idTurno=idturno;
}

void Turno::setAgenda(int idagenda){
_idAgenda=idagenda;
}

void Turno::setIdPaciente(int idPaciente){
_idPaciente=idPaciente;
}

void Turno::setEstado(bool estado){
_estado=estado;
}


void Turno::cargarTurno(){

cout << "ID Paciente: " << endl;
cin >> _idPaciente;
cout << "ID Agenda: " << endl;
cin >> _idAgenda;
cout << "ID TURNO: " << endl;
cin >> _idTurno;

_estado=true;

}

void Turno::mostrarTurno(){
    cout << "ID Paciente:  " << getPaciente();
    cout << endl;
    cout << "ID Agenda:  " << getAgenda();
    cout << endl;
    cout << "ID Turno: " << getIdTurno();
}
