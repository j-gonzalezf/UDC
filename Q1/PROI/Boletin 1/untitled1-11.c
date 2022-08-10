#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que empleando expresiones, convierta un
 * tiempo expresado en segundos al formato horas : minutos : segundos.
 * */

int main() {
    int seg, s, m, h;

    printf("Introduzca una cantidad de segundos: ");
    scanf("%d", &seg);

    s = seg%60;
    m = seg/60;
    h = m/60;
    m = m%60;

    printf("%d segundos son %d h : %d min : %d seg", seg, h, m, s);
    return 0;
}
