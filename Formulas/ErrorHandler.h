#pragma once



namespace fmls
{
	enum ErrorType
	{
		SYNTAX_ERROR = 0,
		MATH_ERROR,
		EXP_ERROR
	};

	class ErrorHandler
	{
	public:

		static void RaiseError(ErrorType type, const char* msg);
		static int GetErrors();

	private:
		static int errRaised;
	};
}