#include <stdio.h>
#include <sys/time.h>
#include <mpi.h>
#include <math.h>

#define DEBUG 1 //Poner a 1 para ver resultados de los calculos y a 2 para ver tiempos  

#define N 10 //Tamaño de la matriz

int main(int argc, char *argv[] ) {

  int i, j;
  int numprocs, rank;
  float vector[N];
  struct timeval  tv1, tv2, tv3, tv4;


  //Inicializacion MPI
	if(!MPI_Init(&argc, &argv)==MPI_SUCCESS){
    return MPI_ERR_OTHER;
  }
	if(!MPI_Comm_size(MPI_COMM_WORLD, &numprocs)==MPI_SUCCESS){
    return MPI_ERR_COMM;
  }
	if(!MPI_Comm_rank(MPI_COMM_WORLD, &rank)==MPI_SUCCESS){
    return MPI_ERR_COMM;
  }
     
    int mb = ceil(1.0*N/numprocs);
    float matrix[mb*numprocs][N];
    float  matrix2[mb][N];
    int t_computacion_total[numprocs], t_comunicaciones_total[numprocs];
    
  /* Initialize Matrix and Vector */
  if(rank == 0){
    for(i=0;i<N;i++) {
        vector[i] = i;
        for(j=0;j<N;j++) {
            matrix[i][j] = i+j;
            //printf("Matriz: %f\n",matrix[i][j]);
        }
    }
  }
  
  int count = mb*N;

  gettimeofday(&tv3, NULL);

  //Comprobacion de error
  if(!MPI_Scatter(matrix, count, MPI_FLOAT, matrix2, count, MPI_FLOAT, 0, MPI_COMM_WORLD) == MPI_SUCCESS){
    printf("Error Scatter\n");
  }
  
  //TODO broadcast con vector
  if(!MPI_Bcast(vector, N, MPI_FLOAT, 0, MPI_COMM_WORLD)==MPI_SUCCESS){
    printf("Error Bcast\n");
    return -1;
  }
  
  gettimeofday(&tv1, NULL);

  float result[mb*numprocs];        //Resultado final (del total de procesos)      
  float result2[mb];                //Resultado de cada proceso 
  for(i=0;i<mb;i++) {        //Hace la multiplicacion matricial
    result2[i]=0;
    for(j=0;j<N;j++) {
      result2[i] += matrix2[i][j]*vector[j];
    }
  }
  gettimeofday(&tv2, NULL); //Medir tiempo de computación 
                            //tiempo de comunnicacion es tiempo de Bcast, Gatter y Scatter
              
  int microseconds = (tv2.tv_usec - tv1.tv_usec)+ 1000000 * (tv2.tv_sec - tv1.tv_sec);
  //printf("Microseconds: %d\n",microseconds);
  

  if(!MPI_Gather(result2, mb, MPI_FLOAT, result, mb, MPI_FLOAT, 0, MPI_COMM_WORLD) == MPI_SUCCESS){
    printf("Error Gather\n");
  } 
  
  
  gettimeofday(&tv4, NULL);
  int microseconds2 = (tv4.tv_usec - tv3.tv_usec)+ 1000000 * (tv4.tv_sec - tv3.tv_sec);    //Para tiempo de comunicaciones
  
  for(int x =0; x < numprocs;x++){
    if(rank == x){
      t_computacion_total[x] = microseconds;
      t_comunicaciones_total[x] = microseconds2;  
    } 
  }
  
  if(!MPI_Gather(&microseconds, 1, MPI_INT, t_computacion_total, 1, MPI_INT, 0, MPI_COMM_WORLD) == MPI_SUCCESS)
    printf("Error Gather");
  if(!MPI_Gather(&microseconds2, 1, MPI_INT, t_comunicaciones_total, 1, MPI_INT, 0, MPI_COMM_WORLD) == MPI_SUCCESS)
    printf("Error gather");
  /*Display result */

  if(rank == 0){
    if (DEBUG){
      for(i=0;i<N;i++) {
        printf(" %f \t ",result[i]);
      }
    } else {
        printf ("Time (seconds) = %lf\n", (double) microseconds/1E6);
        for(int x =0; x<numprocs;x++){
          printf("Tiempo de comunicaciones del proceso %d es: %lf\n", x,(double) t_comunicaciones_total[x]/1E6);
          printf("Tiempo de computación del proceso %d es: %lf\n", x,(double) t_computacion_total[x]/1E6);
        }
    }    
  }

  if(MPI_Finalize() == MPI_SUCCESS){
    return MPI_SUCCESS;
  }else{
    return MPI_ERR_OTHER;
  }
}

//Scatter distribuye un vector en trozos
//Gatter Reconstruye el vector a partir de los trozos
//./matrix > out   ->vuelvo la salida en un fichero out
//mpirun -n 4 ./matrix > out2      ->salida del programa paralelo en out2
//diff out out2  ->Salida de out y out2 debe ser la misma
