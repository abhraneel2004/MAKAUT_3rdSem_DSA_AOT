#include <iostream>
using namespace std;
#define MAX 100

class Stack1
{
	

public:
	int top;
	char arr[MAX];
	int isFull();
	int isEmpty();
	void push(char);
	char pop();
	char peek();
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

void Stack1::push(char data)
{
	arr[++top] = data;
}

char Stack1::pop()
{
	char c = arr[top];
	top--;
	return c;
}

char Stack1::peek()
{
	return arr[top];
}

void Stack1::display()
{

	for (int i = 0; i <= top; i++)
	{
		cout << arr[i] << " ";
	}
}
