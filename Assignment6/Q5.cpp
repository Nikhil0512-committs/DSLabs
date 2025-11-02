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
                    newNode->next = nullptr;
                        if (!head) {
                                head = newNode;
                                        return;
                                            }
                                                Node* temp = head;
                                                    while (temp->next)
                                                            temp = temp->next;
                                                                temp->next = newNode;
                                                                }

                                                                bool isCircular() {
                                                                    if (!head) return false;
                                                                        Node* temp = head->next;
                                                                            while (temp && temp != head)
                                                                                    temp = temp->next;
                                                                                        return temp == head;
                                                                                        }

                                                                                        int main() {
                                                                                            insert(10);
                                                                                                insert(20);
                                                                                                    insert(30);
                                                                                                        insert(40);
                                                                                                            cout << "Before making circular: ";
                                                                                                                if (isCircular())
                                                                                                                        cout << "Circular Linked List" << endl;
                                                                                                                            else
                                                                                                                                    cout << "Not a Circular Linked List" << endl;

                                                                                                                                        Node* temp = head;
                                                                                                                                            while (temp->next)
                                                                                                                                                    temp = temp->next;
                                                                                                                                                        temp->next = head;

                                                                                                                                                            cout << "After making circular: ";
                                                                                                                                                                if (isCircular())
                                                                                                                                                                        cout << "Circular Linked List" << endl;
                                                                                                                                                                            else
                                                                                                                                                                                    cout << "Not a Circular Linked List" << endl;

                                                                                                                                                                                        return 0;
                                                                                                                                                                                        }
                                                                                                                                                                                        