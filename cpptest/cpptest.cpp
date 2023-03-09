// cpptest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <type_traits>

#include <bits/stdc++.h>

using namespace std;

// Complete the longestIncreasingSubsequence function below.
int longestIncreasingSubsequence(vector<int> arr) {
//if empty
//  append
//else
//  for list; list exists and > end; go to next list;
//  if no list left
//    clone previous list and append
//  else if == to end
//    do nothing
//  else
//    delete list
//    close previous list and append
//
//    From the above we ONLY ever look at the endpoints.
    vector<int>::size_type i, j, arr_size = arr.size();
    vector<int> endpoint(arr_size);
    for (i = 0; i < arr_size; ++i) {
        for (j = 0; 0 < endpoint[j] && endpoint[j] < arr[i]; ++j)
            ;
        if (!endpoint[j] || endpoint[j] != arr[i])
            endpoint[j] = arr[i];
    }
    for (i = 0; i < arr_size && endpoint[i] != 0; ++i)
        ;
    int rc = i;
    return (rc);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = longestIncreasingSubsequence(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
