#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
 //1 1 2 2 4 4 5 5 5 [4,4,5,5,5]
 //4,4,4,4,5,5,5,5,5

 //4 6 5 3 3 1  [4,3,3]
 //3,2,2,2,2,1

 //1 2 2 3 1 2  [1,2,2,1,2]
 //1,5,5,4,2,5

int pickingNumbers(vector<int> a) {
    //The algorithm that seems to work on the samples (above)
    //where I'm making a total guess and it took me forever
    //is for each digit, scan the array for a count of numbers
    //that is equal to or one (1) less than the digit
    //and get the maximum of this count for all digits
    //and return that.
    //Note that the samples except the first DO NOT include any "subarray"!!!
    //Also there was no absolute value involved!!!
    vector<int>::size_type i, j, a_size = a.size();
    int maxDiffs = 0;
    int m;
    for (i = 0; i < a_size; ++i)
    {
        m = 0;
        for (j = 0; j < a_size; ++j)
            if (a[i] - a[j] == 1 || a[i] - a[j] == 0)
                ++m;
        if (maxDiffs < m)
            maxDiffs = m;
    }
    return (maxDiffs);
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

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

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
