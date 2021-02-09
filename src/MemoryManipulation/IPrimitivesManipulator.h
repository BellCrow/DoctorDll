#pragma once
#include <string>
#include "Types.h"
namespace MemoryManipulation {

	// Abstracts the memory buffer manipulator to work on data types like ints or floats and geenric structures.
	class IPrimitivesManipulator
	{
		public:
		//read primitives
		virtual Util::byte ReadByte(Util::byte* readFrom) = 0;
		virtual short ReadShort(Util::byte* readFrom) = 0;
		virtual __int32 ReadInt32(Util::byte* readFrom) = 0;
		virtual __int64 ReadInt64(Util::byte* readFrom) = 0;
		virtual float ReadFloat(Util::byte* readFrom) = 0;
		virtual double ReadDouble(Util::byte* readFrom) = 0;
		virtual std::wstring ReadStringAscii(Util::byte* readFrom, int maxCharCount) = 0;
		virtual std::wstring ReadStringUnicode(Util::byte* readFrom, int maxCharCount) = 0;
		virtual void ReadStruct(Util::byte* readFrom, Util::byte* writeTo, int structSize) = 0;

		//write primitive
		virtual void WriteByte(Util::byte* writeTo, Util::byte data) = 0;
		virtual void WriteShort(Util::byte* writeTo, short data) = 0;
		virtual void WriteInt32(Util::byte* writeTo, __int32 data) = 0;
		virtual void WriteInt64(Util::byte* writeTo, __int64 data) = 0;
		virtual void WriteFloat(Util::byte* writeTo, float data) = 0;
		virtual void WriteDouble(Util::byte* writeTo, double data) = 0;
		virtual void WriteStringAsUnicode(Util::byte* writeTo, std::wstring data) = 0;
		virtual void WriteStringAsAscii(Util::byte* writeTo, std::wstring data) = 0;
		virtual void WriteStruct(Util::byte* writeTo, Util::byte* data, int structSize) = 0;
	};
}
