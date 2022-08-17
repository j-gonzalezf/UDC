#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que muestre por pantalla
 * tres números enteros introducidos por teclado ordenados de menor a mayor.
 * */

int main() {
    int x, y, z;

    printf("Introduzca 3 númros enteros: \n");
    scanf("%d%d%d", &x, &y, &z);

    printf("Primer Número: %d\nSegundo Número: %d\nTercer Número: %d\n\n", x, y, z);

    if((x >= y) && (x >= z)){
            if(y >= z) printf("%d <= %d <= %d\n", z, y, x);
            else printf("%d <= %d <= %d\n", y, z, x);
    }
    else {
        if ((y >= x) && (y >= z)) {
            if (x >= z) printf("%d <= %d <= %d\n", z, x, y);
            else printf("%d <= %d <= %d\n", x, z, y);
        } else {
            if (y >= x) printf("%d <= %d <= %d\n", x, y, z);
            else printf("%d <= %d <= %d\n", y, x, z);
        }
    }
    return 0;
}
