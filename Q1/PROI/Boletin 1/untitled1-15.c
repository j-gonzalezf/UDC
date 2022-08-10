#include <stdio.h>
#include <math.h>

/* Un camión transporta T kilogramos de baldosas; se sabe que cada baldosa pesa B kilogramos.
 * Las baldosas se van a utilizar para recubrir una superficie rectangular. Plantee e implemente
 * un programa en Lenguaje C que indique el número de baldosas que habría en un lado del mayor cuadrado que
 * se pueda recubrir con ésas baldosas, sin romperlas.
 * */

int main() {
    float t, r;
    int b, c;

    printf("Introduzca el número de kg que transporta el camión: ");
    scanf("%f", &t);
    printf("Introduzca el peso que tendrá cada baldosa: ");
    scanf("%f", &r);

    b = t/r;
    if(b*r != t){
        printf("ERROR: el camión debe transportar baldosas completas, sin romperlas");
    }
    else {
        c = sqrt(b);
        printf("Hay %d baldosa/s en cada lado del mayor cuadrado que se puede recubrir con "
               "las %d baldosas que hay", c, b);
    }
    return 0;
}
