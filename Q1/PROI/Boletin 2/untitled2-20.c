#include <stdio.h>
#include <math.h>

/* Plantee e implemente un programa en Lenguaje C que solicite el nombre, el peso (en kilos)
 * y la altura (en centímetros) de una persona por teclado y que calcule su índice de masa corporal,
 * IMC=peso_en_kilos/(altura_en_metros)^2, indicando por pantalla si la persona está
 * por debajo de su peso de salud (IMC<18.5), normal (18.5<=IMC<25), con sobrepeso de grado I (25<=IMC<27),
 * sobrepeso de grado II (27<=IMC<30) u obesa (IMC>=30).
 * */

int main() {
    float alt, pes, imc;
    char n [20];

    printf("Introduzca usted su nombre: ");
    scanf("%s", n);
    printf("Introduzca su altura (cm): ");
    scanf("%f", &alt);
    printf("Introduzca su peso (kg): ");
    scanf("%f", &pes);

    imc = (float) (pes/pow(alt/100, 2));

    if(imc < 18.5)
        printf("%s, según el índice de masa corporal (IMC=%.2f), tiene usted un PESO POR DEBAJO DE SU PESO DE SALUD para su estatura\n", n, imc);
    if(imc >= 18.5 && imc < 25)
        printf("%s, según el índice de masa corporal (IMC=%.2f), tiene usted un PESO NORMAL para su estatura\n", n, imc);
    if(imc >= 25 && imc < 27)
        printf("%s, según el índice de masa corporal (IMC=%.2f), tiene usted un PESO CON SOBREPESO DE GRADO I para su estatura\n", n, imc);
    if(imc >= 27 && imc < 30)
        printf("%s, según el índice de masa corporal (IMC=%.2f), tiene usted un PESO CON SOBREPESO DE GRADO II para su estatura\n", n, imc);
    if(imc >= 30)
        printf("%s, según el índice de masa corporal (IMC=%.2f), tiene usted un PESO OBESO para su estatura\n", n, imc);
    return 0;
}
