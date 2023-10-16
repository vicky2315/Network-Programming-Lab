#include <cstdio>
#include <WinSock2.h>
#define MESSAGESIZE 40


#pragma once
class Connection {
public:
	// Constructor.
	// sock: the socket that we've accepted the client connection on.
	Connection(SOCKET sock);

	// Destructor.
	~Connection();

	// Return the client's socket.
	SOCKET sock();

	// Return whether this connection is in a state where we want to try
	// reading from the socket.
	bool wantRead();

	// Call this when the socket is ready to read.
	bool doRead();

private:
	// This client's socket.
	SOCKET sock_;

	// The data we've read from the client.
	int readCount_;
	char readBuffer_[MESSAGESIZE];
};


