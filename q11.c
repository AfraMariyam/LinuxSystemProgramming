#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[]){

	int pid1,pid2,status,fd[2];

	char *argv1[]={"cat","linux_system_programming.txt",NULL};
	char *argv2[]={"less",NULL};
	pipe(fd);
	pid1=fork();
	
	if(pid1==0)
	{
		printf("child1 process");
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execvp(argv1[0],argv1);
	}
	
	pid2=fork();
	if(pid2==0){
		printf("child2 process\n");
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execvp(argv2[0],argv2);

	}

	waitpid(pid1,&status,0);
	waitpid(pid2,&status,0);


}
