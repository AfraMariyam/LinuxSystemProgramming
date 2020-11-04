#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fdread;
	char readbuffer[100];

	while(1){
		fdread=open("fifo",O_RDONLY);
		read(fdread,readbuffer,sizeof(readbuffer));
		printf("read from first file:%s \n",readbuffer);
	}

}
