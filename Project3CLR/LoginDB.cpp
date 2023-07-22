#include <iostream>
#include "DBInteractions.h"

using namespace std;

class LoginDB
{
	sqlite3_stmt* stmt; // prepared statement

	bool login(string username, string password) {
		cout << username << " : " << password << endl;
		sqlite3* db = DBInteraction::getDbInstance();

		const char* sql = "SELECT * FROM users";
		int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	}
};