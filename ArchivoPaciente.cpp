#include <iostream>
#include <string>
#include "ArchivoPaciente.h"
#include "Paciente.h"

using namespace std;


ArchivoPaciente::ArchivoPaciente(const string &nombreArchivo){
            _nombreArchivo=nombreArchivo;
            tamanioRegistro=sizeof(Paciente);
}

bool ArchivoPaciente::guardarPaciente(Paciente pac){
    FILE *pPaciente=fopen(_nombreArchivo.c_str(), "ab");
    if (pPaciente==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    fwrite(&pac, sizeof(Paciente), 1, pPaciente);

    cout<<"Guardado exitoso"<<endl;
    fclose(pPaciente);
    return true;
}

bool ArchivoPaciente::listarPacientes(){
    Paciente pac;
    FILE* pPaciente=fopen(_nombreArchivo.c_str(), "rb");
    if (pPaciente==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    while (fread(&pac, tamanioRegistro,1, pPaciente)==1){
        pac.mostrar();
    }

    fclose(pPaciente);
    return true;
}

int ArchivoPaciente::buscarPaciente(const std::string _idPaciente){
    Paciente pac;
    FILE* pPaciente=fopen(_nombreArchivo.c_str(), "rb");
        if (pPaciente==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return -2;
        }
    int pos=0;
    while(fread(&pac, tamanioRegistro, 1, pPaciente)==1){
        if(pac.getIdPaciente()=="P-"+ _idPaciente){
            return pos;
        }
        pos++;
    }
    fclose(pPaciente);
    return -1;
}

Paciente ArchivoPaciente::leerRegistro(int pos){
    Paciente pac;
    FILE* pPaciente=fopen(_nombreArchivo.c_str(), "rb");
        if (pPaciente==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return pac;
    }
    fseek(pPaciente, pos*tamanioRegistro,0); //pos*tama¤oRegistro multiplica la posicion por el tama¤o de cada registro para moverse dentro del archivo
    fread(&pac, tamanioRegistro, 1, pPaciente);

    fclose(pPaciente);
    return pac;
}

bool ArchivoPaciente::leerRegistro(int posicion,Paciente &reg){

FILE *pPaciente;
pPaciente=fopen(_nombreArchivo.c_str(),"rb");

if(pPaciente==NULL)return false;

fseek(pPaciente,tamanioRegistro* posicion,SEEK_SET);
if(fread(&reg,tamanioRegistro,1,pPaciente)!=1){
    fclose(pPaciente);
    return false;
}
fclose(pPaciente);

return true;
}
