#include <iostream>
#include <cstring>
#include "Turno.h"
using namespace std;


Turno::Turno()
{
    _idTurno=0;
    _idAgenda=0;
    strcpy(_idPaciente, "P-00000000");
    strcpy(_idMedico, "M-00000000");
    _codEspecialidad=0;
    _estado=true;

}

Turno::Turno(int idTurno, int idAgenda, const string &idPaciente,
             const string &idMedico, int codEsp, Fecha fecha, Hora hora) {
    _idTurno = idTurno;
    _idAgenda = idAgenda;
    strncpy(_idPaciente, idPaciente.c_str(), sizeof(_idPaciente) - 1);
    _idPaciente[sizeof(_idPaciente) - 1] = '\0';
    strncpy(_idMedico, idMedico.c_str(), sizeof(_idMedico) - 1);
    _idMedico[sizeof(_idMedico) - 1] = '\0';
    _fechaTurno = fecha;
    _horaTurno = hora;
    _codEspecialidad = codEsp;
    _estado = true;
}

int Turno::getIdTurno(){
    return _idTurno;
}

int Turno::getIdAgenda(){
    return _idAgenda;
}

string Turno::getIdPaciente() const {
    return string(_idPaciente);
}

Fecha Turno::getFechaTurno(){
    return _fechaTurno;
}

Hora Turno::getHoraTurno(){
    return _horaTurno;
}

string Turno::getIdMedico() const {
    return string(_idMedico);
}

int Turno::getCodEspecialidad(){
    return _codEspecialidad;
}

bool Turno::getEstado(){
    return _estado;
}


void Turno::setIdTurno(int idTurno){
    _idTurno=idTurno;
}

void Turno::setIdAgenda(int idAgenda){
    _idAgenda=idAgenda;
}

void Turno::setIdPaciente(const string &idPaciente) {
    strncpy(_idPaciente, idPaciente.c_str(), sizeof(_idPaciente) - 1);
    _idPaciente[sizeof(_idPaciente) - 1] = '\0';
}

void Turno::setFechaTurno(Fecha fecha){
    _fechaTurno=fecha;
}

void Turno::setHoraTurno(Hora hora){
    _horaTurno=hora;
}

void Turno::setIdMedico(const string &idMedico) {
    strncpy(_idMedico, idMedico.c_str(), sizeof(_idMedico) - 1);
    _idMedico[sizeof(_idMedico) - 1] = '\0';
}

void Turno::setCodEspecialidad(int codEsp){
    _codEspecialidad=codEsp;
}

void Turno::setEstado(bool estado){
    _estado=estado;
}


void Turno::cargarTurno(){

cout << "ID Paciente: " << endl;
string idPac;
cin >> idPac;
setIdPaciente(idPac);

cout << "ID Agenda: " << endl;
cin >> _idAgenda;

cout << "ID TURNO: " << endl;
cin >> _idTurno;

_estado=true;

}

void Turno::mostrarTurno(){

   cout << "ID Turno: " << _idTurno << endl;
    cout << "ID Paciente: " << _idPaciente << endl;
    cout << "ID Medico: " << _idMedico << endl;
    cout << "Cod. Especialidad: " << _codEspecialidad << endl;
    cout << "Fecha: ";
    _fechaTurno.Mostrar();
    cout << "Hora: ";
    _horaTurno.Mostrar();
    cout << "Estado: " << (_estado ? "ACTIVO" : "CANCELADO") << endl;
    cout << "========================================" << endl;
}
