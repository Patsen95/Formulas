#include "Tokenizer.h"
#include "Operator.h"


#include <iostream>
#include <array>


namespace fmls
{
	static const std::array<const char*, 9> _ops = { "+", "-", "*", "/", "%", "^", "sq", "log", "ln" };


	bool IsDigit(const char& val)
	{
		if(val > 47 && val < 58)
			return true;
		return false;
	}



	//Tokenizer::Tokenizer() {}
	//Tokenizer::~Tokenizer() {}

	void Tokenizer::ParseInput(std::string& input)
	{
		PRINTLN(input);

		size_t _len = input.length();
				
		// Trim all white characters
		for(int i = 0; i < _len; i++)
		{
			while(input[i] == 32)
				input.erase(i, 1);
			_len = input.length(); // Update length
		}

		// SYNTAX ERROR CATCHING
		// Checking if input contains any of predefined operators

		int _par_cnt = 0;

		for(int i = 0; i < _len; i++)
		{
			// Count parenthesis
			if(input[i] == '(') _par_cnt++;
			if(input[i] == ')') _par_cnt--;

			// Operator without number next to it...
			if(((input[i] == *_ops[0] || input[i] == *_ops[1]) && !IsDigit(input[i + 1]))) // +, -
				ErrorHandler::RaiseError(ErrorType::SYNTAX_ERROR, "Operator without value.");

			// ...or behind it
			if(((input[i] == *_ops[2] || input[i] == *_ops[3] || input[i] == *_ops[4]) && // *, /, %
				(_len == 1 || !IsDigit(input[i - 1]))))
				ErrorHandler::RaiseError(ErrorType::SYNTAX_ERROR, "Operator without value.");

			if(((input[i] == *_ops[2] || input[i] == *_ops[3] || input[i] == *_ops[4]) && // *, /, %
				!IsDigit(input[i + 1])))
				ErrorHandler::RaiseError(ErrorType::SYNTAX_ERROR, "Operator without value.");
		}

		if(_par_cnt != 0)
		{
			ErrorHandler::RaiseError(ErrorType::SYNTAX_ERROR, "Some parenthesis are not complete");
			return;
		}
		
		PRINTLN(input);

		// Add multiplication sign, if needed
		for(int i = 0; i < _len; i++)
		{
			if((i + 1) < _len)
			{
				if((IsDigit(input[i]) && input[i + 1] == '(') ||
					(input[i] == ')' && IsDigit(input[i + 1])))
					input.insert(i + 1, "*");
			}
		}

		PRINTLN(input);

	}
}
