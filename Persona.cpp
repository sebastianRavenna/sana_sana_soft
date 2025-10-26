#include <iostream>
#include <cstring>
#include <string>
#include "Persona.h"
#include "Funciones.h"
using namespace std;

Persona::Persona()
{
    strcpy(_idPersona, "00000000");
    strcpy(_DNI, "00000000");
    strcpy(_nombre, "SinNombre");
    strcpy(_apellido, "SinApellido");
    strcpy(_domicilio, "SinDomicilio");
    strcpy(_mail, "sinmail@ejemplo.com");
    strcpy(_telefono, "0000000000");
    strcpy(_sexo, "N");
    fechaNac = Fecha();
    fechaIngreso = Fecha();
    _estado = true;
}


void Persona::cargar(){
/*cout << "ID de persona: " << endl;
cin >> _idPersona;
cin.ignore();
cout << endl;
*/
cout << "DNI: " << endl;
setDNI(cargarCadena());
setIdPersona(getDNI());
cout << endl;

cout << "Nombre: " << endl;
setNombre(cargarCadena());
cout << endl;

cout << "Apellido: " << endl;
setApellido(cargarCadena());
cout << endl;


cout << "Domicilio: " << endl;
setDomicilio(cargarCadena());
cout << endl;


cout << "Mail: " << endl;
setMail(cargarCadena());
cout << endl;

cout << "Telefono: " << endl;
setTelefono(cargarCadena());
cout << endl;

cout << "Sexo (M/F): " << endl;
setSexo(cargarCadena());
cout << endl;

cout << "Fecha de nacimiento: " << endl;
fechaNac.Cargar();
cout << endl;

cout << "Fecha de Ingreso: " << endl;
fechaIngreso.Cargar();
cout << endl;

_estado=true;

cout.flush();
}



void Persona::mostrar() {
    cout << "ID: " << getIdPersona() << endl;
    cout << "DNI: " << getDNI() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Apellido: " << getApellido() << endl;
    cout << "Domicilio: " << getDomicilio() << endl;
    cout << "Mail: " << getMail() << endl;
    cout << "Telefono: " << getTelefono() << endl;
    cout << "Sexo: " << getSexo() << endl;
    cout << "Fecha de nacimiento: ";
    fechaNac.Mostrar();
    cout << "Edad: "<<getEdad()<<endl;
    cout << "Fecha de ingreso: ";
    fechaIngreso.Mostrar();
    getAntiguedad();

    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
}

string Persona::getIdPersona()const{
    return _idPersona;
}
string Persona::getDNI()const{
    return _DNI;
}
string Persona::getNombre()const{
    return string (_nombre);//por qu‚ ponemos string y parentesis?
}
string Persona::getApellido()const{
    return string (_apellido);
}
string Persona::getDomicilio()const{
    return string (_domicilio);
}
string Persona::getMail()const{
    return string (_mail);
}
string Persona::getTelefono()const{
    return string (_telefono);
}
string Persona::getSexo()const{
    return string (_sexo);
}
/*
string Persona::getNombreCompleto()const{

}
*/
Fecha Persona::getFechaNac(){
    return fechaNac;
}
Fecha Persona::getFechaIngreso(){
    return fechaIngreso;
}
bool Persona::getEstado(){
    return _estado;
}

int Persona::getEdad(){
    int edad;
    Fecha hoy;
    hoy.fechaActual();
    edad = hoy.calcularEdad(fechaNac);
    return edad;
}

void Persona::getAntiguedad(){
    Fecha hoy;
    hoy.fechaActual();
    int anios, meses;
    anios = hoy.calcularAntiguedad(fechaIngreso)/12;
    meses = hoy.calcularAntiguedad(fechaIngreso)%12;
    cout<<"Antiguedad: "<<anios<<" Anios y "<<meses<<" Meses."<<endl;
}


void Persona::setDNI(const string &dni){
strncpy(_DNI, dni.c_str(), sizeof(_DNI) - 1);
_DNI[sizeof(_DNI) - 1] = '\0';
}

void Persona::setIdPersona(const string &idPersona){
strncpy(_idPersona, idPersona.c_str(), sizeof(_idPersona) - 1);
_idPersona[sizeof(_idPersona) - 1] = '\0';
}

void Persona::setNombre(const string &nombre){
    strncpy(_nombre,nombre.c_str(),sizeof(_nombre)-1);
    _nombre[sizeof(_nombre)-1]= '\0';
}
void Persona::setApellido(const string &apellido){
    strncpy(_apellido,apellido.c_str(),sizeof(_apellido)-1);
    _apellido[sizeof(_apellido)-1]= '\0';
}
void Persona::setDomicilio(const string &domicilio){
    strncpy(_domicilio,domicilio.c_str(),sizeof(_domicilio)-1);
    _domicilio[sizeof(_domicilio)-1]= '\0';
}
void Persona::setMail(const string &mail){
    strncpy(_mail,mail.c_str(),sizeof(_mail)-1);
    _mail[sizeof(_mail)-1]= '\0';
}
void Persona::setTelefono(const string &telefono){
    strncpy(_telefono,telefono.c_str(),sizeof(_telefono)-1);
    _telefono[sizeof(_telefono)-1]= '\0';
}
void Persona::setSexo(const string &sexo){
    strncpy(_sexo,sexo.c_str(),sizeof(_sexo)-1);
    _sexo[sizeof(_sexo)-1]= '\0';
}
void Persona::setFechaNac (Fecha f){
    fechaNac=f;
}
void Persona::setFechaIngreso(Fecha f){
    fechaIngreso=f;
}

void Persona::setEstado(bool estado){
    _estado=estado;
}




