#pragma once
#include "IIndentedLogger.h"
#include <string>

namespace Logger {

	class IndentedConsoleLogger : public IIndentedLogger
	{
	public:
		//Ctor
		IndentedConsoleLogger() :_indentationLevel(0) {}

		//dtor
		virtual ~IndentedConsoleLogger() {}

		//copy ctor
		IndentedConsoleLogger(const IndentedConsoleLogger& other) = delete;

		//move ctor
		IndentedConsoleLogger(const IndentedConsoleLogger&& other) = delete;

		//copy assignement
		IndentedConsoleLogger& operator= (const IndentedConsoleLogger& other) = delete;

		//move assignement
		IndentedConsoleLogger& operator= (const IndentedConsoleLogger&& other) = delete;

		// Inherited via IIndentedLogger
		virtual Util::sp<IndentationToken> RaiseIndentation() override;
		virtual void LowerIndentation() override;
		virtual void Debug(std::string message) override;
		virtual void Info(std::string message) override;
		virtual void Warning(std::string message) override;
		virtual void Error(std::string message) override;

	private:
		const std::string PaddingString = "   ";
		int _indentationLevel;

		static void TokenDestroyCallback(void* callbackObject)
		{
			IndentedConsoleLogger* castObject = static_cast<IndentedConsoleLogger*>(callbackObject);
			castObject->LowerIndentation();
		}

		std::string CreatePaddingString();
	};

}