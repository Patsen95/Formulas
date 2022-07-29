#include "Tokenizer.h"
#include "Operator.h"


#include <iostream>
#include <cctype>



namespace fmls
{
	/// TODO: Think to use std::vector instead or create Operator class object and
	/// register all operators in it
	static const char *_ops[9] = { "+", "-", "*", "/", "%", "^", "sq", "log", "ln" };

	Tokenizer::Tokenizer() {}

	void Tokenizer::ParseInput(std::string input)
	{
		int len = input.length();
		for(int i = 0; i < len; i++)
		{
			// Trim all white characters
			while(input[i] == 32)
				input.erase(i, 1);

			// Add multiplication sign, if needed
			if((isdigit(input[i]) && input[i + 1] == '(') ||
				(input[i] == ')' && isdigit(input[i + 1])))
				input.insert(i + 1, "*");
			len = input.length(); // Update length
		}

		// ERROR CATCHING
		//for(int i = 0; i < len; i++)
		//{
		//	// Check for parenthesis...
		//	if((!(input[i] == '*' && input[i + 1] == '(') && !(input[i] == ')' && input[i + 1] == '*')) &&
		//		(!(input[i] == '/' && input[i + 1] == '(') && !(input[i] == ')' && input[i + 1] == '/')) &&
		//		(!(input[i] == '*' && input[i + 1] == '(') && !(input[i] == ')' && input[i + 1] == '*')) &&
		//		(!(input[i] == '*' && input[i + 1] == '(') && !(input[i] == ')' && input[i + 1] == '*')))
		//	{
		//		// Operator without number next to it...
		//		if(((input[i] == *_ops[0] || input[i] == *_ops[1]) && !isdigit(input[i + 1]))) // +, -
		//			print("[Syntax error] Operator \'" << input[i] << "\' without value.\n");

		//		// ...or behind it
		//		if(((input[i] == *_ops[2] || input[i] == *_ops[3] || input[i] == *_ops[4]) && // *, /, %
		//			(len == 1 || !isdigit(input[i - 1]))))
		//			print("[Syntax error] Operator \'" << input[i] << "\' without leftside value.\n");

		//		if(((input[i] == *_ops[2] || input[i] == *_ops[3] || input[i] == *_ops[4]) && // *, /, %
		//			!isdigit(input[i + 1])))
		//			print("[Syntax error] Operator \'" << input[i] << "\' without rightside value.\n");
		//	}
		//}
	}
}
