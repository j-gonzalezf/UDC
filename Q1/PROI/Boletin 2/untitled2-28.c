#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que acepte valores enteros como entrada (por teclado)
 * y que muestre por pantalla la suma de los valores introducidos. El programa terminará cuando el usuario introduzca un 0.
 * */

int main() {
    int x, sum = 0;

    printf("Introduce un número: ");
    scanf("%d", &x);

    sum = sum + x;

    do{
        printf("\nIntroduce otro número para sumarlo o pulsa 0 para parar: ");
        scanf("%d", &x);
        if(x != 0) {
            sum = sum + x;
            printf("La suma de los números es %d\n", sum);
        }
    }
    while (x != 0);

    printf("Operación terminada con éxito\n");
    return 0;
}
