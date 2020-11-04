#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){

	int fdwrite,ret;
	char writebuffer[50];


	while(1){
		fdwrite=open("fifo",O_WRONLY);
		fgets(writebuffer,50,stdin);
		ret=write(fdwrite,writebuffer,sizeof(writebuffer));
		printf("the number of bytes written is %d and wrote %s \n",ret,writebuffer);

	}
	
}

