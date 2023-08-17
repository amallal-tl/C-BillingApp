#include "Logger.h"
#include "Utils.h"


Logger::Logger() {}

void Logger::printLog(int log_level) {
	Utils util;
	
	System::String^ logfile = "log_"+ util.getCurrentDate();

	// Get the current time 
	time_t now = time (NULL); 
	// Convert it to a string 
	char* time_str = ctime (&now); 
	// Remove the newline character at the end
	time_str[strlen(time_str) - 1] = "\0";
	// Create an ofstream object 
	std::ofstream ofs;
	// Open the log file in append mode
	ofs.open (logfile, std::ios::app);
	// Check if the file is opened successfully if (ofs.is_open ()) { 
	// Write the timestamp and the message to the file ofs << “[” << time_str << "] " << message << std::endl;
	// Close the file ofs.close (); } else { 
	// Print an error message to the standard error stream std::cerr << "Error: could not open " << LOG_FILE << std::endl;
} 
}
}