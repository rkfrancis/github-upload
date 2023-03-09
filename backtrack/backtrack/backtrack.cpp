// backtrack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define F first
#define S second
#define pb push_back 
#define all(v) v.begin(),v.end()
#define pii pair <int,int >
#define pll pair <ll,ll >
#define pld pair <long double,long double>
#define SET(arr,val) memset(arr,val,sizeof arr)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
using namespace std;
const int MAXN = 100005;
const int MOD = 1000000000 + 7;

bool getans(std::vector<int >& v, int n) {
	if (n == 0) {
		for (int i : v) {
			if (i == 0)
				return false;
		}
		return true;
	}
	for (int j = 0;j < v.size();j++) {
		if (j + 1 + n >= v.size()) {
			return false;
		}
		if (v[j] == 0 and v[j + 1 + n] == 0)
			v[j] = n, v[j + 1 + n] = n;
		else
			continue;
		bool to = getans(v, n - 1);
		if (to) {
			return true;
		}

		if (v[j] == n and v[j + 1 + n] == n)
			v[j] = 0, v[j + 1 + n] = 0;
		else
			continue;

	}
	return false;
}

int main()
{
	int n = 2;
	// si(n);
	std::vector<int > ans;
	for (int i = 0;i < ;2 * n;i++) {
		ans.pb(0);
	}
	bool yo = getans(ans, n);
	if (ans[0] == 0)
		cout << "-1";
	else
		for (int i : ans)
			cout << i;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
