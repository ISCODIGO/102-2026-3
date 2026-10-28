#include <stdio.h>

int main() {
    for (int candidato = 1; candidato <= 100; candidato++) {
        int hayDivisor = 0;
        printf("%d ", candidato);

        for(int divisores = 2; divisores <= candidato/2; divisores++) {
            if (candidato % divisores == 0) {
                hayDivisor = 1;
                break;
            }
        }

        if (hayDivisor) {
            puts("No es primo");
        } else {
            puts("Es primo");
        }
    }

    return 0;
}
