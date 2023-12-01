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