#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
int pid = fork();
	if (pid == 0) 
	{
		int pid1 = fork(); 
		if (pid1 == 0) 
		{
			printf("I am child after fork(), launching ps -ef\n");
			char *args[] = {"/bin/ps", "-ef", NULL};
			execvp("/bin/ps", args);}
		else {
			wait(NULL);
			printf("I am parent after fork(), child is %d\n", pid1);
		}
		printf("I am child after fork(), launching free -h\n");
		char *args[] = {"free", "-h", NULL};
		execvp("free", args);
	}
		else {
			wait(NULL);
			printf("I am parent after fork(), child is %d\n", pid);
		}
	return 0;
}
	

