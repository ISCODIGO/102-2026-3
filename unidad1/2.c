#include <stdio.h>
#include <limits.h>

int main() {
    int anio = 2026;
    int mes = 9;
    int dia = 2;
    printf("La fecha es: %02d/%02d/%d", dia, mes, anio);
    printf("El dia es: %02d\nEl mes es: %02d\nEl anio es: %d", dia, mes, anio);

    printf("\n\n=====\n=   =\n=   =\n=====");

    int operacion = 2 + 3 * 5 && 3 > 4;
    printf("\n2 + 3 * 5 && 3 > 4: %d", operacion);

    int sePasa = INT_MAX;
    printf("\nValor max: %d", sePasa);
    sePasa += 1; // sePasa = sePasa + 1;

    printf("\nValor max + 1: %d", sePasa);

    printf("\nValor min - 1: %d", INT_MIN - 1);
    return 0;
}
