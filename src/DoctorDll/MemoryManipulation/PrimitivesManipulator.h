#pragma once
#include "IMemoryManipulator.h"
#include "Types.h"


using namespace Util;

namespace MemoryManipulation {
	class PrimitivesManipulator
	{
	public:
		PrimitivesManipulator(sp<IMemoryManipulator> memoryManipulator)	:_memoryManipulator(memoryManipulator){}
		
	private:
		sp<IMemoryManipulator> _memoryManipulator;
	};
}


