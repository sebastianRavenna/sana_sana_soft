#include <iostream>
#include "Agenda.h"
using namespace std;
Agenda::Agenda()
{
_idAgenda=0;
_idMedico=0;
_codEspecialidad=0;
fechaTurno= Fecha();
horaTurno= Hora();
_asignado=true;
_estado=true;

}

Agenda::Agenda(int idAgenda,int idMedico,int codEsp,Fecha fecha, Hora hora){
    _idAgenda=idAgenda;
    _idMedico=idMedico;
    _codEspecialidad=codEsp;
    fechaTurno=fecha;
    horaTurno=hora;
    _asignado=true,
    _estado=true;

  }

int Agenda::getIdAgenda(){
return _idAgenda;
}

int Agenda::getIdMedico(){
return _idMedico;
}

int Agenda::getCodEspecialidad(){
return _codEspecialidad;
}

Fecha Agenda::getFechaTurno(){
return fechaTurno;
}

Hora Agenda::getHoraTurno(){
return horaTurno;
}

bool Agenda::getAsignado(){
return _asignado;
}

bool Agenda::getEstado(){
return _estado;
}

void Agenda::setIdMedico(int idMedico){
    _idMedico=idMedico;
}

void Agenda::setIdAgenda(int idAgenda){
    _idAgenda=idAgenda;
}

void Agenda::setCodEspecialidad(int codEspecilidad){
_codEspecialidad=codEspecilidad;
}

void Agenda::setFechaTurno(Fecha fechaturno){
fechaTurno=fechaturno;
}

void Agenda::setHoraTurno(Hora hora){
horaTurno=hora;
}

void Agenda::setAsginado(bool asignado){
_asignado=asignado;
}

void Agenda::setEstado(bool estado){
_estado=estado;
}

void Agenda::cargarAgenda(){
cout << "ID Agenda: " << endl;
cin >> _idAgenda;
cout << "ID Medico: " << endl;
cin >> _idMedico;
cout << "ID Cod.Especialidad: " << endl;
cin >> _codEspecialidad;
fechaTurno.Cargar();
horaTurno.Cargar();

_asignado=true;
_estado=true;
}

void Agenda::mostrarAgenda(){
    cout << "ID Agenda: " << getIdAgenda();
    cout << "ID Medico: " << getIdMedico();
    cout << "ID Cod.Especialidad: " << getCodEspecialidad();

    fechaTurno.Mostrar();
    horaTurno.Mostrar();
    cout << "Estado: " << (_asignado ? "Activo" : "Inactivo") << endl;
}
