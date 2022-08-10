#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite por teclado la base y altura de un triángulo rectángulo
 * y muestre por pantalla su superficie. Presente la salida con el siguiente formato:
 * La superficie del triángulo es: XX.XX
 * */

int main() {
    float x, y, superficie;

    printf("Introduzca una base y una altura: ");
    scanf("%f%f", &x, &y);

    superficie = (x*y)/2;

    printf("La superficie de triangulo es: %.2f", superficie);
    return 0;
}
