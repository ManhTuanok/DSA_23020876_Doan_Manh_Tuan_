#include "linked_list.h"

using namespace std;

void LinkedList::get(int k){
    Node* temp = head;
    int count = 0;
    while (temp!= NULL){
        if (count == k){
            cout << temp->data << endl;
            return;
        }
        count++;
        temp = temp->next;
    }
    cout << "Cannot get" << endl;
}

void LinkedList::addFirst(Node* head,int value){
    Node* newNode = new LinkedList::Node;
    newNode->data = value;
    newNode->next = head;
}

void LinkedList::addLast(Node* head, int value){
    Node* newNode = new LinkedList::Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next!= nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::addPosition(Node* head, int p, int value){
    if (p < 0){
        cout << "Cannot add" << endl;
        return;
    }

    if (p == 0){
        addFirst(head, value);
        return;
    }

    Node* newNode = new LinkedList::Node;
    newNode->data = value;
    newNode->next = NULL;

    Node* temp = head;
    for (int i = 0; i < p-1 && temp!=NULL; i++){
        temp = temp->next;
    }

    if (temp == NULL){
        cout << "Cannot add" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::removeFirst(Node* head){
    if (head == NULL){
        cout << "Cannot remove" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::removeLast(Node* head){
    if (head == NULL){
        cout << "Cannot remove" << endl;
        return;
    }

    if (head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next!= NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void LinkedList::removePosition(Node* head, int p){
    if (p < 0){
        cout << "Cannot remove" << endl;
        return;
    }

    if (head == NULL){
        cout << "Cannot remove" << endl;
        return;
    }

    if (p == 0){
        removeFirst(head);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < p-1 && temp!=NULL; i++){
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL){
        cout << "Cannot remove" << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}


void LinkedList::displayForward(Node* head){
    Node* temp = head;
    while (temp!= NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void LinkedList::displayBackward(Node* head){
    if (head == NULL){
        return;
    }

    displayBackward(head->next);
    cout << head->data << " ";
}

