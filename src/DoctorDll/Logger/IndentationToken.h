#pragma once
#include "Types.h"
namespace Logger
{
	class IndentationToken
	{
	public:
		//Ctor
		IndentationToken(void (*dtorCallback)(void* object), void* callBackArgument) {
			if (dtorCallback == nullptr) {
				throw std::exception("Dtor callback for indentation token cannot be null");
			}
			_dtorCallback = dtorCallback;
			_callbackArgument = callBackArgument;
		}

		//dtor
		virtual ~IndentationToken() {
			_dtorCallback(_callbackArgument);
		}

		//copy ctor
		IndentationToken(const IndentationToken& other) = delete;

		//move ctor
		IndentationToken(const IndentationToken&& other) = delete;

		//copy assignement
		IndentationToken& operator= (const IndentationToken& other) = delete;

		//move assignement
		IndentationToken& operator= (const IndentationToken&& other) = delete;
	private:
		void (*_dtorCallback)(void* object);
		void* _callbackArgument;
	};

}