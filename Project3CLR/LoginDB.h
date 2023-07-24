#ifndef LOGINDB_H
#define LOGINDB_H

#include <string>
#include "DBInteractions.h"

class LoginDB {
private:
	sqlite3_stmt* stmt; // prepared statement
public:
	bool login(std::string username, std::string password); // login method
};

#endif
