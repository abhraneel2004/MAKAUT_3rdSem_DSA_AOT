#include <iostream>
using namespace std;
#define MAX 5

class Stack1
{
	int top;
	int arr[MAX];

public:
	int isFull();
	int isEmpty();
	void push(int);
	void pop();
	void peek();
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

void Stack1::pop()
{
	top--;
}

void Stack1::peek()
{
	cout << arr[top];
}

void Stack1::display()
{

	for (int i = 0; i <= top; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int a;
	int c;
	Stack1 s;
	do
	{
		cout << "\nStack Operations" << endl;
		cout << "--------------------" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Peek" << endl;
		cout << "4. Display" << endl;
		cout << "5. Exit" << endl;
		cout << "--------------------" << endl;
		cout << "\nEnter Your Choice: ";
		cin >> c;
		switch (c)
		{
		case 1: // pushing the data

			if (s.isFull())
			{
				cout << "The Stack is full\n";
			}
			else
			{
				int val;
				cout << "Enter your data: ";
				cin >> val;
				s.push(val);
			}
			break;
		case 2: // pop function
			if (s.isEmpty())
			{
				cout << "The Stack is Empty\n";
			}
			else
			{
				s.pop();
			}
			break;
		case 3:
			if (s.isEmpty())
			{
				cout << "The Stack is Empty\n";
			}
			else
			{
				s.peek();
			}
			break;
		case 4:
			if (s.isEmpty())
			{
				cout << "The Stack is Empty\n";
			}
			else
			{
				s.display();
						}
			break;
		case 5:
			break;
		}
	} while (c != 5);
	return 0;
}
