#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite un número por teclado y que esté
 * constantemente solicitando un número si no está comprendido entre 20 y 30 ambos inclusive.
 * */

int main() {
    int x = 0;

    do{
        printf("Introduzca un número entre 20 y 30: ");
        scanf("%d", &x);
    }
    while (x < 20 || x > 30);

    return 0;
}
