#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "options.h"

#define MAX_AMOUNT 20

struct bank {
    int num_accounts;        // number of accounts
    int *accounts;           // balance array
    pthread_mutex_t **mutex; //mutex array
    pthread_mutex_t *macabado;
    pthread_mutex_t *miterations;
    int cont;                //contador de iteraciones
    int iterations;          //// number of operations
    int acabado;             //contador para saber cuando se acaba (acabado = 0)
};

struct args {
    int          thread_num;  // application defined thread #
    int          delay;       // delay between operations
    //int	         iterations;  // number of operations
    int          net_total;   // total amount deposited by this thread
    struct bank *bank;        // pointer to the bank (shared with other threads)
};

struct thread_info {
    pthread_t    id;    // id returned by pthread_create()
    struct args *args;  // pointer to the arguments
};


int iterations_cont(int *cont) {
    
    int valor = *cont;
    return valor;
}

// Threads run on this function
void *deposit(void *ptr)
{
    struct args *args =  ptr;
    int amount, account, balance;
    
    while(iterations_cont(&args->bank->cont)!=0) {

        pthread_mutex_lock(args->bank->miterations);
        //printf("Iteracion: %d\n",args->bank->cont);
        if(args->bank->cont>0) args->bank->cont--;
        pthread_mutex_unlock(args->bank->miterations);
        amount  = rand() % MAX_AMOUNT;
        account = rand() % args->bank->num_accounts;

        pthread_mutex_lock(args->bank->mutex[account]);
        
        printf("Thread %d depositing %d on account %d\n",
            args->thread_num, amount, account);

        balance = args->bank->accounts[account];
        if(args->delay) usleep(args->delay); // Force a context switch

        balance += amount;
        if(args->delay) usleep(args->delay);

        args->bank->accounts[account] = balance;
        if(args->delay) usleep(args->delay);

        pthread_mutex_unlock(args->bank->mutex[account]);
        args->net_total += amount;
        
    }
    
    return NULL;
}

void *transfer(void *ptr)
{
	struct args *args =  ptr;
	int amount, account1, account2, balance1, balance2;
    
	while(iterations_cont(&args->bank->cont)!=0) {

        pthread_mutex_lock(args->bank->miterations);
        //printf("Numero iteraciones: %d\n",args->bank->cont );
        if(args->bank->cont>0) args->bank->cont--;
        pthread_mutex_unlock(args->bank->miterations);

		account1 = rand() % args->bank->num_accounts;
		account2 = rand() % args->bank->num_accounts;
		while (account1 == account2)
			account2 = rand() % args->bank->num_accounts;

		while(1){
			pthread_mutex_lock(args->bank->mutex[account1]);
			
            if(pthread_mutex_trylock(args->bank->mutex[account2])){
				pthread_mutex_unlock(args->bank->mutex[account1]);
				continue;
			}

			balance1 = args->bank->accounts[account1];
			if(args->delay) usleep(args->delay); // Force a context switch

			balance2 = args->bank->accounts[account2];
			if(args->delay) usleep(args->delay); // Force a context switch

			amount  = 0;
			if (balance1 != 0)
				amount = rand() % (balance1+1);

			printf("Thread %d transferring %d on account %d from account %d\n",
			args->thread_num, amount, account2, account1);

			balance1 -= amount;
			if(args->delay) usleep(args->delay);

			args->bank->accounts[account1] = balance1;
			if(args->delay) usleep(args->delay);

			balance2 += amount;
			if(args->delay) usleep(args->delay);

			args->bank->accounts[account2] = balance2;
			if(args->delay) usleep(args->delay);

			pthread_mutex_unlock(args->bank->mutex[account1]);
			pthread_mutex_unlock(args->bank->mutex[account2]);
			break;
		}
	}
	return NULL;
}


// start opt.num_threads threads running on deposit.
struct thread_info *start_threads(struct options opt, struct bank *bank, void *(*func)(void *))
{
    int i;
    struct thread_info *threads;

