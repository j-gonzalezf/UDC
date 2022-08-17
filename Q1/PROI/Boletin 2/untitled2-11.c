#include<stdio.h>
#include<math.h>

/* Plantee e implemente un programa en Lenguaje C cuyo objetivo sea calcular las raíces de una ecuación de 2º grado, ax2+bx+c.
 * El programa debe solicitar por teclado los coeficientes a, b, c. y mostrar por pantalla las soluciones x1 y x2
 * */

int main(void) {
    float a, b, c, disc, xR1, xR2, xI, xR;

    printf("Introduzca los coeficientes a, b y c: ");
    scanf("%f%f%f", &a, &b, &c);

    if (a != 0) {
        disc = powf(b, 2) - 4*a*c;
        if (disc > 0.0) {
            printf("Las dos raices son reales");
            xR1 = (-b + sqrt(disc))/(2.0*a);
            xR2 = (-b - sqrt(disc))/(2.0*a);
            printf("x1=%.2f x2=%.2f", xR1, xR2);
        }
        else {
            if (disc == 0.0) {
                xR1 = (-b)/(2.0*a);
                printf("La ecuación solo tiene una raíz %.2f", xR1);
            }
            else { /* disc <0 */
                xR = (-b/(2.0*a));
                xI = (sqrt(-disc)/(2.0*a));
                printf("La solución es compleja");
                printf("La parte real es %.2f y la imaginaria es +/-%.2fi", xR, xI);
            }
        }
    }
    else{
        printf("Es una recta, el punto de corte es:");
        xR1 = -c/b;
        printf("x=%.2f\n\n", xR1);
    }
    return 0;
}
