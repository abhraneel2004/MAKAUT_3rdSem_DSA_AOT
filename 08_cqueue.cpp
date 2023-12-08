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
	void enqueue(int item)
	{
		if (isFull())
		{
			cout << "The queue is Full." << endl;
		}
		if (front == -1)
		{
			front = rear = 0;
		}
		else
			rear = (rear + 1) % MAX;
		cqueue[rear] = item;
	}

	void dequeue()
	{
		if (isEmpty())
			cout << "The queue is empty." << endl;
		cout << "Deleted Item is: " << cqueue[front] << endl;
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % MAX;
	}
	void cqdisplay()
	{
		int i;
		if (front == -1)
		{
			cout << "Queue is empty" << endl;
			return;
		}
		cout << "\n\nThe elements of the Queue are:\n";
		if (front <= rear)
		{
			for (i = front; i <= rear; i++)
				cout << cqueue[i] << endl;
		}
		else
		{
			for (i = front; i <= MAX - 1; i++)
				cout << cqueue[i] << endl;
			for (i = 0; i <= rear; i++)
				cout << cqueue[i] << endl;
		}
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
			cq.enqueue(item);
			break;

		case 2:
			cq.dequeue();
			break;

		case 3:
			cq.cqdisplay();
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
