//#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
#include <string>
#include <functional>

using namespace std;

/*
 * Complete the aOrB function below.
 */
void aOrB(int k, string a, string b, string c) {
    string::size_type aLen = a.length();
    string::size_type bLen = b.length();
    string::size_type cLen = c.length();
    string::size_type maxLen = max(aLen, bLen);
    maxLen = max(maxLen, cLen);
    vector<unsigned char> av(maxLen);
    vector<unsigned char> bv(maxLen);
    vector<unsigned char> cv(maxLen);
    string wk;
    string::size_type diff = maxLen - aLen;
    for (string::size_type i = 0; i < aLen; ++i) {
        wk.append(1, a[i]);
        av[i+diff] = static_cast<unsigned char>(stoi(wk, nullptr, 16));
        wk.clear();
    }
    diff = maxLen - bLen;
    for (string::size_type i = 0; i < bLen; ++i) {
        wk.append(1, b[i]);
        bv[i+diff] = static_cast<unsigned char>(stoi(wk, nullptr, 16));
        wk.clear();
    }
    diff = maxLen - cLen;
    for (string::size_type i = 0; i < cLen; ++i) {
        wk.append(1, c[i]);
        cv[i+diff] = static_cast<unsigned char>(stoi(wk, nullptr, 16));
        wk.clear();
    }
    //             #  get minimum flips
    //ac = a ^ c    //bits to flip on a to make it c
    //bc = b ^ c    //bits to flip on b to make it c
    //ab = ac & bc  //bits that flip for both a and b
    //ab &= ~c      //and we are interested only in the 0 bits in c
    unsigned char wkc;
    vector<unsigned char> dv(maxLen);
    for (string::size_type i = 0; i < maxLen; ++i) {
        dv[i] = (av[i] ^ cv[i]) & (bv[i] ^ cv[i]);
        wkc = cv[i];
        dv[i] &= ~wkc;
    }
    //x = (a | b) ^ c   // bits to flip to make a|b into c, not taking into account the same bit getting flipped on both
    //x = bin(x).count('1') + bin(ab).count('1')
    //if x > k:
    //    print(-1)
    vector<unsigned char> xv(maxLen);
    for (string::size_type i = 0; i < maxLen; ++i) {
        xv[i] = (av[i] | bv[i]) ^ cv[i];          
    }
    int xx = 0;
    for (string::size_type i = 0; i < maxLen; ++i) {
        //                 # TODO comment here
        xx += ((bitset<8>(xv[i])).count());
        xx += ((bitset<8>(dv[i])).count());
    }
    if (xx > k) {
        cout << dec << -1 << endl;
        return;
    }
    //    #  get spare flips
    //    spare = k - x
    //    #  flip off set bits in a and b to match off bits in c
    //    a &= c
    //    b &= c
    //    #  find bits in a or b that need to be set to match c
    //    x = (a | b) ^ c
    //    #  apply x set bits to b
    //    b |= x
    int spare = k - xx;
    for (string::size_type i = 0; i < maxLen; ++i) {
        av[i] &= cv[i];
        bv[i] &= cv[i];
        xv[i] = (av[i] | bv[i]) ^ cv[i];
        bv[i] |= xv[i];
    }
    //    #  use spare flips to reduce a to its minimum
////// The below doesn't apply as we are using C++.
    //    l = len(bin(a)) - 1
    //    mask = 2**l
    //    ones = 2**len(bin(c)) - 1
    //    while spare and mask:
    //        mask >>= 1
    //        if a & mask:
    //            if b & mask:
    //                a &= ones ^ mask
    //                spare -= 1
    //            elif spare > 1:
    //                a &= ones ^ mask
    //                b |= mask
    //                spare -= 2
    if (0 < spare) {
        unsigned char m, mask;
        for (string::size_type i = 0; i < maxLen && 0 < spare; ++i) {
            for (m = 0; m < 4; ++m) {
                if (m != 0)
                    mask >>= 1;
                else
                    mask = 8;
                if ((av[i] & mask) != 0) {
                    if ((bv[i] & mask) != 0) {
                        av[i] &= ~mask;
                        --spare;
                        if (!(0 < spare))
                            break;
                    }
                    else if (!(spare < 2)) {
                        av[i] &= ~mask;
                        bv[i] |= mask;
                        spare -= 2;
                        if (!(0 < spare))
                            break;
                    }
                }
            }
        }
    }
                   // Printing Section
    bool leadingZero = true;
    bool noPrint = true;
    for (string::size_type i = 0; i < maxLen; ++i) {
        if (leadingZero) {
            if (!av[i])
                continue;
            leadingZero = false;
        }
        if (av[i] < 0x0a)
            cout << static_cast<char>(av[i] + '0');
        else
            cout << static_cast<char>(av[i] - 0x0a + 'A');
        if (noPrint)
            noPrint = false;
    }
    if (noPrint)
        cout << '0';
    cout << '\n';
    if (!leadingZero)
        leadingZero = true;
    if (!noPrint)
        noPrint = true;
    for (string::size_type i = 0; i < maxLen; ++i) {
        if (leadingZero) {
            if (!bv[i])
                continue;
            leadingZero = false;
        }
        if (bv[i] < 0x0a)
            cout << static_cast<char>(bv[i] + '0');
        else
            cout << static_cast<char>(bv[i] - 0x0a + 'A');
        if (noPrint)
            noPrint = false;
    }
    if (noPrint)
        cout << '0';
    cout << endl;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string c;
        getline(cin, c);

        aOrB(k, a, b, c);
    }

    return 0;
}

#if 0
void aOrB(int k, string a, string b, string c) {
    unsigned long C = stoul(c, nullptr, 16);
    unsigned long B = stoul(b, nullptr, 16);
    unsigned long A = stoul(a, nullptr, 16);
    vector<pair<unsigned long, unsigned long>> av;

    for (unsigned long j = 0; j <= 0xff; ++j) {
        for (unsigned long i = 0; i <= 0xff; ++i) {
            if ((j | i) == C) {
                if (!(k < (bitset<8>(j ^ A)).count() + (bitset<8>(i ^ B)).count()))
                    av.push_back(make_pair(j, i));
            }
        }
    }
    if (!av.size()) {
        cout << dec << -1 << endl;
        return;
    }
    if (1 < av.size())
        sort(av.begin(), av.end());
    cout << hex << av.begin()->first << '\n';
    cout << hex << av.begin()->second << endl;
}
#endif /* 0 */
