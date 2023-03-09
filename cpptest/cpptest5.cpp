//#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <utility>
#include <string>
#include <functional>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the iterateIt function below.
 */
int iterateIt(vector<int> a) {
    /*
rep := 0
while A not empty:
    B := []
    for x in A, y in A:
        if x != y: append absolute_value(x - y) to B
    A := B
    rep := rep + 1
    */
    int rep = 0;
    vector<int> b;
    while (!a.empty()) {
        sort(a.begin(), a.end());
        b.clear();
        //        for (auto v : a)
        //            cout << v << ' ';
        //        cout << endl;
        for (auto x = a.begin(); x != a.end(); ++x) {
            for (auto y = a.begin(); y != a.end(); ++y) {
                if (x != y && *x != *y)
                    b.push_back(abs(*x - *y));
            }
        }
        a = b;
//        for (auto v : a)
//            cout << v << ' ';
//        cout << endl;
//        if (rep == numeric_limits<int>::max()) {
//            rep = -1;
//            break;
//        }
        ++rep;
    }
    return (rep);
}

int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    int result = iterateIt(a);

//    fout << result << "\n";

//    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
