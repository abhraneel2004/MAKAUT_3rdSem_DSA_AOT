#include <iostream>
#define MAX 100
#include "Stack1.cpp"

char infix[MAX], postfix[MAX];
Stack1 st;


int isAlNum(char x){
	return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'));
}

int prec(char x){
	switch (x)
	{
	case '^':
		return 3;
		break;
	case '*':
	case '/':
	case '%':
		return 2;
		break;
	case '+':
	case '-':
		return 1;
		break;
	case '(':
		return 0;
		break;
	}
}


void in_post(char in[]){
	int i = 0, p = 0;
    char next;
    while (in[i] != '\0')
    {
        char c = in[i];
        if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            char next;
            while ((next = st.pop()) != '(')
            {
                postfix[p++] = next;
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
        {
            while (st.top != -1 && prec(c) <= prec(st.peek()))
            {
                postfix[p++] = st.pop();
            }
            st.push(c);
        }
        else
        {
            postfix[p++] = c;
        }
        i++;
    }
    while (st.top != -1)
    {
        postfix[p++] = st.pop();
    }
    postfix[p] = '\0';
}

int main(void){
	cout<<"Enter the Infix expression: ";
	cin>>infix;
	in_post(infix);
	for (int i  = 0; i<(sizeof(postfix)/sizeof(char));i++){
		if (postfix[i] == '('){
			cout<<"Invalid Expression\n";
			return 0;
		}
	}
	cout<<"The postfix expression is: "<<postfix<<endl;
	return 0;
	
}





