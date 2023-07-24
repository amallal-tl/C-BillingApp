#pragma once
#include <string>
//#include <locale>
#include <string>
using namespace System;
//using namespace System::Runtime::InteropServices;

using namespace std;
using namespace System;

// Define a class that has a static method to convert String^ to std::string
class ProjectClr3Services {
public:
    // Declare the static method
    static string getString(String^ str);
};



// Define the static method
string ProjectClr3Services::getString(String^ str) {
    //IntPtr ip = Marshal::StringToHGlobalAnsi(str); // convert String^ to IntPtr
    //const char* cstr = static_cast<const char*>(ip.ToPointer()); // convert IntPtr to const char*
    //std::string text(cstr); // convert const char* to std::string
    //Marshal::FreeHGlobal(ip); // free memory
    return "";
}
