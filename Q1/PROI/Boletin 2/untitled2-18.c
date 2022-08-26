#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que adivine un número del 1 al 10
 * conociendo su paridad y el resto de dividirlo por cinco.
 * */

int main() {
    int x, y;

    printf("Piensa en un número entero del 1 al 10...\n");
    printf("¿El número que ha pensado es impar (1) o par (2)? ");
    scanf("%d", &x);

    if(x != 1 && x != 2) printf("ERROR: ha de seleccionar entre 1 o 2\n");
    else {
        printf("¿Cuál es el resto de dividir el número que ha pensado entre 5? ");
        scanf("%d", &y);

        if (y < 0 || y > 10) printf("ERROR: 404 not found");
        else {
            switch (x) {
                case 1:
                    switch (y) {
                        case 0:
                            printf("El número que ha pensado es el 5\n");
                            break;
                        case 1:
                            printf("El número que ha pensado es el 1\n");
                            break;
                        case 2:
                            printf("El número que ha pensado es el 7\n");
                            break;
                        case 3:
                            printf("El número que ha pensado es el 3\n");
                            break;
                        case 4:
                            printf("El número que ha pensado es el 9\n");
                            break;
                    }
                    break;
                case 2:
                    switch (y) {
                        case 0:
                            printf("El número que ha pensado es el 10\n");
                            break;
                        case 1:
                            printf("El número que ha pensado es el 6\n");
                            break;
                        case 2:
                            printf("El número que ha pensado es el 2\n");
                            break;
                        case 3:
                            printf("El número que ha pensado es el 8\n");
                            break;
                        case 4:
                            printf("El número que ha pensado es el 4\n");
                            break;
                    }
                    break;
            }
        }
    }
    return 0;
}
