#include<iostream>
#include "rlutil.h"
#include "menuPrincipal.h"
using namespace std;



void menuFacturacion(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;

do{
    rlutil::cls();
    cout <<margenTitulo<< " _____          _                        _             " << endl;
    cout <<margenTitulo<< "|  ___|_ _  ___| |_ _   _ _ __ __ _  ___(_) ___  _ __  " << endl;
    cout <<margenTitulo<< "| |_  / _` |/ __| __| | | | '__/ _` |/ __| |/ _ \\| '_ \\ " << endl;
    cout <<margenTitulo<< "|  _|| (_| | (__| |_| |_| | | | (_| | (__| | (_) | | | |" << endl;
    cout <<margenTitulo<< "|_|   \\__,_|\\___|\\___|\\__,_|_|  \\__,_|\\___|_|\\___/|_| |_|" << endl<<endl<<endl;

    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - CREAR FACTURA         ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - BUSCAR FACTURA        ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - MODIFICAR FACTURA     ||"<<endl;
    cout<<margenMenu<<"||============================||"<<endl;
    cout<<margenMenu<<"||  0 - VOLVER AL M. INICIAL  ||"<<endl;
    cout<<margenMenu<<" =============================="<<endl<<endl;

    cout<<margenMenu<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;

    while(numeroInicio>3||numeroInicio<0){
        cout<<margenMenu<<"Numero incorrecto"<<endl;
        cout<<margenMenu<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }


    switch(numeroInicio){
        case 1:
            rlutil::cls();
            cout<<"CREAR FACTURA";
        break;

        case 2:
            rlutil::cls();
            cout<<"BUSCAR FACTURA";
        break;

        case 3:
            rlutil::cls();
            cout<<"MODIFICAR FACTURA";
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


