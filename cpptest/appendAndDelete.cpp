#include <locale>
#include <codecvt>
//#include <string>

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
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */
//Make s look like t by deleting characters from the end and adding characters.
//Characters deleted and added must be equal to k.
//If you delete all characters you can continue to delete and still get an empty string.
string appendAndDelete(string s, string t, int k) {
    string::size_type i, delo, addo, s_size = s.size(), t_size = t.size();
    string::size_type min_str = min(s_size, t_size);
    for (i = 0; i < min_str; ++i) {
        if (s[i] != t[i]) {
            break;
        }
    }

    delo = s_size - i; //delo is number of delete operations
    addo = t_size - i; //addo is number of add operations

    if (k < (s_size + i + addo)) {
        if ((k < (delo + addo)) || (((k - (delo + addo)) % 2) == 1))
            return ("No"s);
    }
    return ("Yes"s);
    //k 1<21,1<9,No
    //k 9<21,9<9,0%2,Yes
    //k 10<21,10<9,1%2,No
    //k 11<21,11<9,0%2,Yes
    //k 20<21,20<9,1%2,No
    //k 21<21,Yes
    //hackerhappy 5
    //hackerrank 4
    //i 6
    //9
    //k 1<6,1<0,1%2,No
    //k 2<6,2<0,2%2,Yes
    //k 5<6,5<0,1%2,No
    //k 6<6,Yes
    //aba 0
    //aba 0
    //i 3
    //7
    //k 1<9,1<3,No
    //k 2<9,2<3,No
    //k 3<9,3<3,0%2,Yes
    //k 4<9,4<3,1%2,No
    //k 5<9,5<3,0%2,Yes
    //k 8<9,8<3,0%2,No
    //k 9<9,Yes
    //ashley 3
    //ash 0
    //i 3
    //2
}

int main()
{
//RF fix for compiler error C4996
//    ofstream fout(getenv("OUTPUT_PATH"));
    char* pValue;
    size_t pValueLen;
    errno_t err = _dupenv_s(&pValue, &pValueLen, "OUTPUT_PATH");
    if (err) return -1;
    //ofstream fout(pValue);
    free(pValue);

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);
    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);
    //fout << result << "\n";
    //fout.close();
    cout << result << '\n';

    const char *narrow_utf8_source_string { "\xE3\x81\x8A\xE3\x81\xAF\xE3\x82\x88\xE3\x81\x86" };
    const wchar_t *wide_utf16_source_string { L"\x304A\x306F\x3088\x3046" };    // "おはよう"
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::string narrow = converter.to_bytes(wide_utf16_source_string);   // wide to narrow
    std::wstring wide = converter.from_bytes(narrow_utf8_source_string); // narrow to wide

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

//Windows pre C++11
//#include <stdexcept>
//#include <vector>
//#include <windows.h>
//
//using std::runtime_error;
//using std::string;
//using std::vector;
//using std::wstring;
/*
wstring utf8toUtf16(const string& str)
{
    if (str.empty())
        return wstring();

    size_t charsNeeded = ::MultiByteToWideChar(CP_UTF8, 0,
        str.data(), (int)str.size(), NULL, 0);
    if (charsNeeded == 0)
        throw runtime_error("Failed converting UTF-8 string to UTF-16");

    vector<wchar_t> buffer(charsNeeded);
    int charsConverted = ::MultiByteToWideChar(CP_UTF8, 0,
        str.data(), (int)str.size(), &buffer[0], buffer.size());
    if (charsConverted == 0)
        throw runtime_error("Failed converting UTF-8 string to UTF-16");

    return wstring(&buffer[0], charsConverted);
}
*/
