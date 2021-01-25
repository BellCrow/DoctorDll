#include "IIndentedLogger.h"
#include "IndentedLogger.h"
#include "IndentationToken.h"
#include "Types.h"
#include "IndentedLoggerTest.h"
#include "LocalMemoryManipulator.h"
#include "LocalMemoryManipulatorTest.h"
#include "ProcessMemoryManipulator.h"
#include "ProcessMemoryManipulatorTest.h"

using namespace Logger;

int main(int argc, char** argv)
{
	MemoryManipulation::ProcessMemoryManipulatorTest::ExecuteTest();
}