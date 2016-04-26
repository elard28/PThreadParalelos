#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM 16

void *fun( void *ptr )
{
	char *message;
	message = (char *) ptr;
	printf("%s \n", message);
}


int main(int argc, char const *argv[])
{
	const char *msg = "Hola!!";

	clock_t start, end;
  	double time_used=0;

	/*pthread_t thread[NUM];
	for (int i = 0; i < NUM; i++)
	{
		start = clock();
		pthread_create(&thread[i], NULL,fun, (void*) msg);
		end = clock();
		time_used += 10*((double) (end - start)) / CLOCKS_PER_SEC;
	}*/


	for (int i = 0; i < NUM; i++)
	{
		start = clock();
		pthread_t thread2;
		pthread_create(&thread2, NULL,fun, (void*) msg);
		end = clock();
		time_used += 100*((double) (end - start)) / CLOCKS_PER_SEC;
	}


	/*start = clock();
	free(thread);
	end = clock();
	time_used += 10*((double) (end - start)) / CLOCKS_PER_SEC;*/

	printf("%1.4f\n", time_used/NUM);


	return 0;
}