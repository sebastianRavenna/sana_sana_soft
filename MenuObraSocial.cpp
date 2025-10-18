#include<iostream>
#include "rlutil.h"
#include "menuPrincipal.h"
using namespace std;



void menuObraSocial(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;

do{
    rlutil::cls();
    cout <<margenTitulo<< "   ___  _                 ____             _       _ " << endl;
    cout <<margenTitulo<< "  / _ \\| |__  _ __ __ _  / ___|  ___   ___(_) __ _| |" << endl;
    cout <<margenTitulo<< " | | | | '_ \\| '__/ _` | \\___ \\ / _ \\ / __| |/ _` | |" << endl;
    cout <<margenTitulo<< " | |_| | |_) | | | (_| |  ___) | (_) | (__| | (_| | |" << endl;
    cout <<margenTitulo<< "  \\___/|_.__/|_|  \\__,_| |____/ \\___/ \\___|_|\\__,_|_|" << endl<<endl<<endl;

    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - ALTA O. SOCIAL        ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - BUSCAR O. SOCIAL      ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - MODIFICAR O. SOCIAL   ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  4 - BAJA O. SOCIAL        ||"<<endl;
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

    switch(numeroInicio){
        case 1:
            rlutil::cls();
            cout<<"ALTA O. SOCIAL";
        break;

        case 2:
            rlutil::cls();
            cout<<"BUSCAR O. SOCIAL";
        break;

        case 3:
            rlutil::cls();
            cout<<"MODIFICAR O. SOCIAL";
        break;

        case 4:
            rlutil::cls();
            cout<<"BAJA O. SOCIAL";
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


