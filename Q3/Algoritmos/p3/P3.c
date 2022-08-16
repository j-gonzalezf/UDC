/*
 * Algoritmos
 * Grupo: 1.2
 * Práctica 3
 * Adriano Miranda Seoane - adriano.miranda
 * Jorge González Fernández - j.gonzalezf
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

struct nodo {
int elem;
int num_repeticiones;
struct nodo *izq, *der;
};

typedef struct nodo *posicion;
typedef struct nodo *arbol;
static struct nodo *crearnodo(int e) {
	struct nodo *p = malloc(sizeof(struct nodo));
	if (p == NULL) 	{
		printf("memoria agotada\n"); 
		exit(EXIT_FAILURE);
	}
	p->elem = e;
	p->num_repeticiones = 1;
	p->izq = NULL;
	p->der = NULL;
	return p;
}

void aleatorio(int v [], int n) {
	int i, m=2*n+1;
	for (i=0; i < n; i++)
	    v[i] = (rand() % m) - n;
}

void inicializar_semilla() {
	srand(time(NULL));
}

double microsegundos() {
	struct timeval t;
	if (gettimeofday(&t, NULL) < 0 )
		return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}

arbol Creararbol(){
	arbol A;
	return (A = NULL);
}

int esarbolvacio(arbol A){
	return (A ==NULL);
}

posicion buscar(int x, arbol A){
	if(A==NULL){
		return NULL;
	}else if(x==A->elem){
		return A; 
	}else if(x<A->elem){
		return buscar(x,A->izq);
	}else{
		return buscar(x,A->der);
	}
} 

arbol eliminararbol(arbol A){
	if(A!=NULL){
		eliminararbol(A->izq);
		eliminararbol(A->der);
		free(A);
		A = NULL;
		return A;	
	}else{
		free(A);
		A = NULL;
		return A;
	}
}


posicion hijoizquierdo(arbol A){
	int x = A->izq->elem;
	if(A ==NULL){
		return NULL;
	}else if(x==A->elem){
		return A;
	}else if(x<A->elem){
		return hijoizquierdo(A->izq);
	}else{
		return hijoizquierdo(A->der);
	}
	
}

posicion hijoderecho(arbol A){
	int x =A->der->elem;
	if(A ==NULL){
		return NULL;
	}else if(x==A->elem){
		return A;
	}else if(x<A->elem){
		return hijoderecho(A->izq);
	}else{
		return hijoderecho(A->der);
	}
}

/*int numerorepeticiones(posicion p){
int A;
	 
	 if(arbol!=NULL)
     {
          if(p == A->p);
          numerorepeticiones(arbol->izq);
          numerorepeticiones(arbol->der);
     }
}*/

void visualizar(arbol A){
	if(A!=NULL){
		printf("(");
		visualizar(A->izq);
		printf(" %d ",A->elem);
		visualizar(A->der);
		printf(")");
	}
}

arbol insertar(int e, arbol a){
	if (a == NULL){
		return crearnodo(e);
	}else if (e < a->elem){
		a->izq = insertar(e, a->izq);
	}else if (e > a->elem){
		a->der = insertar(e, a->der);
	}else{
		a->num_repeticiones++;
	}
	return a;
}

int altura(arbol A){
int AltIzq, AltDer;

    if(A==NULL)
        return -1;
    else
    {
      AltIzq = altura(A->izq);
      AltDer = altura(A->der);
      if(AltIzq>AltDer)
         return AltIzq+1;
      else
         return AltDer+1;
    }	
}

void test(){
		
	arbol A = Creararbol();
	visualizar(A);
	posicion p;
	printf("Altura del arbol: %d\n",altura(A));
	A = insertar(3,A);
	A = insertar(1,A);
	A = insertar(2,A);
	A = insertar(5,A);
	A = insertar(4,A);
	A = insertar(5,A);
	visualizar(A);
	printf("\n");
	printf("Altura del arbol: %d\n",altura(A));
	
	if(buscar(1,A) != NULL){
	p= buscar(1,A);
	printf("Busco 1 y encuentro %d\n",p->elem);
	}else{
		printf("Busco 1 no encuentro nada \n");
	}
	if(buscar(2,A) != NULL){
	p= buscar(2,A);
	printf("Busco 2 y encuentro %d\n",p->elem);
	}else{
		printf("Busco 2 no encuentro nada \n");
	}
	if(buscar(3,A) != NULL){
	p= buscar(3,A);
	printf("Busco 3 y encuentro %d\n",p->elem);
	}else{
		printf("Busco 3 no encuentro nada \n");
	}
	if(buscar(4,A) != NULL){
	p= buscar(4,A);
	printf("Busco 4 y encuentro %d\n",p->elem);
	}else{
		printf("Busco 4 no encuentro nada \n");
	}
	if(buscar(5,A) != NULL){
	p= buscar(5,A);
	printf("Busco 5 y encuentro %d\n",p->elem);
	}else{
		printf("Busco 5 no encuentro nada \n");
	}
	if(buscar(6,A) != NULL){
	p= buscar(6,A);
	printf("Busco 6 y encuentro %d\n",p->elem);
	}else{
		printf("Busco 6 no encuentro nada \n");
	}
	printf("Borro todos los nodos liberadno la memoria\n");
	A = eliminararbol(A);
	printf("Altura de A : %d",altura(A));
	/*if(A = numerorepeticiones(1) != 0){
		printf("Busco 1 y no encuentro nada");
	}else{
		printf("Busco 1 y encuentro %d: %d veces\n",buscar(5,A),A=numerorepeticiones(5));
	}*/
}

