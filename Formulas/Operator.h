#pragma once

#include <string>
#include <map>



namespace fmls
{
	class Operator
	{
	public:

		static enum Type
		{
			ADDITION = 0,
			SUBTRACTION,
			MULTIPLICATION,
			DIVISION,
			MODULO,
			EXP,
			S_ROOT,
			LOG_10,
			LOG_NATURAL,
		};

		static std::string GetSymbol(Type type);

	private:
		static const std::map<int, std::string> _operators;

	};
}
