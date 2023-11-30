//librerias a utilizar

#include <iostream> // Librería estándar de entrada y salida de datos.
#include <cstdlib> // Librería para funciones y constantes de uso general.
#include <fstream>  // Librería para realizar operaciones de entrada y salida de archivos.
using namespace std;

//---------funciones--------------

//funcion para limpiar pantalla
void limpiar(){
    system("cls");
}

//slogan del cajero
void slogan(){
    cout<<"\nBIENVENIDO A TU CAJERO AUTOMATICO PREFERIDO \nTu dinero, tu tiempo, tu eleccion.\n ";
}

//---------------------------FUNCIONES DE AGREGAR E ELIMINAR USUARIOS--------------------------------------

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

    cout << "Ingrese el PIN de seguridad: ";
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
        cout<<"======================="<<endl;
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

const int tiposBilletes = 5;
const int tipos[] = {1, 5, 10, 20, 100};

// Estructura para representar el estado del cajero automático
 struct Cajero {
    int billetes[tiposBilletes];
 };

//funcion para el menu de opciones 
 int mostrarMenu(){

    int opcRellenar;

    cout<<"\n------BIENVENIDO------\n"<<endl;
    cout<<"eliga una opcion.\n"<<endl;
    cout<<"1.rellenar de dinero al cajero"<<endl;
    cout<<"2.eliminar dinero del cajero"<<endl;
    cout<<"3.mostrar estado del cajero"<<endl;
    cout<<"4.salir"<<endl;
    cout<<"\nponga su opcion :"; 
    cin>> opcRellenar;

    return opcRellenar;
 }
// funcion para rellenar de dinero al cajero automatico
 void ingresarDinero(Cajero &cajero_r) {

    ofstream archivo("relleno_De_Dinero.txt",ios::app);
    // Bucle para iterar a través de los tipos de billetes
    for (int i = 0; i < tiposBilletes; ++i) {
        // Variable para almacenar la cantidad de billetes ingresados por el usuario
        int cantidad;

        // Solicitar al usuario que ingrese la cantidad de billetes de la denominación actual
        cout << "Ingrese la cantidad de billetes de $" << tipos[i] << ": ";
        cin >> cantidad;

        // Actualizar la cantidad de billetes en el arreglo 'billetes' del objeto 'cajero'
        cajero_r.billetes[i] += cantidad;
    }
    
    archivo.close();

    // Mensaje indicando que el dinero ha sido ingresado correctamente
    cout << "\nDinero ingresado correctamente.\n";
 }
 
  void verEstadoCajero(const Cajero &cajero_r){

     ofstream archivo("relleno_De_Dinero.txt",ios::app);// Abre el archivo en modo de adjuntar
     
     cout << "\nEstado del cajero:\n";

    for (int i = 0; i < tiposBilletes; ++i) {
        cout << "Billetes de $" << tipos[i] << ": " << cajero_r.billetes[i] << endl;
    }

    // Calcular la suma total de todos los billetes ingresados
    int sumaTotal = 0;
    for (int i = 0; i < tiposBilletes; ++i) {
        sumaTotal += tipos[i] * cajero_r.billetes[i];
    }
    archivo.close();
    cout << "\n total del dinero : $" << sumaTotal << endl;

 }
 

 void retirarDinero(Cajero &cajero_r) {
    // Bucle para iterar a través de los tipos de billetes
    for (int i = 0; i < tiposBilletes; ++i) {
        // Variable para almacenar la cantidad de billetes a retirar
        int cantidad;

        // Solicitar al usuario que ingrese la cantidad de billetes de la denominación actual a retirar
        cout << "Ingrese la cantidad de billetes de $" << tipos[i] << " a retirar: ";
        cin >> cantidad;

        // Verificar si hay suficientes billetes para retirar
        if (cantidad <= cajero_r.billetes[i]) {
            // Actualizar la cantidad de billetes en el arreglo 'billetes' del objeto 'cajero'
            cajero_r.billetes[i] -= cantidad;
        } else {
            cout << "No hay suficientes billetes de $" << tipos[i] << " en el cajero.\n";
        }
    }

    // Mensaje indicando que el dinero ha sido retirado correctamente
    cout << "\nDinero retirado correctamente.\n";
};


void mostarCajero(Cajero &cajero_r){

  ofstream archivo("relleno_De_Dinero.txt");
  for (int i = 0; i < tiposBilletes; ++i) {
    archivo << "Billetes de $" << tipos[i] << ": " << cajero_r.billetes[i] << endl;
  }
  archivo.close();

};



 void RellenoCajero(){

    Cajero Cajero_r={0};

    int opcion;
    do {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                ingresarDinero(Cajero_r);
                mostarCajero(Cajero_r);
                break;
            case 2:
                retirarDinero(Cajero_r);
                mostarCajero(Cajero_r);
                break;
            case 3:
                verEstadoCajero(Cajero_r);
                mostarCajero(Cajero_r);
                break;

            case 4:
            break;

            default:
                cout << "Opción inválida. Por favor, intente de nuevo.\n";
        }

    } while (opcion != 4);


 }
 

//------------------------FUNCION PARA PODER INICAR SESION COMO ADMINISTRADOR-----------------------------
bool seccionAdmin() {
    bool correcto = true;
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

// Funcion menu usuario
void menuUser(){
int opcionUser, retiroDinero;
// Saber cantidad de dinero para poder retirar
int billeteCien = 0, billeteVeinte = 0, billeteDiez = 0, billeteCinco = 0, billeteUno = 0;
       do
       {
        cout << "\n===== Cajero Automatico =====\n";
        cout << "1. Depositar dinero\n";
        cout << "2. Retirar dinero\n";
        cout << "3. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcionUser;

        switch (opcionUser) {
            case 1:
            cout << "caso Depositar dinero";
            limpiar();
            slogan();
                break;

            case 2: // Retirar dinero
            limpiar();
            slogan();
            cout << "\nIngrese la cantidad de dinero a retirar: ";
            cin >> retiroDinero;
            
            do {
                while (retiroDinero >= 100)
                {
                    retiroDinero = retiroDinero - 100;
                    ++billeteCien;
                }

                while (retiroDinero >= 20)
                {
                    retiroDinero = retiroDinero - 20;
                    ++billeteVeinte;
                }

                while (retiroDinero >= 10)
                {
                    retiroDinero = retiroDinero - 10;
                    ++billeteDiez;
                }

                while (retiroDinero >= 5)
                {
                    retiroDinero = retiroDinero - 5;
                    ++billeteCinco;
                }

                while (retiroDinero >= 1)
                {
                    retiroDinero = retiroDinero - 1;
                    ++billeteUno;
                }
                
            } while (retiroDinero > 0);
            
            cout << "Cantidad:\n100: " << billeteCien 
            << "\n20: " << billeteVeinte 
            << "\n10: " << billeteDiez 
            << "\n5: " << billeteCinco 
            << "\n1: " << billeteUno;
                break;
            
            default:
               cout << "Opcion no valida. Intente nuevamente." <<endl;
                break;
        }

    } while (opcionUser != 3);
}

