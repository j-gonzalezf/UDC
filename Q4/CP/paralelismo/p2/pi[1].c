#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>


int MPI_FlattreeColectiva(void* pi, void* pirec, int count, MPI_Datatype datatype, int root, MPI_Comm comm) {
    int k;
    int numprocs, rank;
    MPI_Status status;
    double pi2 = *(double * )pi; 
    
    MPI_Comm_size(comm, &numprocs);
    MPI_Comm_rank(comm, &rank);           
    
    if(rank == root){
        for (k = 1; k < numprocs; k++){ 
            MPI_Recv(pirec, count, datatype, k, root, comm, &status);  
            pi2 += (*(double * )pirec);

            printf("Pi2: %f\n",pi2);
        }
        *(double * )pirec = pi2;
    }else{
        MPI_Send(pi, count, datatype, root, 0, comm);
    }
}
       

int ipow(int base, int exp)
{
    int res = 1;
    for (;;)
    {
        if (exp & 1)
            res *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return res;
}

int MPI_BinomialBcast(void *n, int count, MPI_Datatype datatype, int root, MPI_Comm comm) {
    int error, k;
    int numprocs, rank;
    int receiver, sender;

    MPI_Status status;

    MPI_Comm_size(comm, &numprocs);
    MPI_Comm_rank(comm, &rank);


    for (k = 1; k <= ceil(log2(numprocs)); k++) {   
        
        if (rank < ipow(2, k-1)) {
            receiver = rank + ipow(2, k-1);
            if (receiver < numprocs) {
                MPI_Send(n, count, datatype, receiver, 0, comm);
            }
        } else {
            if (rank < ipow(2, k)) {
                sender = rank - ipow(2, k-1);
                MPI_Recv(n, count, datatype, sender, 0, comm, &status);
            }
        }
    }
}

int main(int argc, char *argv[]){
    int i, done = 0, n, count;
    double PI25DT = 3.141592653589793238462643;
    double pi, x, y, z, pirec;
    int numprocs, rank, k;

    MPI_Status status;
    MPI_Init(&argc, &argv);                     //MPI_COMM_WORLD es el comunicador universal, para que se comuniquen todos los procesos
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);   //Pone en numprocs el numero de procesos que hay en ejecución
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);       //Pone en rank el rango de cada proceso (para poder hacer rank = 0 por ejemplo)

    //El proceso 0 envía el numero de puntos al resto de procesos
    while (!done) { 
        if(rank ==0){       //Esto es para que lo haga solo el proceso 0 
            printf("Enter the number of points: (0 quits) \n");     
            scanf("%d",&n);     
            printf("numprocs %d\n", numprocs);
        } 
        //Donde antes hacíamos send, Receive para cada proceso ahora hacemos una de estas operaciones
        //Se llama numprocs veces a cada operacion
        
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);   
        //MPI_BinomialBcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

        if (n == 0) break;  //Corta el bucle 

        for (i = rank+1; i <= n; i+=numprocs) {
            x = ((double) rand()) / ((double) RAND_MAX);    //Calculo punto aleatorio
            y = ((double) rand()) / ((double) RAND_MAX);
            z = sqrt((x*x)+(y*y));
            if(z <= 1.0)
                count++;
        }
        pi = ((double) count/(double) n)*4.0;

        //MPI_Reduce(&pi, &pirec, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); //Recive todo
        MPI_FlattreeColectiva(&pi, &pirec, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD); //TODO: Cambiar funcion con bucle de Receive para recivir no para mandar 

        if(rank ==0){
            printf("pi is approx. %.16f, Error is %.16f\n", pirec, fabs(pirec - PI25DT));
        }
    }
    MPI_Finalize();     //Espera que terminen todos los procesos para finalizar
    return 0;
}

//MPI_BinomialBcast: Pasamos de un orden lineal a un orden logarítmico
//paso1; 0 envia a 1  (desplazamiento de 1)
//paso2: 0 envia a 2 y 1 a 3  (desplazamiento de 2)
//paso3: 0 envia a 4, 1 a 5, 2 a 6 y 3 a 7    (desplazamiento de 4)
//paso 4: 0 envía a 8, 1 a 9, 2 a 10, 3 a 11, 4 a 12, 5 a 13, 6 a 14, 7 a 15 (desplazamiento 8)
//Es log en base 2 para poder hacer los desplazamientos (1, 2, 4, 8 ...)