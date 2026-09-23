#include "problemas.h"
#include "validaciones.h"
#include <iostream>

void problema1(){
    int denominaciones[10] = {
        50000, 20000, 10000, 5000, 2000,
        1000, 500, 200, 100, 50
    };

    std::cout << "Ingrese la cantidad de dinero: ";
    int cantidad = validarEntero();
    int cantidadOriginal;

    cantidadOriginal = cantidad;

    std::cout << "\nCombinacion de billetes y monedas:\n";

    for (int i = 0; i < 10; i++) {

        int cantidadDenominacion = cantidad / denominaciones[i];

        std::cout << denominaciones[i] << " : "
             << cantidadDenominacion << std::endl;

        cantidad = cantidad % denominaciones[i];
    }

    std::cout << "Faltante: " << cantidad << std::endl;
}

void problema2() {
    const int TAM = 200;
    char arreglo[TAM];
    int contador[26] = {0};
    srand(time(0));

    for (int i = 0; i < TAM; i++) {
        arreglo[i] = 'A' + (rand() % 26);
        contador[arreglo[i] - 'A']++;
    }

    std::cout << "Arreglo generado:" << std::endl;
    for (int i = 0; i < TAM; i++) {
        std::cout << arreglo[i];
    }
    std::cout << std::endl << std::endl;

    std::cout << "Repeticiones por letra:" << std::endl;
    for (int i = 0; i < 26; i++) {
        std::cout << (char)('A' + i) << ": " << contador[i] << std::endl;
    }
}

void problema3(){
    std::cin.ignore();
    char cadena1[100]; char cadena2[100];
    std::cout << "Ingrese la primera cadena: ";
    std::cin.getline(cadena1, 100);

    std::cout << "Ingrese la segunda cadena: ";
    std::cin.getline(cadena2, 100);

    if (compararCadenas(cadena1, cadena2)) {
        std::cout << "Las cadenas son iguales." << std::endl;
    } else {
        std::cout << "Las cadenas son diferentes." << std::endl;
    }
}

void problema4(){
    const int MAX = 100;
    char cadena[MAX];
    while(true){
        std::cout << "Ingrese una cadena de caracteres numericos: ";
        std::cin >> cadena;
        int resultado = cadenaAEntero(cadena);
        if(resultado != 0) {
            std::cout << "El numero entero es: " << resultado << std::endl;
            break;
        }
    }
}

void problema5(){
    std::cout << "Ingrese un numero entero: ";
    int numero = validarEntero();

    std::cin.ignore();
    char cadena[20];

    convertirACadena(numero, cadena);
    std::cout << "La cadena es: " << cadena << std::endl;
}

void problema6(){
    const int MAX = 200;
    char original[MAX];
    char mayusculas[MAX];

    std::cout << "Ingrese una cadena de caracteres: ";
    std::cin.getline(original, MAX);

    int i = 0;
    while (original[i] != '\0') {
        mayusculas[i] = original[i];
        i++;
    }
    mayusculas[i] = '\0';

    aMayusculas(mayusculas);

    std::cout << "Original: " << original << std::endl;
    std::cout << "En mayuscula: " << mayusculas << std::endl;
}

void problema7(){
    char entrada[100];
    std::cout << "Ingrese caracteres: ";
    std::cin >> entrada;

    char salida[100];

    eliminarRepetidos(entrada, salida);

    std::cout << "Original: " << entrada << ". Sin repetidos: " << salida << std::endl;
}

void problema8(){
    const int MAX = 200;
    char original[MAX];
    char texto[MAX];
    char numeros[MAX];

    std::cout << "Ingrese una cadena de caracteres: ";
    std::cin.getline(original, MAX);

    separarNumeros(original, texto, numeros);

    std::cout << "Original: " << original << "." << std::endl;
    std::cout << "Texto: " << texto << ". Numero: " << numeros << std::endl;
}

