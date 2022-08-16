#include <stdio.h>
#define TAM 30

/* Plantee e implemente un programa en lenguaje C, que utilizando exclusivamente subprogramas,
 * calcule la suma de los elementos de un array de números reales proporcionados por el usuario,
 * considerando como máximo 30 elementos.
 * */

void leer(int numero[], int a){
    for(int i=0; i<a; i++) {
            printf("Introduce un elemento a sumar: ");
            scanf("%d", &numero[i]);
    }
}

void suma(int numero[], int a){
    int suma=0;
    for(int i=0; i<a; i++){
        suma = suma + numero[i];
    }
    printf("La suma de todos los elementos es: %d\n", suma);
}

int main() {
    int num[TAM], x;

    printf("Introduzca el número de elementos a sumar (max 30): ");
    scanf("%d", &x);

    if(x<0) printf("ERROR: el número de elementos ha de ser un natural\n");
    else{
        if (x <= 30) {
            leer(num, x);
            suma(num, x);
        } else printf("ERROR: se ha alcanzado la cifra máxima\n");
    }
    return 0;
}
