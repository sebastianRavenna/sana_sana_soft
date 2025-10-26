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
    while (fread(&pac, sizeof(Paciente),1, archivo)==1){
        pac.mostrar();
    }

    fclose(archivo);
    return true;
}





/*Paciente ArchivoPaciente::buscarPaciente(int pos){

    FILE* archivo=fopen(_nombreArchivo.c_str(), "rb");
        if (archivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return nullptr;
        }

    fseek(archivo, 0, SEEK_END);

    long tamanioArchivo=ftell(archivo);
    tamRegistro = tamanioArchivo/sizeof(Paciente);

    rewind(archivo);//esto lleva al puntero al inicio
    Paciente *pacientes = new Paciente [tamRegistro];

    fread(pacientes, sizeof(Paciente), tamRegistro, archivo);

    fclose(archivo);

    return pacientes;
}*/

