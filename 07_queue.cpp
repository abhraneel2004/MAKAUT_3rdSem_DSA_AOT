#include <iostream>
using namespace std;
#define MAX 5

class QueueL
{
	int front, rear;
	int arr[MAX];

public:
	int isFull();
	int isEmpty();
	void enqueue(int);
	int dequeue();
	void peek();
	void display();
	QueueL()
	{
		front = -1;
		rear = -1;
	}
};

int QueueL::isFull()
{
	return rear == MAX - 1;
}

int QueueL::isEmpty()
{
	return front == rear;
}

void QueueL::enqueue(int data)
{

	arr[++rear] = data;
}

int QueueL::dequeue()
{

	front++;
	return arr[front];
}

void QueueL::peek()
{

	cout << arr[front + 1];
}

void QueueL::display()
{

	for (int i = front + 1; i <= rear; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int main()
{
	int a;
	int c;
	QueueL lq;
	do
	{
		cout << "\nQueue Operations" << endl;
		cout << "--------------------" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Peek" << endl;
		cout << "4. Display" << endl;
		cout << "5. Exit" << endl;
		cout << "--------------------" << endl;
		cout << "\nEnter Your Choice: ";
		cin >> c;
		switch (c)
		{
		case 1:
			if (lq.isFull())
			{
				cout << "The Linear Queue is Full" << endl;
			}
			else
			{
				int val;
				cout << "Enter your data: ";
				cin >> val;
				lq.enqueue(val);
			}
			break;
		case 2:
			if (lq.isEmpty())
			{
				cout << "The Linear Queue is Empty" << endl;
			}
			else
			{
				int item = lq.dequeue();
				cout << "Deleted Item: " << item << endl;
			}
			break;
		case 3:
			if (lq.isEmpty())
			{
				cout << "The Linear Queue is Empty" << endl;
			}
			else
			{
				lq.peek();
			}
			break;
		case 4:
			if (lq.isEmpty())
			{
				cout << "The Linear Queue is Empty" << endl;
			}
			else
			{
				lq.display();
			}
			break;
		case 5:
			break;
		default:
			cout << "Ivalid Choice\n";
		}

	} while (c != 5);
	return 0;
}
