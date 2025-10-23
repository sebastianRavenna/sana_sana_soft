#include <iostream>
#include <cstring>
#include "HistoriaClinica.h"
#include "Funciones.h"

using namespace std;

HistoriaClinica::HistoriaClinica(){
    _idHistoria = 0;
    _idPaciente = 0;
    _idMedico = 0;
    _fechaConsulta = Fecha();
    strcpy(_descripcion,"SinDescripcion");
    _estado = true;
}

int HistoriaClinica::getIdHistoria(){
    return _idHistoria;
}

int HistoriaClinica::getIdPaciente(){
    return _idPaciente;
}

Fecha HistoriaClinica::getFechaConsulta(){
    return _fechaConsulta;
}

int HistoriaClinica::getIdMedico(){
    return _idMedico;
}

std::string HistoriaClinica::getDescripcion()const{
    return _descripcion;
}

bool HistoriaClinica::getEstado(){
    return _estado;
}

void HistoriaClinica::setIdHistoria(int idHistoria){
    _idHistoria = idHistoria;
}

void HistoriaClinica::setIdPaciente(int idPaciente){
    _idPaciente = idPaciente;
}

void HistoriaClinica::setIdMedico(int idMedico){
    _idMedico = idMedico;
}

void HistoriaClinica::setFechaConsulta(Fecha f){
    _fechaConsulta = f;
}

void HistoriaClinica::setDescripcion(const std::string &descripcion){
    strncpy(_descripcion, descripcion.c_str(), sizeof(_descripcion) - 1);
    _descripcion[sizeof(_descripcion) - 1] = '\0';
}

void HistoriaClinica::setEstado(bool estado){
    _estado = estado;
}

void HistoriaClinica::mostrar(){
    cout<<"ID Historia Clinica: "<<getIdHistoria()<<endl;
    cout<<"ID Paciente: "<<getIdPaciente()<<endl;
    cout<<"ID Medico: "<<getIdMedico()<<endl;
    cout<<"Fecha: ";
    getFechaConsulta().Mostrar();
    cout<<endl;
    cout<<"Descripcion: "<<getDescripcion()<<endl;
    cout<<"Estado: ";
    if(getEstado()){
        cout<< "Activo"<<endl;
    }
    else{
        cout<<"Inactivo"<<endl;
    }
    cout<<endl;

}

void HistoriaClinica::cargar(){
    int idHC, idPac, idMed;
    Fecha fechaCons;
    std::string descrip;
    bool est;

    cout<<"ID Historia Clinica: ";
    cin>>idHC;
    setIdHistoria(idHC);
    cout << endl;

    cout<<"ID Paciente: ";
    cin>>idPac;
    setIdPaciente(idPac);
    cout << endl;

    cout<<"ID Medico: ";
    cin>>idMed;
    setIdMedico(idMed);
    cout << endl;

    cout<<"Fecha: ";
    fechaCons.Cargar();
    setFechaConsulta(fechaCons);
    cout << endl;

    cout<<"Descripcion: ";
    setDescripcion(cargarCadena());
    cout << endl;

    _estado=true;
}


