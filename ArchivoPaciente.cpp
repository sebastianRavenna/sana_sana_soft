#include <iostream>
#include <string>
#include <cstring>
#include "ArchivoPaciente.h"
#include "Paciente.h"
#include <cstdio>
using namespace std;


ArchivoPaciente::ArchivoPaciente(const string &nombreArchivo){
            _nombreArchivo=nombreArchivo;
            tamanioRegistro=sizeof(Paciente);
        }

bool ArchivoPaciente::guardarPaciente(Paciente pac){
    FILE *archivo=fopen(_nombreArchivo.c_str(), "ab");
    if (archivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    fwrite(&pac, sizeof(Paciente), 1, archivo);

    cout<<"Guardado exitoso"<<endl;
    fclose(archivo);
    return true;
}

bool ArchivoPaciente::listarPacientes(){
    Paciente pac;
    FILE* archivo=fopen(_nombreArchivo.c_str(), "rb");
    if (archivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    while (fread(&pac, tamanioRegistro,1, archivo)==1){
        pac.mostrar();
    }

    fclose(archivo);
    return true;
}

int ArchivoPaciente::buscarPaciente(const std::string& _idPaciente){
    Paciente pac;
    FILE* archivo=fopen(_nombreArchivo.c_str(), "rb");
        if (archivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return -2;
        }
    int pos=0;
    while(fread(&pac, tamanioRegistro, 1, archivo)==1){
        if(pac.getIdPaciente()=="P-"+ _idPaciente){
            return pos;
        }
        pos++;
    }
    fclose(archivo);
    return -1;
}

Paciente ArchivoPaciente::leerRegistro(int pos){
    Paciente pac;
    FILE* archivo=fopen(_nombreArchivo.c_str(), "rb");
        if (archivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return pac;
    }
    fseek(archivo, pos*tamanioRegistro,0);
    fread(&pac, tamanioRegistro, 1, archivo);

    fclose(archivo);
    return pac;
}
