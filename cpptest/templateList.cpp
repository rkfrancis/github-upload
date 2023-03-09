#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

#include "templateList.hpp"

using namespace std;

//limit 1 to 32 digits (limit for unsigned long long is 17-digits)
//1234
//91011
//99100
//101103
//010203
//13
//1

//Sets of digits have to increment, no zero begin. Print YES <smallest> or NO.
//YES 1
//YES 9
//YES 99
//NO
//NO
//NO
//NO

int main()
{
    int array[] = { 2, 4, 6, 8, 10 };
    alist<int> al(array, sizeof(array) / sizeof(array[0]));
    al.contents();

    al.insert_after(5, 11);
    al.insert_after(4, 9);
    al.insert_after(3, 7);
    al.insert_after(2, 5);
    al.insert_after(1, 3);
    al.insert_after(0, 1);
    al.contents();

    al.remove(10);
    al.remove(8);
    al.remove(6);
    al.remove(4);
    al.remove(2);
    al.contents();

    al.update(1, 2);
    al.update(2, 4);
    al.update(3, 6);
    al.update(4, 8);
    al.update(5, 10);
    al.contents();

    int index;
    if (al.existsValue(2, &index))
        cout << 2 << " exists at index " << index << '\n';
    else
        cout << 2 << " does not exist" << '\n';

    if (al.existsValue(3, &index))
        cout << 3 << " exists at index " << index << '\n';
    else
        cout << 3 << " does not exist" << '\n';

    cout << "Element count is " << al.elementCount() << endl;
}
