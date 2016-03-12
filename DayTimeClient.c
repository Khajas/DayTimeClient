/***************************************************************
Programmer: Khaja Anwar Ali Siddiqui
Title: Daytime Client-Server Model.
***************************************************************/
#include"prog1.h"
int main(int argc, char *argv[]){
	int sockfd, n;
	char recvline[MAXLINE+1];
	struct sockaddr_in servaddr;
	if(argc!=2)
	printf("%s","Too many(few) arguments supplied");
	if((sockfd=socket(AF_INET, SOCK_STREAM, 10))<0)
	printf("%s","Couldn't create a socket");
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(13);
	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))<0)
	printf("%s","Connect error");
	while((n=read(sockfd, recvline, MAXLINE))>0){
		recvline[n]=0;
		if(fputs(recvline, stdout)==EOF)
		printf("%s","fputs error");
	}
	if(n<0)
	printf("%s","Read error");
	exit(0);
}
