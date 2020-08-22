#include <thread>
#include <iostream>
#include <set>
#include "Server.h"
#include "Controller.h"

Server server;
Controller controller;

void ClientHandler(int current_socket) {

	char from[64];
	char to[64];
	char freight_type[64];
	int cars_count;
	string msg;
	while (true) {
	    sleep(1);
		try {

			if (recv(current_socket, from, sizeof(from), 0) > 0
				&& recv(current_socket, to, sizeof(to), 0) > 0
				&& recv(current_socket, freight_type, sizeof(freight_type), 0) > 0
				&& recv(current_socket, (char*)&cars_count, sizeof(int), 0) > 0)
					msg = controller.order(from, to, freight_type, cars_count - (int)'0');
		}
		catch (exception& ex) {
			msg = ex.what();
		}
		send(current_socket, msg.c_str(), msg.size(), 0);
	}
}

int main(int argc, char* argv[]) {

	while (true) {

	    int servSock = accept(server.getServerSocket(), NULL, NULL);

		if (servSock ==  0) {
			cout << "Error #2\n";
		}
		else {
			cout << "Client Connected!" << endl;
			char msg_start[64] = "Hello. You can order transportation your freight\n";
			send(servSock, msg_start, sizeof(msg_start), 0);

            thread func_thread(ClientHandler, servSock);
            func_thread.detach();
		}
	}


	system("pause");
	return 0;
}