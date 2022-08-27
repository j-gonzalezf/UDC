#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que reciba números enteros
por teclado y al terminar indique cuánto vale la suma de los números pares y los
impares por separado. La entrada de números terminará cuando se introduzca
un cero.
 * */

int main() {
    int n = -1, sump = 0, sumi = 0;

    printf("A continuación introduzca los números enteros que desee sumar separados por espacios y pulsa 0 para parar:");

    while (n != 0) {
        scanf("%d", &n);
        if (n % 2 == 0) {
            sump = sump + n;
        }
        else { sumi = sumi + n; }
    }

    printf("Pares: %d\nImpares: %d\n", sump, sumi);
    return 0;
}
