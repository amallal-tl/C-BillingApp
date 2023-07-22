// DBInteractions.h

#ifndef DBINTERACTIONS_H // include guard
#define DBINTERACTIONS_H

#include "sqlite/sqlite3.h" // include the sqlite library

// declare a class named as DBInteraction
class DBInteraction {
private:
    // declare a static member variable for the db pointer
    static sqlite3* db;
    static const char* dbName;

    // declare a private constructor to prevent instantiation
    DBInteraction();

public:
    // delete the copy constructor to prevent copying
    DBInteraction(const DBInteraction& db) = delete;

    // declare a static member function to get the db instance
    static sqlite3* getDbInstance();

    // declare a member function to close the db instance
    void closeInstance();
};

#endif // DBINTERACTIONS_H
