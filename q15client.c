#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]){
	
	char *ip = "127.0.0.1";
	int port = 8080;
	int ret;
	char *filename;
	
	int sockfd;
	struct sockaddr_in server_addr;
	int sockfd_new;
	
	FILE *fp;
	if(argc >= 2){
		filename = argv[1];
	}else{
		printf({"Error file name not given\n");
		exit(1);
	}
	
	char data[1024] = {0};
	char filename1[32];
	
	printf("%s :file name\n",argv[0]);
	printf("%s :next file\n ",argv[1]);
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		perror("Error in socket\n");
		exit(1);
	}
	printf("server socket created successfully.\n");
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = port;
	server_addr.sin_addr.s_addr =inet_addr(ip);
	
	ret = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if(ret == -1){
		perror("Error in socket\n");
		exit(1);
	}
	printf("Connected to Server\n");
	
	printf("enter the text file\n");
	scanf("%s",filename1);
	if(send(sockfd, filename1, sizeof(filename1), 0) == -1){
			perror("Error in sending file \n");
			exit(1);
		
	}
	printf("%s \n", filename1);
	
	fp = fopen(filename, "r");
	if(fp == NULL){
		perror("Error in reading file\n");
		exit(1);
	}
	
	while(fgets(data, 1024, fp) != NULL){
		if(send(sockfd, data, sizeof(data), 0) == -1){
			perror("Error in sending file \n");
			exit(1);
		
		}
		printf("%s ",data);
		bzero(data, 1024);
	}
	
		
	printf("\nFile data sent successfully\n");
	printf("Closing the connection\n");
	close(sockfd);
	
}
