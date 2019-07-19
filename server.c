#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int fd,new_fd;
    struct sockaddr_in serv,cl;
    int len=sizeof(cl);
    char buf[10]="Hello";

    serv.sin_family=AF_INET;
    serv.sin_port=htons(4243);
    serv.sin_addr.s_addr=inet_addr("127.0.0.1");

    fd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    bind(fd,(struct sockaddr *)&serv,sizeof(serv));

    listen(fd,1);

    new_fd=accept(fd,(struct sockaddr *)&cl,&len);

    send(new_fd,&buf,6*sizeof(char),0);

    printf("Send: %s\n",buf);

    recv(new_fd,&buf,6*sizeof(char),0);
    printf("Receive: %s\n",buf);

    close(new_fd);
    close(fd);

    return 0;
}
