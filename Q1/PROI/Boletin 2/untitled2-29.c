#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que acepte valores reales como entrada (por teclado)
 * y que muestre por pantalla la media aritmética de los valores introducidos. El programa terminará cuando el usuario pulse enter.
 * */

int main() {
    int cont = 0, cero;
    float med, x1 = 0, x;

    printf("Antes de nada, debido a que el programa finaliza al pulsar 0,\n"
           "introduzca el número de ceros que vaya a utilizar para la media si es que los necesita, sino pulse 0: ");
    scanf("%d", &cero);

    cont = cont + cero;

    printf("\nIntroduce un número: ");
    scanf("%f", &x);

    x1 = x;

    printf("\nIntroduzca otro número u otros números separados por espacios para hallar su media y pulsa 0 para parar: ");

    do{
        cont++;
        if(x != 0) {
            scanf("%f", &x);
            x1 = x1 + x;
            med = x1/cont;
        }
    }
    while (x != 0);

    printf("La media de los números es %.2f\n", med);
    return 0;
}
