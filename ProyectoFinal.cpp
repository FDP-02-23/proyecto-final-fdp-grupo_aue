//---------------------------------LIBRERIAS-----------------------------

#include <iostream> //libreria estandar de c++
#include "LibreriaLocal.h" //incluyendo libreria local
#include<fstream>// Librería para realizar operaciones de entrada y salida de archivos.
#include <ctime>

using namespace std;


//------------------------------FUNCIONES-----------------------------------------------------
void MenuPrincipal();


//-------------------------------MAIN------------------------------------------
int main(){
    limpiar();

     logAccion("Inicio del programa");
    
     MenuPrincipal();

      logAccion("fin del programa");
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
        case 1://-----------------------------------menu administrador----------------------------------
            limpiar();
            slogan();

            //el if es para iniciar seccion en el menu de adminstradores 
            
            if (!seccionAdmin()){
                break;  //se utiliza para salir inmediatamente del bucle y continuar con la ejecución del código fuera del bucle.
                }

            int opc_admin;
            limpiar();
            do
            {
                slogan();
                cout << "\n===== MENU ADMINISTRADOR =====\n" << endl;
                cout << "1. agregar e eliminar usuarios al sistema" << endl;
                cout << "2. rellenar e eliminar dinero del cajero" << endl;
                cout << "3. cambiar la contrasena de la cuenta" << endl;
                cout << "4. Regresar al menu" << endl;
                cout << "\nIngrese una opcion: ";
                cin >> opc_admin;

                switch (opc_admin)
                {
                case 1:
                limpiar();
                slogan();
                    AgregareEliminarUsuarios(); //Funcion donde se guarda la informacion en el archivo de texto
                    cout << "Presione ENTER para continuar"<<endl;
                    cin.ignore();  //se utiliza para ignorar caracteres en el flujo de entrada estándar (cin)
                    cin.get(); //se utiliza para leer un solo carácter del flujo de entrada estándar (cin).
                    limpiar();
                break;

                case 2:
                limpiar();
                slogan();
                    RellenoCajero();//funcion donde guardara el dinero,lo eliminara y ver el estado del cajero
                    cout<<"Presione ENTER para continuar"<<endl;
                    cin.ignore();
                    cin.get();
                    limpiar();
                break;
                
                case 3:
                limpiar();
                slogan();
                //funcion
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
        limpiar();

        int opc_gral;
        do
        {
            slogan();
            cout << "\n===== MENU GENERAL =====\n" << endl;
                cout << "1. retiro de dinero" << endl;
                cout << "2. deposito de dinero" << endl;
                cout << "3. estado de cuenta" << endl;
                cout << "4. Regresar al menu" << endl;
                cout << "\nIngrese una opcion: ";
                cin >> opc_gral;

                switch (opc_gral)
                {
                case 1:
                limpiar();
                slogan();
                //menuUser();
                cout<<"presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();

                break;

                case 2:
                limpiar();
                slogan();
                //funcion
                cout<<"presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();

                break;

                case 3:
                limpiar();
                slogan();
                //funcion
                cout<<"presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();

                break;

                case 4:
                break;
                
                default:
                cout<<"opcion no valida, intento de nuevo"<<endl;
                    break;
                }


            
        } while (opc_gral !=4);

        break;

        case 3:
        break;
        
        default:
        cout<<"opcion no valida, intente de nuevo"<<endl;
            break;
        }
    
    } while (opc != 3);
    


    }