#include<iostream>
#include "rlutil.h"
#include "Paciente.h"
#include "ArchivoPaciente.h"
#include "menuHistoriaClinica.h"

using namespace std;



void menuPaciente(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;
Paciente paciente;
ArchivoPaciente archivoPaciente;

do{
    cout<<endl;
    rlutil::cls();
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

    cin.ignore(1000, '\n');

    switch(numeroInicio){
        case 1:
            cout<<endl;
            rlutil::cls();
            cout << "\n=== ALTA DE PACIENTE ===" << endl;
            paciente.cargar();
            archivoPaciente.guardarPaciente(paciente);
            cout<<endl;
            //paciente.mostrar();
        break;

        case 2:
            rlutil::cls();
            cout<<"BUSCAR PACIENTE";
        break;

        case 3:
            rlutil::cls();
            cout<<"MODIFICAR PACIENTE";
        break;

        case 4:
            rlutil::cls();
            cout<<"BAJA PACIENTE";
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


