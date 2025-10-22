#include <cstring>
#include <string>
#include <iostream>
#include "ObraSocial.h"
#include "Funciones.h"

using namespace std;

ObraSocial::ObraSocial(){
        _idObraSocial = 0;
        strcpy(_nombreObraSocial,"SinNombre");
        _estado = true;
}

int ObraSocial::getIdObraSocial(){
    return _idObraSocial;
}
string ObraSocial::getNombreObraSocial ()const{
    return _nombreObraSocial;
}

bool ObraSocial::getEstado(){
    return _estado;
}

void ObraSocial::setIdObraSocial(int idOS){
    _idObraSocial = idOS;
}

void ObraSocial::setNombreObraSocial(const string &nombreOS){
    strncpy(_nombreObraSocial, nombreOS.c_str(),sizeof(_nombreObraSocial)-1);
    _nombreObraSocial[sizeof(_nombreObraSocial)-1] = '\0';
}

void ObraSocial::setEstado(bool estado){
    _estado = estado;
}

void ObraSocial::cargar(){
    int id;
    string nom;
    bool est;

    cout<<"Nombre de Obra Social: ";
    setNombreObraSocial(cargarCadena());
    cout<<"ID de Obra Social: ";
    cin>>id;
    setIdObraSocial(id);
    cout<<"Estado de Obra Social (1-Activo // 0-Inactivo): ";
    cin>>est;
    setEstado(est);
    }

void ObraSocial::mostrar(){
    cout<<"Nombre de Obra Social: "<<getNombreObraSocial()<<endl;
    cout<<"ID de Obra Social: "<<getIdObraSocial()<<endl;
    cout<<"Estado de Obra Social: ";
    if(getEstado()){
        cout<< "Activo"<<endl;
    }
    else{
        cout<<"Inactivo"<<endl;
    }
}

/*bool ObraSocial::leer(){
}
bool ObraSocial::escribir(){
}*/




