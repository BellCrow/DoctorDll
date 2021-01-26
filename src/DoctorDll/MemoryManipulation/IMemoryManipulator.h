#pragma once
#include <vector>
#include "Types.h"
namespace MemoryManipulation {
	
	class IMemoryManipulator {
	public:
		//Reads from the remote memory at the given address and saves the data into a given local buffer
		virtual void ReadBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size) = 0;
		//Reads from a given local buffer and writes the data in the remote memory at the given address
		virtual void WriteBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size) = 0;
	};
}