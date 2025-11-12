#include <iostream>
#include <string>
#include "ArchivoMedico.h"
#include "Medico.h"
#include "Funciones.h"
#include "rlutil.h"
#include "MenuMedico.h"
#include "ArchivoEspecialidad.h"
using namespace std;


ArchivoMedico::ArchivoMedico(const string &nombreArchivo){
_nombreArchivo=nombreArchivo;
tamanioRegistro=sizeof(Medico);
}

bool ArchivoMedico::guardarMedico(const Medico &reg){
    FILE *pMedico;
    pMedico=fopen(_nombreArchivo.c_str(), "ab");

    if (pMedico==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    fwrite(&reg, sizeof(Medico), 1, pMedico);

    cout<<"Guardado exitoso"<<endl;

    fclose(pMedico);
    return true;
}

/*
bool ArchivoMedico::modificarRegistro(Medico &reg,int posicion){
    FILE *pMedico;
    pMedico=fopen(_nombreArchivo.c_str(),"rb+");

    if(pMedico==NULL)
    {
        return false;

        fseek(pMedico,posicion*tamanioRegistro,SEEK_SET);
        if(fwrite(&reg, tamanioRegistro,1,pMedico)!=1)
        {
            fclose(pMedico);
            return false;

        }
        cout << "Registro modificado con exito." << endl;
        fclose(pMedico);
        return true;
    }
}
*/
int ArchivoMedico::buscarRegistro(const string _idMedico){
Medico reg;

FILE *pMedico;
pMedico=fopen(_nombreArchivo.c_str(),"rb");
if(pMedico==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
    return -2;
}

    int pos=0;
    while(fread(&reg, tamanioRegistro,1,pMedico)==1){
       if(reg.getIdMedico()== "M-" + _idMedico){
            return pos;
       }
       pos++;
    }

    fclose(pMedico);
    return -1;
}

Medico ArchivoMedico::leerRegistro(int pos){
  Medico reg;
    FILE* pMedico=fopen(_nombreArchivo.c_str(), "rb");
        if (pMedico==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return reg;
    }
    fseek(pMedico, pos*tamanioRegistro,0);
    fread(&reg, tamanioRegistro, 1, pMedico);

    fclose(pMedico);
    return reg;
}

bool ArchivoMedico::leerRegistro(int posicion,Medico &reg){
FILE *pMedico;
pMedico=fopen(_nombreArchivo.c_str(),"rb");

if(pMedico==NULL)return false;

fseek(pMedico,tamanioRegistro* posicion,SEEK_SET);
if(fread(&reg,tamanioRegistro,1,pMedico)!=1){
    fclose(pMedico);
    return false;
}
fclose(pMedico);

return true;
}

bool ArchivoMedico::modificarRegistro(const std::string _idPaciente, int pos2){
    Medico reg;
    ArchivoMedico archivoMedico;
    ArchivoEspecialidad archivoEspecialidad;

    FILE* pMedico=fopen(_nombreArchivo.c_str(), "rb+");
        if (pMedico==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return false;
    }

    fseek(pMedico, pos2 * tamanioRegistro, 0);
    fread(&reg, tamanioRegistro, 1, pMedico);

    int opcionModificar=-1;
    Fecha nuevaFecha;
    do{
    system("cls");
    reg.mostrar();
    cout<<endl;

    cout << "================================" << endl;
    cout << "   SELECCIONE QUE MODIFICAR" << endl;
    cout << "================================" << endl;
    cout << "1.  DNI" << endl;
    cout << "2.  Nombre" << endl;
    cout << "3.  Apellido" << endl;
    cout << "4.  Domicilio" << endl;
    cout << "5.  Mail" << endl;
    cout << "6.  Telefono" << endl;
    cout << "7.  Sexo" << endl;
    cout << "8.  Fecha de Nacimiento" << endl;
    cout << "9.  Fecha de Ingreso" << endl;
    cout << "10. Cod.Especialidad" << endl;
    cout << "11. Matricula" << endl;
    cout << "0. Volver" << endl;
    cout << "================================" << endl;
    cout << "Opcion: ";
    cin >> opcionModificar;
    cin.ignore();

    while(opcionModificar>11||opcionModificar<0){
        cout<<"Numero incorrecto"<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>> opcionModificar;
        cin.ignore();
    }


    switch(opcionModificar) {
        case 1:{
            cout << "Ingrese nuevo DNI: ";

            string idMedico=cargarCadena();
            int posBuscar = archivoMedico.buscarRegistro(idMedico);
            if(posBuscar<0){
            reg.setDNI(idMedico);
            reg.setIdPersona(reg.getDNI());
            cout << endl;

            string idMed = "M-" + reg.getDNI();
            reg.setIdMedico(idMed);
            cout << "DNI modificado exitosamente." << endl;
            cin.get();
        }
        else{
                cout << endl;
                cout<<"El DNI ingresado pertenece a un medico ya registrado."<<endl<<endl;
                cout<<"Presione ENTER para continuar...";
                cin.get();
        }
        break;
        }

        case 2:
            cout << "Ingrese nuevo Nombre: ";
            reg.setNombre(cargarCadena());
            cout << "Nombre modificado exitosamente." << endl;
            break;

        case 3:
            cout << "Ingrese nuevo Apellido: ";
            reg.setApellido(cargarCadena());
            cout << "Apellido modificado exitosamente." << endl;
            break;

        case 4:
            cout << "Ingrese nuevo Domicilio: ";
            reg.setDomicilio(cargarCadena());
            cout << "Domicilio modificado exitosamente." << endl;
            break;

        case 5:
            cout << "Ingrese nuevo Mail: ";
            reg.setMail(cargarCadena());
            cout << "Mail modificado exitosamente." << endl;
            break;

        case 6:
            cout << "Ingrese nuevo Telefono: ";
            reg.setTelefono(cargarCadena());
            cout << "Telefono modificado exitosamente." << endl;
            break;

        case 7:{
            cout << "Ingrese nuevo Sexo (M/F): ";
            string sexo = cargarCadena();
            while(sexo != "M" && sexo!= "F"){
                cout<<endl;
                cout<<"El sexo ingresado no es valido. Por favor, ingrese M o F"<<endl;
                cout << "Sexo (M/F): ";
                sexo = cargarCadena();
            }
                reg.setSexo(sexo);
            cout << "Sexo modificado exitosamente." << endl;
            cin.get();
            break;
            }

        case 8: {
            cout << "Ingrese nueva Fecha de Nacimiento: " << endl;
            bool esValido;
            do{
                nuevaFecha.Cargar();
                esValido = nuevaFecha.verificarFecha();
                }
            while(esValido == false);
            reg.setFechaNac(nuevaFecha);
            cout << endl;
            cout << "Fecha de Nacimiento modificada exitosamente." << endl;
            cin.ignore();
            cin.get();
            break;
        }

        case 9: {
            Fecha nuevaFecha2;
            cout << "Ingrese nueva Fecha de Ingreso: " << endl;

            bool esValido2;
            do{
                nuevaFecha2.Cargar();
                esValido2 = nuevaFecha2.verificarFecha();
                }
            while(esValido2 == false);
            reg.setFechaIngreso(nuevaFecha2);
            cout << endl;
            cout << "Fecha de Ingreso modificada exitosamente." << endl;
            cin.ignore();
            cin.get();
            break;
        }

        case 10:
            cout << "Ingrese nuevo Codigo de Especialidad: ";
            int codEspecialidad;
            cin >> codEspecialidad;

            while(archivoEspecialidad.buscarRegistro(codEspecialidad) < 0){
                cout<<"El codigo de especialidad ingresado no existe. Por favor, vuelva a intentarlo..."<<endl;
                cout << "Cod de Especialidad: ";
                cin >> codEspecialidad;
            }
            reg.setCodEspecialidad(codEspecialidad);
            cout << "Codigo de Especialidad modificado exitosamente." << endl;
            cin.ignore();
            cin.get();
            break;

        case 11:
            cout << "Ingrese nuevo numero de Matricula: ";
            int matricula;
            cin >> matricula;

            while(archivoMedico.buscarPorMatricula(matricula) >= 0){
                cout<<"La matricula ingresada ya esta registrada. Por favor, vuelva a intentarlo..."<<endl;
                cout << "Matricula: ";
                cin >> matricula;
            }
            reg.setMatricula(matricula);
            cout << "Matricula modificada exitosamente." << endl;
            cin.ignore();
            cin.get();
            break;

        case 0:
           // menuMedico();
            break;

        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
    }

    }while (opcionModificar!=0);

    fseek(pMedico, pos2 * tamanioRegistro, 0);
    fwrite(&reg, tamanioRegistro, 1, pMedico);

    fclose(pMedico);
    return true;
}
bool ArchivoMedico::listarMedicos(){
    Medico reg;
    FILE* pMedico;
    pMedico=fopen(_nombreArchivo.c_str(), "rb");
    if (pMedico==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    while (fread(&reg, tamanioRegistro,1, pMedico)==1){
        reg.mostrar();
    }

    fclose(pMedico);
    return true;
}

/*
bool ArchivoMedico::bajaLogica(string idMedico){
    Medico reg;
    ArchivoMedico archi;
    int pos=archi.buscarRegistro(idMedico);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    return archi.modificarRegistro(reg, pos);
}

bool ArchivoMedico::altaLogica(string idMedico){
    Medico reg;
    ArchivoMedico archi;
    int pos=archi.buscarRegistro(idMedico);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(true);
    return archi.modificarRegistro(reg, pos);
}
*/

bool ArchivoMedico::cambioEstado(const std::string _idMedicp, int pos2){
    Medico reg;
    bool nuevoEstado;
    FILE* pMedico;
    pMedico=fopen(_nombreArchivo.c_str(), "rb+");

        if (pMedico==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return false;
    }

    fseek(pMedico, pos2 * tamanioRegistro, 0);
    fread(&reg, tamanioRegistro, 1, pMedico);

    cout<<"Medico: "<<reg.getNombre()<<" "<<reg.getApellido()<<endl;
    cout<<"Estado: "<<(reg.getEstado() ? "Activo" : "Inactivo")<<" "<<endl;
    int opcCambio;
    if(reg.getEstado()==1){
        cout<<"¨Desea pasar el medico a Estado Inactivo? 1.Si - 2.No:";
        cin>>opcCambio;
        cin.ignore();
        if(opcCambio==1){
            nuevoEstado = false;
            cout<<"El medico fue dado de Baja en el sistema"<<endl;
        }
    }else{
        cout<<"¨Desea cambiar el medico a Estado Activo? 1.Si - 2.No:";
        cin>>opcCambio;
        cin.ignore();
        if(opcCambio==1){
            nuevoEstado = true;
            cout<<"El medico fue dado de Alta en el sistema"<<endl;
        }
    }
    reg.setEstado(nuevoEstado);

    fseek(pMedico, pos2 * tamanioRegistro, 0);
    fwrite(&reg, tamanioRegistro, 1, pMedico);

    fclose(pMedico);
    return reg.getEstado();
}

int ArchivoMedico::buscarPorMatricula(int matricula){
Medico reg;

FILE *pMedico;
pMedico=fopen(_nombreArchivo.c_str(),"rb");
if(pMedico==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
    return -2;
}

    int pos=0;
    while(fread(&reg, tamanioRegistro,1,pMedico)==1){
       if(reg.getMatricula()== matricula){
            return pos;
       }
       pos++;
    }

    fclose(pMedico);
    return -1;
}
