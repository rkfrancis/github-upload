#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//basically this is: turn the string into a palindrome by going down only (lowercase ASCII only)
// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    string::size_type s_size = s.size();
    if (!s_size) return -1;
    string::size_type i, j;
    for (i = 0, j = s_size - 1; !(j < i); ++i, --j) {
        if (s[i] != s[j])
            break;
    }
    if (j < i) return -1;
    /* We know we have found a difference inside the string.
       So we have to determine which character to remove.
       So if everything matches after i we remove i.
       Therefore anything that doesn't match means we remove j. */
    string::size_type a, b;
    for (a = i + 1, b = j; a < b; ++a, --b) {
        if (s[a] != s[b]) {
    /*     [although this solution passed all of the tests it does not
            work in the case where there is NO SOLUTION... it will return j
            instead of -1]
            So to fix this I added the loop below to verify that j is the
            right index to return.
            For example with the data:
            1
            hgygsvlfcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcwflvsgygh
            with only the return below you get 44 and with my loop below you get 44
            but with this data:
            1
            hgygsvlfcwnswtuhmyaljkqlqjjqlakjlaymhutwsnwcwflvsgygh
            with only the return below you get 44 and with my loop below you get -1
            where my loop is the correct one where as you can see I replaced one of
            the q's with an 'a'. */
//            return (static_cast<int>(j));
            for (a = i, b = j - 1; a < b; ++a, --b) {
                if (s[a] != s[b])
                    return -1;
            }
            return (static_cast<int>(j));
        }
    }
    return (static_cast<int>(i));
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

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
