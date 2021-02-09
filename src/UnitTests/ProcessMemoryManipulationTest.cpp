#include "pch.h"
#include "CppUnitTest.h"
#include "ProcessMemoryManipulator.h"
#include "ProcessHelper.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	//these test can probably be ignored if they faile and you did not made any changes to the ProcessMemoryManipulator class.
	//It needs a running instance of a process, thats specified in the test and actually reads memory of another process.
	TEST_CLASS(ProcessMemoryManipulatorTest)
	{
	public:
		TEST_METHOD(ReadBufferFromRemoteProcess)
		{
			//is dos header magic number 
			Util::byte excpectedData[4] = { 0x4d, 0x5a, 0x90, 0x00 };
			Util::byte writeIntoBuffer[4] = { };
			//the test need to have firefox running. But you can enter every other process name too.
			//the kernel32 dll is going to be loaded at the same address as in the current process anyway
			std::wstring remoteProcessName = L"firefox.exe";

			int pid = Util::GetPidForProcessName(remoteProcessName);
			HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
			auto lastError = GetLastError();
			HANDLE k32HandleAddress = GetModuleHandle(L"kernel32.dll");
			ProcessMemoryManipulator sut(processHandle);
			sut.ReadBuffer((Util::byte*)k32HandleAddress, writeIntoBuffer, sizeof(excpectedData));

			int counter = 0;
			Assert::AreEqual(excpectedData[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(excpectedData[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(excpectedData[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(excpectedData[counter], writeIntoBuffer[counter]);

			CloseHandle(processHandle);
		}
	};
}
