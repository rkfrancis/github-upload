#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//limit 1 to 32 digits (limit for unsigned long long is 17-digits)
//1234
//91011
//99100
//101103
//010203
//13
//1

//Sets of digits have to increment, no zero begin. Print YES <smallest> or NO.
//YES 1
//YES 9
//YES 99
//NO
//NO
//NO
//NO

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    if (s.substr(0, 1) == string("0")) {
        cout << "NO" << endl;
        return;
    }
    string::size_type i, j, k, m, n, si, s_size = s.size();
    string wk, wk2;
    unsigned long long num, num2, smallestFirst = 0;
    for (n = 0; n < s_size / 2; ++n) {
        k = n + 1;
        for (i = 0; i < s_size;) {
            j = k;
            wk = s.substr(i, j);
            num = stoull(wk);
            if (!i)
                smallestFirst = num;
            i += j;
            si = i;
            ++num;

            wk2 = to_string(num);
            m = wk2.size();
            wk = s.substr(si, m);
            si += m;
            num2 = stoull(wk);
            if (num != num2)
                break;
            if (si >= s_size) { //should never be >
                cout << "YES" << ' ' << smallestFirst << endl;
                return;
            }
            if (k < m)
                k = m;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }
}
