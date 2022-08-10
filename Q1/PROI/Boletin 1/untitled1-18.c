#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite a un usuario su nombre, apellidos,
 * sueldo mensual (en euros) y el dinero que gasta diariamente en ocio, comida y transporte.
 * A continuación, utilizando descriptores de formato, debe mostrar una tabla como la que se indica
 * donde se recoja el % de su sueldo que gasta semanalmente en ocio, comida y transporte.
 * Incluya también el total del gasto semanal realizado.
 * */

int main() {
    char x[50], y[50], z[50];
    float a, b, c, s, t, o;

    printf("Introduzca su nombre y apellidos: \n");
    scanf("%s%s%s", &x, &y, &z);
    printf("Introduzca (en €) su sueldo y el dinero que gasta diariamente en ocio, comida y transporte, u otros: \n");
    scanf("%f%f%f%f%f", &s, &a, &b, &c, &o);

    t = (a + b + c + o)*7;

    if(t*30/7<=s) {
        printf("********************************************************\n");
        printf("*******\t\t\t%s %s: %.2f€\t\t\t*******\n", x, y, s);
        printf("\n");
        printf("\t\t %sOcio\t\t%sComida\t\t%sTransporte\t\t%sOtros\n", "%", "%", "%", "%");
        printf("\t\t%.2f%s\t\t%.2f%s\t\t\t%.2f%s\t\t %.2f%s\n", 7 * a * 100 / s, "%", 7 * b * 100 / s, "%",
               7 * c * 100 / s, "%", 7 * o * 100 / s, "%");
        printf("\n");
        printf("*******\t\t\t\t\t\t\t\t\t\t\t*******\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\tGasto semanal\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t%.2f€", t);
        printf("\n");
    }
    else printf("Usted está en banca rota");
    return 0;
}