    printf("creating %d threads\n", opt.num_threads);
    threads = malloc(sizeof(struct thread_info) * opt.num_threads);

    if (threads == NULL) {
        printf("Not enough memory\n");
        exit(1);
    }

    // Create num_thread threads running swap()
    for (i = 0; i < opt.num_threads; i++) {
        threads[i].args = malloc(sizeof(struct args));

        threads[i].args -> thread_num = i;
        threads[i].args -> net_total  = 0;
        threads[i].args -> bank       = bank;
        threads[i].args -> delay      = opt.delay;
        //threads[i].args -> iterations = opt.iterations;
        

        if (0 != pthread_create(&threads[i].id, NULL, func, threads[i].args)) {
                        printf("Could not create thread #%d", i);
                        exit(1);
        }            
    }
    return threads;
}

struct thread_info *start_thread(struct options opt, struct bank *bank, void *(*func)(void *))
{
    struct thread_info *threads;

    threads = malloc(sizeof(struct thread_info) * 1);

    if (threads == NULL) {
        printf("Not enough memory\n");
        exit(1);
    }

    // Create num_thread threads running swap()
    
        threads[0].args = malloc(sizeof(struct args));

        threads[0].args -> thread_num = 0;
        threads[0].args -> net_total  = 0;
        threads[0].args -> bank       = bank;
        threads[0].args -> delay      = opt.delay;
        //threads[0].args -> iterations = opt.iterations;
        

        if (0 != pthread_create(&threads[0].id, NULL, func, threads[0].args)) {
                        printf("Could not create thread #%d", 0);
                        exit(1);
        }            

    return threads;
}

// wait for all threads to finish
void wait(struct options opt, struct bank *bank, struct thread_info *threads) {
    // Wait for the threads to finish
    for (int i = 0; i < opt.num_threads; i++)
        pthread_join(threads[i].id, NULL);
    bank->cont = bank->iterations; 
}

//Wait para los threads de transferencia
void wait2(struct options opt, struct bank *bank, struct thread_info *threads_transfer) {
    // Wait for the threads to finish
    
    for (int i = 0; i < opt.num_threads; i++)
        pthread_join(threads_transfer[i].id, NULL);
    
    bank->acabado = 1;  //Threads de transferencia terminados
}
 
// Print the final balances of accounts and threads
void print_balances(struct bank *bank, struct thread_info *thrs_deposit, struct thread_info *thrs_transfer, int num_threads) {
    int total_deposits=0,total_transfer=0, bank_total=0;
    printf("\nNet deposits by thread\n");

    for(int i=0; i < num_threads; i++){
        printf("%d: %d\n", i, thrs_deposit[i].args->net_total);
        total_deposits += thrs_deposit[i].args->net_total;
    }

    for(int i=0; i < num_threads; i++) {
        printf("%d: %d\n", i, thrs_transfer[i].args->net_total);
        total_transfer += thrs_transfer[i].args->net_total;
    }
    printf("Total: %d\n", total_deposits);

    printf("\nAccount balance\n");
    for(int i=0; i < bank->num_accounts; i++) {
        printf("%d: %d\n", i, bank->accounts[i]);
        bank_total += bank->accounts[i];
    }
    printf("Total: %d\n", bank_total);
}

int flag_on(pthread_mutex_t *m, int *flag) {

    pthread_mutex_lock(m);
    int valor_flag = *flag;
    pthread_mutex_unlock(m);
    //printf("valor_flag es : %d\n",valor_flag);
    return valor_flag;
}


