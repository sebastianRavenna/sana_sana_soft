#include<iostream>
#include "rlutil.h"
#include "string"
#include "Paciente.h"
#include "ArchivoPaciente.h"
#include "menuHistoriaClinica.h"
#include "Funciones.h"

using namespace std;



void menuPaciente(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio, posBuscar=0;
Paciente paciente;
ArchivoPaciente archivoPaciente;
std::string idPac;

do{
    cout<<endl;
    system("cls");
    cout <<margenTitulo<< "  ____            _            _            " << endl;
    cout <<margenTitulo<< " |  _ \\ __ _  ___(_) ___ _ __ | |_ ___  ___ " << endl;
    cout <<margenTitulo<< " | |_) / _` |/ __| |/ _ \\ '_ \\| __/ _ \\/ __|" << endl;
    cout <<margenTitulo<< " |  __/ (_| | (__| |  __/ | | | ||  __/\\__ \\" << endl;
    cout <<margenTitulo<< " |_|   \\__,_|\\___|_|\\___|_| |_|\\__\\___||___/" << endl<<endl<<endl;

    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - ALTA PACIENTE         ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - BUSCAR PACIENTE       ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - MODIFICAR PACIENTE    ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  4 - BAJA PACIENTE         ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  5 - HISTORIA CLINICA      ||"<<endl;
    cout<<margenMenu<<"||============================||"<<endl;
    cout<<margenMenu<<"||  0 - VOLVER AL M. INICIAL  ||"<<endl;
    cout<<margenMenu<<" =============================="<<endl<<endl;

    cout<<margenMenu<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;

    while(numeroInicio>5||numeroInicio<0){
        cout<<margenMenu<<"Numero incorrecto"<<endl;
        cout<<margenMenu<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }


    switch(numeroInicio){
        case 1:
            cout<<endl;
            rlutil::cls();
            cout << "\n=== ALTA DE PACIENTE ===" << endl;
            paciente.cargar();
            cout<<endl;
        break;

        case 2:
            rlutil::cls();

            cout << "\n=== BUSCAR DE PACIENTE ===" <<endl<<endl;
            cout<<"INGRESE DNI DEL PACIENTE: ";
            cin>> idPac;
            posBuscar=archivoPaciente.buscarPaciente(idPac);
            if(posBuscar>=0){
                paciente=archivoPaciente.leerRegistro(posBuscar);
                paciente.mostrar();
            }else cout<<"Paciente no encontrado."<<endl;
            cout<<endl;
        break;

        case 3:
            rlutil::cls();

            cout << "\n=== MODIFICAR DE PACIENTE ===" <<endl<<endl;
            cout<<"INGRESE DNI DEL PACIENTE A MODIFICAR: ";
            cin>> idPac;
            posBuscar=archivoPaciente.buscarPaciente(idPac);
            if(posBuscar>=0){
                archivoPaciente.modificarRegistro(idPac, posBuscar);
            }else cout<<"Paciente no encontrado."<<endl;
            cout<<endl;
        break;

        case 4:
            rlutil::cls();

            cout << "\n=== ESTADO DE PACIENTE ===" <<endl<<endl;
            cout<<"INGRESE DNI DEL PACIENTE: ";
            cin>> idPac;
            posBuscar=archivoPaciente.buscarPaciente(idPac);
            if(posBuscar>=0){
                archivoPaciente.cambioEstado(idPac, posBuscar);
            }else cout<<"Paciente no encontrado."<<endl;
            cout<<endl;

        break;

        case 5:
            rlutil::cls();
            menuHistoriaClinica();
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


