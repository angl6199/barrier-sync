/*
	-------PROYECTO FINAL-------
	Implementación que simula las barreras de sincronización con base en mutex y semaphores

	como correrlo:
	gcc -pthread -o (nombre ejecutable) (nombre codigo.c) barreras.h barreras.c (posible otros .h utilizados)

*/
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include "barreras.h"

int count = 0;
int total_threads = 0;
sem_t sem;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

// Método para determinar los THREADS e iniciar la barrera 
int iniciar_barrera(int threads){
	if(threads <= 0){
		return -1;
	}
	total_threads = threads + 1;
	pthread_mutex_init(&mut, NULL);
	sem_init(&sem,0,0);
	return 0;
}
//Método que simula espera de barrera
void esperar_barrera() {
	pthread_mutex_lock(&mut);					//thread 2 count 5
	count += 1;
	pthread_mutex_unlock(&mut);

	if (count == total_threads) {
		sem_post(&sem);				// 2 
	}
	sem_wait(&sem);		// 1 3 4 prin 
	pthread_mutex_lock(&mut);
	count -= 1;
	pthread_mutex_unlock(&mut);
	sem_post(&sem);
	//count = 0;
}
//Método para destruir los Semáforos y el mutex
void destruir_barrera(){
	count = 0;
	sem_destroy(&sem);
	pthread_mutex_destroy(&mut);
}