#include "ProcessMemoryManipulator.h"
#include <Windows.h>
#include <string>

using namespace Util;
void ProcessMemoryManipulator::ReadBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size)
{
	SIZE_T readBytes = 0;
	if (ReadProcessMemory(_processHandle, readFromAddress, writeToAddress, size, &readBytes) == 0 || readBytes != size)
	{
		auto lastError = GetLastError();
		throw std::exception((std::string("Error reading data from remote process: ") + std::to_string(lastError)).c_str());
	}
}

void ProcessMemoryManipulator::WriteBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size)
{
	SIZE_T writtenBytes = 0;
	if (WriteProcessMemory(_processHandle, writeToAddress, readFromAddress, size, &writtenBytes) == 0 || writtenBytes != size)
	{
		auto lastError = GetLastError();
		throw std::exception((std::string("Error writing data to remote process: ") + std::to_string(lastError)).c_str());
	}
}
