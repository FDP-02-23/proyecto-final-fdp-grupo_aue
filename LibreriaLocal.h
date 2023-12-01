//librerias a utilizar

#include <iostream> // Librería estándar de entrada y salida de datos.
#include <cstdlib> // Librería para funciones y constantes de uso general.
#include <fstream>  // Librería para realizar operaciones de entrada y salida de archivos.
#include <ctime> // este encabezado proporciona funcionalidades relacionadas con el manejo de tiempo y fecha en C++.
using namespace std;


//------------------------------------------FUNCIONES-------------------------------------------------


void logAccion() {
    
    const string mensaje;
    // Abre el archivo de registro en modo de añadir (append)
    ofstream logFile("log.txt", ios::app);

    if (logFile.is_open()) {
        // Obtiene la fecha y hora actual para el registro
        time_t tiempoActual = time(nullptr);
        string tiempoStr = ctime(&tiempoActual);

        // Escribe en el archivo de registro
        logFile << tiempoStr.substr(0, tiempoStr.length() - 1) << " - " << mensaje <<endl;

        // Cierra el archivo de registro
        logFile.close();
    } else {
        cout << "Error al abrir el archivo de registro." <<endl;
    }
}

//funcion para limpiar pantalla
void limpiar(){
    system("cls");
}

//slogan del cajero
void slogan(){
    cout<<"\nBIENVENIDO A TU CAJERO AUTOMATICO PREFERIDO \nTu dinero, tu tiempo, tu eleccion.\n ";
}

//---------------------------FUNCIONES DE AGREGAR E ELIMINAR USUARIOS--------------------------------------

struct persona {
    string nombre;
    int pin;
};

void agregarUsuario(persona& nuevoUsuario) {
    cout << "Ingrese su nombre: ";
    cin.ignore();
    getline(cin,nuevoUsuario.nombre);

    cout << "Ingrese su PIN: ";
    cin >> nuevoUsuario.pin;

    cout << "Usuario agregado correctamente.\n";
}

