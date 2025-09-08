#include <iostream>
#include <stack>
#include <cmath>
using namespace std;


int evaluatePostfix(string postfix) {
    stack<int> st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            st.push(c - '0');
        }

        else {
            int num2 = st.top(); st.pop();
            int num1 = st.top(); st.pop();

            switch (c) {
                case '+':
                  st.push(num1 + num2);
                  break;
                case '-':
                  st.push(num1 - num2);
                  break;
                case '*':
                  st.push(num1 * num2);
                  break;
                case '/':
                  st.push(num1 / num2);
                  break;
                case '^':
                  st.push(pow(num1, num2));
                  break;
            }
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Answer is: " << evaluatePostfix(postfix) << endl;
    return 0;
}
