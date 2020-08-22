#include <cstring>    // sizeof()
#include <iostream>
#include <string>
#include <thread>

// headers for socket(), getaddrinfo() and friends
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <unistd.h>    // close()

#include "Client.h"

using namespace std;


Client client;


[[noreturn]] void ClientHandler() {
	char msg[64];
	while (true) {
		if (recv(client.getClientSocket(), msg, sizeof(msg), 0) > 0) {
			cout << msg << endl;
			memset(msg, 0, 64);
			sleep(1);
		}
	}
}


int main(int argc, char* argv[]) {

    thread func_thread(ClientHandler);

	char from[64];
	char to[64];
	char freight_type[64];
	char cars_count[64];
	while (true) {
		sleep(1);
		cout << "Input city1" << endl;
		cin.getline(from, sizeof(from));
		cout << "Input city2" << endl;;
		cin.getline(to, sizeof(to));
		cout << "Input type of freight (liquid, wood or ore)" << endl;;
		cin.getline(freight_type, sizeof(freight_type));
		cout << "Input count of cars" << endl;
		cin.getline(cars_count, sizeof(cars_count));
		send(client.getClientSocket(), from, sizeof(from), 0);
		send(client.getClientSocket(), to, sizeof(to), 0);
		send(client.getClientSocket(), freight_type, sizeof(freight_type), 0);
		send(client.getClientSocket(), cars_count, sizeof(int), 0);
		cin.clear();
		cout << endl;
	}

	system("pause");
	return 0;
}
