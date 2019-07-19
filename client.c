#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int fd;
    struct sockaddr_in serv;
    char buf[10];

    serv.sin_family=AF_INET;
    serv.sin_port=htons(4243);
    serv.sin_addr.s_addr=inet_addr("127.0.0.1");

    fd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    connect(fd,(struct sockaddr *)&serv,sizeof(serv));

    recv(fd,&buf,6*sizeof(char),0);

    printf("Receive: %s\n",buf);

    buf[0]='7';

    send(fd,&buf,6*sizeof(char),0);

    printf("Send: %s\n",buf);

    close(fd);

    return 0;
}
