//---------------------------------LIBRERIAS-----------------------------

#include <iostream> //libreria estandar de c++
#include "LibreriaLocal.h" //incluyendo libreria local
#include<fstream>// Librería para realizar operaciones de entrada y salida de archivos.
using namespace std;


//------------------------------FUNCIONES-----------------------------------------------------
void slogan();
void limpiar();
bool seccionAdmin();
void MenuPrincipal();
int obtenerSaldo();
void mostrarSaldo();
void rellenarDinero();
void eliminarDatos();
void RellenarCajero();


//-------------------------------MAIN------------------------------------------
int main(){
    limpiar();
    MenuPrincipal();

    return 0;
}

//----------------------------FUNCION DEL MENU PRINCIPAL----------------------------------------------
    void MenuPrincipal(){ 

    int opc=0;

    do
    {
        limpiar();
        slogan();

        cout << "\n===== MENU PRINCIPAL =====\n" << endl;
        cout << "1. Opciones para administrador" << endl;
        cout << "2. Opciones generales" << endl;
        cout << "3. Salir" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opc; 

        switch (opc)
        {
        case 1:
            limpiar();
            slogan();

            //el if es para iniciar seccion en el menu de adminstradores 
            
            if (!seccionAdmin()){
                break;
                }

            int opc_admin;
            limpiar();
            do
            {
                slogan();
                cout << "\n===== MENU ADMINISTRADOR =====\n" << endl;
                cout << "1. agregar e eliminar usuarios al sistema" << endl;
                cout << "2. rellenar dinero al cajero" << endl;
                cout << "3. cambiar la contrasena de la cuenta" << endl;
                cout << "4. Regresar al menu" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opc_admin;

                switch (opc_admin)
                {
                case 1:
                limpiar();
                slogan();
                    AgregarUsuarios(); //Funcion donde se guarda la informacion en el archivo de texto
                    cout << "Presione ENTER para continuar"<<endl;
                    cin.ignore();  //se utiliza para ignorar caracteres en el flujo de entrada estándar (cin)
                    cin.get(); //se utiliza para leer un solo carácter del flujo de entrada estándar (cin).
                    limpiar();
                break;

                case 2:
                limpiar();
                slogan();
                    RellenarCajero();//funcion donde guardara el dinero,lo eliminara y ver el estado del cajero
                    cout<<"Presione ENTER para continuar"<<endl;
                    cin.ignore();
                    cin.get();
                    limpiar();
                break;
                
                case 3:
                limpiar();
                slogan();
                cout<<"presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();
                break;   

                case 4:
                break;

                default:
                cout<<"opcion invalida "<<endl;
                    break;
                }
            } while (opc_admin != 4);
            
            break;

            
        
        case 2://-----------------------menu principal---------------------------------


        break;

        case 3:
        break;
        
        default:
            break;
        }
    
    } while (opc != 3);
    


    }



 
 
