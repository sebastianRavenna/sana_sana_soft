#include<iostream>
#include "rlutil.h"
#include "menuPrincipal.h"
using namespace std;



void menuReportes(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;

do{
    rlutil::cls();
    cout <<margenTitulo<< "  ____                       _            " << endl;
    cout <<margenTitulo<< " |  _ \\ ___ _ __   ___  _ __| |_ ___  ___ " << endl;
    cout <<margenTitulo<< " | |_) / _ \\ '_ \\ / _ \\| '__| __/ _ \\/ __|" << endl;
    cout <<margenTitulo<< " |  _ <  __/ |_) | (_) | |  | ||  __/\\__ \\" << endl;
    cout <<margenTitulo<< " |_| \\_\\___| .__/ \\___/|_|   \\__\\___||___/" << endl;
    cout <<margenTitulo<< "            |_|                            " << endl<<endl<<endl;

    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - FACTURACION           ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - PACIENTES             ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - MEDICOS               ||"<<endl;
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
            cout<<"FACTURACION";
        break;

        case 2:
            rlutil::cls();
            cout<<"PACIENTES";
        break;

        case 3:
            rlutil::cls();
            cout<<"MEDICOS";
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";
            rlutil::anykey();

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


