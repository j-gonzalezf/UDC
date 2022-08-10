#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que calcule el producto escalar de dos vectores
 * en el espacio euclídeo. (dimension de 3)
 * */

int main() {
    float v1, v12, v13, v2, v22, v23, pro;

    printf("Introduzca un vector: ");
    scanf("%f%f%f", &v1, &v12, &v13);

    printf("Introduzca otro vector: ");
    scanf("%f%f%f", &v2, &v22, &v23);

    pro = v1*v2 + v12*v22 + v13*v23;
    printf("Producto escalar: %.2f", pro);
}
