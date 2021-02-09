#include "PrimitivesManipulator.h"

namespace MemoryManipulation {
    Util::byte PrimitivesManipulator::ReadByte(Util::byte* readFrom)
    {
        Util::byte readData = 0;
        _memoryManipulator->ReadBuffer(readFrom, &readData, sizeof(Util::byte));
        return readData;
    }
    short PrimitivesManipulator::ReadShort(Util::byte* readFrom)
    {
        short readData = 0;
        _memoryManipulator->ReadBuffer(readFrom, reinterpret_cast<Util::byte*>(&readData), sizeof(short));
        return readData;
    }
    __int32 PrimitivesManipulator::ReadInt32(Util::byte* readFrom)
    {
        __int32 readData = 0;
        _memoryManipulator->ReadBuffer(readFrom, reinterpret_cast<Util::byte*>(&readData), sizeof(__int32));
        return readData;
    }
    __int64 PrimitivesManipulator::ReadInt64(Util::byte* readFrom)
    {
        __int64 readData = 0;
        _memoryManipulator->ReadBuffer(readFrom, reinterpret_cast<Util::byte*>(&readData), sizeof(__int64));
        return readData;
    }
    float PrimitivesManipulator::ReadFloat(Util::byte* readFrom)
    {
        float readData = 0;
        _memoryManipulator->ReadBuffer(readFrom, reinterpret_cast<Util::byte*>(&readData), sizeof(float));
        return readData;
    }
    double PrimitivesManipulator::ReadDouble(Util::byte* readFrom)
    {
        double readData = 0;
        _memoryManipulator->ReadBuffer(readFrom, reinterpret_cast<Util::byte*>(&readData), sizeof(double));
        return readData;
    }
    std::wstring PrimitivesManipulator::ReadStringAscii(Util::byte* readFrom, int maxCharCount)
    {
        std::string readAsciiString = "";
        char* readStringData = new char[maxCharCount];
        ReadStruct(readFrom, reinterpret_cast<Util::byte*>(readStringData), maxCharCount);
        char* stringReadpointer = reinterpret_cast<char*>(readStringData);
        int readOffset = 0;
        do
        {
            char readChar = *(reinterpret_cast<char*>(readStringData + readOffset));
            if (readChar == 0)
            {
                break;
            }
            readOffset += sizeof(char);
            readAsciiString += readChar;
        } while (readOffset < maxCharCount);

        //converting ascii to unicode string
        std::wstring ret(readAsciiString.begin(), readAsciiString.end());
        
        delete[] readStringData;
        return ret;
    }
    std::wstring PrimitivesManipulator::ReadStringUnicode(Util::byte* readFrom, int maxCharCount)
    {
        std::wstring readAsciiString = L"";
        wchar_t* readStringData = new wchar_t[maxCharCount];
        ReadStruct(readFrom, reinterpret_cast<Util::byte*>(readStringData), maxCharCount);

        wchar_t* stringReadpointer = reinterpret_cast<wchar_t*>(readStringData);
        int readOffset = 0;
        do
        {
            wchar_t readChar = *(reinterpret_cast<wchar_t*>(stringReadpointer + readOffset));
            if (readChar == 0)
            {
                break;
            }
            readOffset++;
            readAsciiString += readChar;
        } while (readOffset < maxCharCount);

        delete[] readStringData;
        return readAsciiString;
    }
    void PrimitivesManipulator::ReadStruct(Util::byte* readFrom, Util::byte* writeTo, int structSize)
    {
        _memoryManipulator->ReadBuffer(readFrom, writeTo, structSize);
    }


    void PrimitivesManipulator::WriteByte(Util::byte* writeTo, Util::byte data)
    {
        _memoryManipulator->WriteBuffer(&data, writeTo, sizeof(byte));
    }
    void PrimitivesManipulator::WriteShort(Util::byte* writeTo, short data)
    {
        _memoryManipulator->WriteBuffer(reinterpret_cast<Util::byte*>(&data), writeTo, sizeof(short ));
    }
    void PrimitivesManipulator::WriteInt32(Util::byte* writeTo, __int32 data)
    {
        _memoryManipulator->WriteBuffer(reinterpret_cast<Util::byte*>(&data), writeTo, sizeof(__int32 ));
    }
    void PrimitivesManipulator::WriteInt64(Util::byte* writeTo, __int64 data)
    {
        _memoryManipulator->WriteBuffer(reinterpret_cast<Util::byte*>(&data), writeTo, sizeof(__int64 ));
    }
    void PrimitivesManipulator::WriteFloat(Util::byte* writeTo, float data)
    {
        _memoryManipulator->WriteBuffer(reinterpret_cast<Util::byte*>(&data), writeTo, sizeof(float ));
    }
    void PrimitivesManipulator::WriteDouble(Util::byte* writeTo, double data)
    {
        _memoryManipulator->WriteBuffer(reinterpret_cast<Util::byte*>(&data), writeTo, sizeof(double ));
    }
    void PrimitivesManipulator::WriteStringAsUnicode(Util::byte* writeTo, std::wstring data)
    {
        int bytesToWrite = data.size();
        _memoryManipulator->WriteBuffer(const_cast<byte*>(reinterpret_cast<const byte*>(data.c_str())), writeTo, bytesToWrite);
        byte stringZeroTermination[sizeof(wchar_t)] = { 0,0 };
        _memoryManipulator->WriteBuffer(stringZeroTermination, writeTo, sizeof(stringZeroTermination));
    }
    void PrimitivesManipulator::WriteStringAsAscii(Util::byte* writeTo, std::wstring data)
    {
        //convert from unicode to ascii
        std::string toWrite(data.begin(), data.end());
        int bytesToWrite = toWrite.size();
        _memoryManipulator->WriteBuffer(const_cast<byte*>(reinterpret_cast<const byte*>(toWrite.c_str())), writeTo, bytesToWrite);
        byte stringZeroTermination[sizeof(char)] = { 0 };
        _memoryManipulator->WriteBuffer(stringZeroTermination, writeTo, sizeof(stringZeroTermination));
    }
    void PrimitivesManipulator::WriteStruct(Util::byte* writeTo, Util::byte* data, int structSize)
    {
        _memoryManipulator->WriteBuffer(data, writeTo, structSize);
    }
}