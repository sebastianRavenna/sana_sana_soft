#include <iostream>
#include <string>
#include "ArchivoObraSocial.h"
#include "Funciones.h"
using namespace std;
ArchivoObraSocial::ArchivoObraSocial(const string &nombreArchivo)
{
    _nombreArchivo=nombreArchivo;
    tamanioRegistro=sizeof(ObraSocial);
}

bool ArchivoObraSocial::agregarRegistro(const ObraSocial &reg){
FILE *pObraSocial;
pObraSocial=fopen(_nombreArchivo.c_str(),"ab");

if(pObraSocial==NULL){
    return false;
}
 fwrite(&reg,tamanioRegistro,1,pObraSocial);

 cout << "Guardado exitoso" << endl;
 fclose(pObraSocial);
 return true;
}

ObraSocial ArchivoObraSocial::leerObraSocial(int posicion){
ObraSocial reg;
FILE *pObraSocial;

pObraSocial=fopen(_nombreArchivo.c_str(),"rb");
if(pObraSocial==NULL){
    cout << "ERROR EN EL ARCHIVO" << endl;
    return reg;
}
fseek(pObraSocial,tamanioRegistro * posicion,0);
fread(&reg,tamanioRegistro,1,pObraSocial);

fclose(pObraSocial);
return reg;
}

bool ArchivoObraSocial::leerRegistro(int posicion, ObraSocial &reg){

FILE *pObraSocial;
pObraSocial=fopen(_nombreArchivo.c_str(),"rb");

if(pObraSocial==NULL){
    return false;
}
fseek(pObraSocial,tamanioRegistro*posicion,SEEK_SET);
if(fread(&reg,tamanioRegistro,1,pObraSocial)!=1){
    fclose(pObraSocial);
    return false;
}
fclose(pObraSocial);
return true;
}

int ArchivoObraSocial::buscarObraSocial(const string &nombreObraSocial){
ObraSocial reg;
FILE *pObraSocial;

pObraSocial=fopen(_nombreArchivo.c_str(),"rb");
if(pObraSocial==NULL){
    return -2;
}
int pos=0;
while(fread(&reg,tamanioRegistro,1,pObraSocial)==1){
    if(reg.getNombreObraSocial()== nombreObraSocial){
        return pos;
    }
    pos ++;
}
fclose (pObraSocial);
return -1;
}

int ArchivoObraSocial::contarRegistro(){
ObraSocial reg;
FILE *pObraSocial;
pObraSocial=fopen(_nombreArchivo.c_str(),"rb");

if(pObraSocial==NULL){
    return 0;
}
fseek(pObraSocial,0,SEEK_END); //puntero al final del archivo
int cantBytes= ftell(pObraSocial); //calcula la cantidad de bytes desde el inicio del archivo a la posicion actual
int cantRegistros=0;
cantRegistros=cantBytes/sizeof(ObraSocial); //dividimos el total de bytes por el tamaño de un registro

fclose(pObraSocial);
return cantRegistros;
}

bool ArchivoObraSocial::modificarObraSocial(int posicion){
ObraSocial reg;
FILE *pObraSocial;
pObraSocial=fopen(_nombreArchivo.c_str(),"rb+");
if(pObraSocial==NULL){
    cout << "ERROR EN EL ARCHIVO" << endl;
    return false;
}
fseek(pObraSocial,posicion * tamanioRegistro, 0);
fread(&reg,tamanioRegistro,1,pObraSocial);

int opcionModificar=-1;

do{
    system("cls");
    reg.mostrar();
    cout << endl;

    cout << "================================" << endl;
    cout << "   SELECCIONE QUE MODIFICAR" << endl;
    cout << "================================" << endl;
    cout << "1. Id. Obra Social" << endl;
    cout << "2. Nombre Obra Social" << endl;
    cout << "0. Volver" << endl;
    cout << "================================" << endl;
    cout << "Opcion: ";
    cin >>opcionModificar;
    cin.ignore();

    while(opcionModificar>2||opcionModificar<0){
        cout << "Numero incorrecto" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opcionModificar;
        cin.ignore();
    }

    switch (opcionModificar){
case 1:
    cout << "Ingrese nuevo ID: ";
    int idobrasocial;
    cin >> idobrasocial;
    reg.setIdObraSocial(idobrasocial);
    cout << "ID modificado exitosamente." << endl;
    break;

case 2:
    cout << "Ingrese nuevo nombre de Obra Social: ";
    reg.setNombreObraSocial(cargarCadena());
    cout << "Nombre modificado exitosamente." << endl;
    break;


    case 0:
    cout << "Volviendo al menu anterior..." << endl;
    break;

    default:
    cout << "Opcion invalida. Intente nuevamente." << endl;
    break;
    }
} while (opcionModificar!=0);

fseek(pObraSocial,posicion * tamanioRegistro,0);
fwrite(&reg,tamanioRegistro,1,pObraSocial);

fclose(pObraSocial);
return true;
}

bool ArchivoObraSocial::listarOS(){
ObraSocial reg;
FILE *pObraSocial;
pObraSocial=fopen(_nombreArchivo.c_str(),"rb");
if(pObraSocial==NULL){
cout << "ERROR EN EL ARCHIVO" << endl;
return false;
}
cout << "Listado de obras sociales: " << endl;
while (fread(&reg,tamanioRegistro,1,pObraSocial)==1){
    reg.mostrar();
}
fclose(pObraSocial);
return true;
}

bool ArchivoObraSocial::cambioEstado(const string nombreOS, int posicion){
ObraSocial reg;
bool nuevoEstado;
FILE *pObraSocial;
pObraSocial=fopen(_nombreArchivo.c_str(), "rb+");

if(pObraSocial==NULL){
    cout << "ERROR EN EL ARCHIVO" << endl;
    return false;
}
fseek(pObraSocial,posicion * tamanioRegistro,0);
fread(&reg,tamanioRegistro,1,pObraSocial);

cout << "Obra Social: " << reg.getNombreObraSocial() << endl;
cout << "Estado: " << (reg.getEstado() ? "Activo" : "Inactivo")<< " " << endl;

int opcCambio;
if(reg.getEstado()==1){
    cout << "Desea pasar la obra social a estado: INACTIVO? 1. SI - 2.NO: ";
    cin >> opcCambio;
    cin.ignore();
if(opcCambio==1){
    nuevoEstado = false;
    cout << "La obra social fue dada de baja correctamente." << endl;
}
}else {
cout << "Desea cambiar la obra social a estado: ACTIVO? " << endl;
cout << "1.SI - 2-NO.";
cin >> opcCambio;
cin.ignore();
if(opcCambio==1){
    nuevoEstado = true;
    cout << "La obra social fue dada de alta en el sistema" << endl;
}
}
reg.setEstado(nuevoEstado);

fseek(pObraSocial,posicion * tamanioRegistro,0);
fwrite (&reg, tamanioRegistro, 1, pObraSocial);

fclose (pObraSocial);
return reg.getEstado();
}
