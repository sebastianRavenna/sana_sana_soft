#include<iostream>
#include "rlutil.h"
#include "Especialidad.h"
using namespace std;



void menuEspecialidad(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;

do{
    rlutil::cls();
    cout <<margenTitulo<< " _____                     _       _ _     _           _  " << endl;
    cout <<margenTitulo<< "| ____|___ _ __   ___  ___(_) __ _| (_) __| | __ _  __| | " << endl;
    cout <<margenTitulo<< "|  _| / __| '_ \\ / _ \\/ __| |/ _` | | |/ _` |/ _` |/ _` | " << endl;
    cout <<margenTitulo<< "| |___\\__ \\ |_) |  __/ (__| | (_| | | | (_| | (_| | (_| | " << endl;
    cout <<margenTitulo<< "|_____|___/ .__/ \\___|\\___  |_|\\__,_|_|_|\\__,_|\\__,_|\\__,_| " << endl;
    cout <<margenTitulo<< "          |_|                                               " << endl<<endl<<endl;


    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - ALTA ESPECIALIDAD     ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - BUSCAR ESPECIALIDAD   ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - MODIF ESPECIALIDAD    ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  4 - BAJA ESPECIALIDAD     ||"<<endl;
    cout<<margenMenu<<"||============================||"<<endl;
    cout<<margenMenu<<"||  0 - VOLVER AL M. INICIAL  ||"<<endl;
    cout<<margenMenu<<" =============================="<<endl<<endl;

    cout<<margenMenu<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;

    while(numeroInicio>4||numeroInicio<0){
        cout<<margenMenu<<"Numero incorrecto"<<endl;
        cout<<margenMenu<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }

    Especialidad especialidad;
    switch(numeroInicio){
        case 1:
            rlutil::cls();
            especialidad.cargar();
        break;

        case 2:
            rlutil::cls();
            cout<<"BUSCAR ESPECIALIDAD";
        break;

        case 3:
            rlutil::cls();
            cout<<"MODIFICAR ESPECIALIDAD";
        break;

        case 4:
            rlutil::cls();
            cout<<"BAJA ESPECIALIDAD";
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


