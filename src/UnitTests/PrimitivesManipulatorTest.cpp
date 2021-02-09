#include "pch.h"
#include "CppUnitTest.h"
#include "LocalMemoryManipulator.h"

#include "Types.h"
#include "PrimitivesManipulator.h"
#include "IPrimitivesManipulator.h"
#include "LocalMemoryManipulator.h"
#include "IMemoryManipulator.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(PrimitivesManipulatorTest)
	{
	private:
		//fields go here
		char* _testAsciiString = nullptr;
		char* _testUnicodeString = nullptr;
		Util::byte* _testBuffer = {};
		sp<MemoryManipulation::IMemoryManipulator> _memManipulator;
		sp<MemoryManipulation::IPrimitivesManipulator> _sut;
	public:
		TEST_METHOD_INITIALIZE(Init)
		{
			//setting up some testData
			_memManipulator = std::make_shared<MemoryManipulation::LocalMemoryManipulator>();
			_sut = std::make_shared<MemoryManipulation::PrimitivesManipulator>(_memManipulator);
			_testAsciiString = "MyTestAsciiString";
			_testUnicodeString = "MyTestUnicodeString";
			_testBuffer = new Util::byte[]{ 0,1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
		}
		
		TEST_METHOD_CLEANUP(CleanUp){
			delete[] _testBuffer;
		}

		TEST_METHOD(Readbyte)
		{
			auto readByte = _sut->ReadByte(&_testBuffer[20]);
			
			Assert::AreEqual(_testBuffer[20],readByte);
		}
	};
}