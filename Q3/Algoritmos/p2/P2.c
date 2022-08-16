/*
 * Algoritmos
 * Grupo: 1.2
 * Práctica 1
 * Adriano Miranda Seoane - adriano.miranda
 * Jorge González Fernández - j.gonzalezf
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

void ascendente(int v [], int n) {
	int i;
	for (i=0; i < n; i++){
		v[i] = i;
	}
}

void descendente(int v[], int n){
	int i;
	for(i=0;i<=n;i++){
		v[i] = n-i;
	}
}

void listar_vector (int v[], int n){
	int k;
	printf("[");
	for (k=0;k < n ;k++){
		printf("%d ",v[k]);		
	}
	printf("]");
}

double microsegundos() {
	struct timeval t;
	if (gettimeofday(&t, NULL) < 0 )
		return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}

void inicializar_semilla() {
	srand(time(NULL));
}

void aleatorio(int v [], int n) {
	int i, m=2*n+1;
	for (i=0; i < n; i++)
	    v[i] = (rand() % m) - n;
}
void ord_ins(int v[],int n){
	int x,j,i;
	for(i = 0 ;i < n ;i++){
		x = v[i];
		j = i-1;
		while (j >= 0 && v[j] > x){
			v[j+1] = v[j];
			j = j-1;	
		}
		v[j+1] = x;
	}

}

void ord_shell(int v[],int n){	
	int incremento,tmp;
	int seguir = 0;
	int j,i = 0;
	incremento = n;
	do {
		incremento = incremento / 2;
		for(i = incremento; i < n; i++){
			tmp = v[i];
			j = i;
			seguir = 1;			
			while( j-incremento+1 > 0 && seguir == 1){
				if (tmp < v[j-incremento]){
					v[j] = v[j-incremento];
					j = j-incremento;		
				} else { seguir = 0; }
			}
			v[j] = tmp;
		}
	} while( incremento != 1);

}

int ordenado(int v[], int n){
	int i = 0;
	while ((i < n-1)) {
	    if (v[i] < v[i+1]) {
		return 0;
	    }
	    i ++;
	}
	return 1;
}

void test(){
	int v[10];
	int v2[10];
	int j;
	aleatorio(v,10);
	for (j = 0; j < 10; j++){
   		v2[j] = v[j];}
	printf("\nTest\n\n [+]Vector original: ");
	listar_vector(v,10); ord_ins(v,10);
	printf("\n[-]Insercion:");
	listar_vector(v,10);
	printf("- Ordenado ? %d\n",ordenado(v,10));
	ord_shell(v2,10);
	printf("[-]Shell:");	
	listar_vector(v2,10);
	printf("- Ordenado ? %d\n",ordenado(v2,10));	
	printf("\n[*]Inicializacion descendente \n"); //Descendente
	descendente(v,10);	
	printf("\n[+]Vector original: ");
	listar_vector(v,10);
	printf("- Ordenado ? %d\n",ordenado(v,10));
	ord_ins(v,10);
	printf("[-]Insercion:");
	listar_vector(v,10);
	printf("- Ordenado ? %d\n",ordenado(v,10));
	descendente(v,10); ord_shell(v,10);
	printf("[-]Shell:");	
	listar_vector(v,10);
	printf("- Ordenado ? %d\n",ordenado(v,10));
	printf("\n[*]Inicializacion ascendente \n"); //Ascendente
	ascendente(v,10);	
	printf("\n[+]Vector original: ");
	listar_vector(v,10);
	printf("- Ordenado ? %d\n",ordenado(v,10));
	ord_ins(v,10);
	printf("[-]Insercion:");
	listar_vector(v,10);
	printf("- Ordenado ? %d\n",ordenado(v,10));
	ascendente(v,10); ord_shell(v,10);
	printf("[-]Shell:");	
	listar_vector(v,10);
	printf("- Ordenado ? %d\n",ordenado(v,10));
}

void tiempos(void (*func)(),int nmax,void (*init)(),float ci,float ca,float cs){
	int i,k,n = 0;
	double ta,tb,t,t1,t2;	
	char * s;
	int v[nmax];
	n = 500;
	k = 1000;
	while(n <= nmax){
		s = "";
		init(v,n);
		ta = microsegundos();
		func(v,n);
		tb = microsegundos();			
		t = tb - ta;
		if ( t < 500 ){
			ta = microsegundos();
			for(i=0;i < k;i++){
				init(v,n);
				func(v,n);	
			}	
			tb = microsegundos();
			t1 = tb - ta;
			ta = microsegundos();
			for(i=0;i < k;i++){
				init(v,n);			
			}
			tb = microsegundos();
			t2 = tb - ta;
			t = (t1-t2)/k;
			s = "(*)";
		}
		printf("%10d%15f%15f%15f%15.7f%5s\n",n,t,t/pow(n,ci),t/pow(n,ca),t/pow(n,cs),s);
		n = n * 2;
	}
}

void precalc(){
	//Func Auxiliar para que vaya trabajando la cpu
	int v[16000];
	int i;
	for (i=0;i < 20;i++){
		descendente(v,16000);
		ord_ins(v,16000);
	}
}

int main(int argc, char **argv) {
    inicializar_semilla();
    test();
    precalc();
    //Medicion de tiempos ins
    printf("\n[+]Ordenacion por insercion aleatoria\n");
    printf("\tn\tt(n)\t\tt(n)/n^1.8\tt(n)/n^2\tt(n)/n^2.2\n");
    tiempos(ord_ins, 32000, aleatorio, 1.8, 2, 2.2);
    printf("\n[+]Ordenacion por insercion ascendente\n");
    printf("\tn\tt(n)\t\tt(n)/n^0.8\tt(n)/n\tt(n)/n^1.2\n");
    tiempos(ord_ins, 32000, ascendente, 0.8, 1, 1.2);
    printf("\n[+]Ordenacion por insercion descendente\n");
    printf("\tn\tt(n)\t\tt(n)/n^1.8\tt(n)/n^2\tt(n)/n^2.2\n");
    tiempos(ord_ins, 32000, descendente, 1.8, 2, 2.2);
    //Medicion de tiempos shell
    printf("\n[+]Ordenacion por shell aleatoria\n");
    printf("\tn\tt(n)\t\tt(n)/n\t\tt(n)/n^1.18\tt(n)/n^1.4\n");
    tiempos(ord_shell, 32000, aleatorio, 1, 1.18, 1.4);
    printf("\n[+]Ordenacion por shell ascendente\n");
    printf("\tn\tt(n)\t\tt(n)/n\t\tt(n)/n^1.12\tt(n)/n^1.3\n");
    tiempos(ord_shell, 32000, ascendente, 1, 1.12, 1.3);
    printf("\n[+]Ordenacion por shell descendente\n");
    printf("\tn\tt(n)\t\tt(n)/n\t\tt(n)/n^1.12\tt(n)/n^1.3\n");
    tiempos(ord_shell, 32000, descendente, 1, 1.12, 1.3);
    return 0;
}
