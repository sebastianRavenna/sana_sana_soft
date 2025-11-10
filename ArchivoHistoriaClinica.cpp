#include <iostream>
#include <string>
#include <cstring>
#include "ArchivoHistoriaClinica.h"
#include "HistoriaClinica.h"
#include "Fecha.h"
#include "Funciones.h"
#include "Medico.h"
#include "ArchivoMedico.h"

using namespace std;

ArchivoHistoriaClinica::ArchivoHistoriaClinica(const string &nombreArchivo){
    _nombreArchivo = nombreArchivo;
    _tamanioRegistro = sizeof(HistoriaClinica);
}

bool ArchivoHistoriaClinica::listarHistoriaClinica(){
    HistoriaClinica his;
    FILE* pHistoria=fopen(_nombreArchivo.c_str(), "rb");
    if(pHistoria == NULL){
        cout<<"Error en el Archivo"<<endl;
        return false;
    }
    while(fread(&his, _tamanioRegistro, 1, pHistoria)==1){
        his.mostrar();
        cout<<"------------------------------"<<endl;
        cout<<endl;
    }
    fclose(pHistoria);
    return true;
}

bool ArchivoHistoriaClinica::listarHistoriaClinicaxPaciente(std::string &dniPacienteBuscado){ // para buscar historias clinicas de un paciente en particular
    HistoriaClinica his;
    ArchivoMedico archivoMedico;
    Medico medico;
    string dniMedico, nombreMedico, sexoMedico;
    int posBuscar;
    FILE* pHistoria=fopen(_nombreArchivo.c_str(), "rb");
    if(pHistoria == NULL){
        cout<<"Error en el Archivo"<<endl;
        return false;
    }
    bool datoEncontrado=false;
    while(fread(&his, _tamanioRegistro, 1, pHistoria)==1){
        if(his.getDniPaciente()==dniPacienteBuscado){
            dniMedico = his.getIdMedico().substr(2); // Es necesario sacar los 2 primeros caracteres del ID de Medico para poder obtener el DNI limpio
            posBuscar = archivoMedico.buscarRegistro(dniMedico);
            medico = archivoMedico.leerRegistro(posBuscar);
            nombreMedico = medico.getNombre() + " " + medico.getApellido();
            sexoMedico = medico.getSexo();

            his.mostrarxPaciente(nombreMedico, sexoMedico);
            cout<<"------------------------------"<<endl;
            cout<<endl;
            datoEncontrado =true;
        }
    }
    fclose(pHistoria);
    if(!datoEncontrado){
        cout<<"El paciente no tiene Historia Clinica"<<endl;
    }
    return datoEncontrado;
}


bool ArchivoHistoriaClinica::guardarHistoriaClinica(HistoriaClinica his){
    FILE* pHistoria=fopen(_nombreArchivo.c_str(), "ab");
    if(pHistoria == NULL){
        cout<<"Error en el Archivo"<<endl;
        return false;
    }
    fwrite(&his, sizeof(HistoriaClinica), 1, pHistoria);
    cout<<"Guardado Exitoso";
    fclose(pHistoria);
    return true;
}

int ArchivoHistoriaClinica::buscarHistoriaClinica(int idHistoria){ // Aca busca por ID de Historia Clinica
    HistoriaClinica his;
    FILE* pHistoria=fopen(_nombreArchivo.c_str(), "rb");
    if(pHistoria == NULL){
        cout<<"Error en el Archivo"<<endl;
        return -2;
    }
    int pos=0;
    while(fread(&his, _tamanioRegistro, 1, pHistoria)== 1){
        if(his.getIdHistoria()== idHistoria){
            return pos;
        }
        pos++;
    }
    fclose(pHistoria);
    return -1;
}

HistoriaClinica ArchivoHistoriaClinica::leerRegistro(int tamRegistro){
    HistoriaClinica his;
    FILE* pHistoria=fopen(_nombreArchivo.c_str(), "rb");
    if(pHistoria == NULL){
        cout<<"Error en el Archivo"<<endl;
        return his;
    }
    fseek(pHistoria, tamRegistro*_tamanioRegistro,0);
    fread(&his, _tamanioRegistro, 1, pHistoria);
    fclose(pHistoria);
    return his;

}

bool ArchivoHistoriaClinica::leerRegistro(int posicion, HistoriaClinica &reg){
    FILE* pHistoria;
    pHistoria=fopen(_nombreArchivo.c_str(),"rb");
    if(pHistoria == NULL){
        cout<<"Error en el Archivo"<<endl;
        return false;
    }
    fseek(pHistoria, _tamanioRegistro*posicion, SEEK_SET);
    if(fread(&reg, _tamanioRegistro, 1, pHistoria)!=1){
        fclose(pHistoria);
        return false;
    }
    fclose(pHistoria);
    return true;
}

int ArchivoHistoriaClinica::CantidadRegistros(){
    FILE* pHistoria = fopen(_nombreArchivo.c_str(), "rb");
    if(pHistoria == NULL){
        return 0;
    }
    fseek(pHistoria, 0, SEEK_END);
    int cantidadRegistros = ftell(pHistoria) / _tamanioRegistro;
    fclose(pHistoria);
    return cantidadRegistros;
}

bool ArchivoHistoriaClinica::modificarRegistro(HistoriaClinica his, int posicion){
    FILE* pHistoria = fopen(_nombreArchivo.c_str(), "rb+");
    if(pHistoria == NULL){
        return false;
    }
    fseek(pHistoria, posicion * _tamanioRegistro, 0);
    fwrite(&his, _tamanioRegistro, 1, pHistoria);
    fclose(pHistoria);
    return true;


}

bool ArchivoHistoriaClinica::abmLogico(std::string &dniPacienteBuscado){
    int posBuscar=0;
    HistoriaClinica his;
    FILE* pHistoria = fopen(_nombreArchivo.c_str(), "rb+");
    if(pHistoria == NULL){
        cout<<"Error en el Archivo"<<endl;
        return false;
    }
    bool datoEncontrado = false;

    while(fread(&his, _tamanioRegistro, 1, pHistoria)==1){
        if(his.getDniPaciente() == dniPacienteBuscado){
            if(his.getEstado()== true){
                his.setEstado(false);
                fseek(pHistoria, posBuscar*_tamanioRegistro, SEEK_SET);
                fwrite(&his, _tamanioRegistro, 1, pHistoria);
                fseek(pHistoria, (posBuscar+1)*_tamanioRegistro, SEEK_SET);
                datoEncontrado = true;
                }
            else{
                his.setEstado(true);
                fseek(pHistoria, posBuscar*_tamanioRegistro, SEEK_SET);
                fwrite(&his,_tamanioRegistro, 1, pHistoria);
                fseek(pHistoria, (posBuscar+1)*_tamanioRegistro, SEEK_SET);
                datoEncontrado = true;
            }
        }
        posBuscar++;
    }
    fclose(pHistoria);

    if (datoEncontrado) {
        cout<<endl;
        cout <<"Se modifico el estado de todas las historias clinicas del paciente"<<endl<<endl;
    }
    else{
        cout<<endl;
        cout<<"El paciente no tiene Historia Clinica" << endl<<endl;
    }
    return datoEncontrado;
}


