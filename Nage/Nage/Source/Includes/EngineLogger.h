#pragma once
#include <map>

class EngineLogger final{
public:
	enum LogLevel {
		LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_FATAL
	};

	static void Log(std::string str);
	static void NewLine();


	static void Log(LogLevel log_level, std::string str);
private:
	static std::map<LogLevel, std::string> LogLevelMessages;

};
