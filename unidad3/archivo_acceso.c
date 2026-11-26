// Errores de acceso al abrir un archivo.
// Solo para Windows: _doserrno, _chmod y _fsopen no son C estándar.
#include <stdio.h>
#include <stdlib.h>   // _doserrno
#include <errno.h>    // errno, ENOENT, EACCES
#include <io.h>       // _chmod
#include <share.h>    // _SH_DENYRW
#include <sys/stat.h> // _S_IREAD, _S_IWRITE

#define ERROR_EN_USO 32 // código de Windows: archivo en uso por otro proceso

void probar(const char *nombre, const char *modo) {
    printf("%s (modo \"%s\"): ", nombre, modo);

    FILE *archivo = fopen(nombre, modo);
    if (archivo != NULL) {
        printf("se abrio correctamente.\n");
        fclose(archivo);
        return;
    }

    // Guardarlos de inmediato: otra llamada (incluso printf) puede cambiarlos
    int error = errno;
    unsigned long error_windows = _doserrno;

    if (error == ENOENT) {
        printf("el archivo o la ruta no existe.\n");
    } else if (error == EACCES && error_windows == ERROR_EN_USO) {
        printf("el archivo esta en uso.\n");
    } else if (error == EACCES) {
        printf("acceso denegado (permisos, solo lectura o es una carpeta).\n");
    } else {
        printf("otro error (errno = %d).\n", error);
    }
}

int main() {
    // Archivo de prueba
    FILE *archivo = fopen("acceso.txt", "w");
    if (archivo == NULL) {
        perror("Error al crear acceso.txt");
        return 1;
    }
    fprintf(archivo, "prueba\n");
    fclose(archivo);

    // 1. El archivo no existe
    probar("no_existe.txt", "r");

    // 2. La ruta es una carpeta ("." es la carpeta actual)
    probar(".", "r");

    // 3. Archivo de solo lectura: se puede leer, pero no escribir
    if (_chmod("acceso.txt", _S_IREAD) == -1) {
        perror("Error al cambiar permisos");
    } else {
        probar("acceso.txt", "r");
        probar("acceso.txt", "a");
        _chmod("acceso.txt", _S_IREAD | _S_IWRITE);
    }

    // 4. Archivo en uso: se abre bloqueando la lectura y la escritura
    FILE *bloqueo = _fsopen("acceso.txt", "r", _SH_DENYRW);
    if (bloqueo == NULL) {
        perror("Error al bloquear acceso.txt");
    } else {
        probar("acceso.txt", "r");
        fclose(bloqueo);
    }

    // 5. Al liberar el bloqueo se puede abrir de nuevo
    probar("acceso.txt", "r");

    // Borrar el archivo de prueba
    if (remove("acceso.txt") != 0) {
        perror("Error al borrar acceso.txt");
        return 1;
    }

    return 0;
}
