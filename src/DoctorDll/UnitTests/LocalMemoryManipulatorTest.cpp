#include "pch.h"
#include "CppUnitTest.h"
#include "LocalMemoryManipulator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(LocalMemoryManipulatorTest)
	{
	public:
		TEST_METHOD(ReadBufferFromStack)
		{
			Util::byte readFromBuffer[10] = { 0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0x10 };
			Util::byte writeIntoBuffer[10] = { };

			MemoryManipulation::LocalMemoryManipulator sut;
			sut.ReadBuffer(readFromBuffer, writeIntoBuffer, sizeof(readFromBuffer));

			int counter = 0;
			Assert::AreEqual(readFromBuffer[counter], writeIntoBuffer[counter]);
			counter++;
			
			Assert::AreEqual(readFromBuffer[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(readFromBuffer[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(readFromBuffer[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(readFromBuffer[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(readFromBuffer[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(readFromBuffer[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(readFromBuffer[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(readFromBuffer[counter], writeIntoBuffer[counter]);
			counter++;

			Assert::AreEqual(readFromBuffer[counter], writeIntoBuffer[counter]);
			counter++;
		}
	};
}
