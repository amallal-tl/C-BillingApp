// LoginDB.cpp
#include "LoginDB.h"

using namespace System::Data::SqlClient;

bool LoginDB::login(System::String^ username, System::String^ password) {
	System::String^ connectionString = "Data Source=AMALLALTL;" +
		"Initial Catalog=projectclr3;" +
		"Integrated Security=SSPI;";

	//try {
		SqlConnection sqlConn(connectionString);
		sqlConn.Open();
		
		System::String^ sqlQuery = "SELECT[userid] FROM[dbo].[User] WHERE username = @user AND password = @pass";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@user", username);
		command.Parameters->AddWithValue("@pass", password);

		SqlDataReader^ reader = command.ExecuteReader();
		if (reader->Read()) {
			return true;
		}
		else {
			return false;
		}
	/*}catch (Exception^ e) {

	}*/
}