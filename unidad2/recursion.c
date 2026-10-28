#include <stdio.h>
long long factorial(int n); // Prototipo

int main() {
    int numero = 20;
    printf("%d", sizeof(long long));
    printf("El factorial de %d es: %lld\n", numero, factorial(numero));
    return 0;
}

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base
    }
    else {
        return n * factorial(n - 1); // Componente recursivo
    }
}
