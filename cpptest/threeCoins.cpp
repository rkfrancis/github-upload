#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

void printSums(vector<size_t> coins)
{
	bool b[1001] { false };
	b[0] = true;
	sort(coins.begin(), coins.end());
	vector<size_t>::size_type i,j, coins_size = coins.size();
	for (i = 0; i < coins_size; ++i) {
		for (j = coins[i]; j < sizeof(b)/sizeof(b[0]); ++j) {
			if (b[j - coins[i]]) {
				b[j] = true;
			}
		}
	}
	for (i = coins[0]; i < sizeof(b)/sizeof(b[0]); ++i) {
		if (b[i]) {
			cout << i << endl;
		}
	}
}

int main()
{
	//vector<size_t> arr {10, 15, 55};
	//printSums(arr);
	std::streamsize N = 3, j = 1;
	for (std::streamsize i = N; 0 < i; --i) {
		if (1 < i)
			cout << std::setfill(' ') << std::setw(i - 1) << ' ';
		cout << std::setfill('x') << std::setw(j) << 'x';
		j += 2;
		if (1 < i)
			cout << std::setfill(' ') << std::setw(i - 1) << ' ' << '\n';
	}
}
//  x
// xxx
//xxxxx