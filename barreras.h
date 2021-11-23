
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
/*
	Métodos que se deben inculir para utilizar el procedimiento de barreras simuladas con semáforos y mutex. 

	Es importante incluir todos los métodos al momento de necesitar la barrera de sincronización. 

*/
/*
	Método que inicia las barreras que incluye el mutex y el semáforo que se utiliza
	@param
	Cantidad de threads creado en la aplicación
	@return
	-1 en creada no exitosa
	0 on éxito
*/
int iniciar_barrera(int threads);
/*
	Método que realiza la operación las barreras que incluye el mutex y el semáforo que se utiliza
	@param
	
	@return
	
	
*/
void esperar_barrera();
/*
	Método que mata la operación las barreras que incluye el mutex y el semáforo que se utiliza
	@param
	
	@return
	
*/
void destruir_barrera();