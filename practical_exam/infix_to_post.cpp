#include<iostream>
using namespace std;
#define MAX 100
#include "Stack1.cpp"

char infix[MAX], postfix[MAX];
int balanced(char arr[]){
    int i = 0;
    Stack1 s1;
    while(arr[i]!='\0'){
        char c = arr[i];
        if (c=='(' || c=='{' || c=='[')
            s1.push(c);
        else if (c==')'){
            if (s1.isEmpty()|| s1.peek()!='('){
                // cout<<"Invalid Expression\n";
                return 0;
            }
            s1.pop();
        }
        else if (c=='}'){
            if (s1.isEmpty()|| s1.peek()!='{'){
                // cout<<"Invalid Expression\n";
                return 0;
            }
            s1.pop();
        }
        else if (c==']'){
            if (s1.isEmpty()|| s1.peek()!='['){
                // cout<<"Invalid Expression\n";
                return 0;
            }
            s1.pop();
        }
        i++;
    }
    return s1.isEmpty();
}
int prec(char c){
    switch(c){
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
        default:
            return -1;
    }
}

void in_to_post(char arr[]){
    int i = 0, p = 0;
    char c,next;
    Stack1 opStack;
    while(arr[i]!='\0'){
        c = arr[i];
        if (c == '('){
            opStack.push(c);
        }
        else if(c==')'){
            while((next = opStack.pop())!='('){
                postfix[p++]=next;
            }
        }
        else if(c=='+' || c=='-' || c== '*' || c=='/'){
            while(opStack.top != -1 && prec(c)<=prec(opStack.peek())){
                postfix[p++] = opStack.pop();
            }
            opStack.push(c);
        }
        else{
            postfix[p++] = c;
        }
        i++;
    }
    while(opStack.top != -1){
        postfix[p++] = opStack.pop();
    }
    postfix[p] = '\0';
}

int main(void){
    cout<<"Enter the infix expression: ";
    cin>>infix;
    if(balanced(infix)){
        in_to_post(infix);
        for(int i = 0; i< (sizeof(postfix)/sizeof(char));i++){
            if (postfix[i]=='('){
                cout<<"Invalid Expression\n";
                return 1;
            }
        }
        cout<<"Equivalent Postfix Expression is: "<<postfix<<endl;
    }
    else{
        cout<<"Invalid Expression\n";
    }
    
    return 0;
}
