#include <iostream>
#include <cstring>
#include "Factura.h"
#include "Fecha.h"

using namespace std;

Factura::Factura(){
        _idFactura = 0; // Ver como hacer para que aumente de forma automatica
        _idMedico = 0;
        _codEspecialidad = 0;
        _fechaFactura = Fecha();
        strcpy(_dniPaciente, "00000000");
        strcpy(_tipoFactura, "X");
        _importe = 0.0;
        _estado = true;
}

int Factura::getIdFactura(){
    return _idFactura;
}

int Factura::getIdMedico(){
    return _idMedico;
}

int Factura::getCodEspecialidad(){
    return _codEspecialidad;
}

Fecha Factura::getFechaFactura(){
    return _fechaFactura;
}

string Factura::getDniPaciente()const{
    return _dniPaciente;
}

string Factura::getTipoFactura()const{
    return _tipoFactura;
}

float Factura::getImporte(){
    return _importe;
}

bool Factura::getEstado(){
    return _estado;
}

void Factura::setIdFactura(int idFactura){
    _idFactura = idFactura;
}

void Factura::setIdMedico(int idMedico){
    _idMedico = idMedico;
}

void Factura::setCodEspecialidad(int codEspecialidad){
    _codEspecialidad = codEspecialidad;
}

void Factura::setFechaFactura(Fecha f){
    _fechaFactura = f;
}

void Factura::setDniPaciente(const std::string &dniPaciente){
    strncpy(_dniPaciente, dniPaciente.c_str(), sizeof(_dniPaciente) - 1);
    _dniPaciente[sizeof(_dniPaciente) - 1] = '\0';
}

void Factura::setTipoFactura(const std::string &tipoFactura){
    strncpy(_tipoFactura, tipoFactura.c_str(), sizeof(_tipoFactura)-1);
    _tipoFactura[sizeof(_tipoFactura)-1]= '\0';
}

void Factura::setImporte(float importe){
    _importe = importe;
}

void Factura::setEstado(bool estado){
    _estado = estado;
}

void Factura::mostrar(){
    cout<<"ID Factura: "<< getIdFactura() <<endl;
    cout<<"Tipo de Factura: "<< getTipoFactura() <<endl;
    cout<<"Fecha: ";
    getFechaFactura().Mostrar();
    cout<<endl;
    cout<<"DNI Paciente: "<< getDniPaciente() <<endl;
    cout<<"ID Medico: "<< getIdMedico() <<endl;
    cout<<"Codigo de Especialidad: "<< getCodEspecialidad() <<endl;
    cout<<"Importe: "<< getImporte()<<endl;
    cout<<"Estado: "<< getEstado()<<endl;
}


void Factura::cargar(){
    int idFact, idMed, codEsp;
    float imp;
    std::string tipoFac, dniPac;
    bool est;
    Fecha fechaAux;

    cout<<"ID Factura: "<<endl; // Ver como hacer para que aumente de forma automatica
    cin>>idFact;
    setIdFactura(idFact);
    cout<<"Tipo de Factura: "<<endl;
    cin>>tipoFac;
    setTipoFactura(tipoFac);
    cout<<"Fecha: "<<endl;
    fechaAux.Cargar();
    setFechaFactura(fechaAux);
    cout<<endl;
    cout<<"DNI Paciente: "<<endl;
    cin>>dniPac;
    setDniPaciente(dniPac);
    cout<<"ID Medico: "<<endl;
    cin>>idMed;
    setIdMedico(idMed);
    cout<<"Codigo de Especialidad: "<<endl;
    cin>>codEsp;
    setCodEspecialidad(codEsp);
    cout<<"Importe: "<<endl;
    cin>>imp;
    setImporte(imp);
    cout<<"Estado: "<<endl;
    cin>>est;
    setEstado(est);
}
