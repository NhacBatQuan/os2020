#include<stdio.h>
#include<pthread.h>

void *prime (void *args)
 {
	int n,count=0;
	printf("Prime numbers under 1000000: \n");
	for (n=2;n<=1000000;n++)
	{		count=0;
		for (int i=1;i<=n;i++)
		{
			if(!(n%i))
				count ++;
			if(count > 2)
				break;
		}
		if (count==2)
		printf("%d\n",n);
}
}

void *fibonacci(void*args) {
	int num = 2, previous = 1;
	for(int i=0; i<1000000; i++) {
		printf("%d\n", num);
		int next = num + previous;
		previous = num;
		num = next;
	
		if(num >= 1000000)
			break;
	}
}
int main () {
	pthread_t thread1;
	pthread_t thread2;
	pthread_create(&thread1, NULL,prime, NULL);
	pthread_create(&thread2, NULL,fibonacci, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}


