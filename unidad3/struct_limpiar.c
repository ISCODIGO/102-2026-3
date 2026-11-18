// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpiar(char*);

int main() {
    char entrada[10];
    fgets(entrada, 10, stdin);
    limpiar(entrada);
    //int posicion = strcspn(entrada, "\n");
    //entrada[posicion] = '\0';
    printf("La cadena es: %s.", entrada);
    return 0;
}

void limpiar(char* cadena) {
    int pos = 0;
    while (cadena[pos] != '\0') {
        if (cadena[pos] == '\n') {
            cadena[pos] = '\0';
            break;
        }
        pos++;
    }
}