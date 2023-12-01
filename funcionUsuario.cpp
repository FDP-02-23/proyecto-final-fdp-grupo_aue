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

