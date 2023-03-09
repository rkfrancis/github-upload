#include <iostream>
#include <functional>        // bind and placeholders
#include <cmath>

using namespace std;
//using namespace placeholders;                 // if you uncomment then you can use _1 instead of placeholders::_1

/*
Bind is a function adapter that lets us partially evaluate a function.
*/

//compute the log of x to base b
double logx(int b, double x) { return (log(x) / log(b)); }

int main()
{
	//1 (a). Using bind.
				   //Bind returns a function object which we will let the compiler deduce using auto
	auto logx2 = bind(logx, 2, placeholders::_1); //< ------------------------ - bind on logx()
               //< ------------placeholders::_1 means we want the first argument of the function to be 2nd of logx()
	cout << logx2(16.0) << endl;

	//1 (b). Using a lambda expression.
	auto g = [](double x) { return logx(2, x); };
	cout << g(16.0) << endl;

	//2.
	auto logb100 = bind(logx, placeholders::_1, 100.0);
	cout << "log of 100 with variable base: \n";
	for (int i = 2; i <= 10; ++i)
		cout << "log of 100 to base " << i << " is " << logb100(i) << endl;
}
