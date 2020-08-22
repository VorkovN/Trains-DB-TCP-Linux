#include "DB_Connector.h"


DB_Connector::DB_Connector() {
    sql::Driver *driver;
    driver = get_driver_instance();
    connection = driver->connect("tcp://127.0.0.1:3306", "root", "*****");
    /* Connect to the MySQL test database */
    connection->setSchema("Projects");

}

bool DB_Connector::findTrain(const string& station, const string& freight, const int cars_count) {
    sql::PreparedStatement *prep_stmt;
    sql::ResultSet *res;
    prep_stmt = connection->prepareStatement("SELECT Quantity FROM stations WHERE Station = ? AND Freight = ? AND Cars_count = ?");
    prep_stmt->setString(1, station);
    prep_stmt->setString(2, freight);
    prep_stmt->setInt(3, cars_count);
    res = prep_stmt->executeQuery();
    if (!res->next() || res->getInt("Quantity") < 1) {
        cout << "Find error" << endl;
        return false;
    }
    //else return false;
    cout << "find" << endl;
    delete res;
    delete prep_stmt;

    return true;
};

bool DB_Connector::send(const string& station, const string& freight, const int cars_count) {

    sql::PreparedStatement *prep_stmt;
    prep_stmt = connection->prepareStatement("UPDATE stations SET Quantity = Quantity - 1 WHERE Station = ? AND Freight = ? AND Cars_count = ?");

    prep_stmt->setString(1, station);
    prep_stmt->setString(2, freight);
    prep_stmt->setInt(3, cars_count);

    if (!prep_stmt->executeUpdate()){
        cout << "Send Error " << endl;
    }
    cout << "send" << endl;
    delete prep_stmt;
    return true;
};

bool DB_Connector::receive(const string& station, const string& freight, const int cars_count) {

    sql::PreparedStatement *prep_stmt;
    prep_stmt = connection->prepareStatement("UPDATE stations SET Quantity = Quantity + 1 WHERE Station = ? AND Freight = ? AND Cars_count = ?");
    prep_stmt->setString(1, station);
    prep_stmt->setString(2, freight);
    prep_stmt->setInt(3, cars_count);

    if (!prep_stmt->executeUpdate()){
        cout << "eee" << endl;
        sql::PreparedStatement *prep_stmt2;
        prep_stmt2 = connection->prepareStatement("INSERT INTO stations (Station, Freight, Cars_count, Quantity) VALUES(?, ?, ?, 1)");
        prep_stmt2->setString(1, station);
        prep_stmt2->setString(2, freight);
        prep_stmt2->setInt(3, cars_count);

        if (!prep_stmt2->executeUpdate()){
            cout << "Insert Error " << endl;
            return false;
        }
        cout << "insert" << endl;
    }
    cout << "receive" << endl;
    delete prep_stmt;
    return true;
};
