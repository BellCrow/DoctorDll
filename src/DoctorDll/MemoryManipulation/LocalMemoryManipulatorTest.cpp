#include "LocalMemoryManipulatorTest.h"
#include "LocalMemoryManipulator.h"
#include "Types.h"

namespace MemoryManipulation
{
	void LocalMemoryManipulatorTest::ExecuteTest()
	{
		Util::byte readFromBuffer[20] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0x10 };
		Util::byte writeIntoBuffer[20] = { };
		
		LocalMemoryManipulator sut;
		sut.ReadBuffer(readFromBuffer, writeIntoBuffer, sizeof(readFromBuffer));

	}
}

