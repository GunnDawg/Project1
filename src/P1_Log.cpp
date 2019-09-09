#include "P1_Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

void Logger::Init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");

	sCoreLogger = spdlog::stdout_color_mt("Log");
	sCoreLogger->set_level(spdlog::level::trace);

	sFileLogger = spdlog::basic_logger_mt("FileLog", "log.txt");
	sFileLogger->set_level(spdlog::level::trace);
}