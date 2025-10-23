#include <iostream>
#include "rlutil.h"
#include "menuPrincipal.h"
#include "menuHistoriaClinica.h"
#include "HistoriaClinica.h"
using namespace std;

void meniHistoriaClinica(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;

do{
    rlutil::cls();

    cout <<margenTitulo<< " _   _ _     _             _          ____ _ _       _" << endl;
    cout <<margenTitulo<< "| | | (_)___| |_ ___  _ __(_) __ _   / ___| (_)_ __ (_) ___ __ _" << endl;
    cout <<margenTitulo<< "| |_| | / __| __/ _ \\| '__| |/ _` | | |   | | | '_ \\| |/ __/ _` |" << endl;
    cout <<margenTitulo<< "|  _  | \\__ \\ || (_) | |  | | (_| | | |___| | | | | | | (_| (_| |" << endl;
    cout <<margenTitulo<< "|_| |_|_|___/\\__\\___/|_|  |_|\\__,_|  \\____|_|_|_| |_|_|\\___\\__,_|" << endl<<endl<<endl;


    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - CREAR H. CLINICA      ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - BUSCAR H. CLINICA     ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - MODIFICAR H. CLINICA  ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
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
    HistoriaClinica historia;

    switch(numeroInicio){
        case 1:
            rlutil::cls();
            historia.cargar();
            historia.mostrar(); //prueba!!

        break;

        case 2:
            rlutil::cls();
            cout<<"BUSCAR H. CLINICA";
        break;

        case 3:
            rlutil::cls();
            cout<<"MODIFICAR H. CLINICA";
        break;

        case 4:
            rlutil::cls();
            cout<<"BAJA H. CLINICA";
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


