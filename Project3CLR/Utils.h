#pragma once

#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std;

class Utils{
public:
    // Default constructor
    Utils();

    // Get the current date and time as a string
    System::String^ get_current_datetime() const;
};