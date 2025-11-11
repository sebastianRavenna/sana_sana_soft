#include <iostream>
#include <string>
#include "ArchivoPaciente.h"
#include "Paciente.h"
#include "Funciones.h"
#include "rlutil.h"

using namespace std;


ArchivoPaciente::ArchivoPaciente(const string &nombreArchivo){
            _nombreArchivo=nombreArchivo;
            tamanioRegistro=sizeof(Paciente);
}

bool ArchivoPaciente::guardarPaciente(Paciente pac){
    FILE *pPaciente=fopen(_nombreArchivo.c_str(), "ab");
    if (pPaciente==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    fwrite(&pac, sizeof(Paciente), 1, pPaciente);

    cout<<"Guardado exitoso"<<endl;
    fclose(pPaciente);
    return true;
}

int ArchivoPaciente::buscarPaciente(const std::string _idPaciente){
    Paciente pac;
    FILE* pPaciente=fopen(_nombreArchivo.c_str(), "rb");
        if (pPaciente==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return -2;
        }
    int pos=0;
    while(fread(&pac, tamanioRegistro, 1, pPaciente)==1){
        if(pac.getIdPaciente()=="P-"+ _idPaciente){
            return pos;
        }
        pos++;
    }
    fclose(pPaciente);
    return -1;
}

Paciente ArchivoPaciente::leerRegistro(int pos){
    Paciente pac;
    FILE* pPaciente=fopen(_nombreArchivo.c_str(), "rb");
        if (pPaciente==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return pac;
    }
    fseek(pPaciente, pos*tamanioRegistro,0); //pos*tama¤oRegistro multiplica la posicion por el tama¤o de cada registro para moverse dentro del archivo
    fread(&pac, tamanioRegistro, 1, pPaciente);

    fclose(pPaciente);
    return pac;
}


bool ArchivoPaciente::modificarRegistro(const std::string _idPaciente, int pos2){
    Paciente pac;
    FILE* pPaciente=fopen(_nombreArchivo.c_str(), "rb+");
        if (pPaciente==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return false;
    }

    fseek(pPaciente, pos2 * tamanioRegistro, 0);
    fread(&pac, tamanioRegistro, 1, pPaciente);

    int opcionModificar=-1;
    Fecha nuevaFecha;
    do{
    system("cls");
    pac.mostrar();
    cout<<endl;
    //cout << "Paciente: "<<pac.getNombre()<<" "<<pac.getApellido()<<endl<<endl;
    cout << "================================" << endl;
    cout << "   SELECCIONE QUE MODIFICAR" << endl;
    cout << "================================" << endl;
    cout << "1. DNI" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Apellido" << endl;
    cout << "4. Domicilio" << endl;
    cout << "5. Mail" << endl;
    cout << "6. Telefono" << endl;
    cout << "7. Sexo" << endl;
    cout << "8. Fecha de Nacimiento" << endl;
    cout << "9. Fecha de Ingreso" << endl;
    cout << "0. Volver" << endl;
    cout << "================================" << endl;
    cout << "Opcion: ";
    cin >> opcionModificar;
    cin.ignore();

    while(opcionModificar>9||opcionModificar<0){
        cout<<"Numero incorrecto"<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>> opcionModificar;
        cin.ignore();
    }


    switch(opcionModificar) {
        case 1:{
            cout << "Ingrese nuevo DNI: ";
            pac.setDNI(cargarCadena());
            pac.setIdPersona(pac.getDNI());
            cout << endl;

            string idPac = "P-" + pac.getDNI();
            pac.setIdPaciente(idPac);
            cout << "DNI modificado exitosamente." << endl;
            break;
        }
        case 2:
            cout << "Ingrese nuevo Nombre: ";
            pac.setNombre(cargarCadena());
            cout << "Nombre modificado exitosamente." << endl;
            break;

        case 3:
            cout << "Ingrese nuevo Apellido: ";
            pac.setApellido(cargarCadena());
            cout << "Apellido modificado exitosamente." << endl;
            break;

        case 4:
            cout << "Ingrese nuevo Domicilio: ";
            pac.setDomicilio(cargarCadena());
            cout << "Domicilio modificado exitosamente." << endl;
            break;

        case 5:
            cout << "Ingrese nuevo Mail: ";
            pac.setMail(cargarCadena());
            cout << "Mail modificado exitosamente." << endl;
            break;

        case 6:
            cout << "Ingrese nuevo Telefono: ";
            pac.setTelefono(cargarCadena());
            cout << "Telefono modificado exitosamente." << endl;
            break;

        case 7:
            cout << "Ingrese nuevo Sexo (M/F): ";
            pac.setSexo(cargarCadena());
            cout << "Sexo modificado exitosamente." << endl;
            break;

        case 8: {
            cout << "Ingrese nueva Fecha de Ingreso: " << endl;
            nuevaFecha.Cargar();
            pac.setFechaNac(nuevaFecha);
            cout << "Fecha de Nacimiento modificada exitosamente." << endl;
            break;
        }

        case 9: {
            Fecha nuevaFecha;
            cout << "Ingrese nueva Fecha de Ingreso: " << endl;
            nuevaFecha.Cargar();
            pac.setFechaIngreso(nuevaFecha);
            cout << "Fecha de Ingreso modificada exitosamente." << endl;
            break;
        }

        case 0:
            cout << "Volviendo al menu anterior..." << endl;
            break;

        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
    }

    }while (opcionModificar!=0);

    fseek(pPaciente, pos2 * tamanioRegistro, 0);
    fwrite(&pac, tamanioRegistro, 1, pPaciente);

    fclose(pPaciente);
    return true;
}

bool ArchivoPaciente::cambioEstado(const std::string _idPaciente, int pos2){
    Paciente pac;
    bool nuevoEstado;
    FILE* pPaciente=fopen(_nombreArchivo.c_str(), "rb+");
        if (pPaciente==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return false;
    }

    fseek(pPaciente, pos2 * tamanioRegistro, 0);
    fread(&pac, tamanioRegistro, 1, pPaciente);

    cout<<"Paciente: "<<pac.getNombre()<<" "<<pac.getApellido()<<endl;
    cout<<"Estado: "<<(pac.getEstado() ? "Activo" : "Inactivo")<<" "<<endl;
    int opcCambio;
    if(pac.getEstado()==1){
        cout<<"¨Desea pasar el paciente a Estado Inactivo? 1.Si - 2.No:";
        cin>>opcCambio;
        cin.ignore();
        if(opcCambio==1){
            nuevoEstado = false;
            cout<<"El paciente fue dado de Baja en el sistema"<<endl;
        }
    }else{
        cout<<"¨Desea cambiar el paciente a Estado Activo? 1.Si - 2.No:";
        cin>>opcCambio;
        cin.ignore();
        if(opcCambio==1){
            nuevoEstado = true;
            cout<<"El paciente fue dado de Alta en el sistema"<<endl;
        }
    }
    pac.setEstado(nuevoEstado);

    fseek(pPaciente, pos2 * tamanioRegistro, 0);
    fwrite(&pac, tamanioRegistro, 1, pPaciente);

    fclose(pPaciente);
    return pac.getEstado();
}

bool ArchivoPaciente::listarPacientes(){
    Paciente pac;
    FILE* pPaciente=fopen(_nombreArchivo.c_str(), "rb");
    if (pPaciente==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    while (fread(&pac, tamanioRegistro,1, pPaciente)==1){
        pac.mostrar();
    }

    fclose(pPaciente);
    return true;
}

/*bool ArchivoPaciente::leerRegistro(int posicion,Paciente &reg){

FILE *pPaciente;
pPaciente=fopen(_nombreArchivo.c_str(),"rb");

if(pPaciente==NULL)return false;

fseek(pPaciente,tamanioRegistro* posicion,SEEK_SET);
if(fread(&reg,tamanioRegistro,1,pPaciente)!=1){
    fclose(pPaciente);
    return false;
}
fclose(pPaciente);

return true;
}*/


int ArchivoPaciente::contarRegistros(){
    FILE* pPaciente = fopen(_nombreArchivo.c_str(), "rb");
    if(pPaciente == NULL){
        return 0;
    }
    fseek(pPaciente, 0, SEEK_END);
    int cantidadRegistros = ftell(pPaciente) / tamanioRegistro;
    fclose(pPaciente);
    return cantidadRegistros;
}


bool ArchivoPaciente::listarTodoPorApellido(){
    int tam = contarRegistros();
    if(tam == 0){
        cout<<"No hay registros para listar"<<endl<<endl;
        return true;
    }
    //necesitamos si o si un vector dinamico para poder ordenar
    Paciente *vectorPacientes;
    vectorPacientes = new Paciente[tam];

    Paciente pac;
    FILE* pEspecialidad = fopen(_nombreArchivo.c_str(), "rb");
    if(pEspecialidad == NULL){
        cout<<"Error en el Archivo"<<endl;
        delete[] vectorPacientes;
        return false;
    }
    int i=0;
    while(fread(&pac, tamanioRegistro, 1, pEspecialidad)== 1){ // vamos copiando el contenido del archivoHistoriaClinica en el vector dinamico que creamos
        vectorPacientes[i] = pac;
        i++;
    }
    fclose(pEspecialidad);

    for(int i=0; i<tam - 1; i++ ){ //aca va tam-1, porque tomamos un valor del vector y lo comparamos con el siguiente para ver cual es el menor. Si el vector llega a su ultimo elemento, no va a tener un "siguiente" contra quien compararse y por eso va a dar error. Por eso, la iteracion solo llega hasta el penultimo valor del vector
        int indexmenor = i;

        for(int j=i+1; j<tam; j++){ // aca va j=i+1, porque es la manera de "llamar" al valor siguiente de i para poder hacer la comparacion. Tambien va j<tam, porque necesita llegar al ultimo valor del vector para compararlo con i (que llega hasta el penultimo valor del vector)
            string nombreJ = vectorPacientes[j].getApellido();
            string nombreMenor = vectorPacientes[indexmenor].getApellido();

            if(nombreJ<nombreMenor){
                indexmenor = j;
            }
        }
        Paciente pacAux = vectorPacientes[i];
        vectorPacientes[i] = vectorPacientes[indexmenor];
        vectorPacientes[indexmenor] = pacAux;
    }
    for(int i=0; i<tam; i++){
        vectorPacientes[i].mostrar();
        cout<<"------------------------------"<<endl;
        cout<<endl;
    }
    delete[] vectorPacientes;
    return true;
}

