#include <stdio.h>
#define TAM 7

/* Plantee e implemente un programa en lenguaje C, que utilizando exclusivamente subprogramas,
 * solicite nombres de animales por teclado y vaya rellenando un array de 7 elementos,
 * mostrándolos posteriormente por pantalla apropiadamente.
 * */

void leer(char animal[][20]){
    for (int i=0; i<TAM ; i++) {
        printf("Introduce el animal %d: ", i+1);
        scanf("%s", animal[i]);
    }
}

void imprimir(char animal[][20]){
    for (int i=0; i<TAM ; i++) {
        printf("El animal %d es %s\n", i+1, animal[i]);
    }
}

int main() {
    char bestia[TAM][20];

    leer(bestia);
    imprimir(bestia);

    return 0;
}
