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
    cout<<"Tu dinero, tu tiempo, tu elección.";
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

void RellenarCajero(){
    
}