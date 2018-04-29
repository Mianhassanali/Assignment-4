#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


int sum = 0;
int arr[1000];
pthread_t thread[10];


void * add(void* arg)
{
	//derefrencing the value of parameter.
	int start = *((int *)arg);
	int end = *((int *)arg) + 100;
	printf("Start index = %d\n",start);
	//Loop to add array values and storing sum in global variable.
	for(start; start < end; start++)
		sum += arr[start]; 
}

int main()
{
	for(int i=0; i<1000; i++)
        {
		arr[i] = i+1;
	}
	
	
	int indexes[10] = {0,100,200,300,400,500,600,700,800,900};

	for(int i=0; i<10; i++)
	{
		pthread_create(&thread[i],NULL,add,&indexes[i]);
	}
	

	for(int i=0; i<10; i++)
		pthread_join(thread[i], NULL);

	printf("The sum is %d\n",sum);

	return 0;
}
