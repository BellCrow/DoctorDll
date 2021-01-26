#pragma once
#include <string>
#include "Types.h"
namespace MemoryManipulation {

	// Abstracts the memory buffer manipulator to work on data types like ints or floats and geenric structures.
	class IPrimitivesManipulator
	{
		//read primitives
		Util::byte ReadByte();
		short ReadShort();
		__int32 ReadInt32();
		__int64 ReadInt64();
		float ReadFloat();
		double ReadDouble();
		std::wstring ReadString(int macCharCount);
		void ReadStruct(Util::byte* writeTo, int structSize);

		//write primitives
		Util::byte WriteByte(Util::byte );
		short WriteShort(short );
		__int32 WriteInt32(__int32 );
		__int64 WriteInt64(__int64 );
		float WriteFloat(float );
		double WriteDouble(double );
		std::wstring WriteString(std::wstring data);
		void WriteStruct(Util::byte* writeTo, int structSize);
	};
}
