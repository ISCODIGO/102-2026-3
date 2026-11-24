#include <stdio.h>

// typedef crea un alias: se escribe 'Producto' en lugar de 'struct ...'
typedef struct {
    int codigo;
    char nombre[30];
    float precio;
} Producto;

int main() {
    Producto lista[2] = {
        {1001, "Laptop", 899.99f},
        {1002, "Mouse", 25.50f},
    };

    // 1. Escribir: "wb" = escritura binaria
    FILE *archivo = fopen("productos.bin", "wb");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return 1;
    }
    // fwrite(direccion, tamaño de cada elemento, cantidad, archivo)
    // Devuelve cuántos elementos escribió.
    size_t escritos = fwrite(lista, sizeof(Producto), 2, archivo);
    fclose(archivo);
    printf("Productos escritos: %zu\n\n", escritos);

    // 2. Leer: "rb" = lectura binaria
    archivo = fopen("productos.bin", "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }
    Producto p;
    // Lee de uno en uno; cuando ya no hay más, fread devuelve 0
    while (fread(&p, sizeof(Producto), 1, archivo) == 1) {
        printf("%-6d %-10s %8.2f\n", p.codigo, p.nombre, p.precio);
    }
    fclose(archivo);

    return 0;
}
