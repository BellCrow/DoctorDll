#pragma once
#include "Types.h"

namespace Util
{
	class AddressUtils
	{

	public:
		static void* ResolveRva(void* baseAddress, AddressOffset offset)
		{
			return static_cast<void*>(static_cast<char*>(baseAddress) + offset);
		}

		static void* AddOffsetToPtr(void* ptr, int offset)
		{
			return (void*)(((char*)ptr) + offset);
		}
	}
};