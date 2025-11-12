#include <iostream>
#include <cstring>
#include "Agenda.h"
using namespace std;


Agenda::Agenda()
{
    _idAgenda=0;
     strcpy(_idMedico, "M-00000000");
    _codEspecialidad=0;
    _asignado=false;
    _estado=true;

}

Agenda::Agenda(const string &idMedico,int codEsp,Fecha fecha, Hora hora){
    _idAgenda=0;
    strncpy(_idMedico, idMedico.c_str(), sizeof(_idMedico) - 1);
    _idMedico[sizeof(_idMedico) - 1] = '\0';
    _codEspecialidad=codEsp;
    _fechaTurno=fecha;
    _horaTurno=hora;
    _asignado=false,
    _estado=true;

  }

int Agenda::getIdAgenda(){
    return _idAgenda;
}

string Agenda::getIdMedico() const {
    return string(_idMedico);
}

int Agenda::getCodEspecialidad(){
    return _codEspecialidad;
}

Fecha Agenda::getFechaTurno(){
    return _fechaTurno;
}

Hora Agenda::getHoraTurno(){
    return _horaTurno;
}

bool Agenda::getAsignado(){
    return _asignado;
}

bool Agenda::getEstado(){
    return _estado;
}

void Agenda::setIdAgenda(int idAgenda){
    _idAgenda=idAgenda;
}

void Agenda::setIdMedico(const string &idMedico) {
    strncpy(_idMedico, idMedico.c_str(), sizeof(_idMedico) - 1);
    _idMedico[sizeof(_idMedico) - 1] = '\0';
}

void Agenda::setCodEspecialidad(int codEspecilidad){
    _codEspecialidad=codEspecilidad;
}

void Agenda::setFechaTurno(Fecha fechaturno){
    _fechaTurno=fechaturno;
}

void Agenda::setHoraTurno(Hora hora){
    _horaTurno=hora;
}

void Agenda::setAsignado(bool asignado){
    _asignado=asignado;
}

void Agenda::setEstado(bool estado){
    _estado=estado;
}

void Agenda::cargarAgenda(){
    cout << "=== CARGAR AGENDA ===" << endl;
    cout << "ID Medico: " << endl;
    string idMed;
    cin >> idMed;
    setIdMedico(idMed);
    cout << "ID Cod.Especialidad: " << endl;
    cin >> _codEspecialidad;
    cout << "Ingrese Fecha de la Agenda a Abrir:" << endl;
    _fechaTurno.Cargar();
    cout << "Ingrese Hora del Turno:" << endl;
    _horaTurno.Cargar();

    _asignado=false;
    _estado=true;
}

void Agenda::mostrarAgenda(){
    cout << "ID Agenda: " << getIdAgenda()<< endl;
    cout << "ID Medico: " << getIdMedico()<< endl;
    cout << "ID Cod.Especialidad: " << getCodEspecialidad()<< endl;
    cout << "Fecha:";
    _fechaTurno.Mostrar();
    cout << "Hora: ";
    _horaTurno.Mostrar();
    cout << "Asignado: " << (_asignado ? "OCUPADO" : "DISPONIBLE") << endl;

    cout << "Estado: " << (_estado ? "DISPONIBLE" : "SUSPENDIDO") << endl;
    cout << "========================================" << endl;
}
