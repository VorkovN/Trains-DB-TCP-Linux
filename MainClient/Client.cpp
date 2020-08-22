#include "Client.h"

Client::Client() {

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0){
        cout << "socket error" << endl;
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8124);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(clientSocket, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        cout << "connection error" << endl;
        exit(2);
    }
	cout << "Connected!" << endl;
}

Client::~Client() {
    close(clientSocket);
}

int& Client::getClientSocket(){
    return clientSocket;
}