#include <iostream>
using namespace std;

struct Node
{
	int data;
	int priority;
	Node *next;
};

class PQ
{
	Node *front;

public:
	PQ()
	{
		front = NULL;
	}
	void insert(int d, int p)
	{
		Node *curr = new Node;
		curr->data = d;
		curr->priority = p;
		if (!front || p < front->priority)
		{
			curr->next = front;
			front = curr;
			return;
		}
		Node *temp = front;
		while (temp->next != NULL && temp->next->priority <= p)
		{
			temp = temp->next;
		}
		curr->next = temp->next;
		temp->next = curr;
		return;
	}

	void display()
	{
		if (!front)
		{
			cout << "The queue is Empty" << endl;
			return;
		}
		Node *temp = front;
		while (temp != NULL)
		{
			cout << "[" << temp->data << ":" << temp->priority << "] -> ";
			temp = temp->next;
		}
		cout<< "NULL\n";
		return;
	}

	void delfront()
	{
		if (!front)
		{
			cout << "The Queue is empty.\n";
			return;
		}
		Node *temp = front;
		front = front->next;
		delete temp;
		return;
	}

	int countNode()
	{
		if (!front)
		{
			return 0;
		}
		int c = 1;
		Node *temp = front;
		while (temp)
		{
			c++;
			temp = temp->next;
		}
		return c;
	}
};

int main(void)
{
	PQ p;
	int c, val, prio;
	cout << "Priority Queue Operations\n";
	cout << "1. Insert\n";
	cout << "2. Display\n";
	cout << "3. Delete from front\n";
	cout << "5. Count Node\n";
	cout << "6. Exit\n";
	cout << "------------------------------\n";
	do
	{
		cout << "Enter your choice: ";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Enter the value: ";
			cin >> val;
			cout << "Enter the priority: ";
			cin >> prio;
			p.insert(val, prio);
			break;
		case 2:
			p.display();
			break;
		case 3:
			p.delfront();
			break;
		case 5:
			cout <<"Total count of node is :"<< p.countNode() << endl;
			break;
		case 6:
            cout<<"Exiting the program.";
			break;
		default:
			cout << "Invalid choice\n";
			break;
		}
	} while (c != 6);
	return 0;
}