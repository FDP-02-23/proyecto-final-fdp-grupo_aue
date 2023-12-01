struct Usuario {
    string nombre;
    string contrasena;
};

void guardarEnArchivo(const Usuario& usuario) {
    ofstream archivo("usuarios.txt", ios::app);
    archivo <<"nombre :"<< usuario.nombre << " , "<<" contrasena : " << usuario.contrasena << endl;
    archivo.close();
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