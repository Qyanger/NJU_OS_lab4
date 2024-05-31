#include "lib.h"
#include "types.h"

int uEntry(void)
{
	/*
	sem_t mutex;
	sem_init(&mutex, 1);

	sem_t full;
	sem_init(&full, 0);

	sem_t empty;
	sem_init(&empty, 5);

	int ret=1;

	//三个进程
	for(int i=1;i<=3;++i)
	{
		if(ret>0)
		{
			ret=fork();
			if(ret>0)
				printf("child process creating:%d\n", ret);
		}
		else 
			break;
	}

	int pid=getpid();

	if(ret==0)
	{
		for(int i=1;i<=2;++i)
		{
			sem_wait(&empty);
			sem_wait(&mutex);
			printf("Producer %d: produce\n", pid);
			sleep(128);
			sem_post(&mutex);
			sem_post(&full);
		}
		exit();
	}
	else if(ret>0)
	{
		for(int i=1;i<=6;++i)
		{
			sem_wait(&full);
			sem_wait(&mutex);
			printf("Consumer : consume\n");
			sleep(128);
			sem_post(&mutex);
			sem_post(&empty);
		}
	}
	*/
/*
	// For lab4.1
	// Test 'scanf'
	int dec = 0;
	int hex = 0;
	char str[6];
	char cha = 0;
	int ret = 0;
	while (1)
	{
		printf("Input:\" Test %%c Test %%6s %%d %%x\"\n");
		ret = scanf(" Test %c Test %6s %d %x", &cha, str, &dec, &hex);
		printf("Ret: %d; %c, %s, %d, %x.\n", ret, cha, str, dec, hex);
		if (ret == 4)
			break;
	}
	
	*/
	// For lab4.2
	// Test 'Semaphore'
	int i = 4;
	int ret =0;
	sem_t sem;
	printf("Father Process: Semaphore Initializing.\n");
	ret = sem_init(&sem, 2);
	if (ret == -1)
	{
		printf("Father Process: Semaphore Initializing Failed.\n");
		exit();
	}

	ret = fork();
	if (ret == 0)
	{
		while (i != 0)
		{
			i--;
			printf("Child Process: Semaphore Waiting.\n");
			sem_wait(&sem);
			printf("Child Process: In Critical Area.\n");
		}
		printf("Child Process: Semaphore Destroying.\n");
		sem_destroy(&sem);
		exit();
	}
	else if (ret != -1)
	{
		while (i != 0)
		{
			i--;
			printf("Father Process: Sleeping.\n");
			sleep(128);
			printf("Father Process: Semaphore Posting.\n");
			sem_post(&sem);
		}
		printf("Father Process: Semaphore Destroying.\n");
		sem_destroy(&sem);
		exit();
	}
	

	// For lab4.3
	// TODO: You need to design and test the problem.
	// Note that you can create your own functions.
	// Requirements are demonstrated in the guide.


	return 0;
}
