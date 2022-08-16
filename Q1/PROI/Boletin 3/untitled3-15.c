#include <stdio.h>

/* Plantee e implemente en Lenguaje C la función EsVocal (c: char) que recibe un carácter e indica si
 * es vocal o no (sin diferenciar entre mayúsculas y minúsculas). Además de la función, implemente
 * la función apropiada para probar su funcionamiento, activando este último desde el programa principal.
 * */

void EsVocal (char c) {
    switch (c){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U': printf("Es vocal\n");
            break;
        default : printf("No es vocal\n");
            break;
    }
}

int main() {
    char c;

    printf("Introduce una letra: ");
    scanf("%c", &c);

    EsVocal(c);
    return 0;
}
