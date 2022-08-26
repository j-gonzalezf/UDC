#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que admita un carácter (introducido por teclado)
 * y muestre por pantalla si es una vocal, una consonante, un dígito o un carácter especial.
 * */

int main() {
    char c;
    int ascii;

    printf("Introduce un caracter: ");
    scanf("%c", &c);

    ascii = (int) c;

    if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) {
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
            printf("%c es una vocal", c);
        else printf("%c es una consonante", c);
    }
    else {
        if (ascii >= 48 && ascii <= 57) printf("%c es un dígito", c);
        else printf("%c es un caracter especial", c);
        }
    return 0;
}
