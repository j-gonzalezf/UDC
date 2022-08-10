#include <stdio.h>
#define PI 3.1416

/* Plantee e implemente un programa en Lenguaje C que muestre por pantalla una tabla
 * indicando el radio, el perímetro y el área de tres círculos cuyo radio es solicitado por teclado.
 * */

int main() {
    int x, y, z;
    float p1, p2, p3, a1, a2, a3;

    printf("Introduzca el radio de tres circulos: ");
    scanf("%d%d%d", &x, &y, &z);

    p1 = 2*PI*x;
    a1 = PI*x*x;
    p2 = 2*PI*y;
    a2 = PI*y*y;
    p3 = 2*PI*z;
    a3 = PI*z*z;

    printf("RADIO\t\tPERIMETRO\t\tAREA\n");
    printf("=====\t\t=========\t\t=====\n");
    printf("%d\t\t\t%.2f\t\t\t%.2f\n", x, p1, a1);
    printf("%d\t\t\t%.2f\t\t\t%.2f\n", y, p2, a2);
    printf("%d\t\t\t%.2f\t\t\t%.2f\n", z, p3, a3);
    return 0;
}
