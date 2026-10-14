/*
Calculadora:

> numero: 10
> otro: 20
> operacion: +
> salida: 30

*/

#include <stdio.h>

int main() {
    float numero1, numero2, resultado;
    char operacion;

    printf("Operacion: ");
    scanf("%c", &operacion);

    printf("Numero: ");
    scanf("%f", &numero1);

    printf("Otro numero: ");
    scanf("%f", &numero2);

    switch (operacion) {
        case '+':
            resultado = numero1 + numero2; break;
        case '-':
            resultado = numero1 - numero2; break;
        case '/':
            resultado = numero1 / numero2; break;
        case '*':
            resultado = numero1 * numero2; break;
        default:  puts("Operacion no valida");
    }
    printf("\nSalida: %f", resultado);
    return 0;
}

