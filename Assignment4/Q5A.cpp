#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    
    q2.push(x);

   
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }

  
    swap(q1, q2);
    cout << x << " pushed into stack\n";
}

void pop() {
    if (q1.empty()) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << q1.front() << " popped from stack\n";
    q1.pop();
}


void top() {
    if (q1.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << q1.front() << endl;
}

bool isEmpty() {
    return q1.empty();
}

int main() {
    int choice, val;
    do {
        cout << "\n--- Stack Using Two Queues ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Check Empty\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 4:
                if (isEmpty())
                    cout << "Stack is empty\n";
                else
                    cout << "Stack is not empty\n";
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
