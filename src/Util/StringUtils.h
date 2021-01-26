#pragma once
#include <string>
#include <algorithm>

class StringUtil
{
public:
	static std::string ToLower(const std::string& str)
	{
		auto localStringCopy = str;
		std::transform(localStringCopy.begin(), localStringCopy.end(), localStringCopy.begin(), [](unsigned char c) {return std::tolower(c); });
		return std::move(localStringCopy);
	}

	static std::string ReadWStringAsString(wchar_t* stringAddress, int size)
	{
		if (size < 0)
		{
			throw new std::exception("Cannot read strings with negative length");
		}
		if (size == 0)
		{
			return {};
		}

		wchar_t* stringReadPtr = stringAddress;
		int currentSize = size;
		std::wstring wideString;
		wchar_t readChar;
		do
		{
			readChar = *stringReadPtr;
			if (readChar == 0)
			{
				break;
			}
			wideString += readChar;
			stringReadPtr++;
		} while (--currentSize > 0);
				
		std::string convertedString(wideString.begin(), wideString.end());
		return convertedString;
	}
};