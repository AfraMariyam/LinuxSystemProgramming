#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){

	int fdread,fdwrite,bytesread,byteswritten;
	char buf[20];

	fdread=0;
 	
 	fdwrite=dup2(1,0);
 	
 
  	printf("the fd of file is %d and %d \n",fdread,fdwrite);
 
 
  	while(bytesread=read(fdread,&buf,10)>0){
  		
  		byteswritten=write(fdwrite,&buf,10);
 		 //printf("the write is %s \n",buf);
 		 memset(buf,0,20);
 	}
 	close(fdread);
 	close(fdwrite);
  }
