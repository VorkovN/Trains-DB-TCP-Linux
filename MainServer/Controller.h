#pragma once
#include <set>
#include <string>
#include "DB_Connector.h"

using namespace std;

class Controller {

public:

	string order(string from, string to, string freight_type, int cars_count);

	bool checkStations(string name);

	bool checkFreight(string freight);

private:
	DB_Connector db_connector;
	set<string> allowed_stations = {"SPB", "MSK", "EKB"};
	set<string> allowed_freight = {"liquid", "wood", "ore"};
};

