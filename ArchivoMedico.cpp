#include <iostream>
#include "ArchivoMedico.h"
using namespace std;


ArchivoMedico::ArchivoMedico(const string &nombreArchivo){
_nombreArchivo=nombreArchivo;
tamanioRegistro=sizeof(Medico);
}

Medico ArchivoMedico::leerRegistro(int pos){
  Medico reg;
    FILE* pMedico=fopen(_nombreArchivo.c_str(), "rb");
        if (pMedico==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return reg;
    }
    fseek(pMedico, pos*tamanioRegistro,0);
    fread(&reg, tamanioRegistro, 1, pMedico);

    fclose(pMedico);
    return reg;
}

bool ArchivoMedico::agregarRegistro(const Medico &reg){
    FILE *pMedico;
    pMedico=fopen(_nombreArchivo.c_str(), "ab");

    if (pMedico==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    fwrite(&reg, tamanioRegistro, 1, pMedico);

    cout<<"Guardado exitoso"<<endl;
    fclose(pMedico);
    return true;
}


bool ArchivoMedico::modificarRegistro(Medico &reg,int posicion){
    FILE *pMedico;
    pMedico=fopen(_nombreArchivo.c_str(),"rb+");

    if(pMedico==NULL)
    {
        return false;

        fseek(pMedico,posicion*tamanioRegistro,SEEK_SET);
        if(fwrite(&reg, tamanioRegistro,1,pMedico)!=1)
        {
            fclose(pMedico);
            return false;

        }
        cout << "Registro modificado con exito." << endl;
        fclose(pMedico);
        return true;
    }
}
int ArchivoMedico::buscarRegistro(int idMedico){
Medico reg;

FILE *pMedico;
pMedico=fopen(_nombreArchivo.c_str(),"rb");
if(pMedico==NULL){
    return -2;
}

    int pos=0;
    while(fread(&reg, tamanioRegistro,1,pMedico)==1){
       if(reg.getIdMedico()== idMedico){
            return pos;
       }
       pos++;
    }

    fclose(pMedico);
    return -1;
}
bool ArchivoMedico::leerRegistro(int posicion,Medico &reg){
FILE *pMedico;
pMedico=fopen(_nombreArchivo.c_str(),"rb");

if(pMedico==NULL)return false;

fseek(pMedico,tamanioRegistro* posicion,SEEK_SET);
if(fread(&reg,tamanioRegistro,1,pMedico)!=1){
    fclose(pMedico);
    return false;
}
fclose(pMedico);

return true;
}

/*
int ArchivoMedico::contarRegistro(){

}
*/

bool ArchivoMedico::bajaLogica(int idMedico){
    Medico reg;
    ArchivoMedico archi;
    int pos=archi.buscarRegistro(idMedico);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    return archi.modificarRegistro(reg, pos);
}

bool ArchivoMedico::altaLogica(int idMedico){
    Medico reg;
    ArchivoMedico archi;
    int pos=archi.buscarRegistro(idMedico);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(true);
    return archi.modificarRegistro(reg, pos);
}
