// DBInteractions.cpp

#include "DBInteractions.h" // include this
#include <iostream>
// initialize the static member variable
sqlite3* DBInteraction::db = nullptr;
const char* DBInteraction::dbName = "ProjectClr.db";

// define the static member function to get the db instance
sqlite3* DBInteraction::getDbInstance() {
    // check if the db pointer is null
    if (db == nullptr) {
        // open the database and assign it to the db pointer
        int rc = sqlite3_open(dbName, &db); // use the db pointer directly instead of calling db.get()
        // handle any errors
        if (rc) {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
            return nullptr;
        }
        else {
            std::cout << "Opened database successfully" << std::endl;
        }
    }
    // return the db pointer
    return db;
}

// define the member function to close the db instance
void DBInteraction::closeInstance() {
    if (db != nullptr) {
        sqlite3_close(db); // use the db pointer directly instead of calling db.get()
        delete db; // delete the db pointer to free the memory
        db = nullptr; // set the db pointer to null to avoid dangling pointers
    }
}
