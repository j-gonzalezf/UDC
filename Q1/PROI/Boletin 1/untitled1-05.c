#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite por teclado los lados de un rectángulo
 * y muestre por pantalla su superficie.
 */

int main() {
float x, y, s;

printf("Introduzca una base y una altura: ");
scanf("%f%f", &x, &y);

if(x != y) {
    s = x*y;
    printf("La superficie del rectángulo es: %.2f", s);
}
else{
    printf("Esto no es un rectángulo");
}
return 0;
}
