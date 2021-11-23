/*
	-------PROYECTO FINAL-------	
	Aplicación para utilizar la barrrera de sincronización creada, suma de sumas de varios threads

	Correr la implementación creada:
	gcc -pthread -o sumaSumas sumaSumas.c barreras.h barreras.c cadena.h

	./sumaSumas

*/

#include <stdio.h>
#include <unistd.h>
#include "barreras.h"
#include "cadena.h"

#define N_THREADS 4

typedef struct sumSums {
	int inicio;
	int fin;
	long long total;
	int sleepTime;
}sumSums;


void *my_thread(void *arg) {
	sumSums *args = (sumSums *) arg;
	 if (args->sleepTime > 0){
		 sleep(args->sleepTime);
	 } 
	 for(int i = args->inicio; i <= args->fin; i++){
		 args->total += arrayValues4[i];
	 } 
		//args->total = args->valor1 +args->valor2;
	printf("thread acabó,resultado parcial de su suma: %llu\n", args->total);
  esperar_barrera();
  return NULL;
}

int main(void){
	sumSums val_args[N_THREADS] = {
		{0 ,249,0,0},
		{250 ,499,0,3},
		{500 ,749,0,2},
		{750,999,0,1}
	};
	int n = iniciar_barrera(N_THREADS);
	pthread_t threads[N_THREADS];
	
	if (n != -1){
		
		for (int i=0;i<N_THREADS;i++){
			pthread_create(&threads[i],NULL,my_thread, &val_args[i]);
		}

		esperar_barrera();
		printf("Todos los threads acabaron, resultado final:\n");
		long long res = 0;
		for (int i= 0; i< N_THREADS;i++){
			//printf("El total de un thread es de: %lld\n", val_args[i].total);
			res += val_args[i].total; 
		}
		printf("El total de todo es de: %lld\n", res);


		for (int i=0;i<N_THREADS;i++)
			pthread_join(threads[i],NULL);

		//para barreras
		destruir_barrera();
	}else {
		printf("Problem creating threads, negative threads send");
	}
	return 0;
}