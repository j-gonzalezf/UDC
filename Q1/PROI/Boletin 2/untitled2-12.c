#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite tres números enteros positivos (por teclado)
 * y que muestre por pantalla el cociente y el resto de dividir el mayor de ellos por el menor.
 * */

int main() {
    int x, y, z;

    printf("Introduzca 3 números enteros: ");
    scanf("%d%d%d", &x, &y, &z);

    if((x > y) && (y > z)){
        if(z == 0) printf("MATH ERROR");
        else {
            printf("\n\t%d dividido |entre %d\n", x, z);
            printf("\t\t\t\t----------\n");
            printf("\t\t R:%d\t\tC:%d", x % z, x / z);
        }
    }
    if((x > z) && (z > y)){
        if(y == 0) printf("MATH ERROR");
        else {
            printf("\n\t%d dividido |entre %d\n", x, y);
            printf("\t\t\t\t----------\n");
            printf("\t\t R:%d\t\tC:%d", x % y, x / y);
        }
    }
    if((y > x) && (x > z)){
        if(z == 0) printf("MATH ERROR");
        else {
            printf("\n\t%d dividido |entre %d\n", y, z);
            printf("\t\t\t\t----------\n");
            printf("\t\t R:%d\t\tC:%d", y % z, y / z);
        }
    }
    if((y > z) && (z > x)){
        if(x == 0) printf("MATH ERROR");
        else {
            printf("\n\t%d dividido |entre %d\n", y, x);
            printf("\t\t\t\t----------\n");
            printf("\t\t R:%d\t\tC:%d", y % x, y / x);
        }
    }
    if((z > x) && (x > y)){
        if(y == 0) printf("MATH ERROR");
        else {
            printf("\n\t%d dividido |entre %d\n", z, y);
            printf("\t\t\t\t----------\n");
            printf("\t\t R:%d\t\tC:%d", z % y, z / y);
        }
    }
    if((z > y) && (y > x)){
        if(x == 0) printf("MATH ERROR");
        else {
            printf("\n\t%d dividido |entre %d\n", z, x);
            printf("\t\t\t\t----------\n");
            printf("\t\t R:%d\t\tC:%d", z % x, z / x);
        }
    }
    return 0;
}
