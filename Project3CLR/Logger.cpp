#include "Logger.h"
#include "Utils.h"

#using<system.dll>

using namespace System;
using namespace System::IO;

Logger::Logger() {}

int Logger::log_level = 0;

void Logger::setLogLevel(int level) {
	log_level = level;
}

void Logger::printLog(String^ data, int log_level) {
	Utils util;	
	System::String^ fileName = "log_"+ util.getCurrentDate()+".log";
	System::String^ dirName = "logs";
	StreamWriter^ sw = nullptr;
	String^ writeData;

	switch (log_level) {
		case LOG_ALL:
			writeData = "LOG_ALL : " + data;
			break;
		case LOG_INFO:
			writeData = "LOG_INFO : " + data;
			break;
		case LOG_WARNING:
			writeData = "LOG_WARNING : " + data;
			break;
		case LOG_ERROR:
			writeData = "LOG_ERROR : " + data;
			break;
		case LOG_NONE:
			return;
		default:
			writeData = "LOG_ALL_DEFAULT : " + data;
			break;
	}	

	try
	{
		System::IO::Directory::CreateDirectory(dirName);
		System::IO::StreamWriter^ sw = System::IO::File::AppendText(dirName + "\\" + fileName);
		sw->WriteLine(writeData);
		sw->Close();
	}
	catch (Exception^)
	{
		Console::WriteLine("data could not be written");
		sw->Close();
	}
}