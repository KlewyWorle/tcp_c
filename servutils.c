#include "servutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>


int Socket(int domain, int type, int protocol)
{
    int result = socket(domain, type, protocol);
    if(result == -1)
    {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }
    return result;

}
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int result = bind(sockfd, addr, addrlen);
    if(result == -1)
    {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }
}
int Listen(int sockfd, int backlog)
{
    int lis = listen(sockfd, 5);
    if (lis == -1)
    {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    return lis;
}
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int result = accept(sockfd, addr, addrlen);
    if (result == -1)
    {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }
    return result;
}
ssize_t Read(int fd, char *buf, size_t count)
{
    ssize_t rn = read(fd, buf, count);
    if(rn == -1)
    {
        perror("Read error");
        exit(EXIT_FAILURE);
    }
    else if (rn == 0)
    {
        printf("End of file occured\n");
    }
    return rn;
}
void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int result = connect(sockfd, addr, addrlen);
    if(result == -1)
    {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }
}