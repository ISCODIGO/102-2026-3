#include <stdio.h>

int main() {
    // 1. Error al abrir: fopen devuelve NULL y perror muestra la causa
    FILE *archivo = fopen("no_existe.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir no_existe.txt");
    } else {
        fclose(archivo);
    }

    // 2. Error al leer: se provoca leyendo un archivo abierto solo para escribir
    archivo = fopen("errores.txt", "w");
    if (archivo == NULL) {
        perror("Error al crear errores.txt");
        return 1;
    }

    int c = fgetc(archivo);
    // EOF puede significar "fin de archivo" o "error":
    // feof y ferror permiten distinguirlos
    if (c == EOF) {
        if (ferror(archivo)) {
            perror("Error al leer errores.txt");
        } else if (feof(archivo)) {
            printf("Fin del archivo.\n");
        }
    }

    // 3. clearerr limpia los indicadores de error y de fin de archivo
    printf("ferror antes de clearerr:   %s\n", ferror(archivo) ? "si" : "no");
    clearerr(archivo);
    printf("ferror despues de clearerr: %s\n", ferror(archivo) ? "si" : "no");

    // 4. fclose también puede fallar (ej. disco lleno): devuelve EOF
    if (fclose(archivo) == EOF) {
        perror("Error al cerrar errores.txt");
        return 1;
    }

    return 0;
}
