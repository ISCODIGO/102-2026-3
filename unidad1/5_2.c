#include <stdio.h>

int main() {
    int hora;
    char separador;
    int minutos;

    printf("Escriba la hora: ");
    /*scanf("%d", &hora);
    scanf("%c", &separador);
    scanf("%d", &minutos);*/
    scanf("%d%c%d", &hora, &separador, &minutos);

    // Validacion
    if (hora < 0 || hora > 23) {
        puts("La hora no es correcta");
    }

    else

    if (minutos < 0 || minutos > 59) {
        puts("Los minutos no son correctos");
    }

    else

    if (hora > 12) {
        // Si es PM
        printf("%02d:%02d PM", hora - 12, minutos);
    } else {
        // Si es AM
        printf("%02d:%02d AM", hora, minutos);
    }
    return 0;
}
