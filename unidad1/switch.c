#include <stdio.h>

int main() {
    char nota, otro;
    printf("Ingrese su calificacion (A-F): ");
    scanf(" %c", &nota);
    scanf(" %c", &otro);

    printf("Otro: %c\n", otro);

    switch (nota) {
        case 'A': case 'a': puts("Excelente"); break;
        case 'B': case 'b': puts("Notable"); break;
        case 'C': case 'c': puts("Aprobado"); break;
        default:  puts("Calificacion no valida");
    }
    return 0;
}
