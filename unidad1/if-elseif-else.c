#include <stdio.h>
#include <stdbool.h>

int main()
{
    int candidato = 235-235;

    if (candidato < 0) {
        printf("Es negativo");
    } else if (candidato > 0) {
        printf("Es positivo");
    } else {
        printf("Es cero");
    }
    return 0;
}

