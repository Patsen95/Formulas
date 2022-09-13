#include "ErrorHandler.h"
#include "Utils.h"


namespace fmls
{
	int ErrorHandler::errRaised = 0;


	void ErrorHandler::RaiseError(ErrorType type, const char* msg)
	{
		switch(type)
		{
			case ErrorType::SYNTAX_ERROR:
				PRINTLN("[SYNTAX ERROR] " << msg);
				break;

			case ErrorType::MATH_ERROR:
				PRINTLN("[MATH ERROR] " << msg);
				break;
		}
		errRaised++;
	}

	int ErrorHandler::GetErrors()
	{
		return errRaised;
	}
}