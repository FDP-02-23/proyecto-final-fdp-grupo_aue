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

// Definición de la estructura para almacenar información del usuario
struct usuario
{
    string nombre;
    string password;
};

// Función para agregar un nuevo usuario al archivo
void agregarUsuario() {
    usuario agregado;

    // Nombre del archivo que almacenará la información de los usuarios
    string archivoUsuarios = "ingresados.txt";

    // Abre el archivo en modo de añadir (append)
    ofstream ingresados(archivoUsuarios, ios::app);

    if (ingresados.is_open()) {
        // Solicita al usuario que ingrese su nombre vinculado a la cuenta
        cout << "\nIngrese su nombre enlazado con la cuenta: ";
        cin.ignore();
        getline(cin, agregado.nombre);

        // Solicita al usuario que ingrese su contraseña de la cuenta
        cout << "\nIngrese su contrasena de su cuenta: ";
        getline(cin, agregado.password);

        // Escribe la información del usuario en el archivo
        ingresados << "nombre: " << agregado.nombre << endl;
        ingresados << "contrasena: " << agregado.password << endl;

        // Cierra el archivo y muestra un mensaje de éxito
        ingresados.close();
        cout << "\nIngresado exitosamente\n";
    } else {
        // Muestra un mensaje si no se puede abrir el archivo
        cout << "No se puede abrir el archivo\n";
    }
}

// Función para mostrar todos los usuarios registrados
void mostrarUsuarios() {
    // Nombre del archivo que almacena la información de los usuarios
    string archivoUsuarios = "ingresados.txt";
    
    // Abre el archivo en modo de lectura
    ifstream ingresados(archivoUsuarios);

    if (ingresados.is_open()) {
        // Muestra el encabezado
        cout << "\nUsuarios Registrados:\n";
        
        // Estructura para almacenar la información de un usuario
        usuario actual;

        // Lee y muestra la información de cada usuario en el archivo
        while (getline(ingresados, actual.nombre) && getline(ingresados, actual.password)) {
            cout << "\n" << actual.nombre << "\n" << actual.password << "\n\n";
        }

        // Cierra el archivo después de leer todos los usuarios
        ingresados.close();
    } else {
        // Muestra un mensaje si no se puede abrir el archivo
        cout << "No se puede abrir el archivo.\n";
    }
}

// Función principal que actúa como menú principal
void AgregareEliminarUsuarios() {
    string archivoUsuarios = "ingresados.txt";

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
                agregarUsuario();
                break;
            case 2:
                //eliminarUsuario(archivoUsuarios);
                break;
            case 3:
                mostrarUsuarios();
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

    //se utiliza el ios::app para agregar informacion y que la informacion previa no se pierda
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


