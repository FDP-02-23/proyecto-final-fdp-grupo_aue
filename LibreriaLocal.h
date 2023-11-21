//librerias a utilizar

#include <iostream> // Librería estándar de entrada y salida de datos.
#include <cstdlib> // Librería para funciones y constantes de uso general.
#include <fstream>  // Librería para realizar operaciones de entrada y salida de archivos.
using namespace std;

//funciones


bool correcto = true;

void limpiar(){
    system("cls");
}

void slogan(){
    cout<<"\nBIENVENIDO A TU CAJERO AUTOMATICO PREFERIDO \nTu dinero, tu tiempo, tu eleccion.\n ";
}

//---------------------------FUNCIONES DE AGREGAR E ELIMINAR USUARIOS---------------------

// Estructura para representar la información de un usuario
struct Usuario {
    string nombre;
    int pin;
};

// Función para verificar si un usuario existe
bool usuarioExiste(const string& usuario, ifstream& archivoUsuarios) {
    Usuario tempUsuario;

    while (archivoUsuarios >> tempUsuario.nombre >> tempUsuario.pin) {
        if (tempUsuario.nombre == usuario) {
            return true;
        }
    }

    return false;
}

// Función para agregar un nuevo usuario
void agregarUsuario(const string& archivoUsuarios) {
    Usuario nuevoUsuario;

    // Solicitar datos del nuevo usuario
    cout << "Ingrese el nombre de usuario: ";
    cin >> nuevoUsuario.nombre;

    // Verificar si el usuario ya existe
    ifstream archivoLectura(archivoUsuarios);
    if (usuarioExiste(nuevoUsuario.nombre, archivoLectura)) {
        cout << "El usuario ya existe. Intente con otro nombre de usuario." <<endl;
        return;
    }

    cout << "Ingrese el PIN: ";
    cin >> nuevoUsuario.pin;

    // Agregar el nuevo usuario al archivo
    ofstream archivoEscritura(archivoUsuarios,ios::app);  // Modo de apertura para agregar al final del archivo
    if (archivoEscritura.is_open()) {
        archivoEscritura << nuevoUsuario.nombre << " " << nuevoUsuario.pin <<endl;
        cout << "Usuario agregado correctamente." <<endl;
    } else {
        cout<< "Error al abrir el archivo de usuarios para agregar un nuevo usuario." <<endl;
    }
}

// Función para eliminar un usuario y su PIN
void eliminarUsuario(const string& archivoUsuarios) {
    string usuarioEliminar;
    cout << "Ingrese el nombre de usuario a eliminar: ";
    cin >> usuarioEliminar;

    ifstream archivoEntrada(archivoUsuarios);
    if (!archivoEntrada.is_open()) {
        cout<< "Error al abrir el archivo de usuarios para eliminar un usuario." <<endl;
        return;
    }

    ofstream archivoTemp("temp.txt");
    if (!archivoTemp.is_open()) {
        cout<< "Error al abrir el archivo temporal para eliminar un usuario." <<endl;
        return;
    }

    Usuario tempUsuario;
    bool usuarioEncontrado = false;

    while (archivoEntrada >> tempUsuario.nombre >> tempUsuario.pin) {
        if (tempUsuario.nombre == usuarioEliminar) {
            cout << "Usuario eliminado correctamente." <<endl;
            usuarioEncontrado = true;
        } else {
            archivoTemp << tempUsuario.nombre << " " << tempUsuario.pin <<endl;
        }
    }

    archivoEntrada.close();
    archivoTemp.close();

    // Renombrar el archivo temporal al original
    if (remove(archivoUsuarios.c_str()) != 0) {
        cout<< "Error al eliminar el archivo original de usuarios." <<endl;
        return;
    }

    if (rename("temp.txt", archivoUsuarios.c_str()) != 0) {
        cout << "Error al renombrar el archivo temporal." <<endl;
    }

    if (!usuarioEncontrado) {
        cout << "El usuario no existe." <<endl;
    }
}

// Función para mostrar todos los usuarios
void mostrarUsuarios(const string& archivoUsuarios) {
    ifstream archivoLectura(archivoUsuarios);
    if (!archivoLectura.is_open()) {
        cout<< "Error al abrir el archivo de usuarios para mostrar la lista." <<endl;
        return;
    }

    Usuario tempUsuario;

    cout << "\n===== Lista de Usuarios =====\n";
    while (archivoLectura >> tempUsuario.nombre >> tempUsuario.pin) {
        cout << "Nombre: " << tempUsuario.nombre << ", PIN: " << tempUsuario.pin <<endl;
    }

    archivoLectura.close();
}

// Función principal
void AgregarUsuarios() {
    string archivoUsuarios = "usuarios.txt";

    int opcion;

    // Menú principal
    do {
        cout << "\n===== Cajero Automatico =====\n";
        cout << "1. Agregar Usuario\n";
        cout << "2. Eliminar Usuario\n";
        cout << "3. Mostrar Todos los Usuarios\n";
        cout << "0. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarUsuario(archivoUsuarios);
                break;
            case 2:
                eliminarUsuario(archivoUsuarios);
                break;
            case 3:
                mostrarUsuarios(archivoUsuarios);
                break;
            case 0:
                break;
            default:
               cout << "Opcion no valida. Intente nuevamente." <<endl;
                break;
        }

    } while (opcion != 0);

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
            cout << "Dinero agregado correctamente." << endl;
        } else {
            cout<< "Error al abrir el archivo para guardar el saldo." <<endl;
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

