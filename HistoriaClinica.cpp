#include <iostream>
#include <cstring>
#include "HistoriaClinica.h"
#include "Funciones.h"
#include "ArchivoHistoriaClinica.h"
#include "Fecha.h"

using namespace std;

//constructor
HistoriaClinica::HistoriaClinica(){
    _idHistoria = 0;
    strcpy(_dniPaciente, "P-00000000");
    strcpy(_idMedico, "M-00000000" );
    _fechaConsulta = Fecha();
    strcpy(_descripcion,"SinDescripcion");
    _estado = true;
}

int HistoriaClinica::getIdHistoria(){
    return _idHistoria;
}

std::string HistoriaClinica::getDniPaciente() const {
    return _dniPaciente;
}

Fecha HistoriaClinica::getFechaConsulta(){
    return _fechaConsulta;
}

std::string HistoriaClinica::getIdMedico()const{
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

void HistoriaClinica::setDniPaciente(const std::string &dniPaciente) {
    strncpy(_dniPaciente, dniPaciente.c_str(), sizeof(_dniPaciente) - 1);
    _dniPaciente[sizeof(_dniPaciente) - 1] = '\0';
}

void HistoriaClinica::setIdMedico(const std::string &idMed){
    strncpy(_idMedico, idMed.c_str(), sizeof(_idMedico) - 1);
    _idMedico[sizeof(_idMedico) - 1] = '\0';
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
    cout<<"DNI Paciente: "<<getDniPaciente()<<endl;
    cout<<"ID Medico: "<<getIdMedico()<<endl;
    cout<<"Fecha de Consulta: ";
    getFechaConsulta().Mostrar();
    cout<<"Descripcion: "<<getDescripcion()<<endl;
    /*cout<<"Estado: ";
    if(getEstado()){
        cout<< "Activo"<<endl;
    }
    else{
        cout<<"Inactivo"<<endl;
    }
    cout<<endl;*/

}

void HistoriaClinica::mostrarxPaciente(const std::string &nombreMedico, const std::string &sexoMedico){
    cout<<"ID Historia Clinica: "<<getIdHistoria()<<endl;
    if(sexoMedico == "F"){
        cout<<"Atendido por la Dra. "<<nombreMedico<<" (ID: "<<getIdMedico()<<")"<<endl;
    }
    else{
        cout<<"Atendido por el Dr. "<<nombreMedico<<" (ID: "<<getIdMedico()<<")"<<endl;
    }
    cout<<"Fecha de Consulta: ";
    getFechaConsulta().Mostrar();
    cout<<"Descripcion: "<<getDescripcion()<<endl;
   // cout<<"Estado "<<getEstado()<<endl;


}

void HistoriaClinica::cargar(const std::string &idPac, const std::string &idMed){

    Fecha fechaCons;
    std::string descrip;
    bool esValido = false;

    //cout<<"DNI Paciente: ";
    setDniPaciente(idPac);
    //cout << endl;

    //cout<<"ID Medico: ";
    setIdMedico(idMed);
    //cout << endl;

    cout<<"Fecha: "<< endl;
    do{
    fechaCons.Cargar();
    esValido = fechaCons.verificarFecha();
    }
    while(esValido == false);

    setFechaConsulta(fechaCons);
    cout << endl;

    cout<<"Descripcion: ";
    setDescripcion(cargarCadena());
    cout << endl;


    _estado=true;
}

/*void HistoriaClinica::abmLogica(HistoriaClinica &his){
    if(his.getEstado()){
        his.setEstado(false);
    }
    else{
        his.setEstado(true);
    }
}*/

