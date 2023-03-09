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

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data) : left(nullptr), right(nullptr) {
        this->data = data;
    }
};

void printInOrder(struct Node *node) {
    if (node == nullptr)
        return;
    printInOrder(node->left);
    cout << node->data << endl;
    printInOrder(node->right);
}

int run() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    printInOrder(root);
    return 0;
}

bool validAlternate(const string& inStr) {
    string::size_type i, inStr_size = inStr.size();
    if (!inStr_size || inStr_size == 1)
        return true;
    if (inStr_size == 2 && inStr[0] == inStr[1])
        return false;
    for (i = 0; i < inStr_size - 2; ++i) {
        if (inStr[i] != inStr[i + 2])
            return false;
    }
    return true;
}

// Complete the alternate function below.
int alternate(string s) {
    //This was NOT easy. You have to recognize that doing the INVERSE of
    //the REMOVAL of characters is the right way to go.  Otherwise you
    //will get stuck.
    //This means you have to build strings using a SET of characters, the
    //order of which is the original string order.
    //Also it is not clear whether a small string like "aa" or "a" or ""
    //is a valid string.
    //The output is not clear.  Do you really output "$0$"?
    string wk{ s };
    sort(wk.begin(), wk.end());
    wk.erase(unique(wk.begin(), wk.end()), wk.end());
    string::size_type max_len = 0, i, j, k, wk_size = wk.size(), s_size = s.size();
    string cpy;
    cpy.reserve(s_size);
    for (i = 0; i < wk_size; ++i) {
        for (j = i + 1; j < wk_size; ++j) {
            cpy.clear();
            for (k = 0; k < s_size; ++k) {
                if (s[k] == wk[i] || s[k] == wk[j])
                    cpy += s[k];
            }
            if (validAlternate(cpy))
                max_len = max(max_len, cpy.size());
        }
    }
    int rc = static_cast<int>(max_len);
    return (rc);
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

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

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
