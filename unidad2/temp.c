#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FALLOS 6

char* generarPalabra();
void limpiarPantalla();
void definirTablero(char*);
void imprimirTablero(int);
int buscarPalabra(char*, char);

char tablero[50];

int main() {
    // una semilla diferente cada vez que se inicie el programa
    srand(time(NULL));

    char* seleccion = generarPalabra();
    definirTablero(seleccion);

    int intentos = 0;

    while(intentos < FALLOS) {
        imprimirTablero(intentos);
        printf("Escriba una letra: ");
        char letra;
        scanf("%c", &letra);

        if (buscarPalabra(seleccion, letra)) {
            intentos++;
        }
    }

    return 0;
}

char* generarPalabra() {
    char *palabras[] = {
        "abecedario",
        "libreto",
        "amarillo",
        "edulcorante",
        "entramado",
        "cocinero"
    };

    // seleccionar al azar una palabra
    int aleatorio = rand() % 6;
    char *seleccion = palabras[aleatorio];
    return seleccion;
}

void limpiarPantalla() {
    printf("\e[1;1H\e[2J");
}

void definirTablero(char *palabra) {
    int s = strlen(palabra);
    for(int i = 0; i < s*2; i+=2) {
        tablero[i] = '_';
        tablero[i+1] = ' ';
    }
}

void imprimirTablero(int intentos) {
    limpiarPantalla();
    puts(tablero);
    printf("Errores: %d de %d\n", intentos, FALLOS);
}

int buscarPalabra(char *palabra, char letra) {
    int fallido = 1;

    for (int i = 0; i < strlen(palabra); i++) {
        if (letra == palabra[i]) {
            fallido = 0;
            tablero[i*2] = letra;
        }
    }

    return fallido;
}
