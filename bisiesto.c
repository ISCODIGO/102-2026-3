#include <stdio.h>

int main() {
    int anio;

    printf("Escriba un anio: ");
    scanf("%d", &anio);


    // Forma detallada
    if (anio % 4 == 0) {
        // calcular si es bisiesto?

        if (anio % 400 == 0) {
            puts("si");
        }
        else if (anio % 100 == 0) {
            puts("no");
        }
        else {
            puts("si");
        }
    }
    else {
        puts("no");

    }

    // Forma reducida
    if (anio % 4  == 0 && anio % 100 != 0 || anio % 400 == 0) {
        puts("si-reducida");
    } else {
        puts("no-reducida");
    }

    return 0;
}
