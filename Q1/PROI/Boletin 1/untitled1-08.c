#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite al usuario su nombre, edad
 * y lo que se ha gastado en cañas y en transporte durante una semana (en euros)
 * y muestre por pantalla esos mismos datos y la suma de los gastos.
 * */

int main() {
    char x[40];
    int y;
    float t, r, g;

    printf("Introduzca usted su nombre: "); scanf("%s", &x);
    printf("Introduzca usted su edad: "); scanf("%d", &y);
    printf("Introduzca usted el total de sus gastos semanales en cañas (en euros): "); scanf("%f", &t);
    printf("Introduzca usted el total de sus gastos semanales en transporte (en euros): "); scanf("%f", &r);

    g = t + r;

    printf("Nombre: %s\nEdad: %d\nGasto semanal en cañas: %.2f€\nGasto semanal en transporte: %.2f€\n"
           "Total gastos semales: %.2f€", x, y, t, r, g);
    return 0;
}