void tiempos(){
    double ta,tb,t1,t2,t,tp;
    arbol a = Creararbol();
    int i= 0, n =8000,k=1000,j=0;
    printf("   %12s%15s%16s\n","n", "t_ins(n), t_bus(n)");
    printf("\t------------------------------------"
           "---------------------------------------\n");
    for(i = 0; i < 6; i++){
        ta= microsegundos();
        insertar(n,a);
        tb = microsegundos();
        t = tb-ta;
        if ( t < 500 ){
            t1 = microsegundos();
            for(j = 0; j < k; j++){
                insertar(n,a);
            }
            t2 = microsegundos();
            tp=t2-t1;
            t = tp/k;
            printf("(*)");
        }else printf("   ");
        printf("%12d%15.3f\n",n,t);
        n = n * 2;
    }
    for(i = 0; i < 6; i++){
        ta= microsegundos();
        buscar(n,a);
        tb = microsegundos();
        t = tb-ta;
        if ( t < 500 ){
            t1 = microsegundos();
            for(j = 0; j < k; j++){
                buscar(n,a);
            }
            t2 = microsegundos();
            tp=t2-t1;
            t = tp/k;
            printf("(*)");
        }else printf("   ");
        printf("%12d%15.3f\n",n,t);
        n = n * 2;
    }
}


void tiempos_1(){
    double ta,tb,t1,t2,t,tp;
    arbol a = Creararbol();
    int i= 0, n =8000,k=1000,j=0;
    printf("\t\nTiempos insertar: \n");
    printf("   %12s%15s%16s%15s%17s\n","n", "t(n)",
           "t(n)/n^0.8", "t(n)/n^1", "t(n)/n*log(n)");
    printf("\t------------------------------------"
           "---------------------------------------\n");
    for(i = 0; i < 6; i++){
        ta= microsegundos();
        insertar(n,a);
        tb = microsegundos();
        t = tb-ta;
        if ( t < 500 ){
            t1 = microsegundos();
            for(j = 0; j < k; j++){
                insertar(n,a);
            }
            t2 = microsegundos();
            tp=t2-t1;
            t = tp/k;
            printf("(*)");
        }else printf("   ");
        printf("%12d%15.3f%15.6f%15.6f%15.7f\n",n,t,t/(pow(n,0.8)),
               (t/(pow(n,1))),t/(n*log(n)));
        n = n * 2;
    }
}

void tiempos_2(){
    double ta,tb,t1,t2,t,tp;
    arbol a = Creararbol();
    int i= 0, n =8000,k=1000,j=0;
    printf("\t\nTiempos buscar: \n");
    printf("   %12s%15s%16s%15s%17s\n","n", "t(n)",
           "t(n)/n^0.8", "t(n)/n^1", "t(n)/n*log(n)");
    printf("\t------------------------------------"
           "---------------------------------------\n");
    for(i = 0; i < 6; i++){
        ta= microsegundos();
        buscar(n,a);
        tb = microsegundos();
        t = tb-ta;
        if ( t < 500 ){
            t1 = microsegundos();
            for(j = 0; j < k; j++){
                buscar(n,a);
            }
            t2 = microsegundos();
            tp=t2-t1;
            t = tp/k;
            printf("(*)");
        }else printf("   ");
        printf("%12d%15.3f%15.6f%15.6f%15.7f\n",n,t,t/(pow(n,0.8)),
               (t/(pow(n,1))),t/(n*log(n)));
        n = n * 2;
    }
}

int main(){
	test();
	tiempos();
	tiempos_1();
	tiempos_2();
}
