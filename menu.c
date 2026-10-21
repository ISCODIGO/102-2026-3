#include <stdio.h>

int main() {
    int eleccion;
    do {
        puts("Menu");
        puts("1. Suma");
        puts("2. Resta");
        puts("3. Multiplicacion");
        puts("4. Division");
        puts("0. Salir");
        scanf("%d", &eleccion);

    }
    while (eleccion != 0);

    return 0;
}
