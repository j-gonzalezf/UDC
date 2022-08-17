#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que solicite el salario anual bruto de una persona
 * y muestre por pantalla la reducción del IRPF que se le aplicaría según los hijos menores de 18 años que
 * tenga a su cargo, sabiendo que cada hijo (hasta 5) reduce un 10% el total del impuesto que le correspondería pagar.
 * Es decir, si un trabajador gana 20000 € anuales y tiene a su cargo 5 hijos menores de 18 años,
 * suponiendo un IRPF del 15% (debe ser constante en el programa) tendría que pagar 3000€ de impuesto anual,
 * pero se le reduce un n_hijos*10% (50%) y por tanto pagaría únicamente 1500€ al año.
 * */

int main() {
    int h;
    float s, i;

    printf("Introduzca su salario anual bruto (en euros): ");
    scanf("%f", &s);
    printf("Introduzca el número de hijos menores de 18 años a su cargo: ");
    scanf("%d", &h);
    printf("\n");

    i = s*15/100;

    if(h > 5){
        printf("IRPF (15%c): %.2f€\n", '%', i);
        printf("Reduccion debida a hijos a cargo: %.2f€\n", 5*10*i/100);
        printf("Total anual a pagar: %.2f€\n", i - 5*10*i/100);
    }
    else {
        printf("IRPF (15%c): %.2f€\n", '%', i);
        printf("Reduccion debida a hijos a cargo: %.2f€\n", h*10*i/100);
        printf("Total anual a pagar: %.2f€\n", i - h*10*i/100);
    }
    return 0;
}
