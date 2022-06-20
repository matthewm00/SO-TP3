// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// Server side C/C++ program to demonstrate Socket
/*
    Implementación sacada de: https://www.geeksforgeeks.org/socket-programming-cc/
*/
#include "desafios.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
      HANDLE_ERROR("Error in socket");
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR, &opt,
                   sizeof(opt)))
    {
      HANDLE_ERROR("Error in setsockopt");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
      HANDLE_ERROR("Error in bind");
    }
    if (listen(server_fd, 3) < 0)
    {
      HANDLE_ERROR("Error in listen");
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0)
    {
      HANDLE_ERROR("Error in accept");
    }

    FILE *fp;
    fp = fdopen(new_socket, "r");
    if (fp == NULL)
    {
        HANDLE_ERROR("Error in fdopen.");
    }
    init(fp);
    int completed = 1;
    while (completed <= CALLENGE_COUNT)
    {
        if(challenge(completed) > 0){
            completed++;
        }
        sleep(2);
    }
    // Liberamos los recursos utilizados.
    end();
    close(server_fd);
    return EXIT_SUCCESS;
}
