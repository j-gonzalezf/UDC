#include <sys/types.h>
#include <openssl/md5.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define PASS_LEN 6

#define TOTAL_THREADS 10


struct password {
    pthread_mutex_t *m_int;  //mutex para intentos
    pthread_mutex_t *m_enc;  //mutex para encontrada
	pthread_mutex_t *m_num_pass;  //mutex para encontrada
	pthread_mutex_t *m_num_args;
    int intentos;
	char** md5;
	int num_pass;		//numero de passwords procesados
	int num_args;		//Numero de argumentos (numero de md5s)
	int encontrada;
	int aux;
};

struct args {
	int		thread_num;       // application defined thread #
	struct password *psswd;
};

struct thread_info {
	pthread_t    id;        // id returned by pthread_create()
	struct args *args;      // pointer to the arguments
};

long ipow(long base, int exp)
{
    long res = 1;
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

long pass_to_long(char *str) {
    long res = 0;

    for(int i=0; i < PASS_LEN; i++)
        res = res * 26 + str[i]-'a';

    return res;
};

void long_to_pass(long n, unsigned char *str) {  // str should have size PASS_SIZE+1
    for(int i=PASS_LEN-1; i >= 0; i--) {
        str[i] = n % 26 + 'a';
        n /= 26;
    }
    str[PASS_LEN] = '\0';
}


int hex_value(char c) {
    if (c>='0' && c <='9')
        return c - '0';
    else if (c>= 'A' && c <='F')
        return c-'A'+10;
    else if (c>= 'a' && c <='f')
        return c-'a'+10;
    else return 0;
}

void hex_to_num(char *str, unsigned char *hex) {
    for(int i=0; i < MD5_DIGEST_LENGTH; i++)
        hex[i] = (hex_value(str[i*2]) << 4) + hex_value(str[i*2 + 1]);
}

#define GAP "                             "

int flag_on(pthread_mutex_t *m, int *flag) {

    pthread_mutex_lock(m);
    int valor_flag = *flag;
    pthread_mutex_unlock(m);
    //printf("valor_flag es : %d\n",valor_flag);
    return valor_flag;
}

void *count(void *ptr){		//cada segundo que pasa, se reinicia el contador de passwords probadas y se imprime
	struct args *args =  ptr;	//TODO: solo se ejecuta una vez y debe ejecutarse mientras no terminen el resto de threads
	
	while(!flag_on(args->psswd->m_enc, &args->psswd->encontrada)){
		pthread_mutex_lock(args->psswd->m_num_pass);
		printf("  %d",args->psswd->num_pass);	//Numero de passwords por segundo
		args->psswd->num_pass =0;
		pthread_mutex_unlock(args->psswd->m_num_pass);
		fflush(stdout);
		sleep(1);	//se duerme el proceso un segundo
		
	}
	return NULL;
}
//Elmina el md5 indicado
void delete (char **md5, int x, int num) {
	char *aux;

	for (int i = x; i < num-1; i++) {
		aux = md5[i];
		md5[i] = md5[i+1];
		md5[i+1] = aux;
	}
}

void *break_pass(void *ptr) {
	struct args *args =  ptr;
    unsigned char res[MD5_DIGEST_LENGTH];
	unsigned char md5_num[MD5_DIGEST_LENGTH];
    unsigned char *pass = malloc((PASS_LEN + 1) * sizeof(char));
    long bound = ipow(26, PASS_LEN); // we have passwords of PASS_LEN
                                     // lowercase chars =>
                                    //     26 ^ PASS_LEN  different cases

    for(long i=args->thread_num; i < bound; i += TOTAL_THREADS) {
    	     
		pthread_mutex_lock(args->psswd->m_num_pass);
		args->psswd->num_pass++;
		pthread_mutex_unlock(args->psswd->m_num_pass);

    	if (!flag_on(args->psswd->m_enc, &args->psswd->encontrada)) {

            pthread_mutex_lock(args->psswd->m_int);
		    args->psswd->intentos += 1;		
		    pthread_mutex_unlock(args->psswd->m_int);

	        long_to_pass(i, pass);

	        MD5(pass, PASS_LEN, res);

	        
			
			pthread_mutex_lock(args->psswd->m_num_args);
			for (int j = 0; j<args->psswd->num_args; j++) {	//comprobar cada uno de los argumentos con cada password
				hex_to_num(args->psswd->md5[j], md5_num);
	    		if(0 == memcmp(res, md5_num, MD5_DIGEST_LENGTH)) {		//Si se encuentra un password 	
					printf("\r%s: %s%s\n", args->psswd->md5[j], pass, GAP);   //Se printea
					delete(args->psswd->md5, j, args->psswd->num_args);			//Se elimina ese md5
					args->psswd->num_args -= 1;		//Decrementa el numero de argumentos 
					if(args->psswd->num_args==0){	//Si el numero de argumentos llega a 0 
		    			pthread_mutex_lock(args->psswd->m_enc);
		        		args->psswd->encontrada = 1;	//se pondrá a 1 al encontrar el último password
	            		pthread_mutex_unlock(args->psswd->m_enc);
					break; // Found it!
					}
		   	 	}
		 	}    
			 pthread_mutex_unlock(args->psswd->m_num_args);   
	    } else{
	    	break;
        }
    }
    free(pass);

    return NULL;
}

#define STR "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

void *progress(void *ptr) {
	struct args *args =  ptr;
	int  total, aux;
	float ptg;
	long bound = ipow(26, PASS_LEN);

	while (!flag_on(args->psswd->m_enc, &args->psswd->encontrada)) {
		total = 0;

		pthread_mutex_lock(args->psswd->m_int);
		total += args->psswd->intentos;
		pthread_mutex_unlock(args->psswd->m_int);

		ptg = 100*(float)total/(float)bound;
		aux = (int)(ptg*0.5);

		printf("\rChecked: [%.*s%*s] %.2f%% ", aux, STR, 50-aux, "", ptg);
		fflush(stdout);

		//sleep(1);  // La barra se actualiza cada X segs
	}

	printf("  COMPLETED\n");

	return NULL;
}

struct thread_info *start_threads(struct password *psswd){
	struct thread_info *threads;

	printf("Using %d threads to break the pass\n\n", TOTAL_THREADS);
	threads = malloc(sizeof(struct thread_info) * (TOTAL_THREADS+2));

	if (threads == NULL) {  
		printf("Not enough memory\n");
		exit(1);
	}

	for (long i=0; i<TOTAL_THREADS+2; i++) {
		threads[i].args = malloc(sizeof(struct args));

    	threads[i].args -> thread_num = i;
		threads[i].args -> psswd = psswd;

		if (i<TOTAL_THREADS) {
			if (0 != pthread_create(&threads[i].id, NULL, break_pass, threads[i].args)) {
				printf("Could not create thread #%ld", i);
				exit(1);
			}
		} else if(i< TOTAL_THREADS+1){
			if (0 != pthread_create(&threads[i].id, NULL, progress, threads[i].args)) {
				printf("Could not create thread #%ld", i);
				exit(1);
			}
		} else{
			if (0 != pthread_create(&threads[i].id, NULL, count, threads[i].args)) {
				printf("Could not create thread #%ld", i);
				exit(1);
			}
		}
	}

    return threads;
}

// wait for all threads to finish, print totals, and free memory
void wait(struct thread_info *threads, struct password *psswd) {

	for (int i=0; i <TOTAL_THREADS+1; i++)
		pthread_join(threads[i].id, NULL);

}

void init_psswd(struct password *psswd, char *argv[], int num){

    psswd->m_int = malloc(sizeof(pthread_mutex_t));
    if(psswd->m_int == NULL){
		printf("Not enough memory\n");
		exit(1);
	}
    pthread_mutex_init(psswd->m_int,NULL);

    psswd->m_enc = malloc(sizeof(pthread_mutex_t));
    if(psswd->m_enc == NULL){
		printf("Not enough memory\n");
		exit(1);
	}
    pthread_mutex_init(psswd->m_enc,NULL);

    psswd->md5 = malloc(sizeof(char*)*num);
    if(psswd->md5 == NULL){
		printf("Not enough memory\n");
		exit(1);
	}
	for (int i = 0; i < num; i++){
    	psswd->md5[i] = argv[i+1];
		printf("Argumento %d: %s\n",i, argv[i+1]);
	}

	psswd->m_num_pass = malloc(sizeof(pthread_mutex_t));
    if(psswd->m_num_pass == NULL){
		printf("Not enough memory\n");
		exit(1);
	}
	pthread_mutex_init(psswd->m_num_pass,NULL);

	psswd->m_num_args = malloc(sizeof(pthread_mutex_t));
    if(psswd->m_num_args == NULL){
		printf("Not enough memory\n");
		exit(1);
	}
    pthread_mutex_init(psswd->m_num_args,NULL);
    
	//printf("md5: %s\n",psswd->md5);
	psswd->num_args = num; 
	psswd->encontrada = 0;
    psswd->intentos = 0;
    psswd->aux = 0;
	psswd->num_pass =0;
}

void free_memory(struct thread_info *threads, struct password *psswd){
	for (int i = 0; i < TOTAL_THREADS+1; i++)
		free(threads[i].args);

	pthread_mutex_destroy(psswd->m_int);
	pthread_mutex_destroy(psswd->m_enc);
	pthread_mutex_destroy(psswd->m_num_pass);
	pthread_mutex_destroy(psswd->m_num_args);

	free(psswd->m_int);
	free(psswd->m_enc);
	free(psswd->m_num_pass);
	free(psswd->m_num_args);
	free(psswd->md5); 
	free(threads);
	printf("\n");
}

int main(int argc, char *argv[]) {
	struct thread_info *thrs;
	struct password psswd;
    if(argc < 2) {
        printf("Use: %s string\n", argv[0]);
        exit(0);
    }

    init_psswd(&psswd, argv, argc-1);
	printf("Numero de argumentos: %d\n", argc-1);

    thrs = start_threads(&psswd);

    wait(thrs, &psswd);

	free_memory(thrs,&psswd);

    return 0;
}