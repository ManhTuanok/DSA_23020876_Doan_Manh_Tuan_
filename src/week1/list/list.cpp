#include <iostream>
#include "list.h"
using namespace std;

// cac function khoi tao trong List

List::List(int *array, int count)
{
  array = array;
  count = count;
}


void List::get(int k)
{
    if (count < k || count == 0)
    {
        cout << "Cannot get";
        return;
    }
    for (int i = 0; i < count; i++)
    {
        if (i == k)
        {
            cout << array[i] << endl;
        }
    }
}

void List::addFirst(int value)
{
    if (count == 0)
    {
        array[0] = value;
        count++;
        cout << array[0] << endl;
        return;
    }

    for (int i = count - 1; i >= 1; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = value;

    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
}

void List::addLast(int value)
{
    array[count] = value;
    count++;
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
}

void List::addPosition(int p, int value)
{
    if (p < 0 || p > count)
    {
        cout << "Cannot add" << endl;
        return;
    }
    for (int i = count; i > p; i--)
    {
        array[i] = array[i - 1];
    }
    array[p] = value;
    count++;
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
}

void List::removeFirst()
{
    if (count == 0)
    {
        cout << "Cannot remove" << endl;
        return;
    }
    for (int i = 0; i < count - 1; i++)
    {
        array[i] = array[i + 1];
    }
    count--;
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
}

void List::removeLast()
{
    if (count == 0)
    {
        cout << "Cannot remove" << endl;
        return;
    }
    count--;
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
}

void List::removePosition(int p)
{
    if (p < 0 || p >= count)
    {
        cout << "Cannot remove" << endl;
        return;
    }
    for (int i = p; i < count - 1; i++)
    {
        array[i] = array[i + 1];
    }
    count--;
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
}

void List::displayBackward()
{
    for (int i = count - 1; i >= 0; i--)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void List::displayForward()
{
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

