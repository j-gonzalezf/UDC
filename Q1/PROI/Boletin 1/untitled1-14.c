#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que a partir de la temperatura máxima y mínima diaria de
 * una ciudad en grados Fahrenheit (introducidas por teclado) proporcione dichas temperaturas en grados
 * centígrados por pantalla. Contemple una salida ordenada en forma de tabla.
 * */

int main() {
    float max, min, cmax, cmin;
    char c[50];

    printf("Introduzca el nombre de su ciudad: ");
    scanf("%s", &c);
    printf("Introduzca la temperatura máxima en grados Fahrenheit: ");
    scanf("%f", &max);
    printf("Introduzca la temperatura mínima en grados Fahrenheit: ");
    scanf("%f", &min);

    cmax = ((max - 32)*5/9);
    cmin = ((min - 32)*5/9);

    printf("\n------------------------------%s 29/02/2020------------------------------\n", c);
    printf("\n");
    printf("\t\tTMax (ºF)\t\tTMin (ºF)\t\tTMax (ºC)\t\tTMin (ºC)\n");
    printf("\t\t%.2f ºF\t\t%.2f ºF\t\t%.2f ºC\t\t%.2f ºC\n", max, min, cmax, cmin);
    printf("--------------------------------------------------------------------------");
    printf("\n");
    return 0;
}
