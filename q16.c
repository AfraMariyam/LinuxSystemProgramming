#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
	
	int key,shmid;
	void *shmptr;
	char data[512]={0};
	char *filename ;
	int fp;
	int ret,*size;
	
	if(argc >= 2){
		filename = argv[1];
	}else{
		printf("Error file name not given\n");
		exit(1);
	}
	
	key = ftok(".",10);
	shmid = shmget(key,1024,0);
	if(shmid < 0){
		printf("error\n");
		exit(1);
	}
	
	printf("the shared mem segment id is %d \n",shmid);
	shmptr=shmat(shmid,0,0);
	size=(int*)(shmptr);
	printf("%d size\n",*size);
	shmptr=(int*)shmptr+1;
	
	fp = open(filename, O_WRONLY | O_CREAT ,0666);
	if(fp == -1)
		perror("Error\n");
	printf("Writing to file\n");
	
	//printf("data : %s\n",shmptr);
	ret = write(fp,shmptr,*size);
	printf("written %d",ret);
	
	shmdt(shmptr);
}
	

