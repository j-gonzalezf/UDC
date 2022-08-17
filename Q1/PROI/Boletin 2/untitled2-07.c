#include <stdio.h>
#include <math.h>
#include <string.h>

/* Implemente un programa que resuelva ecuaciones de segundo grado empleando sentencias switch para los casos:
 * reales y distintas, complejas conjugadas y raíz real doble.
 * */

int a, b, c, d;
void signo ();
float operacion1mas(float x, float y, float z);
float operacion1menos(float x, float y, float z);
float operacion2y3real(float x, float y, float z);
float operacion2imas(float x, float y, float z);
float operacion2imenos(float x, float y, float z);

int main() {
    int s;

    printf("Las ecuaciones de segundo grado pueden ser:\n1-Reales y distintas\n2-Complejas conjugadas\n3-Raíz real doble\n\n");
    printf("Introduzca el tipo de ecuación: ");
    scanf("%d", &s);

    switch (s) {
        case 1: signo(), printf("\nLas soluciones a la ecuación son:\nx1=%.f\nx2=%.f",
                operacion1mas(a, b, c), operacion1menos(a, b, c));
            break;
        case 2: signo(), printf("\nLas soluciones a la ecuación son:\nx1=%.f+%.fi\nx2=%.f%.fi",
                operacion2y3real(a, b, c), operacion2imas(a, b, c),
                operacion2y3real(a, b, c), operacion2imenos(a, b, c));
            break;
        case 3: signo(); printf("\nLa solucion a la ecuación es:\nx1=%.f", operacion2y3real(a, b, c));
            break;
        default:
            printf("Esta opción no está en la lista");
    }
    return 0;
}

int a, b, c, d;
void signo (){
    char s1 [10], s2 [10], mas[] = "MAS", menos[] = "MENOS";

    printf("Si el primer signo es positivo introduzca MAS en caso contrario introduzca MENOS: ");
    scanf("%s", s1);
    printf("Si el segundo signo es positivo introduzca MAS en caso contrario introduzca MENOS: ");
    scanf("%s", s2);
    printf("\n");

    if (strcmp(s1, mas) == 0 && strcmp(s2, mas) == 0) {
        printf("En la ecuación Ax^2 + Bx + C = D\nIntroduzca los coeficientes A, B, C y D respectivamente : ");
        scanf("%d%d%d%d", &a, &b, &c, &d);
    }
    if (strcmp(s1,mas) == 0 && strcmp(s2, menos) == 0) {
        printf("En la ecuación Ax^2 + Bx - C = D\nIntroduzca los coeficientes A, B, C y D respectivamente : ");
        scanf("%d%d%d%d", &a, &b, &c, &d);
    }
    if (strcmp(s1, menos) == 0 && strcmp(s2, mas) ==  0) {
        printf("En la ecuación Ax^2 - Bx + C = D\nIntroduzca los coeficientes A, B, C y D respectivamente : ");
        scanf("%d%d%d%d", &a, &b, &c, &d);
    }
    if (strcmp(s1, menos) == 0 && strcmp(s2, menos) == 0) {
        printf("En la ecuación Ax^2 - Bx - C = D\nIntroduzca los coeficientes A, B, C y D respectivamente : ");
        scanf("%d%d%d%d", &a, &b, &c, &d);
    }
    c = c-d;
}

float operacion1mas(float x, float y, float z){
    return (-y + powf(powf(y, 2)-4*x*z, 1/2))/2*x;
}
float operacion1menos(float x, float y, float z){
    return (-y - powf(powf(y, 2)-4*x*z, 1/2))/2*x;
}

float operacion2y3real(float x, float y, float z){
    return -y/2*x;
}
float operacion2imas(float x, float y, float z){
    return +powf(fabs(powf(y, 2)-4*x*z/2*x), 1/2);
}
float operacion2imenos(float x, float y, float z){
    return -powf(fabs(powf(y, 2)-4*x*z/2*x), 1/2);
}
