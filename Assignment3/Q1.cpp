#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;


bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}


void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << x << endl;
        return;
    }
    stack[++top] = x;
    cout << x << " pushed to stack.\n";
}


void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Nothing to pop.\n";
        return;
    }
    cout << stack[top--] << " popped from stack.\n";
}


void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n---Stack Menu---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty()) cout << "Stack is empty.\n";
                else cout << "Stack is not empty.\n";
                break;
            case 4:
                if (isFull()) cout << "Stack is full.\n";
                else cout << "Stack is not full.\n";
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! \n";
        }
    } while (choice != 7);

    return 0;
}
