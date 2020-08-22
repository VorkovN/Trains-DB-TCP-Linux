#pragma once
#include <cstring>    // sizeof()
#include <iostream>
#include <string>

// headers for socket(), getaddrinfo() and friends
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <unistd.h>    // close()

using namespace std;

class Server{
public:
	Server();
    ~Server();

	int getServerSocket();

private:
    int serverSocket;
    struct sockaddr_in addr{};
};

