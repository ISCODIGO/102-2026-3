#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool tieneISV = false;

    double precio = 450.0;
    double precioISV = precio;

    if (tieneISV) {  // bool (true|false) // 0 (false) != 0 (true)
        // bloque-if
        //precio = (precio + 15.0/100 * precio)
        //precio = precio * 1.15;
        precioISV *= 1.15;
    }

    printf("El precio neto es %.2f y con ISV es %.2f", precio, precioISV);

    return 0;
}
