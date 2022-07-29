#pragma once

#include <string>


namespace fmls
{
	enum TokenType { INTEGER, FLOATING, OPERATOR };

	class Token
	{
	public:
		Token(std::string &val, TokenType type);

	private:
		TokenType type;
		std::string *value;
	};
}
