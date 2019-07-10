/*
 * TcpClient.c
 *
 *  Created on: Jul 9, 2019
 *      Author: 95776
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 11121

int main() {
        int client_sockfd;
        long recv_len;
        struct sockaddr_in server_addr;
        char buffer[BUFFER_SIZE];

        memset(&server_addr, 0, sizeof(server_addr));
        memset(&buffer, 0, sizeof(buffer));

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(SERVER_PORT);

        if ((client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                printf("Failed to create socket.\n");
                return -1;
        }
        if (connect(client_sockfd, (struct sockaddr*) & server_addr, sizeof(struct sockaddr)) > 0) {
                printf("Failed to connect remote socket.\n");
                return -1;
        }

        strcpy(buffer, "Hello Alice, I'm Bob");
        send(client_sockfd, buffer, strlen(buffer), 0);

        recv_len = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
        buffer[recv_len] = 0;
        printf("Receive message from server: %s\n", buffer);

        close(client_sockfd);
}
