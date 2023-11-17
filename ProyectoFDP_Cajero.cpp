// Declaración de librerias
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Declaración de funciones/estructuras administrador
// Rellenar de dinero el cajero
void rellenarCajero();
// Agregar/eliminar usuarios (puede que sirva con un struct)
void agregarUsuarios();
// Cambiar contraseña de cuentas
void cambiarContrasena();

// Declaración de funciones/estructuras usuario
// Retirar dinero
void retiro();
// Depositar dinero
void deposito();
// Ver el estado de cuenta (archivo de texto)
void estadoCuenta();

// menus
void menuCliente(int);
void menuAdministrador(int);
void menu(int);

// Funcion Main
int main()
{
    int opcionMenu;

    menu(opcionMenu);

    return 0;
}

// Retirar dinero (cliente)
void retiro()
{
    cout << "Opcion retiro\n";
};

// Depositar dinero (cliente)
void deposito()
{
    cout << "Opcion deposito\n";
};

// Ver estado de cuenta del cliente
void estadoCuenta()
{
    cout << "Opcion ver estado de cuenta\n";
};

// Agregar usuarios (admin)
void agregarUsuarios()
{
    cout << "Opcion agregar usuarios\n";
};

// Cambiar contrasenas de cuentas (admin)
void cambiarContrasena()
{
    cout << "Opcion cambiar contrasena\n";
};

// Rellenar con billetes de 100, 50, 20, 1 (admin)
void rellenarCajero()
{
    cout << "Opcion rellenar cajero\n";
};

void menuCliente(int opcionMenu)
{
    system("cls");
    cout << "Bienvenido cliente\nSeleccione la opcion que desee:\n 1-Retirar dinero\n 2-Depositar dinero en su cuenta\n 3-Ver el estado de cuenta\n";
    cin >> opcionMenu;

    switch (opcionMenu)
    {

    case 1:
        retiro();
        break;

    case 2:
        deposito();
        break;

    case 3:
        estadoCuenta();
        break;

    default:
        break;
    }
};

void menuAdministrador(int opcionMenu)
{
    system("cls");
    cout << "Bienvenido administrador\nSeleccione la opcion que desee:\n 1-Agregar usuarios\n 2-Rellenar el cajero\n 3-Cambiar la contrasena de una cuenta\n";
    cin >> opcionMenu;

    switch (opcionMenu)
    {

    case 1:
        agregarUsuarios();
        break;

    case 2:
        rellenarCajero();
        break;

    case 3:
        cambiarContrasena();
        break;

    default: cout << "Ingrese una opcion correcta\n";
        break;
    }
};

void menu(int opcionMenu)
{

    string verificarContra;
    string contrasena = "contrasena123";

    cout << "Ingrese (1) si es un Cliente\nIngrese (2) si es un Administrador\n";
    cin >> opcionMenu;

    switch (opcionMenu)
    {
    case 1:
        cout << "Bienvenido cliente\n";
        menuCliente(opcionMenu);
        break;

    case 2:
        system("cls");
        cout << "Bienvenido administrador\nIngrese la contrasena: ";
        cin >> verificarContra;

        if (verificarContra == contrasena)
        {
            menuAdministrador(opcionMenu);
        }
        else
        {
            cout << "Contrasena incorrecta\n";
        }
        break;

    default:
        cout << "Ingrese una opcion correcta \n";
        break;
    }
};