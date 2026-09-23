#include "validaciones.h"
#include <iostream>

int valorRomano(char c) {
    switch (c) {
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default:  return 0;
    }
}

bool esNumero(char entrada[]) {
    int i = 0;

    while (entrada[i] != '\0') {
        if (entrada[i] < '0' || entrada[i] > '9') {
            return false;
        }
        i++;
    }

    return true;
}


int validarEntero(){
    char entrada[100];

    while (true) {
        std::cin >> entrada;
        std::cin.ignore();
        if (esNumero(entrada)) {
            int numero = 0;

            for (int i = 0; entrada[i] != '\0'; i++) {
                numero = numero * 10 + (entrada[i] - '0');
            }

            return numero;
        }

        std::cout << "Entrada invalida. Ingrese un numero: ";
    }
}

bool compararCadenas(char cadena1[], char cadena2[]) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return false;
        }
        i++;
    }
    if (cadena1[i] == '\0' && cadena2[i] == '\0') {
        return true;
    }
    return false;
}

void convertirACadena(int numero, char cadena[]){
    int i = 0;

    if(numero == 0){
        cadena[0] = '0';
        cadena[1] = '\0';
        return;
    }

    int temporal = numero;
    int cantidadDigitos = 0;

    while(temporal > 0){
        cantidadDigitos++;
        temporal = temporal/10;
    }

    for(int j = cantidadDigitos - 1; j>=0; j--){
        cadena[i] = (numero % 10) + '0';
        numero = numero/10;
        i++;
    }

    for(int j = 0; j < i/2; j++){
        char aux = cadena[j];
        cadena[j] = cadena[i-1-j];
        cadena[i-1-j] = aux;
    }

    cadena[i] = '\0';
}

int cadenaAEntero(const char* cadena) {
    int numero = 0;
    int i = 0;
    int signo = 1;

    if (cadena[0] == '-') {
        signo = -1;
        i = 1;
    } else if (cadena[0] == '+') {
        i = 1;
    }

    while (cadena[i] != '\0') {
        if (cadena[i] < '0' || cadena[i] > '9') {
            std::cout << "Error: caracter no numérico encontrado." << std::endl;
            return 0;
        }

        numero = numero * 10 + (cadena[i] - '0');
        i++;
    }

    return numero * signo;
}

void aMayusculas(char* cadena) {
    int i = 0;

    while (cadena[i] != '\0') {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - 32;
        }
        i++;
    }
}

void eliminarRepetidos(const char* entrada, char* salida) {
    bool visto[256] = {false};

    int j = 0;

    for (int i = 0; entrada[i] != '\0'; i++) {
        unsigned char c = static_cast<unsigned char>(entrada[i]);
        if (!visto[c]) {
            visto[c] = true;
            salida[j++] = entrada[i];
        }
    }

    salida[j] = '\0';
}

void separarNumeros(const char* original, char* texto, char* numeros) {
    int i = 0;
    int t = 0;
    int n = 0;

    while (original[i] != '\0') {
        if (original[i] >= '0' && original[i] <= '9') {
            numeros[n] = original[i];
            n++;
        } else {
            texto[t] = original[i];
            t++;
        }
        i++;
    }

    texto[t] = '\0';
    numeros[n] = '\0';
}

int longitudCadena(const char* cadena) {
    int len = 0;
    while (cadena[len] != '\0') {
        len++;
    }
    return len;
}

int charToInt(char c) {
    return c - '0';
}

int sumarNumeros(const char* cadena, int n) {
    int len = longitudCadena(cadena);

    int residuo = len % n;
    int digitosPrimero = (residuo == 0) ? n : residuo;

    int sumaTotal = 0;
    int posicion = 0;
    bool primerNumero = true;

    while (posicion < len) {
        int numero = 0;
        int digitosActuales;

        if (primerNumero) {
            digitosActuales = digitosPrimero;
            primerNumero = false;
        } else {
            digitosActuales = n;
        }

        for (int i = 0; i < digitosActuales; i++) {
            numero = numero * 10 + charToInt(cadena[posicion]);
            posicion++;
        }

        sumaTotal += numero;
    }

    return sumaTotal;

}

