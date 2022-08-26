#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que muestre la tabla de multiplicar de los cinco primeros números.
 * */

int main() {
    int x = 1, cont = 0;

    do {
        printf("\t\t\t\tTABLA DE MULTIPLICAR DEL %d\n\n", x);

        do {
            printf("\t\t\t\t\t\t%d x %d = %d\n", x, cont, cont * x);
            cont++;
        } while (cont <= 10);

        cont = 0;
        x++;
        printf("\n");
    }
    while (x <= 5);

    return 0;
}
