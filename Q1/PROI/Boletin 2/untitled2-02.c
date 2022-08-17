#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite un número entero por teclado
 * y muestre por pantalla si es par o impar.
 * */

int main() {
    int x, r;

    printf("Introduzca un número entero: ");
    scanf("%d", &x);

    r = x % 2;

    if (r == 0) printf("Es un número par\n");
    else printf("Es un número impar\n");
    return 0;
}
