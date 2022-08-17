#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite al usuario una fecha del año en curso
 * y le muestre en el centro de la pantalla (aproximadamente) el número de días transcurridos desde
 * el comienzo de año hasta esa fecha.
 * */

int main() {
    int a, d, m;

    printf("Indique en que año se encuentra: ");
    scanf("%d", &a);
    printf("Escriba una fecha del año %d (d m): ", a);
    scanf("%d%d", &d, &m);

        if((0 > d) || (d > 31)) printf("El día introducido es erróneo");
        else {
            switch (m){
                case 1:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d);
                break;
                case 2:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d+31);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31);
                break;
                case 3:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d+31+29);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31+28);
                break;
                case 4:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d+31+29+31);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31+28+31);
                break;
                case 5:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d+31+29+31+30);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31+28+31+30);
                break;
                case 6:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d+31+29+31+30+31);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31+28+31+30+31);
                break;
                case 7:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d+31+29+31+30+31+30);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31+28+31+30+31+30);
                break;
                case 8:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d+31+29+31+30+31+30+31);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31+28+31+30+31+30+31);
                break;
                case 9:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d+31+29+31+30+31+30+31+31);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31+28+31+30+31+30+31+31);
                break;
                case 10:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d+31+29+31+30+31+30+31+31+30);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31+28+31+30+31+30+31+31+30);
                break;
                case 11:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año bisiesto en curso", d+31+29+31+30+31+30+31+31+30+31);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31+28+31+30+31+30+31+31+30+31);
                break;
                case 12:
                    if((a%4 == 0) && (a%100 != 0))
                        printf("La fecha introducida corresponde al día %d del año biesiesto en curso", d+31+29+31+30+31+30+31+31+30+31+30);
                    else printf("La fecha introducida corresponde al día %d del año en curso", d+31+28+31+30+31+30+31+31+30+31+30);
                break;
                default: printf("El mes introducido es erróneo");
            }
        }
        return 0;
}
