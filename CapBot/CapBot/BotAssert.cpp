#include "BotAssert.h"
#include <iostream>

namespace Assert
{
	std::string lastErrorMessage;

	const std::string CurrentDateTime()
	{
		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);
		std::stringstream ss;
		ss << std:put_time(&tm, "%d-%,-%Y %H-%M-%S");
		return ss.str();
	}

	void ReportFailure(const char * condition, const char * file, int line, const char * msg, ...)
	{
		char messageBuffer[1024] = "";
		if (msg != nullptr)
		{
			va_list args;
			va_start(args, msg);
			vsnprintf(messageBuffer, 1024, msg, args);
			va_end(args);
		}
	}
}