//librerias a utilizar

#include <iostream> // Librería estándar de entrada y salida de datos.
#include <cstdlib> // Librería para funciones y constantes de uso general.
#include <fstream>  // Librería para realizar operaciones de entrada y salida de archivos.
#include <string>
using namespace std;

//funciones


bool correcto = true;

void limpiar(){
    system("cls");
}

void slogan(){
    cout<<"Tu dinero, tu tiempo, tu eleccion.\n";
}

void AgregarUsuarios()// esta funcion va a guardar las personas que vayan ingresando al sistema
{
    ifstream archivo("usuarios ingresados.txt");
    string linea;

    if (archivo.is_open())
    {
        while (getline(archivo, linea))
        {
            cout << linea <<endl;
        }

        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo agregar a usuarios." << endl;
    }
}

void EliminarUsuario()//eliminar el usuario ingresado
{
    ifstream archivo("usuarios eliminados.txt");
    string linea;

    if (archivo.is_open())
    {
        while (getline(archivo,linea))
        {
            cout<< linea << endl;
        }

        archivo.close();
    }
    else {
        cout<<"no se puede abrir el archivo usuarios eliminados.";
    }
    

}

//----- ---FUNCION PARA RELLENAR EL CAJERO, ELIMINAR y MOSTRAR DINERO DISPONIBLE EN EL CAJERO---------------

// Función para obtener el saldo actual del archivo
int obtenerSaldo(string archivoSaldo) {
    ifstream archivo(archivoSaldo);
    int saldo = 0;
    if (archivo.is_open()) {
        archivo >> saldo;
        archivo.close();
    }
    return saldo;
}

// Función para mostrar el saldo actual
void mostrarSaldo(string archivoSaldo) {
    int saldo = obtenerSaldo(archivoSaldo);
    cout<<"Saldo actual: $" << saldo <<endl;
}

// Función para rellenar dinero en el cajero y actualizar el archivo
void rellenarDinero(string archivoSaldo) {
    int cantidad;
    cout << "Ingrese la cantidad de dinero a agregar: $";
    cin >> cantidad;

    if (cantidad > 0) {
        int saldoActual = obtenerSaldo(archivoSaldo);
        saldoActual += cantidad;

        ofstream archivo(archivoSaldo);
        if (archivo.is_open()) {
            archivo << saldoActual;
            archivo.close();
            cout << "Dinero agregado correctamente." << std::endl;
        } else {
            cout<< "Error al abrir el archivo para guardar el saldo." << std::endl;
        }
    } else {
        cout << "Ingrese una cantidad valida." <<endl;
    }
}

void eliminarDatos(string archivoSaldo) {
    ofstream archivo(archivoSaldo);
    if (archivo.is_open()) {
        archivo << 0;  // Establecer el saldo a cero
        archivo.close();
        cout << "Datos eliminados correctamente." <<endl;
    } else {
        cout << "Error al abrir el archivo para eliminar los datos." <<endl;
    }
}

void RellenarCajero(){

string archivoSaldo = "saldo.txt";

    int opcion=0;

    do {
        cout << "\n----- Cajero Automatico -----\n";
        cout << "1. Mostrar Saldo\n";
        cout << "2. Rellenar Dinero\n";
        cout << "3. Eliminar Datos\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarSaldo(archivoSaldo);
                break;
            case 2:
                rellenarDinero(archivoSaldo);
                break;
            case 3:
                eliminarDatos(archivoSaldo);
                break;
            case 4:
                cout << "Saliendo del programa. Gracias por usar el cajero automatico." <<endl;
                break;

            default:
                cout<< "Opción no valida. Intente nuevamente." <<endl;
                break;
        }

    } while(opcion != 4);

}

//-------------------funcion para iniciar seccion para poder ingresar al menu de administracion---------------
bool seccionAdmin() {
    string User, PassW;
    int intentos = 0;
    while (intentos < 3)
    {
        cout<<"\ningrese sus credenciales como administrador por favor\n";
        cout<< "\nIngrese el nombre de usuario: ";
        cin>> User;
        cout<< "Ingrese la contrasenia: ";
        cin>> PassW;

        if (User == "admin" && PassW == "admin123")
        {
            return true;
        }
        else
        {
            intentos++;
            cout << "Datos incorrectos. Intentos restantes: " << 3 - intentos << endl;
        }
    }

    cout << "Ha excedido el numero de intentos. Reiniciando el programa..." << endl;
    return false;
    
    }

