#include <stdio.h>

int main() {
    printf("Escriba el largo de la figura: ");

    int largo;
    scanf("%d", &largo);

    puts("Cuadrado...");

    for(int i = 0; i < largo; i++) {

        for(int j = 0; j < largo; j++) {
            printf("%c ", '*');
        }
        puts("");
    }

    puts("Triangulo 1...");

    for(int i = 0; i < largo; i++) {

        for(int j = 0; j < largo - i; j++) {
            printf("%c ", '*');
        }
        puts("");
    }

    puts("Triangulo 2...");

    for(int i = 0; i < largo; i++) {
        int estrellas = i + 1;
        int huecos = largo - estrellas;

        for(int j = 0; j < largo; j++) {
            if (j < huecos) {
                printf("  ");
            } else {
                printf("%c ", '*');
            }
        }
        puts("");
    }

    puts("Triangulo 2...");

    for(int i = 0; i < largo; i++) {
        for(int j = 0; j < largo - i - 1; j++) {
            printf("  ");
        }
        for(int j = 0; j <= i; j++) {
            printf("%c ", '*');
        }
        puts("");
    }

    puts("Diagonal 1...");

    for(int i = 0; i < largo; i++) {
        for(int j = 0; j < largo; j++) {
            if (j != i) {
                printf("  ");
            } else {
                printf("%c ", '*');
            }
        }
        puts("");
    }

    puts("Diagonal 2...");

    for(int i = 0; i < largo; i++) {
        for(int j = 0; j < largo; j++) {
            if (j + i + 1 != largo) {
                printf("  ");
            } else {
                printf("%c ", '*');
            }
        }
        puts("");
    }

    return 0;
}
