#include "IndentedLogger.h"
#include <iostream>
namespace Logger
{
	Util::sp<IndentationToken> IndentedConsoleLogger::RaiseIndentation()
	{
		_indentationLevel++;
		return std::make_shared<IndentationToken>(TokenDestroyCallback, this);
	}

	void IndentedConsoleLogger::LowerIndentation()
	{
		_indentationLevel--;
	}

	void IndentedConsoleLogger::Debug(std::string message)
	{
		std::cout << CreatePaddingString() << "Debug:" << message << std::endl;
	}

	void IndentedConsoleLogger::Info(std::string message)
	{
		std::cout << CreatePaddingString() << "Info:" << message << std::endl;
	}

	void IndentedConsoleLogger::Warning(std::string message)
	{
		std::cout << CreatePaddingString() << "Warning:" << message << std::endl;
	}

	void IndentedConsoleLogger::Error(std::string message)
	{
		std::cout << CreatePaddingString() << "Error:" << message << std::endl;
	}

	std::string IndentedConsoleLogger::CreatePaddingString()
	{
		std::string ret = "";
		for (size_t i = 0; i < _indentationLevel; i++)
		{
			ret += PaddingString;
		}
		return ret;
	}

}