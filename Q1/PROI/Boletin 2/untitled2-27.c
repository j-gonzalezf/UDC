#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que sume los primeros 100 números enteros.
 * Realícelo con cada uno de los tres bucles.
 * */

int main() {
    int cont = 0, x = 0, i, sum = 0, j = 0, ant = 0;

    do{
        x = x + cont;
        cont++;
     }
    while(cont <= 100);
    printf("La suma es %d\n", x);


    for (i = 0; i <= 100; i++) sum = sum + i;
    printf("La suma es %d\n", sum);


    while(j <= 100) {
        ant = ant + j;
        j++;
    }
    printf("La suma es %d\n", ant);

    return 0;
}
