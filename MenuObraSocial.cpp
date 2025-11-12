#include<iostream>
#include "rlutil.h"
#include "menuPrincipal.h"
#include "ObraSocial.h"
#include "ArchivoObraSocial.h"
using namespace std;



void menuObraSocial(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;
int posBuscar=0;
string nombreOS;
ArchivoObraSocial archivoOS;
ObraSocial obraSocial;

do{
    rlutil::cls();
    cout <<margenTitulo<< "   ___  _                 ____             _       _ " << endl;
    cout <<margenTitulo<< "  / _ \\| |__  _ __ __ _  / ___|  ___   ___(_) __ _| |" << endl;
    cout <<margenTitulo<< " | | | | '_ \\| '__/ _` | \\___ \\ / _ \\ / __| |/ _` | |" << endl;
    cout <<margenTitulo<< " | |_| | |_) | | | (_| |  ___) | (_) | (__| | (_| | |" << endl;
    cout <<margenTitulo<< "  \\___/|_.__/|_|  \\__,_| |____/ \\___/ \\___|_|\\__,_|_|" << endl<<endl<<endl;

    cout<<margenMenu<<" ================================="<<endl;
    cout<<margenMenu<<"||  1 - ALTA OBRA SOCIAL        ||"<<endl;
    cout<<margenMenu<<"||                              ||"<<endl;
    cout<<margenMenu<<"||  2 - BUSCAR OBRA SOCIAL      ||"<<endl;
    cout<<margenMenu<<"||                              ||"<<endl;
    cout<<margenMenu<<"||  3 - MODIFICAR OBRA SOCIAL   ||"<<endl;
    cout<<margenMenu<<"||                              ||"<<endl;
    cout<<margenMenu<<"||  4 - BAJA OBRA SOCIAL        ||"<<endl;
    cout<<margenMenu<<"||==============================||"<<endl;
    cout<<margenMenu<<"||  0 - VOLVER AL M. INICIAL    ||"<<endl;
    cout<<margenMenu<<" ================================="<<endl<<endl;

    cout<<margenMenu<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;

    while(numeroInicio>4||numeroInicio<0){
        cout<<margenMenu<<"Numero incorrecto"<<endl;
        cout<<margenMenu<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }

    switch(numeroInicio){
        case 1:
            cout << endl;
            rlutil::cls();
            cout << "=== ALTA DE OBRA SOCIAL ===" << endl;
            obraSocial.cargar();
        break;

        case 2:
            rlutil::cls();
            cout<<"====== BUSCAR OBRA SOCIAL ======" << endl;
            cout << "INGRESE NOMBRE DE LA OBRA SOCIAL: " << endl;
            cin >>  nombreOS;
            posBuscar= archivoOS.buscarObraSocial(nombreOS);
            if(posBuscar>=0){
                obraSocial=archivoOS.leerObraSocial(posBuscar);
                obraSocial.mostrar();
            }
            else cout << "Obra Social no encontrada." << endl;

        break;

        break;

        case 3:
              rlutil::cls();
            cout<<"===== MODIFICAR OBRA SOCIAL ======" << endl;
            cout << "INGRESE NOMBRE DE LA OBRA SOCIAL A MODIFICAR: " << endl;
            cin >> nombreOS;
            posBuscar=archivoOS.buscarObraSocial(nombreOS);
            if(posBuscar>=0){
                archivoOS.modificarObraSocial(posBuscar);
            } else cout << "Obra Social no encontrada." << endl;

        break;


        case 4:
              rlutil::cls();
            cout<<"======= ESTADO OBRA SOCIAL =======" << endl;
            cout << "INGRESE NOMBRE DE LA OBRA SOCIAL: ";
            cin >> nombreOS;
            posBuscar=archivoOS.buscarObraSocial(nombreOS);
            if(posBuscar>=0){
                archivoOS.cambioEstado(nombreOS,posBuscar);
            }else cout << "Obra Social no encontrada." << endl;
            cout << endl;
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;

    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


