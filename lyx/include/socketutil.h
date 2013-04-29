#ifndef SOCKETUTIL_H
#define SOCKETUTIL_H

#include <stdbool.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Handle error with user msg
void DieWithUserMessage(const char *msg, const char *detail);
// Handle error with sys msg
void DieWithSystemMessage(const char *msg);

/*
 * Server
 */
// Create, bind, and listen a new TCP server socket
int SetupTCPServerSocket(const char *service);
// Accept a new TCP connection on a server socket
int AcceptTCPConnection(int servSock);

/*
 * Client
 */
int SetupTCPClientSocket(const char *host, const char *service);

enum sizeConstants {
	MAXCLNT = 5,
};

#endif
