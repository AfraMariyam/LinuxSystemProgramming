#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(){

	int fd1,fd2,r,pos;
	char buf[300];
	fd1=open("linux system programming.txt",O_RDONLY);
	fd2=dup(fd1);
	printf("the fd is %d and %d\n",fd1,fd2);

	r= read(fd1,&buf,100);
	printf("bytes read %d\n",r);
	r=read(fd2,&buf,10);
	printf("bytes read %d\n",r);
	r=read(fd1,&buf,100);
	printf("bytes read %d\n",r);
	pos=lseek(fd1,0,SEEK_CUR);
	printf("pos %d\n",pos);
	r=read(fd2,&buf,10);
	printf("bytes read %d\n",r);
	pos=lseek(fd2,0,SEEK_CUR);
	printf("pos %d\n",pos);
}
//pos 110
//pos 120
