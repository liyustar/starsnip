#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <iostream>
using namespace std;

#include "SocketUtility.h"
int main(int argc, char *argv[]) {

	char *server = argv[1];     // First arg: server address/name
	const char *echoString = "1234567890"; // Second arg: string to echo
	// Third arg (optional): server port/service
	char *service = argv[2];

	// Create a connected TCP socket
	int sock = SetupTCPClientSocket(server, service);
	if (sock < 0)
		DieWithUserMessage("SetupTCPClientSocket() failed", "unable to connect");

	size_t echoStringLen = strlen(echoString); // Determine input length

	// Send the string to the server
	ssize_t numBytes = send(sock, echoString, echoStringLen, 0);
	if (numBytes < 0)
		DieWithSystemMessage("send() failed");
	else if (numBytes != echoStringLen)
		DieWithUserMessage("send()", "sent unexpected number of bytes");

	/*

	// Receive the same string back from the server
	unsigned int totalBytesRcvd = 0; // Count of total bytes received
	fputs("Received: ", stdout);     // Setup to print the echoed string
	while (totalBytesRcvd < echoStringLen) {
		char buffer[BUFSIZE]; // I/O buffer
		// Receive up to the buffer size (minus 1 to leave space for
		// a null terminator) bytes from the sender
		numBytes = recv(sock, buffer, BUFSIZE - 1, 0);
		if (numBytes < 0)
			DieWithSystemMessage("recv() failed");
		else if (numBytes == 0)
			DieWithUserMessage("recv()", "connection closed prematurely");
		totalBytesRcvd += numBytes; // Keep tally of total bytes
		buffer[numBytes] = '\0';    // Terminate the string!
		fputs(buffer, stdout);      // Print the buffer
	}
	*/

	fputc('\n', stdout); // Print a final linefeed

	close(sock);
	exit(0);
}
