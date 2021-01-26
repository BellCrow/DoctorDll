#include "ProcessHelper.h"
#include <string>
#include <Windows.h>
#include <TlHelp32.h>

namespace Util {
	int GetPidForProcessName(const std::wstring& processName)
	{
		auto processEnumHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (processEnumHandle == INVALID_HANDLE_VALUE)
		{
			throw std::exception("Could not create snapshot for iteration");
		}

		PROCESSENTRY32 processInfo = {};
		processInfo.dwSize = sizeof(PROCESSENTRY32);
		if (!Process32First(processEnumHandle, &processInfo))
		{
			throw std::exception("Error iterating processes");
		}
		auto iteratedProcessName = std::wstring(processInfo.szExeFile);
		while (iteratedProcessName != processName && Process32Next(processEnumHandle, &processInfo))
		{
			iteratedProcessName = std::wstring(processInfo.szExeFile);
		}
		if (iteratedProcessName == processName)
		{
			return processInfo.th32ProcessID;
		}
		return -1;
	}
}