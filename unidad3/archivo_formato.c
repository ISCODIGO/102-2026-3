#include <stdio.h>

// typedef crea un alias: se escribe 'Estudiante' en lugar de 'struct ...'
typedef struct {
    int id;
    char nombre[50];
    float nota;
} Estudiante;

int main() {
    Estudiante lista[2] = {
        {101, "Juan Perez", 85.5f},
        {102, "Maria Garcia", 92.0f},
    };

    // 1. Escribir: un estudiante por línea, campos separados por ';'
    FILE *archivo = fopen("estudiantes.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return 1;
    }
    for (int i = 0; i < 2; i++) {
        fprintf(archivo, "%d;%s;%.1f\n", lista[i].id, lista[i].nombre, lista[i].nota);
    }
    fclose(archivo);

    // 2. Leer con fscanf
    archivo = fopen("estudiantes.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }
    Estudiante e;
    // %s se detiene en el primer espacio ("Juan Perez" -> "Juan").
    // %49[^;] lee hasta 49 caracteres, o hasta encontrar ';'.
    // fscanf devuelve cuántos campos leyó: deben ser 3.
    while (fscanf(archivo, "%d;%49[^;];%f", &e.id, e.nombre, &e.nota) == 3) {
        printf("%-5d %-20s %.1f\n", e.id, e.nombre, e.nota);
    }
    fclose(archivo);

    return 0;
}
