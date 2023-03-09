#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//basically this is: turn the string into a palindrome by going down only (lowercase ASCII only)
// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) {
    int operations = 0;
    string wk {s};
    reverse(wk.begin(), wk.end());
    if (s != wk) {
        string bk;
        string::size_type s_len = s.size();
        wk = s.substr(0, s_len / 2);
        bk = s.substr(s_len/2 + s_len%2);
        reverse(wk.begin(), wk.end());
        string::size_type i, wk_size = wk.size();
        for (i = 0; i < wk_size; ++i) {
            if (bk[i] < wk[i]) {
                operations += (wk[i] - bk[i]);
            }
            else if (wk[i] < bk[i]) {
                operations += (bk[i] - wk[i]);
            }
        }
    }
    return (operations);
}

int main()
{
    //RF fix for compiler error C4996
    //    ofstream fout(getenv("OUTPUT_PATH"));
    char *pValue;
    size_t pValueLen;
    errno_t err = _dupenv_s(&pValue, &pValueLen, "OUTPUT_PATH");
    if (err) return -1;
    ofstream fout(pValue);
    free(pValue);

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = theLoveLetterMystery(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
