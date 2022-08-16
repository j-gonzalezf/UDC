#include<stdio.h>
#include<math.h>

/* Plantee e implemente un subprograma en Lenguaje C para resolver una ecuación de segundo grado Ax2+Bx+C=0
 * a partir de sus coeficientes A, B y C. Además del subprograma, implemente la función apropiada para probar
 * su funcionamiento, activando este último desde el programa principal.
 * */

void reales(float x, float y, float z){
    float xR1, xR2;

    printf("Las dos raices son reales");
    xR1 = ((-y + sqrt(z))/(2.0*x));
    xR2 = ((-y - sqrt(z))/(2.0*x));

    printf("x1=%.2f x2=%.2f\n", xR1, xR2);
}

void unaraiz(float j, float k) {
    float xR1;

    xR1 = (-k)/(2.0*j);

    printf("La ecuacion solo tiene una raiz %.2f\n", xR1);
}

void compleja(float t, float r, float i) {
    float xR, xI;

    xR = (-r/(2.0*t));
    xI = (sqrt(-i)/(2.0*t));
    printf("La solución es compleja");

    printf("La parte real es %.2f y la imaginaria es +/-%.2fi\n", xR, xI);
}

    int main(void) {
        float a, b, c, disc;

        printf("Escriba el valor de a: ");
        scanf("%f", &a);
        printf("Escriba el valor de b: ");
        scanf("%f", &b);
        printf("Escriba el valor de c: ");
        scanf("%f", &c);

        if (a != 0) {
            disc = pow(b, 2.0) - 4*a*c;
            if (disc > 0.0) {
                reales(a, b, disc);
            } else {
                if (disc == 0.0) {
                    unaraiz(a, b);
                } else { /* disc <0 */
                    compleja(a, b, disc);
                }
            }
        }
    return 0;
}
