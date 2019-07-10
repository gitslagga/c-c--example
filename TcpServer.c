/*
 * TcpServer.c
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

void extract_name(char* buffer) {
        unsigned long len = strlen(buffer);
        int i = (int) len - 1;
        for(; i>= 0; i--) {
                if (!buffer[i]) {
                        break;
                }
        }

        for(int j = 0; j < len - i; j++) {
                buffer[j] = buffer[i + j + 1];
        }
        char temp[64];
        strcat(buffer, ", nice to meet you.");
}

int main() {
        int server_sockfd;
        int client_sockfd;
        long recv_len;
        struct sockaddr_in server_addr;
        struct sockaddr_in  client_addr;
        socklen_t sin_size = sizeof(struct sockaddr_in);
        char buffer[BUFFER_SIZE];
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(SERVER_PORT);

        if((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                printf("Failed to create socket.\n");
                return -1;
        }

        if(bind(server_sockfd, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in)) < 0) {
                printf("Failed to bind socket.\n");
                return -1;
        }

        if(listen(server_sockfd, 5) < 0) {
                printf("Filed to listen socket\n");
        }

        while(1) {
                client_sockfd = accept(server_sockfd, (struct sockaddr*) &client_addr, &sin_size);
                while((recv_len = recv(client_sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
                        buffer[recv_len] = 0;
                        printf("Recieve message from client: %s\n", buffer);
                        extract_name(buffer);
                        char temp[BUFFER_SIZE] = "Hello,";
                        strcat(temp, buffer);
                        send(client_sockfd, temp, strlen(temp), 0);
                }
        }
        return 0;
}
