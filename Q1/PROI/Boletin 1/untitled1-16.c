#include <stdio.h>

/* Plantee e implemente un programa en LENGUAJE C para calcular la suma de dos matrices 2x2.
 * Pida los datos oportunos y calcule el resultado deseado, mostrándolo después en pantalla.
 * */

int main() {
    int a, b, c, d, x, y, z, t, ax, by, cz, dt;

    printf("Matriz 1: \t\t\t\t\tMatriz 2:\n");
    printf("| a\tb |  \t\t\t\t\t| x\ty |\n");
    printf("| c\td |  \t\t\t\t\t| z\tt |\n");

    printf("Introduzca los valores de la primera matriz en orden a, b, c y d: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("Introduzca los valores de la segunda matriz en orden x, y, z y t: ");
    scanf("%d%d%d%d", &x, &y, &z, &t);

    ax = a + x;
    by = b + y;
    cz = c + z;
    dt = d + t;

    printf("Suma de las Matrices 1 y 2: \n");
    printf("| %d\t%d |\n", ax, by);
    printf("| %d\t%d |\n", cz, dt);
    return 0;
}
