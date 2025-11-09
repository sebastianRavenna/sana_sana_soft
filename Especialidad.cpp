#include <iostream>
#include <cstring>
#include "Especialidad.h"
#include "Funciones.h"
using namespace std;

Especialidad::Especialidad()
{
   _codEspecialidad=0;
   strcpy(_descripcion,"Sin descripcion");
   _valorConsulta=0;
   _estado=true;
}
void Especialidad::cargar(){
/*cout << "Codigo de especialidad: " << endl;
cin >>_codEspecialidad;
cin.ignore();
cout << endl;*/

cout << "Descripcion: ";
setDescripcion(cargarCadena());
cout << endl;

cout << "Valor de la consulta: ";
cin >> _valorConsulta;
cin.ignore();
cout << endl;

_estado=true;

}
void Especialidad::mostrar(){
cout << "Especialidad: " << getCodEspecialidad() << endl;
cout << "Descripcion: " << getDescripcion() << endl;
cout << "Valor de la consulta: " << getValorConsulta() << endl;
cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;

}

int Especialidad::getCodEspecialidad(){
    return _codEspecialidad;
}

string Especialidad::getDescripcion()const{
return string (_descripcion);
}

float Especialidad::getValorConsulta(){
return _valorConsulta;
}

bool Especialidad::getEstado(){
return _estado;
}

void Especialidad::setCodEspecialidad(int codEspecialidaad){
_codEspecialidad=codEspecialidaad;
}

void Especialidad::setDescripcion(const std::string &descripcion){
strncpy(_descripcion,descripcion.c_str(),sizeof(_descripcion)-1);
    _descripcion[sizeof(_descripcion)-1]= '\0';
}

void Especialidad::setValorConsulta(float valor){
_valorConsulta=valor;
}

void Especialidad::setEstado(bool estado){
_estado=estado;
}
