#include "Utils.h"

using namespace msclr::interop; // use this namespace for conversion
using namespace System::Data::SqlClient;

int services_running_status = 0;

void Utils::check_operations() {
    // This function will run forever in a separate thread
        services_running_status = 0;
        std::thread dbThread(&Utils::check_Db_Run_Status,this);
        dbThread.detach();
}

bool Utils::getGeneralServicesStatus() {
    if (services_running_status > global_Status_Count)
        return true;
    else false;
}

// A function to check the database run status
void Utils::check_Db_Run_Status() {
        // Declare a constant string variable for the connection string
        System::String^ connectionString = "Data Source=AMALLALTL;" +
            "Initial Catalog=projectclr3;" +
            "Integrated Security=SSPI;";

        while (1) {
            // Use a using statement to create and dispose the SqlConnection object
            SqlConnection sqlConn(connectionString);
            try {
                // Open the connection
                sqlConn.Open();
                services_running_status += 1;
                // Print a success message            
            }
            catch (System::Exception^ e) {
                // Print the exception message
                e;
                //Console::WriteLine("Exception: {0}", e->Message);
            }
            finally {
                // Close the connection
                sqlConn.Close();
                // Print a closing message
            }
        }
}

// Default constructor
Utils::Utils()
{
    // Nothing to do here
}

System::String^ Utils::getCurrentDate() {
    System::DateTime now = System::DateTime::Now;
    System::String^ dateStr = now.ToString("yyyy-MM-dd");

    // Return the String^ result 
    return dateStr;
}

// Get the current date and time as a String^
System::String^ Utils::get_current_datetime() const
{
    // Get the current system time point
    auto now = std::chrono::system_clock::now();

    // Convert it to a time_t object
    auto now_t = std::chrono::system_clock::to_time_t(now);

    // Convert it to a tm struct
    auto now_tm = *localtime(&now_t);

    // Create a string stream to format the output
    std::stringstream ss;

    // Write the date and time in the desired format
    ss << std::put_time(&now_tm, "%Y%m%d%H%M%S");

    // Get the fractional seconds from the time point
    auto fraction = now - std::chrono::time_point_cast<std::chrono::seconds>(now);

    // Convert it to milliseconds
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(fraction).count();

    // Convert the string stream to a std::string
    std::string str = ss.str();

    // Convert the std::string to a String^ using marshal_as
    System::String^ result = marshal_as<System::String^>(str);

    // Return the String^ result
    return result;
}
