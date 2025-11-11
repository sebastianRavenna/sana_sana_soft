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


bool ArchivoHistoriaClinica::listarPorFecha(){
    int tam = CantidadRegistros();
    if(tam == 0){
        cout<<"No hay registros para listar"<<endl<<endl;
        return true;
    }
    //necesitamos si o si un vector dinamico para poder ordenar
    HistoriaClinica *vectorHistoria;
    vectorHistoria = new HistoriaClinica[tam];

    HistoriaClinica his;
    FILE* pHistoria = fopen(_nombreArchivo.c_str(), "rb");
    if(pHistoria == NULL){
        cout<<"Error en el Archivo"<<endl;
        delete[] vectorHistoria;
        return false;
    }
    int i=0;
    while(fread(&his, _tamanioRegistro, 1, pHistoria)== 1){ // vamos copiando el contenido del archivoHistoriaClinica en el vector dinamico que creamos
        vectorHistoria[i] = his;
        i++;
    }
    fclose(pHistoria);

    for(int i=0; i<tam - 1; i++ ){ //aca va tam-1, porque tomamos un valor del vector y lo comparamos con el siguiente para ver cual es el menor. Si el vector llega a su ultimo elemento, no va a tener un "siguiente" contra quien compararse y por eso va a dar error. Por eso, la iteracion solo llega hasta el penultimo valor del vector
        int indexmenor = i;

        for(int j=i+1; j<tam; j++){ // aca va j=i+1, porque es la manera de "llamar" al valor siguiente de i para poder hacer la comparacion. Tambien va j<tam, porque necesita llegar al ultimo valor del vector para compararlo con i (que llega hasta el penultimo valor del vector)
            Fecha fechaJ = vectorHistoria[j].getFechaConsulta();
            Fecha fechaMenor = vectorHistoria[indexmenor].getFechaConsulta();

            if(fechaJ.esMasAntigua(fechaMenor)){
                indexmenor = j;
            }
        }
        HistoriaClinica hisAux = vectorHistoria[i];
        vectorHistoria[i] = vectorHistoria[indexmenor];
        vectorHistoria[indexmenor] = hisAux;
    }
    for(int i=0; i<tam; i++){
        vectorHistoria[i].mostrar();
        cout<<"------------------------------"<<endl;
        cout<<endl;
    }
    delete[] vectorHistoria;
    return true;
}


bool ArchivoHistoriaClinica::listarPorDNI(){
    int tam = CantidadRegistros();
    if(tam == 0){
        cout<<"No hay registros para listar"<<endl<<endl;
        return true;
    }
    //necesitamos si o si un vector dinamico para poder ordenar
    HistoriaClinica *vectorHistoria;
    vectorHistoria = new HistoriaClinica[tam];

    HistoriaClinica his;
    FILE* pHistoria = fopen(_nombreArchivo.c_str(), "rb");
    if(pHistoria == NULL){
        cout<<"Error en el Archivo"<<endl;
        delete[] vectorHistoria;
        return false;
    }
    int i=0;
    while(fread(&his, _tamanioRegistro, 1, pHistoria)== 1){ // vamos copiando el contenido del archivoHistoriaClinica en el vector dinamico que creamos
        vectorHistoria[i] = his;
        i++;
    }
    fclose(pHistoria);

    for(int i=0; i<tam - 1; i++ ){ //aca va tam-1, porque tomamos un valor del vector y lo comparamos con el siguiente para ver cual es el menor. Si el vector llega a su ultimo elemento, no va a tener un "siguiente" contra quien compararse y por eso va a dar error. Por eso, la iteracion solo llega hasta el penultimo valor del vector
        int indexmenor = i;

        for(int j=i+1; j<tam; j++){ // aca va j=i+1, porque es la manera de "llamar" al valor siguiente de i para poder hacer la comparacion. Tambien va j<tam, porque necesita llegar al ultimo valor del vector para compararlo con i (que llega hasta el penultimo valor del vector)
            string dniJ = vectorHistoria[j].getDniPaciente();
            string dniMenor = vectorHistoria[indexmenor].getDniPaciente();

            if(dniJ<dniMenor){
                indexmenor = j;
            }
        }
        HistoriaClinica hisAux = vectorHistoria[i];
        vectorHistoria[i] = vectorHistoria[indexmenor];
        vectorHistoria[indexmenor] = hisAux;
    }
    for(int i=0; i<tam; i++){
        vectorHistoria[i].mostrar();
        cout<<"------------------------------"<<endl;
        cout<<endl;
    }
    delete[] vectorHistoria;
    return true;
}
