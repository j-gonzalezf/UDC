#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

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
            for(k = 1; k < numprocs; k++)
                MPI_Send(&n, 1, MPI_INT, k, 0, MPI_COMM_WORLD);     //Buffer, count, datatype, dest, tag, comunicador 
        } else{
            MPI_Recv(&n, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);  //Buffer, count, datatype, source, tag, comunicador, status object
        }

        if (n == 0) break;
        
        count = 0;

        for (i = rank+1; i <= n; i+=numprocs) {
            x = ((double) rand()) / ((double) RAND_MAX);    //Calculo punto aleatorio
            y = ((double) rand()) / ((double) RAND_MAX);
            z = sqrt((x*x)+(y*y));
            if(z <= 1.0)
                count++;
        }
        pi = ((double) count/(double) n)*4.0;
        if(rank ==0){
            for (k = 1; k < numprocs; k++) {
                MPI_Recv(&pirec, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);      //Recojo la estimación de pi (cada uno de los contadores)
                pi += pirec;                                                                                //Todos los procesos envian al 0 su resultado
            } 
            printf("pi is approx. %.16f, Error is %.16f\n", pi, fabs(pi - PI25DT));
        }else{
            MPI_Send(&pi, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);       
        }
    }
    MPI_Finalize();     //Espera que terminen todos los procesos para finalizar
    return 0;
}