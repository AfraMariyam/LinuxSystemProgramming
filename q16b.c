#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char * argv[]){
	
	int key,shmid;
	void *shmptr;
	char *filename;
	int fp;
	int ret;
	int count=0;
	key = ftok(".",10);
	int size;
	
	if(argc >= 2){
		filename = argv[1];
	}else{
		printf("Error file name not given\n");
		exit(1);
	}
	
	struct stat filestat;
	
	fp = open(filename, O_RDONLY);
	if(fp < 0){
		perror("Error in reading file\n");
		exit(1);
	}
	
	if(fstat(fp,&filestat) != 0){
	 	perror("stat failed");
	 	exit(1);
	 }
	 printf("%ld size:\n",filestat.st_size);
	 size =filestat.st_size;
	 
	 
	shmid = shmget(key,1024,IPC_CREAT|0644);
	if(shmid < 0){
		printf("error1\n");
		exit(1);
	}
	
	printf("the shared mem segment id is %d \n",shmid);
	shmptr= shmat(shmid,0,0);
	printf("addr %p: \n",(void*) &shmptr);
	
	*(int *)shmptr=size;
	printf("%d\n",*(int*)shmptr);
	shmptr=(int*)shmptr+1;
	printf("addr %p: \n",(void*) &shmptr);
	ret=read(fp,shmptr,size);
	printf("bytes_read:%d\n",ret);
	printf("shmptr :%s\n",(char*)shmptr);
	printf("addr %p: \n",(void*) &shmptr);
	shmdt(shmptr);
	
	
}

