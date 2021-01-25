#include "ProcessMemoryManipulatorTest.h"
#include "ProcessMemoryManipulator.h"
#include "ProcessHelper.h"

#include <Windows.h>
#include <string>
namespace MemoryManipulation {
	void ProcessMemoryManipulatorTest::ExecuteTest()
	{
		//is dos header magic number 
		Util::byte excpectedData[4] = { 0x4d, 0x5a, 0x90, 0x00 };
		Util::byte writeIntoBuffer[4] = { };
		std::wstring remoteProcessName = L"firefox.exe";

		int pid = Util::GetPidForProcessName(remoteProcessName);
		HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		auto lastError = GetLastError();
		HANDLE k32HandleAddress = GetModuleHandle("kernel32.dll");
		ProcessMemoryManipulator sut(processHandle);
		sut.ReadBuffer((Util::byte*)k32HandleAddress, writeIntoBuffer, sizeof(excpectedData));

	}
}
