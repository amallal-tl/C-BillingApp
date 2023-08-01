// DBInteractions.cpp

#include "DBInteractions.h" // include this

void DBInteraction::getConnection(){
	System::String^ connectionString = "Data Source=AMALLALTL;" +
		"Initial Catalog=projectclr3;" +
		"Integrated Security=SSPI;";

	SqlConnection sqlConn(connectionString);
	sqlConn.Open();
	//return sqlConn;
}

