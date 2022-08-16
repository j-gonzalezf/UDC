#include <stdio.h>

/* Escribir un programa, empleando funciones de usuario, que pida un número entero y muestre por pantalla
 * el mayor entero que lo divide exceptuando el mismo.
 * */

int mayor(int x){
    int z = 0, y = x;
    for( y; y > 0; y--){
        if(x%y == 0 && z < y && y != x) z = y;
    }
    return z;
}

int main() {
    int e, m;

    printf("Introduza un número entero: ");
    scanf("%d", &e);
    m = mayor(e);

    printf("El mayor entero que divide a %d es %d\n", e, m);
    return 0;
}
