#include <iostream>
#include <map>
#include <functional>
#include <utility>
#include <cmath>


double Plus(double a, double b)
{
	return a + b;
}

class A
{
public:

	double Who(double a, double b)
	{
		return (a >= b) ? a : b;
	};
};

class MyFunc
{
public:
	double operator()(double a, double b)
	{
		return a * b;
	};
};

double Procent(double a, double b)
{
	double result = (a / b) - static_cast<int>(a / b);
	return result;
}

int main()
{
	/*double(*a)(double a, double b)*/
	

	std::minus<double> myminus;
	std::map<char, std::function<double(double, double)>> mycalc{ {'+', Plus},
																		{'-', myminus}, 
																			{'*', MyFunc()},
																				{'/', [](double a, double b) {return a / b; } }, 
																					{'^', static_cast<double(*)(double, double)>(pow)},
																						{'%', std::bind(Procent, std::placeholders::_1, std::placeholders::_2) },
																							{'?', std::bind(&A::Who, A(), std::placeholders::_1, std::placeholders::_2)}
																};
	double a = 2.2;
	double b = 3.2;
	
	try
	{
		double result = mycalc.at('+')(a, b);
		std::cout << result << std::endl;

		double result2 = mycalc.at('-')(b, a);
		std::cout << result2 << std::endl;

		double result3 = mycalc.at('*')(a, b);
		std::cout << result3 << std::endl;

		double result4 = mycalc.at('/')(a, b);
		std::cout << result4 << std::endl;

		double result5 = mycalc.at('^')(a, b);
		std::cout << result5 << std::endl;

		double result6 = mycalc.at('%')(7.0, 5.0);
		std::cout << result6 << std::endl;

		double result7 = mycalc.at('?')(7.0, 5.0);
		std::cout << result7 << std::endl;
	}
	catch (...)
	{

	}

	system("pause");
}