#include <stdio.h>

/* Plantee e implemente una función en Lenguaje C para leer un entero dentro de un intervalo, cuyos límites
 * inferior y superior los proporcione el usuario por teclado. Además de la función, implemente la función apropiada
 * para probar su funcionamiento, activando este último desde el programa principal.
 * */

void leer(int x, int y){
    char entero;
    for(x; x < y; --x) entero = getchar();
    printf("%c", entero);
}

int main() {
    int e1, e2;

    printf("Establezca los limites superior e inferior: ");
    scanf("%d%d", &e1, &e2);

    if(e1 > e2) leer(e1, e2);
    else printf("ERROR: introduzca primero un limite superior y luego un inferior");
    return 0;
}
