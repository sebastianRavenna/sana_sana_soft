#include <iostream>
#include <string>
#include "rlutil.h"
#include "menuTurno.h"
#include "ArchivoTurno.h"
#include "ArchivoAgenda.h"
#include "Fecha.h"
using namespace std;



void menuTurno(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio, posBuscar=0, idTurno;
ArchivoTurno arcTurno;
Turno turno;
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
            cout << "\n=== SOLICITAR TURNO ===" << endl;
            solicitarTurnoMenu();
        break;

        case 2:{
            rlutil::cls();
            int opcionBuscarTurno=-1;
            rlutil::cls();
            do{
            system("cls");
            cout<<endl;


            cout << "\n=== VER TURNOS ===" << endl<<endl;
            cout << "=====================================" << endl;
            cout << "1. Ver Todos los Turnos" << endl;
            cout << "2. Ver Turnos por Dia Elegido" << endl;
            cout << "3. Ver Turnos por Paciente" << endl;
            cout << "0. Volver" << endl;
            cout << "=====================================" << endl;
            cout << "Opcion: ";
            cin >> opcionBuscarTurno;
            cin.ignore();

            while(opcionBuscarTurno>3||opcionBuscarTurno<0){
                cout<<"Numero incorrecto"<<endl;
                cout<<"Ingrese la opcion deseada: ";
                cin>> opcionBuscarTurno;
                cin.ignore();
            }


                switch(opcionBuscarTurno) {
                    case 1:{
                        rlutil::cls();
                        arcTurno.listarTodosLosTurnos();
                        break;
                    }
                    case 2:{
                        Fecha fecha;
                        rlutil::cls();
                        cout << "INGRESE FECHA" << endl;
                        fecha.Cargar();
                        arcTurno.listarTurnosPorFecha(fecha);
                        break;
                        }
                    case 3:{
                        rlutil::cls();
                        std::string idPac;
                        cout<<"INGRESE DNI DEL PACIENTE: ";
                        cin>> idPac;
                        if(posBuscar>=0){
                            arcTurno.listarTurnosPorPaciente(idPac);
                        }else cout<<"Paciente no encontrado."<<endl;
                        cout<<endl;
                        break;
                        }
                    case 0:
                        break;

                    default:
                        cout << "Opcion invalida. Intente nuevamente." << endl;
                        break;
                }

            }while (opcionBuscarTurno!=0);
            break;
        }
        case 3:
            rlutil::cls();
            cout << "\n=== MODIFICAR TURNO ===" << endl;
            cout<<"INGRESE ID DEL TURNO A MODIFICAR: ";
            cin>> idTurno;
            posBuscar=arcTurno.buscarRegistro(idTurno);
            if(posBuscar>=0){
                arcTurno.modificarRegistro(idTurno, posBuscar);
            }else cout<<"Paciente no encontrado."<<endl;
            cout<<endl;
        break;

        break;

        case 4:
            rlutil::cls();
            cout << "\n=== CANCELAR TURNO ===" << endl;
            cout << "INGRESE EL ID DEL TURNO A CANCELAR: ";
            cin>>idTurno;
            arcTurno.cancelarTurno(idTurno);
        break;

        case 0:
            return;
    }
    }while (numeroInicio!=0);

}

void solicitarTurnoMenu() {
    string idPaciente, idMedico;
    Fecha fechaDesde, fechaHasta;
    ArchivoTurno arcTurno;

    cout << "\n=== SOLICITAR TURNO ===" << endl;

    cout << "ID del Paciente: ";
    cin >> idPaciente;

    cout << "ID del Medico: ";
    cin >> idMedico;

    cout << "\nFecha DESDE:" << endl;
    fechaDesde.Cargar();

    cout << "\nFecha HASTA:" << endl;
    fechaHasta.Cargar();

    arcTurno.solicitarTurno(idMedico, idPaciente, fechaDesde, fechaHasta);
}
