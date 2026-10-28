#include <stdio.h>

void intercambio_referencia(int*, int*);
void intercambio_valor(int, int);

int main() {
    int n = 75;
    int *p = &n; // p guarda la direccion de n

    printf("Valor de n: %d\n", n);    // Salida: 75
    printf("Direccion de n: %p\n", &n); // Se usa (void*) para imprimir direcciones de forma est�ndar
    printf("Valor apuntado por p: %p\n", p);

    int x = 10;
    int y = 20;

    intercambio_valor(x, y);
    printf("\nCambio por valor: X=%d y Y=%d", x, y);

    intercambio_referencia(&x, &y);
    printf("\nCambio por referencia: X=%d y Y=%d", x, y);

    return 0;
}


void intercambio_valor(int a, int b) {
    int aux = a;
    a = b;
    b = aux;
    printf("\nDentro de la fn x = %d y y = %d", a, b);
}

void intercambio_referencia(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
    //printf("\nDentro de la fn x = %d y y = %d", a, b);
}
