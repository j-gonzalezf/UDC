#include <stdio.h>
#include <string.h>

/* Plantee e implemente un programa en Lenguaje C para calcular los días que tiene un mes.
 * Tenga en cuenta que si el mes introducido por el usuario es Febrero, el programa deberá solicitar
 * el año del que se trata para poder determinar si es bisiesto o no.
 * */

int main() {
    char x [20];
    int y;

    printf("Introduzca el nombre del mes del que quiere calcular los días: ");
    scanf("%s", &x);

    if(strcmp(x, "enero") == 0 || strcmp(x, "Enero") == 0 || strcmp(x, "ENERO") == 0) printf("El mes de Enero tiene 31 días\n");
    if (strcmp(x, "febrero") == 0 || strcmp(x, "Febrero") == 0 || strcmp(x, "FEBRERO") == 0) {
            printf("Introduzca el año: ");
            scanf("%d", &y);

            if (y % 4 == 0 && y % 100 != 0) printf("El mes de Febrero tiene 29 días\n");
            else printf("El mes de Febrero tiene 28 días\n");
        }
    if(strcmp(x, "marzo") == 0 || strcmp(x, "Marzo") == 0 || strcmp(x, "MARZO") == 0) printf("El mes de Marzo tiene 31 días\n");
    if(strcmp(x, "abril") == 0 || strcmp(x, "Abril") == 0 || strcmp(x, "ABRIL") == 0) printf("El mes de Abril tiene 30 días\n");
    if(strcmp(x, "mayo") == 0 || strcmp(x, "Mayo") == 0 || strcmp(x, "MAYO") == 0) printf("El mes de Mayo tiene 31 días\n");
    if(strcmp(x, "junio") == 0 || strcmp(x, "Junio") == 0 || strcmp(x, "JUNIO") == 0) printf("El mes de Junio tiene 30 días\n");
    if(strcmp(x, "julio") == 0 || strcmp(x, "Julio") == 0 || strcmp(x, "JULIO") == 0) printf("El mes de Julio tiene 31 días\n");
    if(strcmp(x, "agosto") == 0 || strcmp(x, "Agosto") == 0 || strcmp(x, "AGOSTO") == 0) printf("El mes de Agosto tiene 31 días\n");
    if(strcmp(x, "septiembre") == 0 || strcmp(x, "Septiembre") == 0 || strcmp(x, "SEPTIEMBRE") == 0) printf("El mes de Septiembre tiene 30 días\n");
    if(strcmp(x, "octubre") == 0 || strcmp(x, "Octubre") == 0 || strcmp(x, "OCTUBRE") == 0) printf("El mes de Octubre tiene 31 días\n");
    if(strcmp(x, "noviembre") == 0 || strcmp(x, "Noviembre") == 0 || strcmp(x, "NOVIEMBRE") == 0) printf("El mes de Noviembre tiene 30 días\n");
    if(strcmp(x, "diciembre") == 0 || strcmp(x, "Diciembre") == 0 || strcmp(x, "DICIEMBRE") == 0) printf("El mes de Diciembre tiene 31 días\n");
    return 0;
}
