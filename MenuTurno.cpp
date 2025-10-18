#include<iostream>
#include "rlutil.h"
#include "menuPrincipal.h"
using namespace std;



void menuTurno(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;

do{
    rlutil::cls();
    cout <<margenTitulo<< " _____                            " << endl;
    cout <<margenTitulo<< "|_   _|   _ _ __ _ __   ___  ___ " << endl;
    cout <<margenTitulo<< "  | || | | | '__| '_ \\ / _ \\/ __|" << endl;
    cout <<margenTitulo<< "  | || |_| | |  | | | | (_) \\__ \\" << endl;
    cout <<margenTitulo<< "  |_| \\__,_|_|  |_| |_|\\___/|___/" << endl<<endl<<endl;

    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - CREAR TURNO           ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - BUSCAR TURNO          ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - MODIFICAR TURNO       ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  4 - CANCELAR TURNO        ||"<<endl;
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
            cout<<"CREAR TURNO";
        break;

        case 2:
            rlutil::cls();
            cout<<"BUSCAR TURNO";
        break;

        case 3:
            rlutil::cls();
            cout<<"MODIFICAR TURNO";
        break;

        case 4:
            rlutil::cls();
            cout<<"CANCELAR TURNO";
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


