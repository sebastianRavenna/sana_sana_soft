#include <string>
#include "ArchivoEspecialidad.h"
#include<iostream>
#include "Especialidad.h"
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
    cout<<"Guardado Exitoso";
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
FILE *pEspecialidad=fopen(_nombreArchivo.c_str(),"rb");
if(pEspecialidad==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
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

int ArchivoEspecialidad::contarRegistros(){
    FILE* pEspecialidad = fopen(_nombreArchivo.c_str(), "rb");
    if(pEspecialidad == NULL){
        return 0;
    }
    fseek(pEspecialidad, 0, SEEK_END);
    int cantidadRegistros = ftell(pEspecialidad) / tamanioRegistro;
    fclose(pEspecialidad);
    return cantidadRegistros;
}

bool ArchivoEspecialidad::listarEspecialidad(){
    Especialidad obj;
    FILE* pEspecialidad=fopen(_nombreArchivo.c_str(), "rb");
    if(pEspecialidad == NULL){
        cout<<"Error en el Archivo"<<endl;
        return false;
    }
    while(fread(&obj, tamanioRegistro, 1, pEspecialidad)==1){
        obj.mostrar();
        cout<<"------------------------------"<<endl;
        cout<<endl;
    }
    fclose(pEspecialidad);
    return true;
}

bool ArchivoEspecialidad::listarPorNombre(){
    int tam = contarRegistros();
    if(tam == 0){
        cout<<"No hay registros para listar"<<endl<<endl;
        return true;
    }
    //necesitamos si o si un vector dinamico para poder ordenar
    Especialidad *vectorEspecialidad;
    vectorEspecialidad = new Especialidad[tam];

    Especialidad obj;
    FILE* pEspecialidad = fopen(_nombreArchivo.c_str(), "rb");
    if(pEspecialidad == NULL){
        cout<<"Error en el Archivo"<<endl;
        delete[] vectorEspecialidad;
        return false;
    }
    int i=0;
    while(fread(&obj, tamanioRegistro, 1, pEspecialidad)== 1){ // vamos copiando el contenido del archivoHistoriaClinica en el vector dinamico que creamos
        vectorEspecialidad[i] = obj;
        i++;
    }
    fclose(pEspecialidad);

    for(int i=0; i<tam - 1; i++ ){ //aca va tam-1, porque tomamos un valor del vector y lo comparamos con el siguiente para ver cual es el menor. Si el vector llega a su ultimo elemento, no va a tener un "siguiente" contra quien compararse y por eso va a dar error. Por eso, la iteracion solo llega hasta el penultimo valor del vector
        int indexmenor = i;

        for(int j=i+1; j<tam; j++){ // aca va j=i+1, porque es la manera de "llamar" al valor siguiente de i para poder hacer la comparacion. Tambien va j<tam, porque necesita llegar al ultimo valor del vector para compararlo con i (que llega hasta el penultimo valor del vector)
            string nombreJ = vectorEspecialidad[j].getDescripcion();
            string nombreMenor = vectorEspecialidad[indexmenor].getDescripcion();

            if(nombreJ<nombreMenor){
                indexmenor = j;
            }
        }
        Especialidad objAux = vectorEspecialidad[i];
        vectorEspecialidad[i] = vectorEspecialidad[indexmenor];
        vectorEspecialidad[indexmenor] = objAux;
    }
    for(int i=0; i<tam; i++){
        vectorEspecialidad[i].mostrar();
        cout<<"------------------------------"<<endl;
        cout<<endl;
    }
    delete[] vectorEspecialidad;
    return true;
}

