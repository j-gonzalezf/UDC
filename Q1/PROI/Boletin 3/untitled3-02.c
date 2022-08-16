#include <stdio.h>

/* Plantee e implemente un subprograma en Lenguaje C que a partir de la inicial de un día de la semana
 * (L, M, X, J, V, S, D) introducida mediante el teclado, devuelva y muestre por pantalla el nombre del día en cuestión.
 * Además del subprograma, implemente la función apropiada para probar su funcionamiento.
 * */

char nombre(char x){
    switch(x){
        case 'L':
        case 'l': printf("Lunes\n");
            break;
        case 'M':
        case 'm': printf("Martes\n");
            break;
        case 'X':
        case 'x': printf("Miércoles\n");
            break;
        case 'J':
        case 'j': printf("Jueves\n");
            break;
        case 'V':
        case 'v': printf("Viernes\n");
            break;
        case 'S':
        case 's': printf("Sábado\n");
            break;
        case 'D':
        case 'd': printf("Domingo\n");
            break;
    }
}

int main() {
    char d; //d = inicial del día de la semana

    printf("Introduzca una letra (L, M, X, J, V, S, D): ");
    scanf("%c", &d);

    nombre(d);
    return 0;
}
