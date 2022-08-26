#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que muestre por pantalla la tabla de multiplicar del 7.
 * */

int main() {
    int x = 7, cont = 0;

    printf("\t\t\t\tTABLA DE MULTIPLICAR DEL 7\n\n");

    do{
        printf("\t\t\t\t\t\t%d x %d = %d\n", x, cont, cont*x);
        cont++;
    }
    while (cont <= 10);

    printf("\n");
    return 0;
}
