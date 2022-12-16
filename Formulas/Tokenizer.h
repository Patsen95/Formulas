#pragma once

#include <string>
#include <vector>

#include "Utils.h"
#include "ErrorHandler.h"


namespace fmls
{
	enum TokenType
	{
		NONE = 0,
		NUMBER,
		OPERATOR,
	};

	template<typename T>
	class Token
	{
	public:

		Token(const T& t_val, TokenType t_type) :
			t_value(t_val), t_type(t_type)
		{ }

	private:

		T t_value;
		TokenType t_type;
	};



	class Tokenizer
	{
	public:

		static void ParseInput(std::string& input);
		

	private:


	};
}
