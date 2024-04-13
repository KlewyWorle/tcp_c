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
    int serv = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr = {};
    adr.sin_family = AF_INET;
    adr.sin_port = htons(14491);
    int net = inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
    if (net == -1)
    {
        perror("Error net");
        exit(EXIT_FAILURE);
    }
    Connect(serv, (struct sockaddr*)&adr, sizeof(adr));

    write(serv, "Putin\n", 6);

    char buf[256];
    ssize_t server_fd = Read(serv, buf, 256);

    write(STDOUT_FILENO, buf, server_fd);

    sleep(2);

    close(serv);

    
    return 0;
}