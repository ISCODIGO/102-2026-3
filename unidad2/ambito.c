#include <stdio.h>

int variable_global;

void funcion();

int main() {

    funcion();
    printf("Variable global: %d\n", variable_global);

    int variable_main = 10;

    for (int i = 1; i < 10; i++) {
        int variable_for = 9;

        if (variable_main % 2 == 0) {
            int variable_if = 11;

            printf("Variable for: %d\n", variable_for);
        }
    }

    //printf("%d", variable_if);
    return 0;
}


void funcion() {
    variable_global = 99;
}
