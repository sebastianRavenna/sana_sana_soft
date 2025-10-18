#include<iostream>
#include "rlutil.h"
#include "menuPrincipal.h"
#include "Medico.h"
using namespace std;



void menuMedico(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;

do{
    rlutil::cls();
    cout <<margenTitulo<< "  __  __          _ _                 " << endl;
    cout <<margenTitulo<< " |  \\/  | ___  __| (_) ___ ___  ___  " << endl;
    cout <<margenTitulo<< " | |\\/| |/ _ \\/ _` | |/ __/ _ \\/ __| " << endl;
    cout <<margenTitulo<< " | |  | |  __/ (_| | | (_| (_) \\__ \\ " << endl;
    cout <<margenTitulo<< " |_|  |_|\\___|\\__,_|_|\\___\\___/|___/ " << endl<<endl<<endl;

    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - ALTA MEDICO           ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - BUSCAR MEDICO         ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - MODIFICAR MEDICO      ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  4 - BAJA MEDICO           ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  5 - AGENDA                ||"<<endl;
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

    Medico medico;
    switch(numeroInicio){
        case 1:
            rlutil::cls();
            medico.cargar();
        break;

        case 2:
            rlutil::cls();
            cout<<"BUSCAR MEDICO";
        break;

        case 3:
            rlutil::cls();
            cout<<"MODIFICAR MEDICO";
        break;

        case 4:
            rlutil::cls();
            cout<<"BAJA MEDICO";
        break;

        case 5:
            rlutil::cls();
            cout<<"AGENDA";
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


