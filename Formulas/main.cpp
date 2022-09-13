#include <iostream>
#include <string>

#include "Tokenizer.h"





int main()
{
	// 2 + 3(1 - 2)
	//std::string expr = "2 + 3*(1 - 2)";
	std::string expr = "2 +      3*(   1 - 2)";

    //std::cout << "Enter the expression: ";
	//std::cin >> expr;
	
	using namespace fmls;

	//Tokenizer tok;
	//Tokenizer::ParseInput(expr);


	std::cin.get();
}
