#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insert(int value, int posType, int key = 0) {
    Node* newNode = new Node();
    newNode->data = value;
    if (!head) {
        head = newNode;
        head->next = head->prev = head;
        return;
    }
    if (posType == 1) {
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    } else if (posType == 2) {
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    } else if (posType == 3) {
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* nextNode = temp->next;
                newNode->next = nextNode;
                newNode->prev = temp;
                temp->next = newNode;
                nextNode->prev = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    } else if (posType == 4) {
        if (head->data == key) {
            insert(value, 1);
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* prevNode = temp->prev;
                newNode->next = temp;
                newNode->prev = prevNode;
                prevNode->next = newNode;
                temp->prev = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
}

void deleteNode(int key) {
    if (!head) return;
    Node* temp = head;
    do {
        if (temp->data == key) {
            if (temp->next == head && temp->prev == head) {
                delete temp;
                head = nullptr;
                return;
            }
            if (temp == head) {
                Node* last = head->prev;
                head = head->next;
                head->prev = last;
                last->next = head;
                delete temp;
                return;
            } else {
                Node* prevNode = temp->prev;
                Node* nextNode = temp->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                delete temp;
                return;
            }
        }
        temp = temp->next;
    } while (temp != head);
}

void search(int key) {
    if (!head) {
        cout << "List empty\n";
        return;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Node not found\n";
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
    cout << endl;
}

int main() {
    int choice, value, key, posType;
    do {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Display\n0.Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            cout << "1.First 2.Last 3.After Node 4.Before Node: ";
            cin >> posType;
            if (posType == 3 || posType == 4) {
                cout << "Enter key node value: ";
                cin >> key;
            }
            insert(value, posType, key);
        } else if (choice == 2) {
            cout << "Enter node value to delete: ";
            cin >> key;
            deleteNode(key);
        } else if (choice == 3) {
            cout << "Enter node value to search: ";
            cin >> key;
            search(key);
        } else if (choice == 4) {
            display();
        }
    } while (choice != 0);
    return 0;
}
