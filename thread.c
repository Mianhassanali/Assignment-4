#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


int sum = 0;
int arr[1000];
pthread_t thread[10];


void * add(void* arg)
{
	int start = *((int *)arg);
	int end = *((int *)arg) + 100; //derefrencing the value of parameter.
	printf("%d\n",end);
	for(start; start < end; start++)
		sum += arr[start];  //Adding in global variable.
}

int main()
{
	for(int i=0; i<1000; i++)
        {
		arr[i] = 1;
	}
	
	
	int j=0;

	for(int i=0; i<1000; i+=100)
	{
		int x=i;
		pthread_create(&thread[j],NULL,add,&x);
		j++;
	}
	

	for(int i=0; i<10; i++)
		pthread_join(thread[i], NULL);

	printf("The sum is %d\n",sum);

	return 0;
}