void problema9(){
    std::cout << "Ingrese el valor de n: ";
    int n = validarEntero();
    char cadena[100];
    char cadenaOriginal[100];

    std::cout << "Ingrese una cadena de caracteres numéricos: ";
    std::cin >> cadena;

    int i = 0;

    while (cadena[i] != '\0') {
        cadenaOriginal[i] = cadena[i];
        i++;
    }
    cadenaOriginal[i] = '\0';

    int resultado = sumarNumeros(cadena, n);

    std::cout << "Original: " << cadenaOriginal << "." << std::endl;
    std::cout << "Suma: " << resultado << "." << std::endl;
}

void problema10(){
    const int MAX = 100;
    char romano[MAX];

    std::cout << "Ingrese un numero romano: ";
    std::cin >> romano;

    int resultado = romanoAArabigo(romano);

    std::cout << "El numero arabigo es: " << resultado << std::endl;
}

void problema11(){
    char sala[FILAS][ASIENTOS_POR_FILA];
    inicializarSala(sala);

    int opcion;
    char fila;
    int asiento;

    std::cout << "===== SISTEMA DE RESERVAS DE CINE =====" << std::endl;
    std::cout << "Capacidad total: " << FILAS * ASIENTOS_POR_FILA << " asientos" << std::endl;
    std::cout << std::endl;

    do {
        std::cout << "\n--- MENÚ PRINCIPAL ---" << std::endl;
        std::cout << "1. Ver sala de cine" << std::endl;
        std::cout << "2. Reservar asiento" << std::endl;
        std::cout << "3. Cancelar reserva" << std::endl;
        std::cout << "4. Ver estadísticas" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "\n--- SALA DE CINE ---" << std::endl;
            std::cout << "Leyenda: '-' = Disponible, '+' = Reservado" << std::endl;
            std::cout << std::endl;
            mostrarSala(sala);
            break;

        case 2:
            std::cout << "\n--- RESERVAR ASIENTO ---" << std::endl;
            std::cout << "Ingrese fila (A-O): ";
            std::cin >> fila;
            if (fila >= 'a' && fila <= 'o') {
                fila = fila - 'a' + 'A';
            }
            std::cout << "Ingrese número de asiento (1-20): ";
            std::cin >> asiento;
            reservarAsiento(sala, fila, asiento);
            break;

        case 3:
            std::cout << "\n--- CANCELAR RESERVA ---" << std::endl;
            std::cout << "Ingrese fila (A-O): ";
            std::cin >> fila;
            if (fila >= 'a' && fila <= 'o') {
                fila = fila - 'a' + 'A';
            }
            std::cout << "Ingrese número de asiento (1-20): ";
            std::cin >> asiento;
            cancelarReserva(sala, fila, asiento);
            break;

        case 4:
            std::cout << "\n--- ESTADÍSTICAS ---" << std::endl;
            std::cout << "Asientos disponibles: " << contarDisponibles(sala) << std::endl;
            std::cout << "Asientos reservados: " << contarReservados(sala) << std::endl;
            std::cout << "Total de asientos: " << FILAS * ASIENTOS_POR_FILA << std::endl;
            break;

        case 5:
            std::cout << "¡Gracias por usar el sistema de reservas!" << std::endl;
            break;

        default:
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
        }

    } while (opcion != 5);
}

void problema13(){
    const int FILAS = 6;
    const int COLUMNAS = 8;

    int matriz[FILAS][COLUMNAS] =
        {
            {0, 3, 4, 0, 0, 0, 6, 8},
            {5, 13, 6, 0, 0, 0, 2, 3},
            {2, 6, 2, 7, 3, 0, 10, 0},
            {0, 0, 4, 15, 4, 1, 6, 0},
            {0, 0, 7, 12, 6, 9, 10, 4},
            {5, 0, 6, 10, 6, 4, 8, 0}
        };

    int cantidad = contarEstrellas(&matriz[0][0], FILAS, COLUMNAS);

    std::cout << "Cantidad de estrellas encontradas: " << cantidad << std::endl;
}



