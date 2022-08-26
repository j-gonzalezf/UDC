#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que admita el nombre y la edad de una persona
 * y muestre por pantalla si la persona es JOVEN, ADULTA, o ANCIANA según los siguientes criterios:
 * 1. Si tiene menos de 32 años es JOVEN.
 * 2. Si tiene 32 o más años y menos de 75 es ADULTA.
 * 3. Si tiene 75 o más años es ANCIANA.
 * */

int main() {
    char x [50];
    int y;

    printf("Nombre: ");
    scanf("%s", x);
    printf("Edad: ");
    scanf("%d", &y);

    if(y < 32) printf("%s es JOVEN\n", x);
    if((y >= 32) && (y < 75)) printf("%s es ADULTA\n", x);
    if(y >= 75) printf("%s es ANCIANA\n", x);
    return 0;
}
