#include "Paciente.h"

Paciente::Paciente() : Persona(){
_idPaciente=0;
_idObraSocial=0;
}




int Paciente::getIdPaciente(){
return _idPaciente;
}

int Paciente::getIdObraSocial(){
return _idObraSocial;
}

void Paciente::setIdPaciente(int idPaciente){
_idPaciente=idPaciente;
}

void Paciente::setIdObraSocial(int idObraSocial){
_idObraSocial=idObraSocial;
}

void Paciente::cargar(){
    Persona::cargar();

}

void Paciente::mostrar(){
    Persona::mostrar();
}
