// LoginDB.cpp
#include "LoginDB.h"
#include <iostream>

bool LoginDB::login(std::string username, std::string password) {
	std::cout << username << " : " << password << std::endl;
	sqlite3* db = DBInteraction::getDbInstance();

	const char* sql = "SELECT * FROM users";
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	// TODO: add more logic to check the username and password
	return true;
}