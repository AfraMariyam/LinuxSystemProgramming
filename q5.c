#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
	int pid,status,n=0;
	printf("enter the value of n\n");
	scanf("%d",&n);
	pid=fork();
	if(pid==0){
		printf("the child process\n");
		return(n);

	}/*
	if(pid==0){
		printf("the child process\n");
		exit(n);

	}
	if(pid==0){
		printf("the child process\n");
		

	}*/
	
	if(pid!=0 && pid!=-1){
		printf("parent process with pid :%d\n",getpid());
		wait(&status);
		printf("the child status is %d \n ",status);
	}

}
