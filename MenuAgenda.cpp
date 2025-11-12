#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "menuAgenda.h"
#include "ArchivoAgenda.h"
#include "Funciones.h"
#include "Fecha.h"
#include "Hora.h"
using namespace std;



void menuAgenda(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio;
ArchivoAgenda arcAgenda;
Agenda agenda;

do{
    rlutil::cls();
    cout <<margenTitulo<< "    _                        _       " << endl;
    cout <<margenTitulo<< "   / \\   __ _  ___ _ __   __| | __ _ " << endl;
    cout <<margenTitulo<< "  / _ \\ / _` |/ _ \\ '_ \\ / _` |/ _` |" << endl;
    cout <<margenTitulo<< " / ___ \\ (_| |  __/ | | | (_| | (_| |" << endl;
    cout <<margenTitulo<< "/_/   \\_\\__, |\\___|_| |_|\\__,_|\\__,_|" << endl;
    cout <<margenTitulo<< "        |___/                        " << endl<<endl<<endl;

    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - CREAR AGENDA          ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - BUSCAR AGENDA         ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - SUSPENDER AGENDA      ||"<<endl;
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
        case 1:{
            int opcionCrearAgenda=-1;
            rlutil::cls();
            do{
            system("cls");
            cout<<endl;
            //cout << "Agenda: "<<agenda.getNombre()<<" "<<agenda.getApellido()<<endl<<endl;
            cout << "====================================" << endl;
            cout << "     SELECCIONE COMO DESEA CREAR" << endl;
            cout << "====================================" << endl;
            cout << "1. Crear Agenda de un solo Dia" << endl;
            cout << "2. Crear Agenda en un rango de Dias" << endl;
            cout << "0. Volver" << endl;
            cout << "====================================" << endl;
            cout << "Opcion: ";
            cin >> opcionCrearAgenda;
            cin.ignore();

            while(opcionCrearAgenda>2||opcionCrearAgenda<0){
                cout<<"Numero incorrecto"<<endl;
                cout<<"Ingrese la opcion deseada: ";
                cin>> opcionCrearAgenda;
                cin.ignore();
            }


            switch(opcionCrearAgenda) {
                case 1:{
                    rlutil::cls();
                    crearAgendaDia();
                    break;
                }
                case 2:
                    rlutil::cls();
                    crearAgendaRango();
                    break;
                case 0:
                    cout << "Volviendo al menu anterior..." << endl;
                    break;

                default:
                    cout << "Opcion invalida. Intente nuevamente." << endl;
                    break;
            }

            }while (opcionCrearAgenda!=0);
                break;
    }
        case 2:{
            rlutil::cls();
            int opcionBuscarAgenda=-1;
            rlutil::cls();
            do{
            system("cls");
            cout<<endl;

            cout << "=====================================" << endl;
            cout << "      SELECCIONE COMO DESEA BUSCAR" << endl;
            cout << "=====================================" << endl;
            cout << "1. Buscar Agenda Completa" << endl;
            cout << "2. Buscar Agenda en un dia especifico" << endl;
            cout << "3. Buscar Agenda en un rango de Dias" << endl;
            cout << "4. Buscar Agenda por Medico" << endl;
            cout << "0. Volver" << endl;
            cout << "=====================================" << endl;
            cout << "Opcion: ";
            cin >> opcionBuscarAgenda;
            cin.ignore();

            while(opcionBuscarAgenda>4||opcionBuscarAgenda<0){
                cout<<"Numero incorrecto"<<endl;
                cout<<"Ingrese la opcion deseada: ";
                cin>> opcionBuscarAgenda;
                cin.ignore();
            }


            switch(opcionBuscarAgenda) {
                case 1:{
                    rlutil::cls();
                    arcAgenda.listarAgendaCompleta();
                    break;
                }
                case 2:{
                    Fecha fecha;
                    rlutil::cls();
                    cout << "Ingrese fecha:" << endl;
                    fecha.Cargar();
                    arcAgenda.listarAgendaPorFecha(fecha);
                    break;
                    }
                case 3:{
                    rlutil::cls();
                    buscarAgendaRango();
                    break;
                    }
                case 4:{
                    rlutil::cls();
                    buscarAgendaPorMedicoRangoFecha();
                    break;
                    }
                case 0:
                    break;

                default:
                    cout << "Opcion invalida. Intente nuevamente." << endl;
                    break;
                }

                }while (opcionBuscarAgenda!=0);

                break;
}
        case 3:
            rlutil::cls();
            suspenderAgenda();
        break;

        case 0:
        return;
    }
    }while (numeroInicio!=0);

}


