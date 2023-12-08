//postfix evaluation

#include <iostream>
using namespace std;
#define MAX 100

class Stack1
{
	int top;
	int arr[MAX];

	public:
		
		int isFull();
		int isEmpty();
		void push(int);
		int pop();
		int peek();
		void display();
		Stack1()
		{
			top = -1;
		}
};

int Stack1::isFull()
{
	return top == MAX - 1;
}

int Stack1::isEmpty()
{
	return top == -1;
}

void Stack1::push(int data)
{
	arr[++top] = data;
}

int Stack1::pop()
{
	int c = arr[top];
	top--;
	return c;
}

int Stack1::peek(){
	return arr[top];
}


char postfix[MAX];

Stack1 st;

int evalpost(char post[]){
	int i = 0;
	//scanning the expression
	while(post[i]!='\0'){
		char ch = post[i];
		if (i==0 && (ch>='1' && ch<='9')!=1){
			cout<<"invalid expression\n";
			exit(0);
		}
		else if (ch>='1' && ch<='9'){
			st.push(ch-48);
		}
		else{
			
			int op2 = st.pop();
			int op1 = st.pop();

			switch(ch){
				case '+':
					
					st.push(op1+op2);
					break;
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case '/':
					st.push(op1/op2);
					break;
				case '%':
					st.push(op1%op2);
					break;
				default:
					cout<<"invalid expression\n";
					exit(0);
					break;
			}
		}
		i++;
	}
	return st.peek();
}


int main(void){
	cout<<"Enter the postfix expression: ";
	cin>>postfix;
	int x = evalpost(postfix);
	cout<<"The result of this expression is : "<<x<<endl;
	return 0;
}
