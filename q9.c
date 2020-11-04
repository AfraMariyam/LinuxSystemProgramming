#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int signum){
	printf("signal hanlder caught signal :%d\n",signum);
}

int main(){

	printf("INT signal\n");
	signal(SIGINT,sighandler);
	getchar();
	printf("TERM signal\n");

	signal(SIGTERM,sighandler);
	getchar();
	printf("SIG QUIT\n");

	signal(SIGQUIT,sighandler);
	getchar();
	printf("caught the sig quit\n");


}
