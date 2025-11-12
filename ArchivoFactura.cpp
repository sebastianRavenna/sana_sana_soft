#include <iostream>
#include<string>
#include "Funciones.h"
#include "ArchivoFactura.h"

using namespace std;

ArchivoFactura::ArchivoFactura(const string &nombreArchivo)
{
    _nombreArchivo=nombreArchivo;
    tamanioRegistro=sizeof(Factura);
}

bool ArchivoFactura::agregarRegistro(const Factura &reg){
FILE *pFactura;
pFactura=fopen(_nombreArchivo.c_str(),"ab");

if(pFactura==NULL){
    return false;
}
fwrite(&reg,tamanioRegistro,1,pFactura);

cout << "Guardado exitoso" << endl;
fclose(pFactura);
return true;
}

Factura ArchivoFactura::leerFactura(int posicion){
Factura reg;
FILE *pFactura;
pFactura=fopen(_nombreArchivo.c_str(),"rb");

if(pFactura==NULL){
    cout << "ERROR EN EL ARCHIVO" << endl;
    return reg;
}
fseek(pFactura,tamanioRegistro * posicion,0);
fread(&reg,tamanioRegistro,1,pFactura);

fclose(pFactura);
return reg;

}

bool ArchivoFactura::leerRegistro(int posicion,Factura &reg){

FILE *pFactura;
pFactura=fopen(_nombreArchivo.c_str(),"rb");

if(pFactura==NULL){
    return false;
}
fseek (pFactura,tamanioRegistro * posicion,SEEK_SET);
if(fread(&reg,tamanioRegistro,1,pFactura)!=1){
    fclose(pFactura);
    return false;
}
fclose(pFactura);
return true;
}

int ArchivoFactura::buscarFactura(int idFactura){
Factura reg;
FILE *pFactura;

pFactura=fopen(_nombreArchivo.c_str(),"rb");
if(pFactura==NULL){
    return -2;
}
int pos=0;
while(fread(&reg,tamanioRegistro,1,pFactura)==1){
    if(reg.getIdFactura()== idFactura){
        return pos;
    }
    pos++;
}
fclose(pFactura);
return -1;
}

int ArchivoFactura::contarRegistro(){
Factura reg;
FILE *pFactura;
pFactura=fopen(_nombreArchivo.c_str(),"rb");

if(pFactura==NULL){
    return 0;
}
fseek(pFactura,0,SEEK_END);
long cantBytes=ftell(pFactura);
int cantRegistros=0;
cantRegistros=cantBytes/sizeof(Factura);

fclose(pFactura);
return cantRegistros;
}

bool ArchivoFactura::modificarFactura(int posicion){
Factura reg;
FILE *pFactura;
pFactura=fopen(_nombreArchivo.c_str(),"rb+");
if(pFactura==NULL){
    cout << "ERROR EN EL ARCHIVO" << endl;
    return false;
}
fseek(pFactura,posicion * tamanioRegistro,0);
fread(&reg,tamanioRegistro,1,pFactura);

int opcionModificar=-1;

do{
    system("cls");
    reg.mostrar();
    cout << endl;

    cout << "================================" << endl;
    cout << "   SELECCIONE QUE MODIFICAR" << endl;
    cout << "================================" << endl;
    cout << "1. Tipo Factura" << endl;
    cout << "2. ID. Medico" << endl;
    cout << "3. ID. Cod. de Especialidad" << endl;
    cout << "4. DNI del paciente" << endl;
    cout << "5. Importe" << endl;
    cout << "6. Fecha" << endl;
    cout << "0. Volver" << endl;
    cout << "================================" << endl;
    cout << "Opcion: ";
    cin >> opcionModificar;
    cin.ignore();

    while(opcionModificar>6||opcionModificar<0){
        cout << "Numero incorrecto" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opcionModificar;
        cin.ignore();
    }
    switch (opcionModificar){
case 1:{
    cout << "Ingrese nuevo tipo de factura: ";
    reg.setTipoFactura(cargarCadena());
    cout << "Tipo de factura modificado exitosamente." << endl;
    break;
}
case 2:{
    int idmed;
    cout << "Ingrese nuevo ID del medico: ";
    cin >>idmed;
    reg.setIdMedico(idmed);
    cout << "ID modificado exitosamente." << endl;
    break;
}
case 3:{
    int codEsp;
    cout << "Ingrese nuevo codigo de especialidad: ";
    cin >> codEsp;
    reg.setCodEspecialidad(codEsp);
    cout << "Codigo de especialidad modificado exitosamente." << endl;
    break;
}
case 4:{

    cout << "Ingrese nuevo DNI: ";
    reg.setDniPaciente(cargarCadena());
    break;
}
case 5:{
    cout << "Ingrese nuevo importe: ";
    float importe;
    cin >> importe;
    reg.setImporte(importe);
    cout << "Importe modificado exitosamente." << endl;
    break;
}
case 6:{
    Fecha nuevaFecha;
    cout << "Ingrese nueva fecha de facturación: ";
    nuevaFecha.Cargar();
    reg.setFechaFactura(nuevaFecha);
    cout << "Fecha modificada exitosamente." << endl;
    break;
}
case 0:
    cout << "Volviendo al menu anterior..." << endl;
    break;

    default:
    cout << "Opcion invalida. Intente nuevamente." << endl;
    break;
    }
    } while (opcionModificar!=0);

   fseek(pFactura,posicion * tamanioRegistro,0);
   fwrite(&reg,tamanioRegistro,1,pFactura);

   fclose(pFactura);
   return true;
}

bool ArchivoFactura::listarFacturas(){
Factura reg;
FILE *pFactura=fopen(_nombreArchivo.c_str(),"rb");
if(pFactura==NULL){
    cout << "ERROR EN EL ARCHIVO" << endl;
    return false;
}
while(fread(&reg,tamanioRegistro,1,pFactura)==1){
    reg.mostrar();
}
fclose(pFactura);
return true;
}

bool ArchivoFactura::cambioEstado(int idFactura,int posicion){
Factura reg;
bool nuevoEstado;
FILE *pFactura;
pFactura=fopen(_nombreArchivo.c_str(),"rb+");

if(pFactura==NULL){
    cout << "ERROR EN EL ARCHIVO" << endl;
    return false;
}
fseek (pFactura,posicion * tamanioRegistro,0);
fread(&reg,tamanioRegistro,1,pFactura);

cout << "Factura: " << reg.getIdFactura();
cout<<"Estado: " <<(reg.getEstado() ? "Activo" : "Inactivo")<<" "<<endl;

int opcionCambio;
if(reg.getEstado()==1){
    cout << "Desea pasar la factura a estado: INACTIVO";
    cout << "1. SI - 2. NO" << " : ";
    cout << opcionCambio;
    cin.ignore();
if(opcionCambio==1){
    nuevoEstado=false;
    cout << "La factura fue dada de baja correctamente." << endl;
}
} else {
cout << "Desea cambiar la factura a estado: ACTIVO";
cout << "1. SI - 2. NO" << " : ";
cout << opcionCambio;
cin.ignore();
if (opcionCambio==1){
    nuevoEstado=true;
    cout << "La factura fue dada de alta en el sistema correctamente.";
}
}
reg.setEstado(nuevoEstado);

fseek(pFactura, posicion * tamanioRegistro,0);
fwrite(&reg,tamanioRegistro,1,pFactura);

fclose(pFactura);
return reg.getEstado();
}

