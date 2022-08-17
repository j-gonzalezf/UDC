#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que presente el menú que se especifica a continuación y que,
 * según sea el carácter introducido por el usuario, escriba en pantalla BEBÉ, ADOLESCENTE, MUJER, HOMBRE.
 * B.- Bebé
 * A.- Adolescente
 * M.- Mujer
 * H.- Hombre
 * */

int main() {
    char x;

    printf("Introduce una letra (B, A, M o H): ");
    scanf("%c", &x);

    switch (x){
        case 'B':
        case 'b': printf("BEBÉ\n");
            break;
        case 'A':
        case 'a': printf("ADOLESCENTE\n");
            break;
        case 'M':
        case 'm': printf("MUJER\n");
            break;
        case 'H':
        case 'h': printf("HOMBRE\n");
            break;
        default: printf("ERROR: La letra introducida es erronea");
    }
    return 0;
}
