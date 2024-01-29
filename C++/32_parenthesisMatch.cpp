#include<iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string &expression) {
    stack<char> parenStack;

    for (char ch : expression) {
        if (ch == '(') {
            parenStack.push(ch);
        } else if (ch == ')') {
            if (parenStack.empty() || parenStack.top() != '(') {
                return false; 
            }
            parenStack.pop();
        }
    }

    return parenStack.empty();  
}

int main() {
    string expression;
    cout << "Enter an expression with parenthesis: ";
    getline(cin, expression);

    if (isBalanced(expression)) {
        cout << "Parenthesis are balanced!" << endl;
    } else {
        cout << "Parenthesis are not balanced!" << endl;
    }

    return 0;
}