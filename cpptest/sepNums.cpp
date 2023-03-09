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

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    string::size_type half, i, j, k, s_size = s.size();
    if (!(1 < s_size) || s[0] == '0') {
        cout << "NO" << endl;
        return;
    }
    string t, u, wk, val;
    half = s_size / 2;
    int z;
    char buffer[100];
    for (i = 1; i < half; ++i) {
        k = i;
        for (j = 0; j < s_size;) {
            t = s.substr(j, k);
            if (t[0] == '0')
                break;
            z = stoi(t);
            ++z;
            sprintf(buffer, "%i", z);
            wk = string(buffer);
            j += k;
            if (!(j < s_size))
                break;
            k = wk.size();
            u = s.substr(j, k);
            if (u[0] == '0')
                break;
            if (stoi(u) - stoi(t) != 1)
                break;
            if (!j && val.empty()) {
                val = t;
                break;
            }
        }
        if (!val.empty())
            break;
    }
    if (val.empty())
        cout << "NO" << endl;
    else
        cout << "YES" << ' ' << val << endl;
}

int main()
{
////RF fix for compiler error C4996
////    ofstream fout(getenv("OUTPUT_PATH"));
//    char* pValue;
//    size_t pValueLen;
//    errno_t err = _dupenv_s(&pValue, &pValueLen, "OUTPUT_PATH");
//    if (err) return -1;
//    ofstream fout(pValue);
//    free(pValue);

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