void *balance_after_trans(void *ptr){ 
    
    struct args *args =  ptr;
    int bank_total = 0;
    
    
    while(!flag_on(args->bank->macabado, &args->bank->acabado)){
        
        pthread_mutex_lock(args->bank->macabado);
        for(int i=0; i < args->bank->num_accounts; i++) {
            pthread_mutex_lock(args->bank->mutex[i]);    
        }

        for(int i=0; i < args->bank->num_accounts; i++) {
            //printf("%d: %d\n", i, args->bank->accounts[i]);
            bank_total += args->bank->accounts[i];
        }

        for(int i=0; i < args->bank->num_accounts; i++) {
            pthread_mutex_unlock(args->bank->mutex[i]);
        }
        
        printf("Total after transferring: %d\n", bank_total);
        bank_total =0; 
        pthread_mutex_unlock(args->bank->macabado);
    }
    
    return NULL;
}

void free_memory(struct options opt, struct bank *bank, struct thread_info *threads_deposit, struct thread_info *threads_transfer, struct thread_info *threads_balance){

    for (int i = 0; i < opt.num_threads; i++)
        free(threads_deposit[i].args);

    for (int i = 0; i < opt.num_threads; i++)
        free(threads_transfer[i].args);

    free(threads_balance[0].args);
        
    for (int i = 0; i < opt.num_accounts; i++) {
	    pthread_mutex_destroy(bank->mutex[i]);
	    free(bank->mutex[i]);
    }
    pthread_mutex_destroy(bank->macabado);
    pthread_mutex_destroy(bank->miterations);
    free(bank->macabado);
    free(bank->miterations);
    free(bank->mutex);
    free(threads_deposit);
    free(threads_transfer);
    free(threads_balance);
    free(bank->accounts);

}

// allocate memory, and set all accounts to 0
void init_accounts(struct bank *bank, int num_accounts, int iterations) {
    pthread_mutex_t **mutex;
    pthread_mutex_t *macabado;
    pthread_mutex_t *miterations;

    bank->num_accounts = num_accounts;
    bank->accounts     = malloc(bank->num_accounts * sizeof(int));
    
    mutex = malloc(sizeof(pthread_mutex_t) * (bank->num_accounts));
    macabado = malloc(sizeof(pthread_mutex_t) );
    miterations = malloc(sizeof(pthread_mutex_t) );

    if (mutex == NULL) {  
		printf("Not enough memory\n");
		exit(1);
	}
    if (macabado == NULL) {  
		printf("Not enough memory\n");
		exit(1);
	}

    if (miterations == NULL) {  
		printf("Not enough memory\n");
		exit(1);
	}

    for(int i=0; i < bank->num_accounts; i++){
        bank->accounts[i] = 0;
        mutex[i] = malloc(sizeof(pthread_mutex_t));		//Hacemos un malloc para cada mutex del array
		if(mutex[i] == NULL){
			printf("Not enough memory\n");
			exit(1);
		}
        pthread_mutex_init(mutex[i],NULL);
    }
    pthread_mutex_init(macabado,NULL);
    pthread_mutex_init(miterations,NULL);
    
    bank->cont = iterations;
    bank->iterations = iterations;
    bank->mutex = mutex;
    bank-> macabado = macabado;
    bank-> miterations = miterations;
    bank->acabado = 0;
}

int main (int argc, char **argv)
{
    struct options      opt;
    struct bank         bank;
    struct thread_info *thrs_deposit;
    struct thread_info *thrs_transfer;
    struct thread_info *thrs_balance;

    srand(time(NULL));

    // Default values for the options
    opt.num_threads  = 5;
    opt.num_accounts = 10;
    opt.iterations   = 100;
    opt.delay        = 10;

    read_options(argc, argv, &opt);

    init_accounts(&bank, opt.num_accounts, opt.iterations);

    thrs_deposit = start_threads(opt, &bank, deposit);
    
    wait(opt, &bank, thrs_deposit);

    thrs_transfer = start_threads(opt, &bank, transfer);

    thrs_balance = start_thread(opt, &bank, balance_after_trans);
    
    wait2(opt,&bank, thrs_transfer);

    print_balances(&bank, thrs_deposit,thrs_transfer, opt.num_threads);

    free_memory(opt, &bank, thrs_deposit, thrs_transfer, thrs_balance);

    return 0;
}