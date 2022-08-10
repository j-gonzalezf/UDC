#include <stdio.h>
#define ROW 6

/* Plantee e implemente un programa en Lenguaje C que muestre por pantalla
 * las 6 primeras filas de un triángulo de Floyd:
 */

int main() {
    int i, j, k = 1;

    for (i = 1; i <= ROW; i++) {
        for (j = 1; j <= i; j++) {
            printf(" %2d", k++);
        }
        printf( "\n");
    }
    return 0;
}
