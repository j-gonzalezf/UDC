#include <stdio.h>

/* Plantee e implemente una función en Lenguaje C que reciba un entero N y calcule 1+2+3+…+N, devolviendo dicho valor.
 * Además de la función, implemente la función apropiada para probar su funcionamiento,
 * activando este último desde el programa principal.
 * */

int calculo(int x){
    int suma = 0;

    for(int i = 0; i <= x; i++){
        suma = suma + i;
    }
    return suma;
}

int main() {
    int N, cal;

    printf("Introduzca un entero: ");
    scanf("%d", &N);

    cal = calculo(N);

    printf("El resultado es: %d\n", cal);
    return 0;
}
