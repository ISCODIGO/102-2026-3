// una linea


/*
1
2
3
*/

// archivo.c -> compilador -> archivo.exe (Windows)


#include <stdio.h>

int main() {
    printf("Decimal: %d\r\n", 123);
    printf("Hexadecimal: 0x%x\n", 123);
    printf("Octal: %o\n", 123);
    printf("%.2f\n", 3.1499);
    printf("Relleno: [%10d]\n", 152);  // numero queda a la derecha, relleno de espacios
    printf("Relleno: [%010d]\n", 152);  // numero queda a la derecha, relleno de ceros
    printf("Relleno: [%-10d]\n", 152);  // numero queda a la izquierda

    printf("Numero grande: %lld", 4500000000);
    return 0;
}

//0123456789
//       152
