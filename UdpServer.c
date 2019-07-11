/*
 * UdpServer.c
 *
 *  Created on: Jul 11, 2019
 *      Author: 95776
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 11122

void extract_name(char* buffer) {
	unsigned long len = strlen(buffer);
	int i = (int)len - 1;
	for (; i >= 0; i--) {
		if (!buffer[i]) {
			break;
		}
	}
	for (int j = 0; j < len - i; j++) {
		buffer[j] = buffer[i + j + 1];
	}
	
	char temp[64];
	strcpy(temp, buffer);
	strcpy(buffer, "Hello, ");
	strcat(buffer, temp);
	strcat(buffer, ", nice to meet you.");
}

int main() {
	int server_sockfd;
	int client_sockfd;
	long recv_len;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t sin_size = sizeof(struct sockaddr_in);
	char buffer[BUFFER_SIZE];

	memset(&server_addr, 0, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(SERVER_PORT);

	if ((server_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("Failed to create socket.\n");
		return -1;
	}

	if (bind(server_sockfd, (struct sockaddr*) & server_addr, sizeof(struct sockaddr_in)) < 0) {
		printf("Failed to bind socket.\n");
		return -1;
	}

	while (1) {
		if ((recv_len = recvfrom(server_sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &client_addr, &sin_size)) > 0) {
			buffer[recv_len] = 0;
			printf("Recieve message from client: %s\n", buffer);

			extract_name(buffer);

			sendto(server_sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) & client_addr, sin_size);
		}
	}

	return 0;
}