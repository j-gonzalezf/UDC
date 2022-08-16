#include <stdio.h>
#include <math.h>

/* Plantee e implemente en Lenguaje C una función que calcule el valor del siguiente polinomio:
 * 3x5 + 2x4 – 5x3 – x2 + 7x - 6 Además del subprograma, implemente la función apropiada para probar
 * su funcionamiento preguntándole al usuario el valor de x, y activando esta última desde el programa principal.
 * */

int resolver(int a){
    int i;

    for(i = a; 3*pow(i, 5) + 2*pow(i, 4) - 5*pow(i, 3) - pow(i, 2) + 7*i - 6 != 0; i++);
    return i;
}

int main() {
    int x = 0;

    x = resolver(x);

    printf("El valor del polinomio es: %d\nPor lo que se puede factorizar (x - %d)\n", x, x);
    return 0;
}
