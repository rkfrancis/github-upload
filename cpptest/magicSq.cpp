#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    vector<int>::size_type i, j, k;
    int magic_sq[8][3][3] = {
        { { 4, 3, 8 }, { 9, 5, 1 }, { 2, 7, 6 } },
        { { 8, 3, 4 }, { 1, 5, 9 }, { 6, 7, 2 } },
        { { 2, 9, 4 }, { 7, 5, 3 }, { 6, 1, 8 } },
        { { 4, 9, 2 }, { 3, 5, 7 }, { 8, 1, 6 } },
        { { 6, 7, 2 }, { 1, 5, 9 }, { 8, 3, 4 } },
        { { 2, 7, 6 }, { 9, 5, 1 }, { 4, 3, 8 } },
        { { 8, 1, 6 }, { 3, 5, 7 }, { 4, 9, 2 } },
        { { 6, 1, 8 }, { 7, 5, 3 }, { 2, 9, 4 } }
    };
    int minimalCost = 81; //9*(1 to 9=9)
    int cost;
    for (i = 0; i < 8; ++i) {
        cost = 0;
        for (j = 0; j < 3; ++j)
            for (k = 0; k < 3; ++k)
                cost += (s[j][k] < magic_sq[i][j][k] ? magic_sq[i][j][k] - s[j][k] :
                    s[j][k] - magic_sq[i][j][k]);
        if (cost < minimalCost)
            minimalCost = cost;
    }
    return (minimalCost);
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


    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
