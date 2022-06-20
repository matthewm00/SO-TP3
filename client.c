// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// Client side C/C++ program to demonstrate Socket
#include "desafios.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
#define MAX_BUFFER 1024
#define SA struct sockaddr

int main(int argc, char const *argv[])
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER];
    int buffIndex = 0;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }

    if ((connect(sock, (struct sockaddr *)&serv_addr,
                             sizeof(serv_addr))) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    int c;
    while ((c = getchar()) != EOF)
    {
        buffer[buffIndex++] = c;
        if(c == '\n')
        {
            buffer[buffIndex] = 0;
            if (send(sock, buffer, strlen(buffer), 0) < 0)
            {
                HANDLE_ERROR("Error sending from client.\n");
            }
            buffIndex = 0;
        }
    }
    return EXIT_SUCCESS;
}
