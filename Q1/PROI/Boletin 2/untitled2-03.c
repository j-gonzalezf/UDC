#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite por teclado dos números enteros
 * y que muestre un mensaje indicando si el primero es o no divisible por el segundo.
 * */

int main() {
    int x, y, r;

    printf("Introduzca dos números enteros: \n");
    scanf("%d%d", &x, &y);

    r = x % y;

    if(r == 0) printf("%d es divisible por %d", x, y);
    else printf("%d NO es divisible por %d", x, y);
    return 0;
}
