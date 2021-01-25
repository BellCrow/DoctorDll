#include "LocalMemoryManipulator.h"
#include <Windows.h>
#include <string>
using namespace MemoryManipulation;
using namespace Util;
namespace MemoryManipulation
{
	void LocalMemoryManipulator::ReadBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size)
	{
		CopyBuffer(readFromAddress, writeToAddress, size);
	}

	void LocalMemoryManipulator::WriteBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size)
	{
		CopyBuffer(readFromAddress, writeToAddress, size);
	}
	
	void LocalMemoryManipulator::CopyBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size)
	{
		if (int errorCode = memcpy_s(writeToAddress,size,readFromAddress,size))
		{
			throw std::exception((std::string("Error copying buffers memcpy_s error: ") + std::to_string(errorCode)).c_str());
		}
	}
}
