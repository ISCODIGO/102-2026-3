#include <stdio.h>

void a(void); // 0 entradas
void b();  // indefinidas entradas

int main() {
    a(1);
    b(1, 2);
    return 0;
}

void a() {
    b();
    puts("Funcion A");
}

void b() {
    puts("Funcion B");
}
