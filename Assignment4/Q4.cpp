#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 1000   // Max queue size

char queue[SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return ((rear + 1) % SIZE == front);
}

void enqueue(char ch) {
    if (isFull()) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = ch;
}

void dequeue() {
    if (isEmpty()) return;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

char getFront() {
    if (isEmpty()) return '\0';
    return queue[front];
}

int main() {
    char str[SIZE];
    cout << "Enter a string: ";
    cin.getline(str, SIZE);

    int freq[256] = {0};

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];
        freq[(unsigned char)ch]++;

        enqueue(ch);

        while (!isEmpty() && freq[(unsigned char)getFront()] > 1) {
            dequeue();
        }

        if (!isEmpty())
            cout << "First non-repeating character till now: " << getFront() << endl;
        else
            cout << "No non-repeating character till now." << endl;
    }

    if (!isEmpty())
        cout << "\nFirst non-repeating character in the string is: " << getFront() << endl;
    else
        cout << "\nNo non-repeating character found in the string." << endl;

    return 0;
}
