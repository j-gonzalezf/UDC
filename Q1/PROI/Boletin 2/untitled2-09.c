#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que implemente el algoritmo necesario para calcular la edad
 * de una persona suponiendo que se le pide al usuario que introduzca su fecha de nacimiento por teclado
 * y a la salida muestra por pantalla su edad con respecto a la fecha actual.
 * Tenga en cuenta el cumpleaños exacto de la persona para realizar el cálculo.
 * */

int main() {
        int anioN = 0, anioA = 0, mesN = 0, mesA = 0, diaN = 0, diaA = 0, edadD, edadM, edadA;

        printf("Introduce tu día, tu mes y tu año de nacimiento: ");
        scanf("%d%d%d", &diaN, &mesN, &anioN);
        printf("\n");
        printf("Introduce a qué día, el mes y el año en que estamos: ");
        scanf("%d%d%d", &diaA, &mesA, &anioA);
        printf("\n");

        if((anioN > anioA) || ((anioN == anioA) && (mesN > mesA)) || ((anioN == anioA) && (mesN == mesA) && (diaN > diaA)))
            printf("Usted viene del futuro\n");
        else {
            edadA = anioA - anioN;
            edadM = mesA - mesN;
            edadD = diaA - diaN;
            if (edadM < 0) {
                edadA--;
                edadM = 12 + edadM;
            }
            if (edadD < 0) {
                edadM--;
                edadD = 30 + edadD;
            }
            if((edadA == 0) && (edadM == 0) && (edadD == 0)) printf("Bienvenid@ al mundo, usted acaba de nacer\n");
            else printf("Su edad es de: %d años, %d meses, %d días\n", edadA, edadM, edadD);
        }
    return 0;
}
