#include <stdio.h>
#include <stdlib.h>

/*
> calcu.exe 1 + 2
> 3

calcu.exe | 10 | + | 20
 0          1    2   3

*/
int main(int c, char *v[]) {
    int num1, num2;
    char op;

    num1 = atoi(v[1]);
    num2 = atoi(v[3]);
    op = v[2][0];

    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%c\n", op);

    printf("El resultado es: %d", num1 + num2);

    return 0;
}
