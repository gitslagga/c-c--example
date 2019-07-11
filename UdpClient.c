/*
 * UdpClient.c
 *
 *  Created on: Jul 11, 2019
 *      Author: 95776
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 11122

int main() {
	int client_sockfd;
	long recv_len;
	struct sockaddr_in server_addr;
	socklen_t sin_size = sizeof(struct sockaddr_in);
	char buffer[BUFFER_SIZE];

	memset(&server_addr, 0, sizeof(server_addr));
	memset(&buffer, 0, sizeof(buffer));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(SERVER_PORT);

	if ((client_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		printf("Failed to create socket.\n");
		return -1;
	}

	strcpy(buffer, "Hello Alice, I'm Bob");
	sendto(client_sockfd, buffer, strlen(buffer), 0, (struct sockaddr*) & server_addr, sizeof(server_addr));

	recv_len = recvfrom(client_sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) & server_addr, &sin_size);
	buffer[recv_len] = 0;
	printf("Recieve message from server: %s\n", buffer);

	close(client_sockfd);

}
