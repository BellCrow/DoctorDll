#pragma once

#include "IndentationToken.h"
#include <string>
#include "Types.h"

namespace Logger
{
	//Interface for the indented logger implementations
	class IIndentedLogger
	{
	public:
		//Raises the Indentation level by one. The returned token is to be lowering the level, if it is destroyed
		virtual Util::sp<IndentationToken> RaiseIndentation() = 0;
		//Lowers the indentation level by one. This is usually done by the indentation token and thus should not be done manually.
		virtual void LowerIndentation() = 0;

		//Outputs a debug message.
		virtual void Debug(std::string message) = 0;
		//Outputs an info message.
		virtual void Info(std::string message) = 0;
		//Outputs a warning message.
		virtual void Warning(std::string message) = 0;
		//Outputs an error message.
		virtual void Error(std::string message) = 0;
	};

}