#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct DoubleLinkedList {
    Node* head;
    // do phuc tap O(n)
    void get(int index) {
        Node* temp = head;
        Node* tmp = temp;
        int count =0;
        while(temp != NULL){
            if( count == index) {
                cout<< temp->data << endl;
                return ;
            }
            count ++;
            Node* tmp = temp;
            
            temp = temp->next;

        }
    }
// do phuc tap O(1)
    void addFirst(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = NULL;
        if(head!= NULL) {  
            head->prev = newNode;
        }
    }
// do phuc tap O(1)
    void addLast(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if(head = NULL){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
// do phuc tap O(n)
    void addPosittion(int pos, int value) {
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if( pos == 0){
            addFirst(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode-> next = NULL;
        newNode->prev = NULL;

        Node*temp = head;
        for(int i=0; i<pos-1 && temp!= nullptr; i++) {
            temp = temp->next;
        }
        if(temp != NULL) {
            newNode->next = temp->next;
            newNode->prev = temp;
            if(temp->next != NULL){
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }
// do phuc tap O(1)
    void removeFirst(){
        if(head != NULL){
            Node* temp = head;
            head = head->next;
            if(head->prev != NULL){
                head-> prev = NULL;            }
        }
    }
// do phuc tap O(1)
    void removeLast(){
        if(head != NULL){
            Node*temp = head;
        
            while(temp->next!= NULL){
                temp = temp->next;
            }

            if(temp->prev!= NULL){
                temp->prev->next = NULL;
            }

        }
    }
// do phuc tap O(n)
    void removePosition(int pos){
        if(pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* temp = head;
        for(int i=0;i<pos-1 && temp->next != NULL;i++){
            temp = temp->next;
        }

        if(temp->next !=NULL){
            Node* remove = temp->next;
            temp->next = temp->next->next;
            if(remove->next!= NULL){
                remove->next->prev = temp;
            }
        }
    }
// do phuc tap O(n)
    void displayForward(){
        Node* temp =head;
        while(temp != NULL){
            cout<< temp->data << " ";
            temp = temp->next;
        }
    }
// do phuc tap O(n)
    void displayBackward(){
        Node* temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        while(temp!= NULL){
            cout<< temp->data << " ";
            temp = temp->prev;
        }
    }
};

int main() {
    DoubleLinkedList dll;
    dll.head = new Node;
    dll.addFirst(1);
    dll.addFirst(2);
    dll.addFirst(3);
    dll.addLast(4);
    dll.addLast(5);
    dll.addPosittion(2, 6);

    dll.displayForward();
    cout << endl;
    dll.displayBackward();
    cout << endl;

    dll.get(2);

    dll.removeFirst();
    dll.removeLast();
    dll.removePosition(1);

    dll.displayForward();
    cout << endl;
    dll.displayBackward();
    cout << endl;

    return 0;
}