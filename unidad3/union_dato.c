#include <stdio.h>

// En una union todos los campos comparten la MISMA memoria:
// su tamaño es el del campo más grande y solo uno es válido a la vez.
union dato {
    int entero;
    float decimal;
    char letra;
};

// La misma idea con struct: cada campo tiene su propio espacio
struct dato_struct {
    int entero;
    float decimal;
    char letra;
};

// Uso típico: una struct con un "tipo" que indica qué campo de la union es válido
enum tipo { ENTERO, DECIMAL, LETRA };

struct valor {
    enum tipo tipo;
    union dato dato;
};

void mostrar(struct valor v) {
    switch (v.tipo) {
        case ENTERO:
            printf("Entero: %d\n", v.dato.entero);
            break;
        case DECIMAL:
            printf("Decimal: %.2f\n", v.dato.decimal);
            break;
        case LETRA:
            printf("Letra: %c\n", v.dato.letra);
            break;
    }
}

int main() {
    // 1. Tamaño: union vs struct
    printf("sizeof(union dato)  = %zu\n", sizeof(union dato));
    printf("sizeof(struct dato) = %zu\n\n", sizeof(struct dato_struct));

    // 2. Los campos se pisan: al escribir uno, se pierde el anterior
    union dato d;
    d.entero = 65;
    printf("d.entero = %d\n", d.entero);
    d.decimal = 3.14f;
    printf("d.decimal = %.2f\n", d.decimal);
    printf("d.entero ahora = %d (basura: se sobrescribio)\n\n", d.entero);

    // 3. Union con etiqueta de tipo
    struct valor lista[3] = {
        {ENTERO,  {.entero = 42}},
        {DECIMAL, {.decimal = 9.5f}},
        {LETRA,   {.letra = 'A'}},
    };
    for (int i = 0; i < 3; i++) {
        mostrar(lista[i]);
    }

    return 0;
}
