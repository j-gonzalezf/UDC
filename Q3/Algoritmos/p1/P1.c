/*
 * Algoritmos
 * Grupo: 1.2
 * Práctica 1
 * Adriano Miranda Seoane - adriano.miranda
 * Jorge González Fernández - j.gonzalezf
*/

#include <stdio.h>
#include <sys/time.h>
#include <math.h>

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

int fib_1(int n){
    if (n<2){
        return n;
    }else{
        return fib_1(n-1)+fib_1(n-2);
    }
}

int fib_2(int n){
    int i = 1, j = 0; int k =0;
    for(k=0;k<n;k++){
        j=i+j;
        i = j-i;
    }
    return j;
}

int fib_3(int n){
    int i, j, k ,h ,t;
    i=1;j=0;k=0;h=1;
    while (n>0){
        if((n%2) !=0){
            t= j*h;
            j = (i * h) + (j * k) + t;
            i = (i * k) + t;
        }
        t = h*h;
        h = (2 * k * h) + t;
        k = (k * k) + t;
        n = n / 2;
    }
    return j;
}

void test(){
    int n1=3, n2 = 8, n3= 12;
    printf("Test:\n");
    printf("fib1 de %d: %d\n",n1,fib_1(n1));
    printf("fib2 de %d: %d\n",n1,fib_2(n1));
    printf("fib3 de %d: %d\n",n1,fib_3(n1));
    printf("fib1 de %d: %d\n",n2,fib_1(n2));
    printf("fib2 de %d: %d\n",n2,fib_2(n2));
    printf("fib3 de %d: %d\n",n2,fib_3(n2));
    printf("fib1 de %d: %d\n",n3,fib_1(n3));
    printf("fib2 de %d: %d\n",n3,fib_2(n3));
    printf("fib3 de %d: %d\n",n3,fib_3(n3));
    printf("\nTiempos:\n");
}

void tiempos_fib1(){
    double ta,tb,t1,t2,t,tp;
    int i= 0, n =2,k=1000,j=0;
    printf("\t\nTiempos fib1: \n");
    printf("   %12s%14s%17s%15s%14s\n","n", "t(n)",
           "t(n)/1.1^n", "t(n)/fi^n", "t(n)/1,1^n");
    printf("\t-----------------------------------"
           "-------------------------------------\n");
    for(i = 0; i < 5; i++){
        ta= microsegundos();
        fib_1(n);
        tb = microsegundos();
        t = tb-ta;
        if ( t < 500 ){
            t1 = microsegundos();
            for(j = 0; j < k; j++){
                fib_1(n);
            }
            t2 = microsegundos();
            tp=t2-t1;
            t = tp/k;
            printf("(*)");
        }else printf("   ");
        printf("%12d%15.5f%15.6f%15.6f%15.8f\n",n,t,t/(pow(1.1,n)),
               t/pow(((1+sqrt(5))/2),n),t/pow(2,n));
        n = n * 2;
    }
}

void tiempos_fib2(){
    double ta,tb,t1,t2,t,tp;
    int i= 0, n =1000,k=1000,j=0;
    printf("\t\nTiempos fib2: \n");
    printf("   %12s%15s%16s%15s%17s\n","n", "t(n)",
           "t(n)/n^0.8", "t(n)/n^1", "t(n)/n*log(n)");
    printf("\t------------------------------------"
           "---------------------------------------\n");
    for(i = 0; i < 5; i++){
        ta= microsegundos();
        fib_2(n);
        tb = microsegundos();
        t = tb-ta;
        if ( t < 500 ){
            t1 = microsegundos();
            for(j = 0; j < k; j++){
                fib_2(n);
            }
            t2 = microsegundos();
            tp=t2-t1;
            t = tp/k;
            printf("(*)");
        }else printf("   ");
        printf("%12d%15.3f%15.6f%15.6f%15.7f\n",n,t,t/(pow(n,0.8)),
               (t/(pow(n,1))),t/(n*log(n)));
        n = n * 10;
    }
}

void tiempos_fib3(){
    double ta,tb,t1,t2,t,tp;
    int i= 0, n =1000,k=1000,j=0;
    printf("\t\nTiempos fib3: \n");
    printf("   %12s%14s%21s%13s%13s\n","n", "t(n)",
           "t(n)/sqrt(log(n))", "t(n)/log(n)", "t(n)/n^0.5");
    printf("\t------------------------------------"
           "-------------------------------------\n");
    for(i = 0; i < 5; i++){
        ta= microsegundos();
        fib_3(n);
        tb = microsegundos();
        t = tb-ta;
        if ( t < 500 ){
            t1 = microsegundos();
            for(j = 0; j < k; j++){
                fib_3(n);
            }
            t2 = microsegundos();
            tp=t2-t1;
            t = tp/k;
            printf("(*)");
        }else printf("   ");
        printf("%12d%15.4f%15.6f%15.6f%15.7f\n",n,t,t/(sqrt(log(n))),
               t/log(n),(t/pow(n,0.5)));
        n = n * 10;
    }
}

void precalc(){
    fib_1(20);
}

int main(){
    test();
    precalc();
    tiempos_fib1();
    tiempos_fib2();
    tiempos_fib3();
    return 0;
}
