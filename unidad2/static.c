#include <stdio.h>

float ResultadosTotales(float);

int main() {
    printf("%f\n", ResultadosTotales(10));  // 0 + 10
    printf("%f\n", ResultadosTotales(20));  // 10 + 20
    printf("%f\n", ResultadosTotales(25));  // 30 + 25
    return 0;
}


float ResultadosTotales(float valor) {
    static float suma = 0; // Retiene su valor entre llamadas [10]
    suma = suma + valor;
    return suma;
}
