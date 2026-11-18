#include <stdio.h>
#include <string.h>

// Definición de la estructura
struct alumno {
    char nombre[50];
    char cuenta[15];
    char carrera[50];
    int promedio;
};

// Quita el '\n' que deja fgets al final de la cadena
void limpiar_cadena(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

// Descarta lo que quedó en el buffer después de un scanf
void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Lee un entero entre min y max; repite hasta que la entrada sea válida
int leer_entero(const char *mensaje, int min, int max) {
    int valor;
    char siguiente = 0;

    printf("%s", mensaje);
    // scanf("%d%c") lee el entero en 'valor' y el carácter que le sigue en 'siguiente'.
    // Devuelve cuántos valores leyó:
    //   0 -> no hay ningún número (ej. "abc")
    //   1 -> leyó el número, pero no hay carácter después (EOF)
    //   2 -> leyó ambos (ej. "42" + Enter: valor = 42, siguiente = '\n')
    // Cualquier retorno != 2 es entrada inválida.
    // siguiente != '\n' rechaza entradas como "42abc" o "42 5" (debe venir Enter justo después).
    // Por último, valida que el valor esté en el rango [min, max].
    while (scanf("%d%c", &valor, &siguiente) != 2 || siguiente != '\n'
           || valor < min || valor > max) {
        if (siguiente != '\n') limpiar_buffer();
        printf("Valor invalido. Ingrese un numero entre %d y %d: ", min, max);
        siguiente = 0;
    }
    return valor;
}

int main() {
    // 1. Inicialización directa al declarar
    struct alumno a1 = {"Ana Lopez", "20231001", "Ingenieria en Sistemas", 92};

    // 2. Asignación campo por campo
    struct alumno a2;
    strcpy(a2.nombre, "Carlos Mejia");
    strcpy(a2.cuenta, "20231002");
    strcpy(a2.carrera, "Administracion");
    a2.promedio = 85;

    // 3. Lectura desde teclado
    struct alumno a3;
    printf("Nombre: ");
    fgets(a3.nombre, sizeof(a3.nombre), stdin);
    limpiar_cadena(a3.nombre);

    printf("Cuenta: ");
    fgets(a3.cuenta, sizeof(a3.cuenta), stdin);
    limpiar_cadena(a3.cuenta);

    printf("Carrera: ");
    fgets(a3.carrera, sizeof(a3.carrera), stdin);
    limpiar_cadena(a3.carrera);

    a3.promedio = leer_entero("Promedio: ", 0, 100);

    // Mostrar los datos
    struct alumno lista[3] = {a1, a2, a3};
    printf("\n%-20s %-12s %-25s %s\n", "NOMBRE", "CUENTA", "CARRERA", "PROMEDIO");
    for (int i = 0; i < 3; i++) {
        printf("%-20s %-12s %-25s %d\n",
               lista[i].nombre, lista[i].cuenta,
               lista[i].carrera, lista[i].promedio);
    }

    return 0;
}