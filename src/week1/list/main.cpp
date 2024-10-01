#include "list.cpp"

int main()
{
    int *a;
    int b;
    List *list = new List(a, b);

    for (int i = 0; i < 10; i++)
    {
        list->addLast(i);
    }

    list->get(5);
    list->addFirst(100);
    list->addLast(100);
    list->addPosition(3, 100);
    list->removeFirst();
    list->removeLast();
    list->removePosition(3);
    list->displayForward();
    list->displayBackward();
    cout << 1 << endl;
    return 0;
}
