#include<iostream>
#include "rlutil.h"
#include "MenuPrincipal.h"
#include "MenuFacturacion.h"
#include "MenuListados.h"
#include "MenuMedico.h"
#include "MenuObraSocial.h"
#include "MenuPaciente.h"
#include "MenuReportes.h"
#include "MenuTurno.h"

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

    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - TURNO                 ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - PACIENTE              ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - MDICO                ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  4 - OBRA SOCIAL           ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  5 - FACTURACION           ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  6 - LISTADOS              ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  7 - REPORTES              ||"<<endl;
    cout<<margenMenu<<"||============================||"<<endl;
    cout<<margenMenu<<"||  0 - SALIR                 ||"<<endl;
    cout<<margenMenu<<" =============================="<<endl<<endl;

    cout<<margenMenu<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;

    while(numeroInicio>7||numeroInicio<0){
        cout<<margenMenu<<"Numero incorrecto"<<endl;
        cout<<margenMenu<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }


    switch(numeroInicio){
        case 1:
            rlutil::cls();
            menuTurno();
        break;

        case 2:
            rlutil::cls();
            menuPaciente();
        break;

        case 3:
            rlutil::cls();
            menuMedico();
        break;

        case 4:
            rlutil::cls();
            menuObraSocial();
        break;

        case 5:
            rlutil::cls();
            menuFacturacion();
        break;

        case 6:
            rlutil::cls();
            menuListado();
        break;

        case 7:
            rlutil::cls();
            menuReportes();
        break;

        case 0:
            rlutil::cls();
            cout<<"Chau";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


