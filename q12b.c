#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
	int fdread;
	char readbuffer[100];

	while(1){
		fdread=open("fifo",O_RDONLY);
		read(fdread,readbuffer,sizeof(readbuffer));
		printf("read from second  file:%s \n",readbuffer);
	}

}