void guardarUsuarioEnArchivo(const persona& nuevoUsuario) {
    ofstream archivo("usuarios.txt", ios::app);

    if (archivo.is_open()) {
        archivo << "Nombre: " << nuevoUsuario.nombre <<"  ,  "<< " PIN: " << nuevoUsuario.pin << endl;
        archivo.close();
        cout << "Usuario guardado en el archivo.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

void agregarUsuarios() {
    int opc_sw;
    persona nuevoUsuario;
    do {
        limpiar();
        slogan();
        cout << "\neliga una opcion"<<endl;
        cout << "1. Agregar usuario" << endl;
        cout << "2. Mostrar archivo" << endl;
        cout << "3. Regresar al menu" << endl;
        cout << "\ningresa una opcion :";
        cin >> opc_sw;

        switch (opc_sw) {
            case 1:
                limpiar();
                agregarUsuario(nuevoUsuario);
                cout<<"Presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();
                break;

            case 2:
                limpiar();
                guardarUsuarioEnArchivo(nuevoUsuario);
                cout<<"Presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();
                break;
                
            case 3:
            break;

            default:
            cout<<"opcion no valida, intente de nuevo"<<endl;
                break;
        }
    } while (opc_sw != 3);
}



//---------FUNCION PARA RELLENAR EL CAJERO, ELIMINAR y MOSTRAR DINERO DISPONIBLE EN EL CAJERO---------------

// Definición de la cantidad de tipos de billetes
const int tiposBilletes = 5;

//Arreglo que contiene los valores de los distintos tipos de billetes
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
    cout<<"4.generar archivo de cajero"<<endl;
    cout<<"5.salir"<<endl;
    cout<<"\ningrese su opcion :"; 
    cin>> opcRellenar;

    return opcRellenar;
 }


// funcion para rellenar de dinero al cajero automatico
 void ingresarDinero(Cajero &cajero_r) {

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

    // Mensaje indicando que el dinero ha sido ingresado correctamente
    cout << "\nDinero ingresado correctamente.\n";
 }
 
  void verEstadoCajero(const Cajero &cajero_r){
    
     cout << "\nEstado del cajero:\n";

    // Itera sobre los tipos de billetes y muestra la cantidad de cada tipo en el cajero
    for (int i = 0; i < tiposBilletes; ++i) {
        cout << "Billetes de $" << tipos[i] << ": " << cajero_r.billetes[i] << endl;
    }

    // Calcular la suma total de todos los billetes ingresados
    int sumaTotal = 0;
    for (int i = 0; i < tiposBilletes; ++i) {
        sumaTotal += tipos[i] * cajero_r.billetes[i];
    }

    cout << "\n total del dinero : $" << sumaTotal << endl;

 }
 
 void suma(const Cajero &cajero_r){
    int sumaTotal = 0;
    for (int i = 0; i < tiposBilletes; ++i) {
        sumaTotal += tipos[i] * cajero_r.billetes[i];
    }

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


// Función que guarda el estado actual del cajero en un archivo de texto
void mostarCajero(Cajero &cajero_r) {
    // Abre un archivo de texto llamado "relleno_De_Dinero.txt" para escribir en él
    ofstream archivo("relleno_De_Dinero.txt");

    // Itera sobre los tipos de billetes y escribe la cantidad de cada tipo en el archivo
    for (int i = 0; i < tiposBilletes; ++i) {
        archivo << "Billetes de $" << tipos[i] << ": " << cajero_r.billetes[i] << endl;
    }

    // Cierra el archivo después de escribir la información
    archivo.close();
}



 void RellenoCajero(){

    Cajero Cajero_r={0};

    int opcion;
    do {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                limpiar();
                ingresarDinero(Cajero_r);
                cout<<"Presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();
               
                break;
            case 2:
                limpiar();
                retirarDinero(Cajero_r);
                cout<<"Presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();
               
                break;
            case 3:
                limpiar();
                verEstadoCajero(Cajero_r);
                cout<<"Presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();
        
                break;

            case 4:
                limpiar();
                mostarCajero(Cajero_r);
                cout<<"Presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();
            break;

            case 5:
            break;

            default:
                cout << "Opcion invalida. Por favor, intente de nuevo.\n";
        }

    } while (opcion != 5);


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

//------------------------FUNCIONES PARA CAMBIAR DE CONTRASEÑA-------------------------
// Definición de la estructura Usuario
struct Usuario {
    string nombre;
    string contrasena;
};

// Función para guardar la información del usuario en un archivo de texto
void guardarEnArchivo(const Usuario& usuario) {
    // Abre el archivo en modo de añadir (append)
    ofstream archivo("usuarios.txt", ios::app);

    // Verifica si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Escribe en el archivo la información del usuario (nombre y contraseña)
        archivo << "nombre: " << usuario.nombre << " , " << "contrasena: " << usuario.contrasena << endl;

        // Cierra el archivo después de escribir la información
        archivo.close();

        // Mensaje indicando que la información del usuario se guardó en el archivo
        cout << "Información del usuario guardada en el archivo." << endl;
    } else {
        // Mensaje de error si no se pudo abrir el archivo
        cout << "Error al abrir el archivo para guardar la información del usuario." << endl;
    }
}


void cambiarContrasena(Usuario& usuario) {
    string nuevaContrasena;

    cout << "Ingrese su nueva contrasena: ";
    cin >> nuevaContrasena;

    //if para verificar que la contraseña no sea igual a la anterior contrasena 
    if (usuario.contrasena == nuevaContrasena) {
        cout << "La nueva contrasena no puede ser igual a la anterior." << endl;
    } else {
        usuario.contrasena = nuevaContrasena;
        cout << "Contrasena cambiada exitosamente." << endl;

        // Actualizar la contraseña en el archivo
        ofstream archivo("usuarios.txt");
        archivo << usuario.nombre << " " << usuario.contrasena << endl;
        archivo.close();
    }
}

void mostrarInformacion(const Usuario& usuario) {
    cout << "Nombre: " << usuario.nombre << endl;
    cout << "Contrasena: " << usuario.contrasena << endl;
}

void user(){

    limpiar();

    Usuario usuario;
    
    cout << "\nIngrese su nombre: ";
    cin.ignore();
    getline(cin, usuario.nombre);

    cout << "Ingrese su contrasena: ";
    cin >> usuario.contrasena;

    int opcion;
    do {
        cout << "\n=====Menu=====\n";
        cout << "1. Cambiar Contrasena"<<endl;
        cout << "2. Mostrar Informacion"<<endl;
        cout << "3.mostrar archivo"<<endl;
        cout << "4. Salir"<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                limpiar();
                cambiarContrasena(usuario);
                cin.ignore();
                cin.get();
                limpiar();
                break;
            case 2:
                limpiar();
                mostrarInformacion(usuario);
                cin.ignore();
                cin.get();
                limpiar();
                break;
            case 3:
                limpiar();
                guardarEnArchivo(usuario);
                cin.ignore();
                cin.get();
                limpiar();

                break;

            case 4:
            break;

            default:
                cout << "Opcion no valida. Intentelo de nuevo."<<endl;
        }
    } while (opcion != 4);

    
}

