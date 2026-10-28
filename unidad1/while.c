#include <stdio.h>

int main() {

    int i = 0;

    puts("While con incrementador...");
    while(i < 100) {
        printf("%d\n", ++i);
    }


    puts("while con break...");
    i = 0;
    while(1) {
        printf("%d\n", ++i);

        if (i >= 100) {
            //break;
        }
    }

    puts("While con bandera...");
    int bandera = 1;
    //i = 0;
    while(bandera) {
        printf("%d\n", ++i);

        if (i >= 100) {
            printf("Fin: %d", i);
            bandera = 0;
        }
    }
    return 0;
}
