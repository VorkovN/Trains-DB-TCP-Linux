#include "Controller.h"
#include <iostream>

using namespace std;


bool Controller::checkStations(string station) {
	if (allowed_stations.find(station) == allowed_stations.end())
		return false;
	return true;
}

bool Controller::checkFreight(string freight) {
	if (allowed_freight.find(freight) == allowed_freight.end())
		return false;
	return true;
}


string Controller::order(string from, string to, string freight_type, int cars_count) {
	if (!checkStations(to)) return "station " + to + " doesn't exist\n";
	if (!checkStations(from)) return "station " + from + " doesn't exist\n";
	if (!checkFreight(freight_type)) return freight_type + " isn't a type of freight\n";

	if (from == to) return "Please send a train to another city\n";

	if (!db_connector.findTrain(from, freight_type, cars_count)) return "Such train doesn't exist on " + (string)from + " station\n";
	cout << "1" << endl;
	if (!db_connector.send(from, freight_type, cars_count)) return "Sending error\n";
    cout << "2" << endl;
	if (!db_connector.receive(to, freight_type, cars_count)) return "Receiving error\n";
    cout << "3" << endl;
	
	return "Train with " + to_string(cars_count) + " cars of " + (string)freight_type + " left the " + (string)from + " station\n";

};


