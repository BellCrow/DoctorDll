#pragma once
#include "IMemoryManipulator.h"
#include "IPrimitivesManipulator.h"
#include "Types.h"

using namespace Util;

namespace MemoryManipulation {
	class PrimitivesManipulator:public IPrimitivesManipulator
	{
	public:
		PrimitivesManipulator(sp<IMemoryManipulator> memoryManipulator)	:_memoryManipulator(memoryManipulator){}
		
		// Inherited via IPrimitivesManipulator
		// read primitives
		virtual Util::byte ReadByte(Util::byte* readFrom) override;
		virtual short ReadShort(Util::byte* readFrom) override;
		virtual __int32 ReadInt32(Util::byte* readFrom) override;
		virtual __int64 ReadInt64(Util::byte* readFrom) override;
		virtual float ReadFloat(Util::byte* readFrom) override;
		virtual double ReadDouble(Util::byte* readFrom) override;
		virtual std::wstring ReadStringAscii(Util::byte* readFrom, int maxCharCount) override;
		virtual std::wstring ReadStringUnicode(Util::byte* readFrom, int maxCharCount) override;
		virtual void ReadStruct(Util::byte* readFrom, Util::byte* writeTo, int structSize) override;

		// write primitives
		virtual void WriteByte(Util::byte* writeTo, Util::byte data) override;
		virtual void WriteShort(Util::byte* writeTo, short data) override;
		virtual void WriteInt32(Util::byte* writeTo, __int32 data) override;
		virtual void WriteInt64(Util::byte* writeTo, __int64 data) override;
		virtual void WriteFloat(Util::byte* writeTo, float data) override;
		virtual void WriteDouble(Util::byte* writeTo, double data) override;
		virtual void WriteStringAsUnicode(Util::byte* writeTo, std::wstring data) override;
		virtual void WriteStringAsAscii(Util::byte* writeTo, std::wstring data) override;
		virtual void WriteStruct(Util::byte* writeTo, Util::byte* data, int structSize);

	private:
		sp<IMemoryManipulator> _memoryManipulator;

		
	};
}


