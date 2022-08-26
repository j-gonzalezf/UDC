#include <stdio.h>

/* Plantee e implemente un programa en Lenguaje C que calcule la nota media de las 6 asignaturas de un curso académico
 * a partir de las calificaciones introducidas individualmente por teclado. Debe mostrar la calificación media
 * también en formato SOBRESALIENTE (9-10), NOTABLE (7-8.9), APROBADO (5-6.9), SUSPENSO (0-4.9).
 * En el caso de que el alumno no se haya presentado a alguna de las asignaturas, el usuario debe introducir 0 como calificación.
 * En este último caso añada además en la salida la nota media obtenida en las asignaturas a las que se ha presentado.
 * */

int main() {
    float n1, n2, n3, n4, n5, n6, media, mediap=0, cont=0;

    printf("Introduzca calificación asignatura 1 (formato X.X, 0 para No Presentado): ");
    scanf("%f", &n1);

    if(n1 < 0 || n1 > 10) printf("ERROR: La nota introducida debe estar entre 0 y 10 puntos\n");
    else {
        printf("Introduzca calificación asignatura 2 (formato X.X, 0 para No Presentado): ");
        scanf("%f", &n2);
        if (n2 < 0 || n2 > 10) printf("ERROR: La nota introducida debe estar entre 0 y 10 puntos\n");
        else {
            printf("Introduzca calificación asignatura 3 (formato X.X, 0 para No Presentado): ");
            scanf("%f", &n3);
            if (n3 < 0 || n3 > 10) printf("ERROR: La nota introducida debe estar entre 0 y 10 puntos\n");
            else {
                printf("Introduzca calificación asignatura 4 (formato X.X, 0 para No Presentado): ");
                scanf("%f", &n4);
                if (n4 < 0 || n4 > 10) printf("ERROR: La nota introducida debe estar entre 0 y 10 puntos\n");
                else {
                    printf("Introduzca calificación asignatura 5 (formato X.X, 0 para No Presentado): ");
                    scanf("%f", &n5);
                    if (n5 < 0 || n5 > 10) printf("ERROR: La nota introducida debe estar entre 0 y 10 puntos\n");
                    else {
                        printf("Introduzca calificación asignatura 6 (formato X.X, 0 para No Presentado): ");
                        scanf("%f", &n6);
                        if (n6 < 0 || n6 > 10) printf("ERROR: La nota introducida debe estar entre 0 y 10 puntos\n");
                        else {

                            media = (n1 + n2 + n3 + n4 + n5 + n6) / 6;

                            if(n1 != 0) {
                                mediap = mediap + n1;
                                cont++;
                            }
                            if(n2 != 0) {
                                mediap = mediap + n2;
                                cont++;
                            }
                            if(n3 != 0) {
                                mediap = mediap + n3;
                                cont++;
                            }
                            if(n4 != 0) {
                                mediap = mediap + n4;
                                cont++;
                            }
                            if(n5 != 0) {
                                mediap = mediap + n5;
                                cont++;
                            }
                            if(n6 != 0) {
                                mediap = mediap + n6;
                                cont++;
                            }

                            mediap = mediap/cont;

                            if (media >= 0 && media < 5) printf("\nNota media: SUSPENSO (%.2f)", media);
                            if (media >= 5 && media < 7) printf("\nNota media: APROBADO (%.2f)", media);
                            if (media >= 7 && media < 9) printf("\nNota media: NOTABLE (%.2f)", media);
                            if (media >= 9 && media <= 10) printf("\nNota media: SOBRESALIENTE (%.2f)", media);

                            if (mediap >= 0 && mediap < 5) printf("\nNota media asignaturas presentadas(%.f): SUSPENSO (%.2f)\n", cont, mediap);
                            if (mediap >= 5 && mediap < 7) printf("\nNota media asignaturas presentadas(%.f): APROBADO (%.2f)\n", cont, mediap);
                            if (mediap >= 7 && mediap < 9) printf("\nNota media asignaturas presentadas(%.f): NOTABLE (%.2f)\n", cont, mediap);
                            if (mediap >= 9 && mediap <= 10) printf("\nNota media asignaturas presentadas(%.f): SOBRESALIENTE (%.2f)\n", cont, mediap);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
