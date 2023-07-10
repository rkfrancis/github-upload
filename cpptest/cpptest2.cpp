#include <iostream>
#include <thread>
#include <string>

using namespace std;

//passing a string to a function
void func(string& s)
{
	cout << s << ", hi from function\n";
}

//passing a string to a function object
struct func_object
{
	string& s;
	func_object(string& str) : s(str) {}
	void operator()() { cout << s << ", hi from function object\n"; }
};

//the objective of many threaded applications is to asynchronously operate on data sets
int main()
{
	string s{ "This is a string." };

	//lambda expression with string argument
	auto f = [](string& s) { cout << s << ", hi from lambda expression\n"; };


	thread t1{ func, std::ref(s) }; //function
	thread t2{ f, std::ref(s) };    //lambda expression
	thread t3{ func_object(s) };    //function object (ctor call here, then thread calls call operator

	t1.join();
	t2.join();
	t3.join();
}
