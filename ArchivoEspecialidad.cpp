#include <string>
#include "ArchivoEspecialidad.h"
using namespace std;

ArchivoEspecialidad::ArchivoEspecialidad(const string &nombreArchivo){
_nombreArchivo=nombreArchivo;
tamanioRegistro=sizeof(Especialidad);
}

bool ArchivoEspecialidad::agregarRegistro(const Especialidad &reg )
{

FILE *pEspecialidad;
pEspecialidad=fopen(_nombreArchivo.c_str(),"ab");

if (pEspecialidad==NULL)return false;

fwrite(&reg,tamanioRegistro,1,pEspecialidad);
fclose(pEspecialidad);

return true;

}
bool ArchivoEspecialidad::leerRegistro(int posicion,Especialidad &reg){

FILE *pEspecialidad;
pEspecialidad=fopen(_nombreArchivo.c_str(),"rb");

if(pEspecialidad==NULL)return false;

fseek(pEspecialidad,tamanioRegistro* posicion,SEEK_SET);
if(fread(&reg,tamanioRegistro,1,pEspecialidad)!=1){
    fclose(pEspecialidad);
    return false;
}
fclose(pEspecialidad);

return true;
}
bool ArchivoEspecialidad::modificarRegistro(Especialidad &reg, int posicion){
    FILE *pEspecialidad;
    pEspecialidad=fopen(_nombreArchivo.c_str(),"rb+");/// con + se le agrega al modo lo que no puede hacer
    ///rb->leer; wb->empezar de  un archivo; ab->para agregar registro
    if(pEspecialidad==nullptr){
        return false;
    }
    fseek(pEspecialidad, posicion*tamanioRegistro,SEEK_SET);
    if(fwrite(&reg, tamanioRegistro,1,pEspecialidad)!=1){
        fclose(pEspecialidad);
        return false;

    }

    fclose(pEspecialidad);
    return true;
}

int ArchivoEspecialidad::buscarRegistro(int codEspecialidad){
Especialidad reg;

FILE *pEspecialidad;
pEspecialidad=fopen(_nombreArchivo.c_str(),"rb");
if(pEspecialidad==nullptr){
    return -2;
}

    int pos=0;
    while(fread(&reg, tamanioRegistro,1,pEspecialidad)==1){
       if(reg.getCodEspecialidad()== codEspecialidad){
            return pos;
       }
       pos++;
    }

    fclose(pEspecialidad);
    return -1;
}

bool ArchivoEspecialidad::bajaLogica(int codEspecialidad){
    Especialidad reg;
    ArchivoEspecialidad archi;
    int pos=archi.buscarRegistro(codEspecialidad);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    return archi.modificarRegistro(reg, pos);
}
bool ArchivoEspecialidad::altaLogica(int codEspecialidad){
    Especialidad reg;
    ArchivoEspecialidad archi;
    int pos=archi.buscarRegistro(codEspecialidad);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(true);
    return archi.modificarRegistro(reg, pos);
}
Especialidad ArchivoEspecialidad::leerRegistro(int pos){
    Especialidad obj;
    FILE *pEspecialidad;
    pEspecialidad=fopen(_nombreArchivo.c_str(),"rb");
    obj.setCodEspecialidad(-1);
    if(pEspecialidad==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(pEspecialidad,pos*tamanioRegistro,SEEK_SET);
    fread(&obj, tamanioRegistro,1,pEspecialidad);

    fclose(pEspecialidad);
    return obj;

}
