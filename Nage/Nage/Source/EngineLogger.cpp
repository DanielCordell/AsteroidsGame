#include "Includes/EngineLogger.h"

void EngineLogger::Log(std::string str) {
	std::cout << str << std::endl;
}
void EngineLogger::NewLine() { Log(""); }


void EngineLogger::Log(LogLevel log_level, std::string str) {
	std::cout << LogLevelMessages.at(log_level) << str << std::endl;
}

//Log - This is fine
//Error - This is Bad, but recoverable. Will affect gameplay
//Warning - This is Bad, but recoverable. Will not affect gameplay
//Fatal - ABORT ABORT ABORT

std::map<EngineLogger::LogLevel, std::string> EngineLogger::LogLevelMessages = {
	{ LOG_ERROR, "[Error] " },
	{ LOG_FATAL, "[FATAL] " },
	{ LOG_WARNING, "[Warning] " },
	{ LOG_INFO, "[Info] " }
};