#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite el nombre, edad, número de hijos y
 * sueldo anual de una persona (en euros) y muestre por pantalla la misma información (que en el ejercicio 8)
 * indicando su sueldo mensual en vez del sueldo anual.
 * */

int main() {
    char x[40];
    int y, t;
    float r, g;

    printf("Introduzca usted su nombre: "); scanf("%s", &x);
    printf("Introduzca usted su edad: "); scanf("%d", &y);
    printf("Introduzca usted su número de hijos: "); scanf("%d", &t);
    printf("Introduzca usted su sueldo anual (en euros): "); scanf("%f", &r);

    g = r/12;

    printf("Nombre: %s\nEdad: %d\nNumero de hijos: %d\nSueldo mensual: %.2f€", x, y, t, g);
    return 0;
}
