#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

void sighandler(int signum){
	printf("signal hanlder caught signal %d and process id is %d, the recieved signal %s\n",signum,getpid(),sys_siglist[signum]);

}

int main(){

	int pid1,pid2;
	

	pid1=fork();

	if(pid1==0){
	printf("child1 process pid %d and parent pid %d\n",getpid(),getppid());

	for(;;);
	
	}

	if(pid1!=0 && pid1!=-1){


		pid2=fork();
		if(pid2!=0 && pid2!=-1){

			printf("parent process\n");
			signal(SIGINT,sighandler);
			getchar();
			printf("sending int to first child\n");
			kill(pid1,SIGINT);
			getchar();
			
			printf("sending int to second child\n");
			kill(pid2,SIGINT);
			getchar();
			
			printf("sending int to parent \n");
			raise(SIGINT);
			getchar();
			
			}
	}



	if(pid2==0){
		printf("child 2 process  pid %d and parent pid %d\n",getpid(),getppid());
	
		for(;;);
	}	


}
