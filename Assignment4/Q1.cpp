#include <iostream>
using namespace std;

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;


bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return (rear == MAX - 1);
}


void enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot insert " << x << endl;
        return;
    }
    if (front == -1) front = 0; 
    queue[++rear] = x;
    cout << x << " enqueued successfully!" << endl;
}


void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Cannot dequeue." << endl;
        return;
    }
    cout << queue[front] << " dequeued successfully!" << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}


void peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Front element: " << queue[front] << endl;
    }
}


void display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << (isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
                break;
            case 6:
                cout << (isFull() ? "Queue is Full" : "Queue is not Full") << endl;
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
