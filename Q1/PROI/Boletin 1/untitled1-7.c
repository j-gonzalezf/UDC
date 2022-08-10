#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite el precio de un producto (sin IVA)
 * y proporcione por pantalla el importe total del producto con IVA incluído.
 * (IVA constante del 24% para todos los productos)
 * */

int main() {
    float x;

    printf("Introduzca el precio del producto: ");
    scanf("%f", &x);

    x += x*24/100;

    printf("El importe total (IVA incluido) es de: %.2f€", x);
    return 0;
}
