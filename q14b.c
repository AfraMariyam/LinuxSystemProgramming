#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define PERMS 0666

int main(){

	int i,key,msgid;

	struct msg{
	    long mtype;
	    char data[10];
	    }msgwrite;
   
	key=ftok(".",10);
	msgid=msgget(key,PERMS | IPC_CREAT);

	printf("The message queue id is %d\n",msgid);

	for(int i=0;i<=2;i++){
		printf("Enter the msg type:\n");
		scanf("%ld",&msgwrite.mtype);
		printf("Enter the data\n");
		scanf("%s",msgwrite.data);
		msgsnd(msgid,&msgwrite,sizeof(msgwrite.data),IPC_NOWAIT);
		printf("msg:%s\n ",msgwrite.data);
	}

}
