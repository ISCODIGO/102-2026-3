/*

for(A; B; C) {}

 - A: inicializacion
 - B: condicion (true=sigue, false=para)
 - C: actualizacion

*/


#include <stdio.h>

int main() {
    int suma = 0;
    for(int i = 1; i <= 100; i += 2) {
        //printf("%d\n", i);
        suma += i;
    printf("%d\n", suma);
    }
    return 0;
}
