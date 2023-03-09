#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
//basically this is find the number of letters that appear in every string
    string::size_type i, arr_size = arr.size();
    vector<string::size_type> count(26);
    for (i = 0; i < arr_size; ++i) {
                   //remove duplicates
        string s = arr[i];
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        string::size_type j, str_size = s.size();
        for (j = 0; j < str_size; ++j) {
            count[s[j] - 'a']++;
        }
    }
    int counter = 0;
    for (i = 0; i < 26; ++i) {
        if (count[i] == arr_size)
            ++counter;
    }
    return (counter);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
