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
vector<string> split(const string&);

// Complete the superReducedString function below.
string superReducedString(string s) {
    //reduce strings like 'baab' to 'Empty String'
    //by repeatedly removing doubled letters
    string::size_type i, s_size;
    string a{ s };
    string b, c, z;
    do {
        z = a;
        s_size = a.size();
        for (i = 0; i < s_size - 1; ++i) {
            if (a[i] == a[i + 1]) {
                b = a.substr(0, i);
                c = a.substr(i + 2);
                a = b + c;
                break;
            }
        }
    } while (z != a && !a.empty());
    if (a.empty())
        return ("Empty String"s);
    return (a);
}

int main()
{
//RF fix for compiler error C4996
//    ofstream fout(getenv("OUTPUT_PATH"));
    char* pValue;
    size_t pValueLen;
    errno_t err = _dupenv_s(&pValue, &pValueLen, "OUTPUT_PATH");
    if (err) return -1;
    ofstream fout(pValue);
    free(pValue);

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

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

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
