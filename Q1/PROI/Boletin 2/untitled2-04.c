#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que muestre por pantalla
 * el mayor de tres números introducidos por teclado.
 * */

int main() {
    int x, y, z;

    printf("Introduzca tres números enteros: ");
    scanf("%d%d%d", &x, &y, &z);

    printf("Primer Número: %d\nSegundo Número: %d\nTercer Número: %d\n\n", x, y, z);

    if((x == y)||(x == z)||(y == z)) printf("Error: hay números con el mismo valor\n");
    else {
        if ((x > y) && (x > z)) printf("%d es el número mayor de los tres introducidos\n", x);
        else {
            if ((y > x) && (y > z)) printf("%d es el número mayor de los tres introducidos\n", y);
            else printf("%d es el número mayor de los tres introducidos\n", z);
        }
    }
    return 0;
}
