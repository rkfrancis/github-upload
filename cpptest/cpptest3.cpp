#include <iostream>
#include <string>
#include <utility>
#include <sstream>
using namespace std;
int main(void) {
    cout << "Enter a string below:";
    cout << endl;
    string in;
    getline(cin, in);
                   //Reverse a string
    string out;
    copy(in.rbegin(), in.rend(), back_inserter(out));
    cout << '\n' << out << endl;
                   //Reverse each word in a string
    out.clear();
    string wk;
    istringstream istr;
    istr.str(in);
    for (string word; getline(istr, word, istr.widen(' ')); word.clear()) {
        if (!word.empty()) {
            copy(word.rbegin(), word.rend(), back_inserter(wk));
            word = wk;
            wk.clear();
        }
        word += string(" ");
        out += word;
    }
    cout << '\n' << out << endl;
}
