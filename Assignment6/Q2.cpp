#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void display() {
    if (!head) {
        cout << "List empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}

int main() {
    insert(20);
    insert(100);
    insert(40);
    insert(80);
    insert(60);
    display();
    return 0;
}
