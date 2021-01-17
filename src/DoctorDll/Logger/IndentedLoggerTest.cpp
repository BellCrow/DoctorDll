#include "Types.h"
#include "IIndentedLogger.h"
#include "IndentationToken.h"
#include "IndentedLogger.h"
#include <memory>
#include "IndentedLoggerTest.h"

namespace Logger
{
	void TestLogger()
	{
		Util::sp<IIndentedLogger> logger = std::make_shared<IndentedConsoleLogger>();
		logger->Info("Test");
		{
			auto token = logger->RaiseIndentation();
			logger->Info("IndentedInfo1");
			{
				auto token = logger->RaiseIndentation();
				logger->Info("IndentedInfo2");
				{
					auto token = logger->RaiseIndentation();
					logger->Info("IndentedInfo3");
				}
				logger->Info("IndentedInfo2-2");
			}
			logger->Info("IndentedInfo1-2");
		}
		logger->Info("Test");
	}
}