void crearAgendaDia(){
    int codEspecialidad, duracionMinutos;
    string idMedico;
    Fecha fecha;
    Hora horaInicio, horaFin;
    ArchivoAgenda arcAgenda;

    cout << "\n=== GENERAR AGENDA PARA UN DIA ===" << endl;

    cout << "ID del Medico: ";
    cin >> idMedico;

    if(arcAgenda.validarIdMedico(idMedico)){

        string nombreMedico = "M-" + idMedico;
        cout << "Medico: " << arcAgenda.obtenerNombreMedico(nombreMedico) << endl;

        cout << "Codigo de Especialidad: ";
        cin >> codEspecialidad;

        cout << "\nFecha de atencion:" << endl;
        fecha.Cargar();

        cout << "\nHora de INICIO de atencion:" << endl;
        horaInicio.Cargar();

        cout << "\nHora de FIN de atencion:" << endl;
        horaFin.Cargar();

        arcAgenda.ArchivoAgenda::generarAgenda(idMedico, codEspecialidad, fecha,
                                               horaInicio, horaFin);
        }else {
            cout << "El medico con DNI " << idMedico << " no existe" << endl;
            system("pause");
        }
}

void crearAgendaRango() {
    int codEspecialidad, duracionMinutos, cantidadDias;
    string idMedico;
    Fecha fechaDesde, fechaHasta;
    Hora horaInicio, horaFin;
    bool diasSemana[7] = {false};
    int respuesta;

    cout << "=== GENERAR AGENDA POR RANGO DE FECHAS ===" << endl;

    cout << "ID del Medico: ";
    cin >> idMedico;

    cout << "Codigo de Especialidad: ";
    cin >> codEspecialidad;

    cout << "\n¨Que dias de la semana atiende? (1.SI/0.NO)" << endl;
    cout << "Domingo: "; cin >> respuesta;
    diasSemana[0] = respuesta;
    cout << "Lunes: "; cin >> respuesta;
    diasSemana[1] = respuesta;
    cout << "Martes: "; cin >> respuesta;
    diasSemana[2] = respuesta;
    cout << "Miercoles: "; cin >> respuesta;
    diasSemana[3] = respuesta;
    cout << "Jueves: "; cin >> respuesta;
    diasSemana[4] = respuesta;
    cout << "Viernes: "; cin >> respuesta;
    diasSemana[5] = respuesta;
    cout << "Sabado: "; cin >> respuesta;
    diasSemana[6] = respuesta;

    cout << "\nFecha DESDE:" << endl;
    fechaDesde.Cargar();

    cout << "\nFecha HASTA:" << endl;
    fechaHasta.Cargar();

    cout << "\nHora de INICIO de atencion:" << endl;
    horaInicio.Cargar();

    cout << "\nHora de FIN de atencion:" << endl;
    horaFin.Cargar();

    ArchivoAgenda arcAgenda;
    arcAgenda.generarAgendaRango(idMedico, codEspecialidad,fechaDesde, fechaHasta,
                                 horaInicio, horaFin, diasSemana);

    cout << endl;
    cout << "=== AGENDA GENERADA CORRECTAMENTE ===" << endl;
    system("pause");
}

void buscarAgendaRango() {
    Fecha fechaDesde, fechaHasta;
    ArchivoAgenda arcAgenda;

    cout << "\n=== INDICAR RANGO ===" << endl;

    cout << "\nFecha DESDE:" << endl;
    fechaDesde.Cargar();

    cout << "\nFecha HASTA:" << endl;
    fechaHasta.Cargar();

    arcAgenda.listarAgendaPorRangoFecha(fechaDesde, fechaHasta);
}

void suspenderAgenda() {
    Fecha fechaDesde, fechaHasta;
    string idMedico;
    ArchivoAgenda arcAgenda;

    cout << "\n=== INDICAR MEDICO Y RANGO DE FECHAS ===" << endl;

    cout << "\nID MEDICO:" << endl;
    cin>>idMedico;
    cin.ignore();

    cout << "\nFecha DESDE:" << endl;
    fechaDesde.Cargar();

    cout << "\nFecha HASTA:" << endl;
    fechaHasta.Cargar();

    arcAgenda.cambioEstado(idMedico, fechaDesde, fechaHasta);
}

void buscarAgendaPorMedicoRangoFecha(){
    Fecha fechaDesde, fechaHasta;
    string idMedico;
    ArchivoAgenda arcAgenda;

    cout << "\n=== INDICAR MEDICO Y RANGO DE FECHAS ===" << endl;

    cout << "\nID MEDICO:" << endl;
    cin>>idMedico;
    cin.ignore();

    cout << "\nFecha DESDE:" << endl;
    fechaDesde.Cargar();

    cout << "\nFecha HASTA:" << endl;
    fechaHasta.Cargar();

    arcAgenda.listarAgendaPorMedicoRangoFecha(idMedico, fechaDesde, fechaHasta);
}

