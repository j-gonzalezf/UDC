#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite por teclado los lados de un rectángulo
 * y muestre por pantalla su perímetro. Presente la salida con el siguiente formato:
 * El rectángulo tiene un perímetro de: XX.XX
 */

int main() {
    float x, y, p;

    printf("Introduzca una base y una altura: ");
    scanf("%f%f", &x, &y);

    p = x + x + y + y;

    printf("El rectagulo tiene un perímetro de: %.2f", p);
    return 0;
}
