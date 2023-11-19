#include <iostream> //libreria estandar de c++
#include "LibreriaLocal.h" //incluyendo libreria local
#include<fstream>// Librería para realizar operaciones de entrada y salida de archivos.
using namespace std;

//------------------------------FUNCIONES-----------------------------------------------------
void MenuPrincipal(){

}


//-------------------------------MAIN------------------------------------------
int main(){
    limpiar();
    MenuPrincipal();

    return 0;
}


//inicio de secion administrador
bool seccionAdmin() 
{
    string User, PassW;
    int intentos = 0;
    while (intentos < 3)
    {
        cout << "Ingrese el nombre de usuario: ";
        cin >> User;
        cout << "Ingrese la contrasenia: ";
        cin >> PassW;

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

// codigo de funciones 

  void MenuPrincipal(){ //funcion del menu principal

    int opc=0;

    do
    {
        limpiar();
        slogan();

        cout << "===== MENU PRINCIPAL =====" << endl;
        cout << "1. Opciones para administrador" << endl;
        cout << "2. Opciones generales" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc; 

        switch (opc)
        {
        case 1://menu administrador
            
            limpiar();
            slogan();

            int opc_admin;
            limpiar();
            do
            {
                slogan();
                cout << "===== MENU ADMINISTRADOR =====" << endl;
                cout << "1. agregar usuarios al sistema" << endl;
                cout << "2.eliminar usuarios del sistema" <<endl;
                cout << "3. rellenar dinero al cajero" << endl;
                cout << "4. cambiar la contrasena de la cuenta" << endl;
                cout << "5. Regresar al menu" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opc_admin;

                switch (opc_admin)
                {
                case 1:
                limpiar();
                    AgregarUsuarios(); //Funcion donde se guarda la informacion en el archivo de texto
                    cout << "Presione ENTER para continuar"<<endl;
                    cin.ignore();  //se utiliza para ignorar caracteres en el flujo de entrada estándar (cin)
                    cin.get(); //se utiliza para leer un solo carácter del flujo de entrada estándar (cin).
                    limpiar();
                break;

                case 2:
                limpiar();
                    EliminarUsuario();//funcion donde se guardan los usuarios eliminados en el archivo de texto
                    cout<<"Presione ENTER para continuar"<<endl;
                    cin.ignore();
                    cin.get();
                    limpiar();
                break;

                case 3:
                limpiar();
                RellenarCajero();//funcion donde se guardara los datos de dinero 
                cout<<"presione ENTER para continuar"<<endl;
                cin.ignore();
                cin.get();
                limpiar();
                break;
                
                case 4:
                break;   

                case 5:
                break;

                default:
                cout<<"opcion invalida "<<endl;
                    break;
                }
            } while (opc_admin != 5);
            
            break;
        
        case 2://menu principal


        break;
        
        default:
            break;
        }
    
    } while (!3);
    


    }
 
