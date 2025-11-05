#include<iostream>
#include "rlutil.h"
#include <string>
#include "menuEspecialidad.h"
#include "Medico.h"
#include "ArchivoMedico.h"
#include "Funciones.h"

using namespace std;



void menuMedico(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio,posBuscar=0;
Medico medico;
ArchivoMedico archivoMedico;
string idMed;

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
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  6 - ESPECIALIDAD          ||"<<endl;
    cout<<margenMenu<<"||============================||"<<endl;
    cout<<margenMenu<<"||  0 - VOLVER AL M. INICIAL  ||"<<endl;
    cout<<margenMenu<<" =============================="<<endl<<endl;

    cout<<margenMenu<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;

    while(numeroInicio>6||numeroInicio<0){
        cout<<margenMenu<<"Numero incorrecto"<<endl;
        cout<<margenMenu<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }


    switch(numeroInicio){
        case 1:
            cout << endl;
            rlutil::cls();
            cout << "\n=== ALTA DE MEDICO ===" << endl;
            medico.cargar();
            cout << endl;
        break;

        case 2:
            rlutil::cls();
            cout << "\n=== BUSCAR MEDICO ===" <<endl<<endl;
            cout<<"INGRESE DNI DEL MEDICO: ";
            cin>> idMed;
            posBuscar=archivoMedico.buscarRegistro(idMed);
            if(posBuscar>=0){
                medico=archivoMedico.leerRegistro(posBuscar);
                medico.mostrar();
            }
            else cout << "Medico no encontrado." << endl;
            cout << endl;
        break;

        case 3:
            rlutil::cls();
            cout << "\n=== MODIFICAR MEDICO ===" <<endl<<endl;
            cout<<"INGRESE DNI DEL MEDICO A MODIFICAR: ";
            cin >> idMed;
            posBuscar=archivoMedico.buscarRegistro(idMed);
            if(posBuscar>=0){
                archivoMedico.modificarRegistro(idMed,posBuscar);
            } else cout << "Medico no encontrado." << endl;
            cout << endl;
        break;

        case 4:
            rlutil::cls();

            cout << "\n=== ESTADO DE MEDICO ===" <<endl<<endl;
            cout<<"INGRESE DNI DEL MEDICO: ";
            cin>> idMed;
            posBuscar=archivoMedico.buscarRegistro(idMed);
            if(posBuscar>=0){
                archivoMedico.cambioEstado(idMed, posBuscar);
            }else cout<<"Medico no encontrado."<<endl;
            cout<<endl;
        break;

        case 5:
            rlutil::cls();
            cout<<"AGENDA";
        break;

        case 6:
            rlutil::cls();
            menuEspecialidad();
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


