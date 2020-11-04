#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){

	int fdread,ret;
	char readbuffer[50];


	while(1){
		fdread=open("fifo",O_RDONLY);

		ret=read(fdread,readbuffer,sizeof(readbuffer));
		printf("the number of bytes read is %d and read %s \n",ret,readbuffer);

	}
}
