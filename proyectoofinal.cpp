void retiro() {
    // Código de acceso al cajero
    const int codigoCajero = 1234;

    // Saldo inicial del cajero
    double saldoCajero = 1000.0;

    // Variable para almacenar el código ingresado por el usuario
    int codigoIngresado;

    // Variable para almacenar la cantidad de dinero a retirar
    double cantidadRetiro;

    // Solicitar al usuario ingresar el código
    cout << "Ingrese su codigo de acceso: ";
    cin >> codigoIngresado;

    // Verificar el código
    if (codigoIngresado == codigoCajero) {
        // El código es correcto, solicitar la cantidad de dinero a retirar
        cout << "Ingrese la cantidad a retirar: $";
        cin >> cantidadRetiro;

        // Verificar si hay suficiente saldo en el cajero
        if (cantidadRetiro > 0 && cantidadRetiro <= saldoCajero) {
            // Realizar el retiro y actualizar el saldo
            saldoCajero -= cantidadRetiro;
            cout << "Retiro exitoso. Saldo restante: $" << saldoCajero << endl;
        } else {
            cout << "Fondos insuficientes o cantidad invalida." << endl;
        }
    } else {
        cout << "Código incorrecto. Acceso denegado." << endl;
    }

}