#include <stdio.h>
#define M 15.45

/* Plantee e implemente un programa en Lenguaje C que solicite a un usuario su nombre, apellidos,
 * edad y el número de créditos matriculados en primera, segunda y tercera matrícula.
 * A continuación debe mostrar una tabla como la que se indica donde se recoja el coste total de
 * las asignaturas de primera, segunda y tercera matrícula. Suponga que el precio del crédito en
 * primera matrícula (15.45€) se incrementa un 25% en segunda matrícula y un 50% en tercera.
 * Incluya también el coste total de la matrícula del alumno.
 * */

int main() {
    char n [50], a [50];
    int e, m1, m2, m3;
    float c1, c2, c3;

    printf("Introduzca su nombre y apellidos y su edad: \n");
    scanf("%s%s%d", n, a, &e);
    printf("Introduzca ahora el número de créditos matriculados en 1, 2 y 3 matrícula: \n");
    scanf("%d%d%d", &m1, &m2, &m3);

    c1 = m1 * M;
    c2 = m2 * M + m2 * M * 25 / 100;
    c3 = m3 * M + m3 * M * 50 / 100;

    printf("\n\t\t\t\t\t\t\tEXPEDIENTE_FIC\t\t\t\t\t\t\t\n\n");
    printf("Nombre: %s\n", n);
    printf("Apellido: %s\n", a);
    printf("Edad: %d\n", e);
    printf("Número de créditos en la primera matrícula: %d\n", m1);
    printf("Número de créditos en la segunda matrícula: %d\n", m2);
    printf("Número de créditos en la tercera matrícula: %d\n\n", m3);
    printf("************************************************************************\n");
    printf("*******\t\t\t\t\t%s %s: %d años\t\t\t\t\t*******\n\n", n, a, e);
    printf(" Crédits M1   Coste M1   Crédits M2   Coste M2   Crédits M3   Coste M3\n");
    printf("         %d    %.2f€           %d    %.2f€           %d    %.2f€\n", m1, c1, m2, c2, m3, c3);
    printf("*******\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*******\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t  Coste Total Matrícula\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%.2f€\n", c1 + c2 + c3);
    printf("************************************************************************\n");
    return 0;
}
