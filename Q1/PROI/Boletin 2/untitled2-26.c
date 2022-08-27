#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que muestre por pantalla la tabla de multiplicar (0-10)
 * de un número entero positivo introducido por el teclado.
 * */

int main() {
    int x, cont = 0;

    printf("Introduzca un número entero entre el 0 y el 10: ");
    scanf("%d", &x);

    if(x >= 0 && x <= 10) {
        printf("\n\t\t\t\tTABLA DE MULTIPLICAR DEL %d\n\n", x);

        do {
            printf("\t\t\t\t\t\t%d x %d = %d\n", x, cont, cont * x);
            cont++;
        } while (cont <= 10);
    }
    else printf("\nERROR: el número introducido no es válido\n");
    return 0;
}
