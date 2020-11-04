//writing into pipe: reading happends alternatively one at a time.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){

	int fdwrite;
	mkfifo("fifo",0664);
	char message[100];

	while(1){
		fdwrite=open("fifo",O_WRONLY);
	        fgets(message,100,stdin);
		write(fdwrite,message,sizeof(message));
		printf("%s \n",message);
	}
}
