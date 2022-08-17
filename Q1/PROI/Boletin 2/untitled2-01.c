#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite un número entero por teclado
 * y muestre por pantalla si es positivo o negativo.
 * */

int main() {
    float x;

    printf("Introduzca un número: ");
    scanf("%f", &x);

    if(x == 0) printf("El número escogido es neutro");
    else{
        if(x < 0) printf("El número escogido es negativo");
        else printf("El número escogido es positivo");
    }
    return 0;
}
