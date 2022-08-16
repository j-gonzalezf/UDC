#include <stdio.h>

/* Plantee e implemente un subprograma en Lenguaje C para escribir N líneas en blanco por pantalla. 
 * Además del subprograma, implemente un programa principal para probar su funcionamiento.
 * */

void imprimir(int x){
    for(int j = 0; j < x; j++) printf("\n");
}

int main() {
    int n; //n = número de lineas

    printf("Introduzca el número de líneas: ");
    scanf("%d", &n);

    imprimir(n);
    printf("----------------end----------------\n");
    return 0;
}
