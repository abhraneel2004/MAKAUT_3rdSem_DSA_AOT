#include <iostream>
using namespace std;
#define MAX 5

class Cqueue
{
	int front, rear, cqueue[MAX];

public:
	int isFull()
	{
		return front == (rear + 1) % MAX;
	}
	int isEmpty()
	{
		return front == -1;
	}

	void insert(int data)
	{
		if (front == (rear + 1) % MAX)
		{
			cout << "Queue is Full";
			return;
		}
		if (front == -1)
			front = rear = 0;
		else
			rear = (rear + 1) % MAX;
		cqueue[rear] = data;
	}

	void remove_()
	{
		if (front == -1)
		{
			cout << "Queue Underflow\n";
			return;
		}
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % MAX;
	}

	void peek()
	{
		if (front == -1)
		{
			cout << "Queue Underflow\n";
			return;
		}
		cout << "Queue Front: " << cqueue[front] << endl;
	}

	void display()
	{
		int i;
		if (front == -1)
		{
			cout << "Queue Underflow\n";
			return;
		}

		if (front <= rear)
		{
			// cout<<"\n%d---%d\n", temp,rear);
			for (i = front; i <= rear; i++)
				cout << cqueue[i] << "-> ";
		}
		else
		{
			for (i = front; i <= MAX - 1; i++)
				cout << cqueue[i]<<"-> ";
			for (i = 0; i <= rear; i++)
				cout << cqueue[i]<<"-> ";
		}
		cout << "NULL\n";
	}

	Cqueue()
	{
		front = rear = -1;
	}
};

int main(void)
{
	int ch, item;
	Cqueue cq;
	do
	{
		cout << "\n\n*******************************\n";
		cout << "\n1. Insertion";
		cout << "\n2. Deletion";
		cout << "\n3. Display";
		cout << "\n4. Exit\n";
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter your data: ";
			cin >> item;
			cq.insert(item);
			break;

		case 2:
			cq.remove_();
			break;

		case 3:
			cq.display();
			break;

		case 4:
			break;

		default:
			cout << "Invalid Option" << endl;
			break;
		}
	} while (ch != 4);
	return 0;
}
