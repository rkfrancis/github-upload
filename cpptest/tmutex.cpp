#include <iostream>
#include <thread>
#include <mutex>
#include <random>

using namespace std;

mutex g_mutex;     //global mutex used by both threads

									   //the objective of many threaded applications is to asynchronously operate on data sets
int main()
{
	default_random_engine eng;
	uniform_int<int> dist(0, 9);
	uniform_int<char> chardist{ 'a', 'z' };

	//1. First lambda expression outputs 80 random characters from 'a' to 'z'
	auto rand_char = [&]() {                 //lambda
		g_mutex.lock();
		for (int i = 0; i < 80; ++i) {
			cout << chardist(eng);
		}
		cout << endl;
		g_mutex.unlock();
	};
	//2. Second lambda expression outputs 80 random digits between 0 and 9
	auto rand_digit = [&]() {
		g_mutex.lock();
		for (int i = 0; i < 80; ++i) {
			cout << dist(eng);
		}
		cout << endl;
		g_mutex.unlock();
	};

	thread t1{ rand_char };
	thread t2{ rand_digit };

	t1.join();
	t2.join();
}
