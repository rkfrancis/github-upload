#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Complete the longestIncreasingSubsequence function below.
int longestIncreasingSubsequence(vector<int> arr) {
    //if empty
    //  append (create list)
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
//RF fix for compiler error C4996
//    ofstream fout(getenv("OUTPUT_PATH"));
    char *pValue;
    size_t pValueLen;
    errno_t err = _dupenv_s(&pValue, &pValueLen, "OUTPUT_PATH");
    if (err) return -1;
    ofstream fout(pValue);
    free(pValue);

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
