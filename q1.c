#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(){

	int fdread,fdwrite,bytesread,byteswrite;
	char buf[30];
	size_t len=30;
 
	fdread=open("readfile.txt",O_RDONLY);
	fdwrite=open("writefile.txt",O_RDWR|O_CREAT|O_TRUNC,664);

  	printf("the fd of file is %d and %d \n",fdread,fdwrite);
  
  	while((bytesread=read(fdread,&buf,len))>0){
		byteswrite=write(fdwrite,&buf,bytesread);

		printf("bytes read is %d \n and bytes written is %d \n",bytesread,byteswrite);

		getchar();

	}


	close(fdread);
	close(fdwrite);

}
