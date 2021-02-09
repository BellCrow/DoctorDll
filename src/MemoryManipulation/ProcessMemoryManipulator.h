#pragma once
#include <Windows.h>
#include "IMemoryManipulator.h"

class ProcessMemoryManipulator:public MemoryManipulation::IMemoryManipulator
{
public:
	//Ctor
	ProcessMemoryManipulator(int processPid){
		_processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processPid);
	}
	ProcessMemoryManipulator(HANDLE processHandle){
		_processHandle = processHandle;
	}
	
	//dtor
	virtual ~ProcessMemoryManipulator() {
		CloseHandle(_processHandle);
	}
	
	//copy ctor
	ProcessMemoryManipulator(const ProcessMemoryManipulator& other) = delete;
		
	//move ctor
	ProcessMemoryManipulator(const ProcessMemoryManipulator&& other) = delete;
	
	//copy assignement
	ProcessMemoryManipulator& operator= (const ProcessMemoryManipulator& other) = delete;
	
	//move assignement
	ProcessMemoryManipulator& operator= (const ProcessMemoryManipulator&& other) = delete;

	// Inherited via IMemoryManipulator
	virtual void ReadBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size) override;

	virtual void WriteBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size) override;

private:
	HANDLE _processHandle;
	

	

};

