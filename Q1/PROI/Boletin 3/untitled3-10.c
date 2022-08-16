#include <stdio.h>

/* Plantee e implemente una función en Lenguaje C que tenga un argumento de tipo entero y que devuelva
 * la letra P si el número es positivo o N si el número es negativo. Además del subprograma, implemente
 * la función apropiada para probar su funcionamiento, activando este último desde el programa principal.
 * */

void letra(int a){
    if(a < 0) printf("N\n");
    else printf("P\n");
}

int main() {
    int x;

    printf("Introduzca un número entero: ");
    scanf("%d", &x);

    letra(x);
    return 0;
}
