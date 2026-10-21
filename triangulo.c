#include <stdio.h>

int main() {
    printf("Escriba el largo de la figura: ");

    int largo;
    scanf("%d", &largo);

    for(int i = 0; i < largo; i++) {

        for(int j = 0; j < largo; j++) {
            printf("%c ", '*');
        }
        puts("");
    }

    puts("");

    for(int i = 0; i < largo; i++) {

        for(int j = 0; j < largo - i; j++) {
            printf("%c ", '*');
        }
        puts("");
    }

    puts("");

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

    puts("");

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

    puts("");

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
