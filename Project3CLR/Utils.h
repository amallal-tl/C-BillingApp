#pragma once

#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <msclr\\marshal_cppstd.h> // include this header for conversion
#include <thread>

using namespace std;
using namespace System::Data::SqlClient;

class Utils {
private:
	int global_Status_Count = 2;//Count of services required.

	void check_Db_Run_Status();
public:
	// Default constructor
	Utils();

	// Get the current date and time as a string
	System::String^ get_current_datetime() const;
	System::String^ getCurrentDate();
	void check_operations();
	bool getGeneralServicesStatus();
};