#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FALLOS 6

// variables globales
char Tablero[50];  // tablero de juego

// prototipos de funciones
char *elegirPalabra(void);
void dibujarTablero(int, int);
int buscarPalabra(char *, char);
int gano(int);

int main() {
    // una semilla diferente cada vez que se inicie el programa
    srand(time(NULL));
    char *seleccion = elegirPalabra();
    int size = strlen(seleccion);  // dimension de la palabra

    for(int i = 0; i < size; i++) {
        Tablero[i] = '_';
    }

    int intentos = 0;

    while(1) {
        dibujarTablero(size, intentos);

        printf("\n\nEscriba una letra: ");
        char letra;
        scanf(" %c", &letra);

        if (!buscarPalabra(seleccion, letra)) {
            intentos++;
        }

        if (intentos >= FALLOS) {
            dibujarTablero(size, intentos);
            printf("\n\nPERDIO, la palabra era %s\n", seleccion);
            break;
        }

        if (gano(size)) {
            dibujarTablero(size, intentos);
            printf("\n\nGANO\n");
            break;
        }
    }

    return 0;
}

char *elegirPalabra(void) {
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

void dibujarTablero(int size, int intentos) {
    printf("\e[1;1H\e[2J");
    puts("Juego Ahorcado\n");

    printf("Palabra: ");
    for(int i = 0; i < size; i++) {
        printf("%c ", Tablero[i]);
    }

    printf("\t (%d de %d)", intentos, FALLOS);
}

int buscarPalabra(char *palabra, char letra) {
    int hallado = 0;
    int size = strlen(palabra);

    for (int i = 0; i < size; i++) {
        if (letra == palabra[i]) {
            hallado = 1;
            Tablero[i] = letra;
        }
    }
    return hallado;
}

int gano(int size) {
    int hayGanador = 1;
    for(int i = 0; i < size; i++) {
        if (Tablero[i] == '_') {
            hayGanador = 0;
            break;
        }
    }
    return hayGanador;
}
