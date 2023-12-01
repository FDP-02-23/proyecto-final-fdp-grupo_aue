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
 