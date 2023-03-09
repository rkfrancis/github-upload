#include <iostream>
#include <thread>
#include <string>

using namespace std;

//function returns using string *r
void func(string& s, string* r)
{
    *r = s + " from a function.";
}

//function object modifies string *r
struct func_object
{
    const string& s;
    string* r;
    func_object(const string& str, string* rstr) : s(str), r(rstr) {}
    void operator()() { //modify *r (the string)
        *r = s + " from a function object.";
    }
};

//the objective of many threaded applications is to asynchronously operate on data sets
int main()
{
    string s = "This is a string";  //thread argument
    string r1, r2, r3;              //return variables

    auto f = [](const string& s, string* r) mutable { //lambda expression
        *r = s + " from a lambda expression.";
    };

    thread t1{ func, std::ref(s), &r1 };
    thread t2{ func_object(s, &r2) };
    thread t3{ f, s, &r3 };

    t1.join();
    t2.join();
    t3.join();
}
