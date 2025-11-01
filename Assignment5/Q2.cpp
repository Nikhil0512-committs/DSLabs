#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

int deleteOccurrences(int key) {
    int count = 0;
    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->data == key) {
            Node* temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
            count++;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return count;
}

void displayList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, val, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter list elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(val);
    }
    cout << "Enter key to delete: ";
    cin >> key;
    int occurrences = deleteOccurrences(key);
    cout << "Number of occurrences deleted: " << occurrences << endl;
    cout << "Updated Linked List: ";
    displayList();
    return 0;
}
