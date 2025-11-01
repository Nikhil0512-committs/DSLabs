#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertBeforeValue(int value, int beforeValue);
void insertAfterValue(int value, int afterValue);
void deleteFromBeginning();
void deleteFromEnd();
void deleteSpecificNode(int value);
void searchNode(int value);
void displayList();

int main() {
    int choice, value, key;
    do {
        cout << "\n===== Singly Linked List Operations =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter new value: ";
                cin >> value;
                cout << "Enter value before which to insert: ";
                cin >> key;
                insertBeforeValue(value, key);
                break;
            case 4:
                cout << "Enter new value: ";
                cin >> value;
                cout << "Enter value after which to insert: ";
                cin >> key;
                insertAfterValue(value, key);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter value of node to delete: ";
                cin >> value;
                deleteSpecificNode(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;
            case 9:
                displayList();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);
    return 0;
}

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}

void insertBeforeValue(int value, int beforeValue) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == beforeValue) {
        insertAtBeginning(value);
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data != beforeValue) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Node with value " << beforeValue << " not found.\n";
    } else {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp;
        prev->next = newNode;
        cout << "Inserted " << value << " before " << beforeValue << ".\n";
    }
}

void insertAfterValue(int value, int afterValue) {
    Node* temp = head;
    while (temp != nullptr && temp->data != afterValue)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Node with value " << afterValue << " not found.\n";
    } else {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << afterValue << ".\n";
    }
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted node with value " << temp->data << " from beginning.\n";
    delete temp;
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted node with value " << head->data << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    cout << "Deleted node with value " << temp->data << " from end.\n";
    delete temp;
}

void deleteSpecificNode(int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == value) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Node with value " << value << " not found.\n";
    } else {
        prev->next = temp->next;
        cout << "Deleted node with value " << value << ".\n";
        delete temp;
    }
}

void searchNode(int value) {
    Node* temp = head;
    int position = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Node " << value << " found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Node " << value << " not found in the list.\n";
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Current Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
