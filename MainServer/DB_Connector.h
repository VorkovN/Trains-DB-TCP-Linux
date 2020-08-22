#pragma once
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;


class DB_Connector{
public:
    DB_Connector();

    
    bool findTrain(const string& station, const string& freight, int cars_count);
    bool send(const string& station, const string& freight, int cars_count);
    bool receive(const string& station, const string& freight, int cars_count);

private:

    sql::Connection *connection;
};

