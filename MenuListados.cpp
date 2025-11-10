#include<iostream>
#include "rlutil.h"
#include "ArchivoPaciente.h"
#include "ArchivoEspecialidad.h"
#include "ArchivoHistoriaClinica.h"
using namespace std;



void menuListado(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;
ArchivoPaciente pacientes;
ArchivoEspecialidad archivoEspecialidad;
ArchivoHistoriaClinica archivoHistoriaClinica;


do{
    system("cls");//tuve que usar este porque el rlutil no limpiaba toda la pantalla quedaba residuos del ALTA
    //rlutil::cls();
    cout <<margenTitulo<< "  _     _     _            _           " << endl;
    cout <<margenTitulo<< " | |   (_)___| |_ __ _  __| | ___  ___ " << endl;
    cout <<margenTitulo<< " | |   | / __| __/ _` |/ _` |/ _ \\/ __|" << endl;
    cout <<margenTitulo<< " | |___| \\__ \\ || (_| | (_| | (_) \\__ \\" << endl;
    cout <<margenTitulo<< " |_____|_|___/\\__\\__,_|\\__,_|\\___/|___/" << endl<<endl<<endl;

    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - LISTAR TURNOS         ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - LISTAR PACIENTES      ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - LISTAR H. CLINICAS    ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  4 - LISTAR MEDICOS        ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  5 - LISTAR O. SOCIALES    ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  6 - LISTAR FACTURAS       ||"<<endl;
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
    cin.ignore(1000, '\n');

    switch(numeroInicio){
        case 1:
            rlutil::cls();
            cout<<"LISTAR TURNOS";
        break;

        case 2:
            rlutil::cls();
            cout << "\n=== LISTANDO PACIENTES DEL ARCHIVO ===" << endl<< endl;
            pacientes.listarPacientes();
        break;

        case 3:
            rlutil::cls();
            cout<<"=== LISTAR HISTORIAS CLINICAS ==="<<endl<<endl;
            cout<<" =============================="<<endl;
            cout<<"||  1 - POR ID                ||"<<endl;
            cout<<"||                            ||"<<endl;
            cout<<"||  2 - POR FECHA             ||"<<endl;
            cout<<"||                            ||"<<endl;
            cout<<"||  3 - POR DNI PACIENTE      ||"<<endl;
            cout<<"||============================||"<<endl;
            cout<<"||  0 - VOLVER AL M. ANTERIOR ||"<<endl;
            cout<<" =============================="<<endl<<endl;

            cout<<"Ingrese la opcion deseada: ";
            cin>> numeroInicio;

            if(numeroInicio == 1){
                    rlutil::cls();
                    cout<<"=== HISTORIAS CLINICAS ORDENADAS POR ID ==="<<endl<<endl;
                    archivoHistoriaClinica.listarHistoriaClinica();
                    cout<<endl<<endl;
                    cout<<"Presione ENTER para continuar...";
            }
            else if(numeroInicio == 2){
                    rlutil::cls();
                    cout<<"=== HISTORIAS CLINICAS ORDENADAS POR FECHA ==="<<endl<<endl;
            }
            else if(numeroInicio == 3){
                    rlutil::cls();
                    cout<<"=== HISTORIAS CLINICAS ORDENADAS POR DNI PACIENTE ==="<<endl<<endl;
            }
            else{
                    cout<<"Opcion no valida."<<endl<<endl;
                    cout<<"Presione ENTER para continuar...";
            }

        break;

        case 4:
            rlutil::cls();
            cout<<"LISTAR MEDICOS";
        break;

        case 5:
            rlutil::cls();
            cout<<"LISTAR O. SOCIALES";
        break;

        case 6:
            rlutil::cls();
            cout<<"LISTAR FACTURAS";
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