//------------------------------FUNCIONES PARA EL MENU ORIGINAL---------------------------------


//----------------------FUNCIONES DE RETIRO-------------------------------------------


void retiro() {

    int intentos = 3;
    string nombre;
    float pin;

    srand(time(0)); // Seed para generar números aleatorios diferentes en cada ejecución

    cout << "\nIngrese su nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese su PIN: ";
    cin >> pin;

    int saldoAleatorio = rand() % 200000000 + 1;
    cout << "\nInicio de sesion exitoso. Tu saldo es de: $" << saldoAleatorio << endl;

    cout << "\nInicio de sesion exitoso.\n";

    cout << "\n-------BIENVENIDO-------\n" << endl;

    float sald;
    do {
        cout << "Ingrese la cantidad a retirar: $";
        cin >> sald;

        if (sald <= 0) {
            cout << "Ingrese una cantidad válida." << endl;
        } else if (sald > saldoAleatorio) {
            cout << "No tienes suficiente saldo en tu cuenta. Intentos restantes: " << --intentos << endl;
        } else {
            cout << "Retiro exitoso. Tu nuevo saldo es de: $" << saldoAleatorio - sald << endl;
            break;
        }

        if (intentos == 0) {
            cout << "Se agotaron los intentos. Operación cancelada." << endl;
            break;
        }
    } while (true);

    cout << "\nGracias por preferirnos. Fue un gusto atenderle. ¡Tenga un buen día, " << nombre << "!" << endl;
}

 //----------------------FUNCION DE DEPOSITO-------------------------------------------

struct Usuariodep {
    string nombre;
    float saldo;
    int pin;
};


void deposito(Usuariodep& usuariodep) {
    string nombreIngresado;
    int pinIngresado;

    cout<<"\npara confirmar coloque de nuevo su nombre y pin de seguridad"<<endl;
    cout << "Ingrese su nombre: ";
    cin.ignore();
    getline(cin, nombreIngresado);

    cout << "Ingrese su PIN: ";
    cin >> pinIngresado;

    if (nombreIngresado == usuariodep.nombre && pinIngresado == usuariodep.pin) {
        float cantidad;

        cout << "\nIngrese la cantidad a depositar: $";
        cin >> cantidad;

        if (cantidad > 0) {
            usuariodep.saldo += cantidad;
            cout << "\nDepósito exitoso. Tu nuevo saldo es de: $" << usuariodep.saldo << endl;
        } else {
            cout << "\nIngrese una cantidad válida." << endl;
        }
    } else {
        cout << "Credenciales incorrectas. Operación cancelada." << endl;
    }
}


void deposito_e() {
    // Crear un usuario con saldo aleatorio
    Usuariodep usuariodep;
    cout << "\nIngrese su nombre: ";
    cin.ignore();
    getline(cin, usuariodep.nombre);

    cout << "coloque su PIN: ";
    cin >> usuariodep.pin;

    // Generar un saldo aleatorio entre 1000 y 5000
    usuariodep.saldo = rand() % 4001 + 1000;

    // Ejemplos de uso de las funciones
    deposito(usuariodep); // Realizar depósito y registrar transacción


}


//-----------------------------FUNCION DE ESTADO DE CUENTA---------------------------------------
void verEstadoCuenta() {
    string nombreIngresado;
    int pinIngresado;

    cout << "\nIngrese su nombre: ";
    cin.ignore();
    getline(cin, nombreIngresado);

    cout << "Ingrese su PIN: ";
    cin >> pinIngresado;

    // esto es para generar para cada persona saldo aleatorio
    int saldoAleatorio = rand() % 2000000 + 1;

    // Mostramos la información
    cout << "\nEstado de cuenta para " << nombreIngresado << ":\n";
    cout << "Saldo: $" << saldoAleatorio << endl;
}
