#pragma once
#include "IMemoryManipulator.h"
#include "Types.h"

namespace MemoryManipulation
{
	//can be used for debugging purposes, so you dont have to debug code injections with multiple processes
	class LocalMemoryManipulator : public IMemoryManipulator
	{
	public:
		//Ctor
		LocalMemoryManipulator(){}

		//dtor
		virtual ~LocalMemoryManipulator() {}

		//copy ctor
		LocalMemoryManipulator(const LocalMemoryManipulator& other) = delete;

		//move ctor
		LocalMemoryManipulator(const LocalMemoryManipulator&& other) = delete;

		//copy assignement
		LocalMemoryManipulator& operator= (const LocalMemoryManipulator& other) = delete;

		//move assignement
		LocalMemoryManipulator& operator= (const LocalMemoryManipulator&& other) = delete;

		// Inherited via IMemoryManipulator
		virtual void ReadBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size) override;
		virtual void WriteBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size) override;
	private:

		void CopyBuffer(Util::byte* readFromAddress, Util::byte* writeToAddress, __int64 size);
		
	};
}