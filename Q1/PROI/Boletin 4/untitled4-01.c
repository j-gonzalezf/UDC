#include <stdio.h>
#define TAM 10

/* Plantee e implemente un programa en lenguaje C, que utilizando exclusivamente subprogramas,
 * solicite números enteros por teclado y vaya almacenándolos en un array de 10 elementos,
 * mostrando a continuación por pantalla el contenido del array creado.
 * */

void leer(int numero[]);
void imprimir(int numero[]);

int main() {
    int num[TAM];

    leer(num);
    imprimir(num);

    return 0;
}

void leer(int numero[]){
    for(int i=0; i<TAM; i++) {
        printf("Escriba un número: ");
        scanf("%d", &numero[i]);
    }
}
void imprimir(int numero[]){
    for(int i=0; i<TAM; i++){
        printf("El valor de la posición %d es %d\n", i, numero[i]);
    }
}
