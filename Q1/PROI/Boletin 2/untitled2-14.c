#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite por teclado dos números enteros positivos
 * (el primero de 3 cifras y el segundo de 1) y que muestre por pantalla su multiplicación.
 * Debe comprobar que el primer número tiene efectivamente 3 cifras y es positivo, y que el segundo número es
 * también positivo y tiene una única cifra. En caso de que no se cumplan estas condiciones, el programa debe
 * alertar al usuario con un mensaje apropiado.
 * */

int main() {
    int x, y;

    printf("Introduzca un número entero positivo de 3 cifras: ");
    scanf("%d", &x);

    if(x < 0) printf("ERROR: el número ha de ser positivo\n");
    else {
        if ((x < 100) || (x > 999)) printf("ERROR: el número ha de ser de 3 cifras\n");
        else {
            printf("Introduzca ahora un número entero positivo de 1 cifra: ");
            scanf("%d", &y);
            if (y < 0) printf("ERROR: el número ha de ser positivo\n");
            else {
                if ((y < 0) || (y > 9)) printf("ERROR: el número ha de ser de 1 cifra\n");
                else{
                    if(x*y == 0) printf("\n\t\t\t%d\n\n\t\t\tx %d\n\t\t   ====\n\t\t\t  %d\n", x, y, x*y);
                    if((x*y > 99) && (x*y < 1000)) printf("\n\t\t\t%d\n\n\t\t\tx %d\n\t\t   ====\n\t\t\t%d\n", x, y, x*y);
                    if(x*y > 999) printf("\n\t\t\t%d\n\n\t\t\tx %d\n\t\t   ====\n\t\t   %d\n", x, y, x*y);
                }
            }
        }
    }
    return 0;
}
