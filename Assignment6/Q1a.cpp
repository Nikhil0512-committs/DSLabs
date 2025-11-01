#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insert(int value, int posType, int key = 0) {
    Node* newNode = new Node();
    newNode->data = value;
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    if (posType == 1) {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    } else if (posType == 2) {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    } else if (posType == 3) {
        Node* temp = head;
        do {
            if (temp->data == key) {
                newNode->next = temp->next;
                temp->next = newNode;
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
        Node* prev = nullptr;
        do {
            if (temp->data == key) {
                prev->next = newNode;
                newNode->next = temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }
}

void deleteNode(int key) {
    if (!head) return;
    Node* temp = head;
    Node* prev = nullptr;
    do {
        if (temp->data == key) {
            if (temp == head && temp->next == head) {
                delete temp;
                head = nullptr;
                return;
            }
            if (temp == head) {
                Node* last = head;
                while (last->next != head)
                    last = last->next;
                head = head->next;
                last->next = head;
                delete temp;
                return;
            } else {
                prev->next = temp->next;
                delete temp;
                return;
            }
        }
        prev = temp;
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
