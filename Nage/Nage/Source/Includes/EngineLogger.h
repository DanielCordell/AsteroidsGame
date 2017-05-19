#pragma once

#include <string>
#include <map>
#include <iostream>
#include <functional>

class EngineLogger final{
public:
	enum LogLevel {
		LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_FATAL
	};

	static void Log(std::string str) {
		std::cout << str << std::endl;
	}
	static void NewLine() { Log(""); }


	static void Log(EngineLogger::LogLevel log_level, std::string str) {
		std::cout << EngineLogger::LogLevelMessages.at(log_level) << str << std::endl;
	}
private:
	static std::map<EngineLogger::LogLevel, std::string> LogLevelMessages;

};
std::map<EngineLogger::LogLevel, std::string> EngineLogger::LogLevelMessages = {
	{ EngineLogger::LogLevel::LOG_ERROR, "[Error] " },
	{ EngineLogger::LogLevel::LOG_FATAL, "[FATAL] " },
	{ EngineLogger::LogLevel::LOG_WARNING, "[Warning] " },
	{ EngineLogger::LogLevel::LOG_INFO, "[Info] " }
};