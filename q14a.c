#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define PERMS 0666

int main(int argc,char* argv[]){

	struct msg{
	    long mtype;
	    char data[10];
	   }msgread;
	   
	int msgid,key;
   
	key=ftok(".",10);
   
	msgid=msgget(key,PERMS | IPC_CREAT);
	printf("The msg q id is %d\n",msgid);
   
   
	if(argc==2){
		msgread.mtype=atol(argv[1]);  
    		printf("%s typearg:\n",argv[1]);
    		 				      		 				  msgrcv(msgid,&msgread,sizeof(msgread.data),msgread.mtype,IPC_NOWAIT);          
    		printf("message recv is %s\n",msgread.data);
   	}else{
    		msgrcv(msgid,&msgread,sizeof(msgread.data),0,IPC_NOWAIT);
    		printf("message recv is %s\n",msgread.data);
      }
}
