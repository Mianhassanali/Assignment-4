#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int arr[1000];

void * add(void* arg);

int main()
{
	int *sum;           	     //Pointer to receive sum returned by a thread
	int tsum = 0;                //Variable to sum values returned by threads
	pthread_t thread[10];
	
	for(int i=0; i<1000; i++)    //Array initializing loop 
		arr[i] = i+1;	
	
	int indexes[10] = {0,100,200,300,400,500,600,700,800,900};

	for(int i=0; i<10; i++)      //Thread creation loop
		pthread_create(&thread[i],NULL,add,&indexes[i]);
	
	for(int i=0; i<10; i++)	     //Loop to join all the threads to the main process
	{
		pthread_join(thread[i],(void **)&sum);
		tsum += *sum;
		free(sum);
	}

	printf("The sum of array is %d\n", tsum);
	return 0;
}

void * add(void* arg)
{
	//derefrencing the value of parameter.
	int start = *((int *)arg);
	int end = *((int *)arg) + 100;
	int *sum = (int *)malloc(sizeof(int)); //Creating local sum parameter
		
	for(start; start < end; start++)
		*sum += arr[start]; 
	
	return (void *)sum;
}
