#ifndef list_h
#define list_h
#include <iostream>

class List
{
private:
    int array[1000];
    int count = 0;

public:
    
    // ham khoi tao
    List(int *array, int count);
    void get(int k);
    void addFirst(int value);
    void addLast(int value);
    void addPosition(int p, int value);
    void removeFirst();
    void removeLast();
    void removePosition(int p);
    void displayForward();
    void displayBackward();

    
};

#endif