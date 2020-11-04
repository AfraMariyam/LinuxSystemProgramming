#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){

	int sockfd, ret;
	struct sockaddr_in server_addr;
	
	int newsockfd;
	struct sockaddr_in new_addr;
    
	FILE *fp;
	char data[1024]={0};
	char filename[32]={0};
	
	char *ip = "127.0.0.1";
	int port = 8080;
	int opt=1;
	
	socklen_t addr_size;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
    	if(sockfd < 0){
        	printf("Error in connection.\n");
        	exit(1);
    	}
    	printf("server socket created successfully.\n");
	
	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt))){
		perror("set\n");
		exit(1);
	}
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = port;
	server_addr.sin_addr.s_addr =inet_addr(ip);
	
	ret = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if(ret < 0){
		perror("error in bind\n");
		exit(1);
	}
	printf("Binding Successful\n");
	
	if(listen(sockfd, 10) == 0){
		printf("Listening \n");
	}else{
		perror("Error in Listening \n");
		exit(1);
	}
	
	newsockfd = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);
	if(newsockfd < 0){
		printf("Error accept \n");
		exit(1);
	}
	printf("Connected to client\n");
	ret = recv(newsockfd, filename, 32, 0);
		if(ret <= 0){
			printf("Error \n");
			exit(1);
		}
	printf("%s\n", filename);
	
	fp = fopen(filename, "w");
	if(fp == NULL)
		printf("Error");
	printf("Writing to file\n");
	
	while(1){
		ret = recv(newsockfd, data, 1024, 0);
		if(ret <= 0){
			printf("exiting\n");
			break;	
		}
		fprintf(fp ,"%s", data);
		printf("data : %s\n",data);
		bzero(data,1024);
	}
	
	printf("Data written in the file\n");
	
	return 0;

		
}
