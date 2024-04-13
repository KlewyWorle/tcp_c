#include <stdio.h>
#include<stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "servutils.h"
int main()
{
    int server = Socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_port = htons(14491);
    Bind(server, (struct sockaddr*)&adr, sizeof(adr));

    //Lsiten
    int list = Listen(server, 5);

    socklen_t adrlen = sizeof(adr);
    int client_fd = Accept(server, (struct sockaddr*)&adr, &adrlen);

    char buf[256];

    ssize_t rd = Read(client_fd, buf, 256);

    write(STDOUT_FILENO, buf, rd);
    write(client_fd, buf, rd);

    sleep(2);

    close(server);
    close(client_fd);
    

    return 0;
}