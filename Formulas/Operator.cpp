#include "Operator.h"

#include <iostream>



namespace fmls
{
	const std::map<int, std::string> Operator::_operators = {
			{ ADDITION,			"+"},
			{ SUBTRACTION,		"-"},
			{ MULTIPLICATION,	"*"},
			{ DIVISION,			"/"},
			{ MODULO,			"%"},
			{ EXP,				"^"},
			{ S_ROOT,			"sq"},
			{ LOG_10,			"log"},
			{ LOG_NATURAL,		"ln"}
	};

	std::string Operator::GetSymbol(Operator::Type type)
	{
		return _operators.at(type);
	}
}
