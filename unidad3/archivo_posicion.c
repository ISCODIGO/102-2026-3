#include <stdio.h>

// fseek(archivo, desplazamiento, origen) mueve la posición
//   SEEK_SET -> desde el inicio
//   SEEK_CUR -> desde la posición actual
//   SEEK_END -> desde el final
// ftell(archivo) devuelve la posición actual

int main() {
    // "wb+" = crea el archivo y permite escribir y leer.
    // Binario, para que cada posición sea exactamente un byte.
    FILE *archivo = fopen("posiciones.bin", "wb+");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return 1;
    }

    // Posición:     0123456789
    fputs("ABCDEFGHIJ", archivo);

    // 1. Ir al final: ftell da el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    printf("Tamano: %ld bytes\n", ftell(archivo));

    // 2. Ir al inicio
    fseek(archivo, 0, SEEK_SET);
    printf("Posicion inicial: %ld\n", ftell(archivo));

    // 3. Ir a la posición 3
    fseek(archivo, 3, SEEK_SET);
    printf("Caracter en la posicion 3: %c\n", fgetc(archivo));

    // 4. Leer avanza la posición (ahora es 4); saltar 2 más desde aquí
    fseek(archivo, 2, SEEK_CUR);
    printf("Caracter en la posicion 6: %c\n", fgetc(archivo));

    // 5. Último carácter: 1 antes del final
    fseek(archivo, -1, SEEK_END);
    printf("Ultimo caracter: %c\n", fgetc(archivo));

    fclose(archivo);
    return 0;
}
