#include "Utils.h"
#include <msclr\\marshal_cppstd.h> // include this header for conversion

using namespace msclr::interop; // use this namespace for conversion


// Default constructor
Utils::Utils()
{
    // Nothing to do here
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

    // Write the milliseconds with a dot separator
    //ss << "." << std::setfill('0') << std::setw(3) << milliseconds;

    // Convert the string stream to a std::string
    std::string str = ss.str();

    // Convert the std::string to a String^ using marshal_as
    System::String^ result = marshal_as<System::String^>(str);

    // Return the String^ result
    return result;
}
