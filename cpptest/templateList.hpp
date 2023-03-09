#include <iostream>
//#include <iomanip>
//#include <algorithm>
//#include <vector>
//#include <string>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T data) : next(nullptr)
    {
        this->data = data;
    }
};

template <typename T>
class alist
{
    Node<T> *listptr;
    size_t count;
public:
    alist(T *array, size_t arraylen)
    {
        if (array == nullptr || !(0 < arraylen))
        {
            listptr = nullptr;
            count = 0;
            return;
        }
        listptr = new Node<T>(array[0]);
        Node<T> *current = listptr;
        for (count = 1; count < arraylen; ++count)
            current = current->next = new Node<T>(array[count]); //we already have a current so this is the next one
                                                                 //and then this next one becomes the current one
    }
    ~alist()
    {
        Node<T> *p = listptr;
        while (p != nullptr)
        {
            listptr = p->next;
            delete p;
            p = listptr;
        }
    }

    void contents()
    {
        Node<T> *start = listptr;
        for (; start != nullptr; start = start->next)
            cout << start->data << ' ';
        cout << endl;
    }

    void insert(size_t index, T value) //inserts before, 0-based
    {
        Node<T> *new_node = new Node<T>(value);
        ++count;
        if (listptr == nullptr)
        {
            listptr = new_node;
            return;
        }
        Node<T> *current = listptr;
        Node<T> *previous = nullptr;
        for (size_t i = 0; i < index && current != nullptr; ++i)
        {
            previous = current;
            current = current->next;
        }
        new_node->next = current;
        if (previous != nullptr)
            previous->next = new_node;
        else
            listptr = new_node;
    }

    void remove(size_t index)
    {
        if (listptr == nullptr)
            return;
        Node<T> *current = listptr;
        Node<T> *previous = current;
        for (size_t i = 0; i < index && current->next != nullptr; ++i)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
        --count;
        if (!count)
            listptr = nullptr;
    }

    size_t elementCount() const
    {
        return (count);
    }

    void update(size_t index, T value)
    {
        Node<T> *current = listptr;
        for (size_t i = 0; i < index && current->next != nullptr; ++i)
            current = current->next;
        current->data = value;
    }

    bool existsValue(T value, int *pindex = nullptr) const
    {
        int i = 1;
        for (Node<T> *current = listptr; current != nullptr; current = current->next, ++i)
            if (current->data == value)
            {
                if (pindex != nullptr)
                    *pindex = i;
                return true;
            }
        return false;
    }
};
