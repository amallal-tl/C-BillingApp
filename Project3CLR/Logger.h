#pragma once

#include <thread>
#include <iostream> 
#include <fstream>

using namespace std;

#define LOG_ALL 4
#define LOG_ERROR 3
#define LOG_WARNING 2
#define LOG_INFO 1
#define LOG_NONE 0

class Logger {
private:
    const int MAX_LOG_LEVEL = 4;
    static int log_level;

public:
    // Default constructor
    Logger();

    static void Logger::printLog(System::String^ data, int);
    static void setLogLevel(int level);
};

