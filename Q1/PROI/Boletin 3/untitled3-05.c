#include <stdio.h>

/* Plantee e implemente un subprograma en Lenguaje C para mostrar por pantalla el triángulo de Floyd hasta
 * un número entero introducido por teclado. Además del subprograma, implemente la función apropiada para
 * probar su funcionamiento, activando este último desde el programa principal.
 * */

void floyd(int x) {
    int i, j, n = 1;

    for (i = 1; i <= x; i++){
        for (j = 1; j <= i; j++){
            if(x >= n) printf("%d ", n);
            n++;
        }
        printf("\n");
    }
}

int main() {
    int num;

    printf("Introduce un número: ");
    scanf("%d", &num);

    floyd(num);
    return 0;
}
