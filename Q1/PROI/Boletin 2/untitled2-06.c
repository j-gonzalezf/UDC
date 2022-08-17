#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que a partir de la siguiente información
 * (correspondiente a un test realizado por los alumnos): cantidad total de preguntas planteadas y
 * la cantidad de preguntas contestadas correctamente. Permita insertar los dos datos por teclado
 * y muestre como resultado el nivel del mismo según el porcentaje de respuestas correctas obtenidas. Suponga que:
 *      Nivel máximo: Porcentaje >= 90%.             Nivel medio: Porcentaje >= 75% y <90%.
 *      Nivel regular: Porcentaje >= 50% y <75%.     Fuera de nivel: Porcentaje <50%.
 * */

int main() {
    int x, y;
    float p = 0;

    printf("Introduzca el total de preguntas planteadas: ");
    scanf("%d", &x);
    printf("Ahora introduzca la cantidad de preguntas contestadas correctamente: ");
    scanf("%d", &y);

    p = (float) y/x;

    if(p < 0.5) printf("Fuera de nivel");
    else {
        if ((p >= 0.5) && (p < 0.75)) printf("Nivel regular");
        else {
            if ((p >= 0.75) && (p < 0.9)) printf("Nivel medio");
            else {
                if ((p >= 0.9) && (p <= 1)) printf("Nivel máximo");
                else printf("Error");
            }
        }
    }
    return 0;
}
