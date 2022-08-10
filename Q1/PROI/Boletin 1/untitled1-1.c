#include <stdio.h>

/* Plantee e implemente un programa en lenguaje C que solicite el nombre y la edad de un usuario por teclado
 * de forma que el ordenador le salude indicándole la edad que tiene.
 * */

int main (){
    char x [20];
    int y;

    printf("Introduzca usted su nombre: ");
    scanf("%s", &x);
    printf("Introduzca usted su edad: ");
    scanf("%d", &y);

    printf("¡Buenos días %s, tiene usted %d años!", x, y);
    return 0;
}
