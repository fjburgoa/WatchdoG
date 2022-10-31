//esto es un progrmaa de pruebsa con 2 threads
//un thread escribe x pantalla constantemente
//un segudno trhead, se queda esperando a la entrada de datos

#include <iostream>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


using namespace std;


void *fun1(void *arg)
{
	for (int i = 0; i < 30; i++)
	{
		cout << "iteration: " << i << endl;
		usleep(500000);
	}
	return NULL;
}

void *fun2(void *arg)
{
	cin >> (char *)arg;
	return NULL;
}

int main()
{
	pthread_t pth1;
	pthread_t pth2;

	char myarray[50]={0};

	pthread_create(&pth2, NULL, fun2, (void *)myarray);
	pthread_create(&pth1, NULL, fun1, NULL);
	
	//espera a que termine
	pthread_join(pth2, NULL);
	pthread_join(pth1, NULL);
	
	cout << "thread 2 ha leido: " << endl;
	cout << myarray;
	
	return 0;
}


 