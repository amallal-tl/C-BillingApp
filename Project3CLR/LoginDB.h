#ifndef LOGINDB_H
#define LOGINDB_H

#include "DBInteractions.h"

//using namespace System;

class LoginDB {
private:
public:
	bool login(System::String^ username, System::String^ password); // login method
};

#endif
