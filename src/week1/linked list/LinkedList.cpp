#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

 };

 struct LinkedList {
    Node* head;

    void get(int index) {
        Node* temp = head;
        int count = 0;
        while(temp!= nullptr) {
            if(count == index) {
                cout << temp->data << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Index out of range" << endl;
    }

    void addFirst(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void addLast(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next!= nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addPosition(int pos, int value){
        if(pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if(pos == 0) {
            addFirst(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        Node* temp = head;
        for(int i=0; i<pos-1 && temp!= nullptr; i++) {
            temp = temp->next;
        }

        if(temp == nullptr) {
            cout << "Invalid position" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void removeFirst() {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeLast() {
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while(temp->next->next!= nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void removePosition(int pos) {
        if(pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if(head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if(pos == 0) {
            removeFirst();
            return;
        }

        Node* temp = head;
        for(int i=0; i<pos-1 && temp!= nullptr; i++) {
            temp = temp->next;
        }

        if(temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void displayForward(){
        Node* temp = head;
        while(temp!= nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
// duyet nguoc double
    void displayBackward(){
        Node* current = head;
        Node* previous = nullptr;
        Node* next = nullptr;

        while(current!= nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        head = previous;
        displayForward();
    }
 };


 int main() {
    LinkedList list;
    list.head = new Node;
    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(3);
    list.displayForward(); // Output: 3 2 1

    list.addLast(4);
    list.addLast(5);
    list.displayForward(); // Output: 3 2 1 4 5

    list.addPosition(2, 6);
    list.displayForward(); // Output: 3 2 6 1 4 5

    list.removeFirst();
    list.displayForward(); // Output: 2 6 1 4 5

    list.removeLast();
    list.displayForward(); // Output: 2 6 1 4

    list.removePosition(1);
    list.displayForward(); // Output: 2 6 4

    list.get(2); // Output: 6

    list.displayBackward(); // Output
 }