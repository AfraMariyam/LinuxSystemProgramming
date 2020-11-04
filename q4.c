#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int filecopy(int fd1,int fd2,int c){
	int r,w;
	char *buf= (char*)malloc(c*sizeof(char));

	while((r=read(fd1,buf,c))>0){
	   w=write(fd2,buf,c);
	}
	
	free(buf);
	return 1;
}

int main(int argc,char * argv[]){

	int fd1,fd2,bufsize=1,r;

	if(argc<2){
		fd1=0;
		fd2=1;
	}else{
		fd1=open(argv[1],O_RDONLY);
		fd2=1;
  	}
 
	r=filecopy(fd1,fd2,bufsize);
 
	if(r==1)
 		printf("success");
}

