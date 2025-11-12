#include <iostream>
#include <string>
#include "ArchivoAgenda.h"
#include "Agenda.h"
#include "Funciones.h"
#include "rlutil.h"

using namespace std;


ArchivoAgenda::ArchivoAgenda(const string &nombreArchivo){
            _nombreArchivo=nombreArchivo;
            tamanioRegistro=sizeof(Agenda);
}

bool ArchivoAgenda::escribirRegistro(Agenda agenda){
    FILE *pArchivo=fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    fwrite(&agenda, sizeof(Agenda), 1, pArchivo);

    //cout<<"Guardado exitoso"<<endl;
    fclose(pArchivo);
    return true;
}

int ArchivoAgenda::buscarRegistro(int idAgenda){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
        if (pArchivo==NULL){
            return -2;
        }
    int pos=0;
    while(fread(&agenda, tamanioRegistro, 1, pArchivo)==1){
        if(agenda.getIdAgenda()== idAgenda){
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

Agenda ArchivoAgenda::leerRegistro(int pos){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
        if (pArchivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return agenda;
    }
    fseek(pArchivo, pos*tamanioRegistro,0); //pos*tama¤oRegistro multiplica la posicion por el tama¤o de cada registro para moverse dentro del archivo
    fread(&agenda, tamanioRegistro, 1, pArchivo);

    fclose(pArchivo);
    return agenda;
}

int ArchivoAgenda::contarRegistros(){
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
        if (pArchivo==NULL){
            return 0;
    }

    fseek(pArchivo, 0, 2); // los numeros indican: 0 desde el inicio, 1 posicion actual, 2 final del archivo
    int tamBytes= ftell(pArchivo);
    int cantReg= tamBytes/tamanioRegistro;

    return cantReg;
}

bool ArchivoAgenda::cambioEstado(const std::string &idMedico, Fecha fechaDesde,
                                 Fecha fechaHasta ){
    Agenda agenda;

    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb+");
        if (pArchivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return false;
        }

    int opcCambio, contador=0, posicion=0;
    cout<<"¨Desea suspender la Agenda en ese rango? 1.Si - 0.No:";
    cin>>opcCambio;
    cin.ignore();

    if(opcCambio==1){

        while (fread (&agenda, tamanioRegistro, 1, pArchivo)==1){
            if(agenda.getIdMedico()==idMedico && fechaDesde.esIgualOMenor(agenda.getFechaTurno()) &&
                agenda.getFechaTurno().esIgualOMenor(fechaHasta)){
                agenda.setEstado(false);
                agenda.setAsignado(true);

                fseek(pArchivo, posicion * tamanioRegistro, 0);
                fwrite(&agenda, tamanioRegistro, 1, pArchivo);

                fseek(pArchivo, (posicion+1) * tamanioRegistro, 0);
                contador++;
                }
                posicion++;
        }
    }
    fclose(pArchivo);
    if (contador>0){
    cout<<"La Agenda fue Suspendida en el sistema: "<<contador<<endl;
    system("pause");
    }
    return true;
}

void ArchivoAgenda::generarAgenda(const std::string &idMedico, int codEspecialidad, Fecha fecha, Hora horaInicio, Hora horaFin){

    int hora, minutos, minutosInicio, minutosFin, minutoActual, idConsDisp, duracionMinutos=30;

    minutosInicio = horaInicio.getHora()*60 + horaInicio.getMinuto();
    minutosFin = horaFin.getHora()*60 + horaFin.getMinuto();
    minutoActual = minutosInicio;

    while (minutoActual<minutosFin){
        Agenda nuevaConsDisp;

        hora=minutoActual/60;
        minutos=minutoActual%60;
        Hora horaConsulta(hora, minutos);

        idConsDisp = contarRegistros()+1;
        nuevaConsDisp.setIdAgenda(idConsDisp);
        nuevaConsDisp.setIdMedico(idMedico);
        nuevaConsDisp.setCodEspecialidad(codEspecialidad);
        nuevaConsDisp.setFechaTurno(fecha);
        nuevaConsDisp.setHoraTurno(horaConsulta);

        escribirRegistro(nuevaConsDisp);
        minutoActual += duracionMinutos;
    }
}

void ArchivoAgenda::generarAgendaRango(const std::string &idMedico, int codEspecialidad, Fecha fechaDesde,
                        Fecha fechaHasta, Hora horaInicio, Hora horaFin, bool diasActivo[7]){
    int hora, minutos, minutosInicio, minutosFin, minutoActual,
    idConsDisp, duracionMinutos=30;

    Fecha fechaActual = fechaDesde;

    while(fechaActual.esIgualOMenor(fechaHasta)){
        if(diasActivo[fechaActual.getDiaSemana()]){
            generarAgenda(idMedico, codEspecialidad,fechaActual,
                          horaInicio, horaFin);
        }
        fechaActual = fechaActual.sumarUnDia();
    }

}

bool ArchivoAgenda::listarAgendaCompleta(){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    cout << "\n=== AGENDA COMPLETA ==="<< endl;
    while (fread(&agenda, tamanioRegistro,1, pArchivo)==1){
        agenda.mostrarAgenda();
    }

    fclose(pArchivo);
    system("pause");
    return true;
}

bool ArchivoAgenda::listarAgendaPorFecha(Fecha fecha){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    cout << "\n=== AGENDA DEL DIA: ";
    fecha.Mostrar();
    cout << " ===" << endl;
    while (fread(&agenda, tamanioRegistro,1, pArchivo)==1){
        if (agenda.getFechaTurno().esIgual(fecha)){
            agenda.mostrarAgenda();
        }
    }
    fclose(pArchivo);
    system("pause");
    return true;
}

bool ArchivoAgenda::listarAgendaPorRangoFecha(Fecha fechaDesde, Fecha fechaHasta){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    cout << "\n=== AGENDA DEL ";
    fechaDesde.Mostrar();
    cout << " AL ";
    fechaHasta.Mostrar();
    cout << " ===" << endl;

    while (fread (&agenda, tamanioRegistro, 1, pArchivo)==1){
        if(fechaDesde.esIgualOMenor(agenda.getFechaTurno()) &&
            agenda.getFechaTurno().esIgualOMenor(fechaHasta)){
            agenda.mostrarAgenda();
        }
    }
    fclose(pArchivo);
    system("pause");
    return true;
}

bool ArchivoAgenda::listarAgendaPorMedicoRangoFecha(const std::string &idMedico,Fecha fechaDesde, Fecha fechaHasta){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    cout << "\n=== AGENDA DEL MEDICO ";
    agenda.getIdMedico();
    cout << " DESDE EL ";
    fechaDesde.Mostrar();
    cout << " HASTA EL ";
    fechaHasta.Mostrar();
    cout << " ===" << endl;

    while (fread (&agenda, tamanioRegistro, 1, pArchivo)==1){
        if(agenda.getIdMedico()==idMedico && fechaDesde.esIgualOMenor(agenda.getFechaTurno()) &&
           agenda.getFechaTurno().esIgualOMenor(fechaHasta)){
            agenda.mostrarAgenda();
        }
    }
    fclose(pArchivo);
    system("pause");
    return true;
}