void inicializarSala(char sala[FILAS][ASIENTOS_POR_FILA]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
            sala[i][j] = '-';
        }
    }
}

void mostrarSala(char sala[FILAS][ASIENTOS_POR_FILA]) {

    std::cout << "    ";
    for (int j = 1; j <= ASIENTOS_POR_FILA; j++) {
        if (j < 10) {
            std::cout << " " << j << " ";
        } else {
            std::cout << j << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "   +";
    for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
        std::cout << "---+";
    }
    std::cout << std::endl;

    for (int i = 0; i < FILAS; i++) {
        char letraFila = 'A' + i;
        std::cout << " " << letraFila << " |";

        for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
            std::cout << " " << sala[i][j] << " |";
        }
        std::cout << std::endl;

        std::cout << "   +";
        for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
            std::cout << "---+";
        }
        std::cout << std::endl;
    }
}

int filaToIndice(char fila) {
    return fila - 'A';
}

bool filaValida(char fila) {
    return (fila >= 'A' && fila <= 'O');
}

bool asientoValido(int asiento) {
    return (asiento >= 1 && asiento <= ASIENTOS_POR_FILA);
}


bool reservarAsiento(char sala[FILAS][ASIENTOS_POR_FILA], char fila, int asiento) {
    int filaIndice = filaToIndice(fila);
    int asientoIndice = asiento - 1; // Convertir a índice 0-19

    if (!filaValida(fila) || !asientoValido(asiento)) {
        std::cout << "Error: Fila o asiento inválido." << std::endl;
        return false;
    }

    if (sala[filaIndice][asientoIndice] == '+') {
        std::cout << "Error: El asiento " << fila << asiento << " ya está reservado." << std::endl;
        return false;
    }

    sala[filaIndice][asientoIndice] = '+';
    std::cout << "Asiento " << fila << asiento << " reservado exitosamente." << std::endl;
    return true;
}

bool cancelarReserva(char sala[FILAS][ASIENTOS_POR_FILA], char fila, int asiento) {
    int filaIndice = filaToIndice(fila);
    int asientoIndice = asiento - 1;

    if (!filaValida(fila) || !asientoValido(asiento)) {
        std::cout << "Error: Fila o asiento inválido." << std::endl;
        return false;
    }

    if (sala[filaIndice][asientoIndice] == '-') {
        std::cout << "Error: El asiento " << fila << asiento << " no está reservado." << std::endl;
        return false;
    }

    sala[filaIndice][asientoIndice] = '-';
    std::cout << "Reserva del asiento " << fila << asiento << " cancelada exitosamente." << std::endl;
    return true;
}

int contarDisponibles(char sala[FILAS][ASIENTOS_POR_FILA]) {
    int count = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
            if (sala[i][j] == '-') {
                count++;
            }
        }
    }
    return count;
}

int contarReservados(char sala[FILAS][ASIENTOS_POR_FILA]) {
    int count = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
            if (sala[i][j] == '+') {
                count++;
            }
        }
    }
    return count;
}

int romanoAArabigo(const char* romano) {
    int total = 0;
    int i = 0;

    while (romano[i] != '\0') {
        int actual = valorRomano(romano[i]);
        int siguiente = valorRomano(romano[i + 1]);

        if (actual < siguiente) {
            total = total - actual;
        } else {
            total = total + actual;
        }
        i++;
    }

    return total;
}

int contarEstrellas(int *matriz, int filas, int columnas){
    int contador = 0;

    for (int i = 1; i < filas - 1; i++)
    {
        for (int j = 1; j < columnas - 1; j++)
        {
            int suma = matriz[i * columnas + j]
                       + matriz[(i - 1) * columnas + j]
                       + matriz[(i + 1) * columnas + j]
                       + matriz[i * columnas + (j - 1)]
                       + matriz[i * columnas + (j + 1)];

            if (suma / 5.0 > 6)
            {
                contador++;
            }
        }
    }

    return contador;
}
