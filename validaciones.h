#ifndef VALIDACIONES_H
#define VALIDACIONES_H

const int FILAS = 15;
const int ASIENTOS_POR_FILA = 20;

int validarEntero();
bool compararCadenas(char cadena1[], char cadena2[]);
void convertirACadena(int numero, char cadena[]);
void eliminarRepetidos(const char* entrada, char* salida);
int sumarNumeros(const char* cadena, int n);
void inicializarSala(char sala[FILAS][ASIENTOS_POR_FILA]);
void mostrarSala(char sala[FILAS][ASIENTOS_POR_FILA]);
int filaToIndice(char fila);
bool filaValida(char fila);
bool asientoValido(int asiento);
bool reservarAsiento(char sala[FILAS][ASIENTOS_POR_FILA], char fila, int asiento);
int contarDisponibles(char sala[FILAS][ASIENTOS_POR_FILA]);
int contarReservados(char sala[FILAS][ASIENTOS_POR_FILA]);
bool cancelarReserva(char sala[FILAS][ASIENTOS_POR_FILA], char fila, int asiento);
int contarEstrellas(int *matriz, int filas, int columnas);
int cadenaAEntero(const char* cadena);
void aMayusculas(char* cadena);
void separarNumeros(const char* original, char* texto, char* numeros);
int romanoAArabigo(const char* romano);


#endif // VALIDACIONES_H
