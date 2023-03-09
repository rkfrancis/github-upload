#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

using ll = int64_t; //typedef int64_t ll;

const int base = static_cast<int>(1e9);
using BigInt = vector<int>;  //typedef vector<int> BigInt;

void TrimLeadingZeroes(BigInt& a)
{
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

void Print(BigInt a)
{
    TrimLeadingZeroes(a);
    BigInt::size_type a_size = a.size();
    printf("%d", (a_size == 0) ? 0 : a.back());
    if (!(a_size < 2)) {
        for (BigInt::size_type i = a_size - 2; i >= 0; --i) {
            printf("%09d", a[i]);
            if (!i)
                break;
        }
    }
    printf("%s", "\n");
}

BigInt operator*(BigInt a, BigInt b)
{
    TrimLeadingZeroes(a);
    TrimLeadingZeroes(b);
    BigInt ans;
    BigInt::size_type a_size = a.size();
    BigInt::size_type b_size = b.size();
    ans.assign(a_size + b_size, 0);
    for (int i = 0; i < a_size; ++i) {
        ll overflow = 0ll;
        for (int j = 0; j < b_size || 0 < overflow; ++j) {
//            Does multiplication on groupings of 9 (base).
//            The ans[i+j] is the previous overflow.
//            The overflow is put into the new last slot.
            ll s = ans[i+j] + overflow + (ll)a[i] * (j < b_size ? (ll)b[j] : 0ll);
            ans[i+j] = s % base;
            overflow = s / base;
        }
    }
    TrimLeadingZeroes(ans);
    return (ans);
}

void extraLongFactorials(int n)
{
    BigInt a {1};
    for (int i = 2; i <= n; ++i) {
        BigInt b {i};
        a = a * b;
    }
    Print(a);
}

int main()
{
//    BigInt a {408832000, 121645100}; //smaller to larger (19!)
//    BigInt b {20};
//    a = a * b;
//    Print(a); //2 432902008 176640000
    string n_temp;
    getline(cin, n_temp);
    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string& str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string& str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}
