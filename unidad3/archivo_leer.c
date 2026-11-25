#include <stdio.h>

// Lee datos.txt: ejecutar antes archivo_escribir.c (en la misma carpeta)

int main() {
    FILE *archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir datos.txt.\n");
        return 1;
    }

    // 1. Línea por línea: fgets devuelve NULL cuando ya no hay más
    char linea[100];
    int numero = 1;
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%d: %s", numero, linea);    // linea ya incluye el '\n'
        numero++;
    }

    // feof se consulta DESPUÉS de que la lectura falla, no como condición del ciclo
    if (feof(archivo)) {
        printf("Se llego al final del archivo.\n\n");
    }

    // 2. Carácter por carácter: fgetc devuelve EOF al final
    rewind(archivo);    // volver al inicio
    int c;              // int y no char, para poder distinguir EOF
    int total = 0;
    while ((c = fgetc(archivo)) != EOF) {
        putchar(c);
        total++;
    }
    printf("Total de caracteres: %d\n", total);

    fclose(archivo);
    return 0;
}
