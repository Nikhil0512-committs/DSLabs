#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insert(char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome() {
    if (!head) return true;
    Node* left = head;
    Node* right = head;
    while (right->next)
        right = right->next;
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    string str;
    cout << "Enter characters for the doubly linked list: ";
    cin >> str;
    for (char c : str)
        insert(c);
    if (isPalindrome())
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;
    return 0;
}
