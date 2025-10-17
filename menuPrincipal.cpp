#include<iostream>
#include "rlutil.h"
#include "menuPrincipal.h"
using namespace std;



void menuPrincipal(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;

do{
    rlutil::cls();
    cout <<margenTitulo<< " ____                      ____                      ____         __ _    " << endl;
    cout <<margenTitulo<< "/ ___|  __ _ _ __   __ _  / ___|  __ _ _ __   __ _  / ___|  ___  / _| |_  " << endl;
    cout <<margenTitulo<< "\\___ \\ / _` | '_ \\ / _` | \\___ \\ / _` | '_ \\ / _` | \\___ \\ / _ \\| |_| __| " << endl;
    cout <<margenTitulo<< " ___) | (_| | | | | (_| |  ___) | (_| | | | | (_| |  ___) | (_) |  _| |_  " << endl;
    cout <<margenTitulo<< "|____/ \\__,_|_| |_|\\__,_| |____/ \\__,_|_| |_|\\__,_| |____/ \\___/|_|  \\__| " << endl<<endl<<endl;

    cout<<margenMenu<<" =========================="<<endl;
    cout<<margenMenu<<"||  1 - TURNOOOOOOO       ||"<<endl;
    cout<<margenMenu<<"||                        ||"<<endl;
    cout<<margenMenu<<"||  2 - PACIENTE          ||"<<endl;
    cout<<margenMenu<<"||                        ||"<<endl;
    cout<<margenMenu<<"||  3 - MDICO            ||"<<endl;
    cout<<margenMenu<<"||                        ||"<<endl;
    cout<<margenMenu<<"||  4 - OBRA SOCIAL       ||"<<endl;
    cout<<margenMenu<<"||                        ||"<<endl;
    cout<<margenMenu<<"||  5 - FACTURACION       ||"<<endl;
    cout<<margenMenu<<"||                        ||"<<endl;
    cout<<margenMenu<<"||  6 - LISTADOS          ||"<<endl;
    cout<<margenMenu<<"||                        ||"<<endl;
    cout<<margenMenu<<"||  7 - REPORTES          ||"<<endl;
    cout<<margenMenu<<"||========================||"<<endl;
    cout<<margenMenu<<"||  0 - SALIR             ||"<<endl;
    cout<<margenMenu<<" =========================="<<endl<<endl;

    cout<<margenMenu<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;

    while(numeroInicio>7||numeroInicio<0){
        cout<<"Numero incorrecto"<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }

    switch(numeroInicio){
        case 1:
            rlutil::cls();
            cout<<"Turno";
        break;

        case 2:
            rlutil::cls();
            cout<<"Paciente";
        break;

        case 3:
            rlutil::cls();
            cout<<"Medico";
        break;

        case 4:
            rlutil::cls();
            cout<<"Obra Social";
        break;

        case 5:
            rlutil::cls();
            cout<<"Facturacion";
        break;

        case 6:
            rlutil::cls();
            cout<<"Listados";
        break;

        case 7:
            rlutil::cls();
            cout<<"Reportes";
        break;

        case 0:
            rlutil::cls();
            cout<<"Chau";
            rlutil::anykey();

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


