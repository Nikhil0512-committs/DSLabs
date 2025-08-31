#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

int top = -1;
char stack[MAX];


void push(char ch) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!\n";
        return;
    }
    stack[++top] = ch;
}


char pop() {
    if (top == -1) {
        cout << "Stack Underflow!\n";
        return '\0';
    }
    return stack[top--];
}

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;

    int len = strlen(str);

   
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    cout << "Reversed string: ";
   
    for (int i = 0; i < len; i++) {
        cout << pop();
    }
    cout << endl;

    return 0;
}
