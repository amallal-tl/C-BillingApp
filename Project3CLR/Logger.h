#pragma once

#include <thread>
#include <iostream> 
#include <fstream>

using namespace std;

class Logger {
private:
    const int MAX_LOG_LEVEL = 4;

public:
    // Default constructor
    Logger();

    void printLog(int log_level);
};