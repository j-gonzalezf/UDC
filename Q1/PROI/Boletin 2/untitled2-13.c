#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C para clasificar triángulos en función de las longitudes de sus lados,
 * que se solicitarán por teclado, de forma que se indique por pantalla si el triángulo es
 * equilátero (todos los lados iguales), isósceles (dos lados iguales) o escaleno (todos los lados diferentes).
 * */

int main() {
    float x, y, z;

    printf("Introduzca los lados 1, 2 y 3 del triángulo (cm): ");
    scanf("%f%f%f", &x, &y, &z);

    if((x == y) && (y == z)) printf("El triángulo es EQUILATERO (lado1 = lado2 = lado3 = %.f cm)\n", x);
    if(((x == y) && (y != z)) || ((x == z) && (z != y)) || ((y == z) && (z != x))){
        if (x == y) printf("El triángulo es ISÓSCELES (lado 1 = lado 2 = %.f cm)\n", x);
        if (x == z) printf("El triángulo es ISÓSCELES (lado 1 = lado 3 = %.f cm)\n", x);
        if (y == z) printf("El triángulo es ISÓSCELES (lado 2 = lado 3 = %.f cm)\n", y);
    }
    if((x != y) && (y != z) && (x != z)) printf("El triángulo es ESCALENO\n");
    return 0;
}
