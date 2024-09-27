#include <iostream>
class List
{
private:
    int *array;
    int count = 0;

public:
     // ham khoi tao
     List(int size);

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