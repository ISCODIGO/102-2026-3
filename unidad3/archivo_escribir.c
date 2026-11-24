#include <stdio.h>

// Modos de fopen:
//   "w" -> escribir (crea el archivo; si ya existe, BORRA su contenido)
//   "a" -> agregar al final (crea el archivo si no existe)
//   "r" -> leer (el archivo debe existir)

int main() {
    // 1. Abrir en modo escritura
    FILE *archivo = fopen("datos.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return 1;
    }

    // 2. Escribir
    fprintf(archivo, "Primera linea\n");
    fputs("Segunda linea\n", archivo);

    // 3. Cerrar
    fclose(archivo);

    // 4. Abrir de nuevo para agregar: no se pierde lo anterior
    archivo = fopen("datos.txt", "a");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }
    fprintf(archivo, "Tercera linea (agregada con \"a\")\n");
    fclose(archivo);

    printf("Archivo datos.txt creado.\n");
    return 0;
}
