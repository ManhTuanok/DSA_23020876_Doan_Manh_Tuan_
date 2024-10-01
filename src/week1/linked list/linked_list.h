#include <iostream>

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;

public:
    void get(int k);
    void addFirst(Node *head, int value);
    void addLast(Node *head, int value);
    void addPosition(Node *head, int p, int value);
    void removeFirst(Node *head);
    void removeLast(Node *head);
    void removePosition(Node *head, int p);
    void displayForward(Node *head);
    void displayBackward(Node *head);
};