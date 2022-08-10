#include <stdio.h>

/* Plantee e implemente un programa en LENGUAJE Cpara controlar la compra diaria.
 * El programa debe pedir los kilos de patatas comprados y su precio sin IVA,
 * los kilos de manzanas comprados y su precio sin IVA y cuánto ha pagado por un libro que se ha comprado, sin IVA.
 * Suponga que el IVA de los productos alimenticios es del 21% y de los productos de cultura 10%.
 * Muestre por pantalla el importe de cada producto y el importe total de la compra.
 * */

int main() {
    float kgp, kgm, pp, pm, l;

    printf("Introduzca los Kg de patatas comprados: \n");
    scanf("%f", &kgp);
    printf("Ahora su precio sin IVA: \n");
    scanf("%f", &pp);
    printf("Introduzca los Kg de manzanas comprados: \n");
    scanf("%f", &kgm);
    printf("Ahora su precio sin IVA: \n");
    scanf("%f", &pm);
    printf("Por último introduzca el precio del libro sin IVA: \n");
    scanf("%f", &l);


    printf("\n\t\t\t\tSupermercado Manolo\t\t\t\t\n\n");
    printf("Kg de patatas comprados: %.f\n", kgp);
    printf("Precio sin IVA del kilo de patatas (en euros): %.2f\n", pp);
    printf("Kg de manzanas comprados: %.f\n", kgm);
    printf("Precio sin IVA del kilo de manzanas (en euros): %.2f\n", pm);
    printf("Importe del libro sin IVA (euros): %.2f\n\n", l);
    printf("-----------------------------------------------------Ticket 1/1\n");
    printf(" Patatas\t%.f kg\t\t%.2f€\t\t%.2f€\t\t%.2f€ (IVA 21%s)\n", kgp, pp, kgp*pp, kgp*pp + (kgp*pp*21/100), "%");
    printf("Manzanas\t%.f kg\t\t%.2f€\t\t%.2f€\t\t%.2f€ (IVA 21%s)\n", kgm, pm, kgm*pm, kgm*pm + (kgm*pm*21/100), "%");
    printf("   Libro\t%d   \t\t%.2f€\t\t%.2f€\t\t%.2f€ (IVA 10%s)\n", 1, l, 1*l, 1*l*10/100, "%");
    printf("---------------------------------------------------------------\n");
    printf("TOTAL\t\t\t\t\t\t\t\t\t\t\t%.2f€", (kgp*pp + (kgp*pp*21/100)) + (kgm*pm + (kgm*pm*21/100)) + (1*l*10/100));
    return 0;
}
