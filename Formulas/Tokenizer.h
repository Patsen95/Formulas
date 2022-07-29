#pragma once

#include <string>
#include <vector>

#include "Token.h"


namespace fmls
{
//#define endl (std::endl)
//#define print(x) (std::cout << x)


	class Tokenizer
	{
	public:
		Tokenizer();

		static void ParseInput(std::string input);
		static std::vector<Token> Tokenize();

	private:
		std::vector<Token> *tokens;


	};
}
