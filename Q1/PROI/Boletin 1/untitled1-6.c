#include <stdio.h>
#include <math.h>
#define PI 3.14159

/* Plantee e implemente un programa en Lenguaje C que pida el radio de una esfera
 * y calcule su área y su volumen.
 * */

int main(void) {
    float radio, area, volumen;

    printf ("Introduce el radio de la esfera:\n");
    scanf ("%f", &radio);

    area = 4*PI*(pow(radio, 2));
    volumen = 4/3*PI*(pow(radio, 3));

    printf ("El área de la esfera es %f y su volumen es %f.", area, volumen);
    return 0;
}
