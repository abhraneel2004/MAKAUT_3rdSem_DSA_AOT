#include<iostream>
using namespace std;
#include "Stack1.cpp"
#define MAX 100

char postfix[MAX];

int postfixEval(char arr[]){
    Stack1 s1;
    int i;
    while(arr[i]!='\0'){
        char c = arr[i];
        if (c=='+' || c=='-' || c=='*'|| c=='/'){
            int a = s1.pop()-48;
            int b = s1.pop()-48;
            
            if (c=='+')
                s1.push(a+b);
            else if (c=='-')
                s1.push(a-b);
            else if (c=='*')
                s1.push(a*b);
            else if (c=='/')
                s1.push(a/b);
                
        }
        else{
            s1.push(c);
        }
        i++;
    } 
    return 2;
}

int main(void){
    cout<<"Enter the Postfix expression: ";
    cin>>postfix;
    int res = postfixEval(postfix);
    cout<<"Postfix evaluation is: "<<endl;
    return 0;
}
