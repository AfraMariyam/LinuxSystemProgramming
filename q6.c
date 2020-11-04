#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
	int status,n=4,ret,c;
	pid_t pid[n];
	
	for(int i=0;i<n;i++){
		pid[i]=fork();
		if(pid==0){
			printf("the child process\n");
			c=rand()%10;
			printf("random no is %d",c);
			sleep(c);

		}
		
		if(pid[i]!=0 && pid[i]!=-1){
			printf("parent process with pid :%d and child pid is %d \n",getpid(),pid[i]);
			ret=waitpid(pid[i],&status,0);
			printf("the child status is %d and return is %d \n ",status,ret);
		}

	}

}
