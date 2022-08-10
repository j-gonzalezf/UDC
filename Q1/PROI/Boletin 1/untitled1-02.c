#include <stdio.h>

/* Plantee e implemente un programa en que solicite el nombre, apellidos y edad de un usuario por teclado
 * y que le muestre el siguiente mensaje por pantalla: Sr/Sra. Apellido, le faltan aún X años para jubilarse
 * */

int main() {
    char x[20], y[20], t[20];
    int z, edad;

    printf("Introduzca su nombre completo: ");
    scanf("%s%s%s", &x, &y, &t);
    printf("Introduzca su edad: ");
    scanf("%d", &z);

    if(z<67) {
        edad = (67 - z);
        printf("Sr/Sra %s, le quedan %d años para jubilarse", y, edad);
    }
    else{
        printf("Enhorabuena, usted ya está jubilado/a");
    }
    return 0;
}
