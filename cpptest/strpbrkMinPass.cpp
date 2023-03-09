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

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string numbers = "0123456789"s;
    string lower_case = "abcdefghijklmnopqrstuvwxyz"s;
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"s;
    string special_characters = "!@#$%^&*()-+"s;
    int minChars = 6;
    if (password.empty())
        return (minChars);
    minChars = 4;
    int password_size = static_cast<int>(password.size());
    if (strpbrk(password.c_str(), numbers.c_str()) != nullptr)
        --minChars;
    if (strpbrk(password.c_str(), lower_case.c_str()) != nullptr)
        --minChars;
    if (strpbrk(password.c_str(), upper_case.c_str()) != nullptr)
        --minChars;
    if (strpbrk(password.c_str(), special_characters.c_str()) != nullptr)
        --minChars;
    if (password_size + minChars >= 6) //if our final password will be at least 6 chars
        return (minChars);             //then we just need these minimum chars
                                       //otherwise our final password is too small
                                       //so we need to add a minimum number of any
                                       //character(s) plus our minimum chars
    return (minChars + (6 - (password_size + minChars)));
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

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
