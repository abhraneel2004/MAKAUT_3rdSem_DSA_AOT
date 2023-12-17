#include <iostream>
using namespace std;

// structure of a node in C++

class Node
{
public:
	int data;
	Node *next;

	Node(int value)
	{
		data = value;
		next = nullptr;
	}
};

// single linked list creation

class LinkedList
{
	Node *head;

public:
	LinkedList()
	{
		head = NULL;
	}
	void insertAtBeginning(int value)
	{
		Node *newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		cout << "Inserted " << value << " at the beginning.\n";
	}

	void insertAtEnd(int value)
	{
		Node * newNode = new Node(value);
		if (!head){
			newNode->next = head;
			head = newNode;
			cout << "Inserted " << value << " at the End.\n";
			return;
		}
		else{
			Node * temp = head;
			while(temp->next) temp = temp->next;
			temp->next = newNode;
			cout << "Inserted " << value << " at the End.\n";
			return;
		}
	}

	void insertAtAny(int key){
		
		int c2,val2;
		cout<<"Enter data: ";
		cin>>val2;
		Node * newNode2 = new Node(val2);
		if(!head){
			insertAtBeginning(val2);
			return;
		}
		else{
			Node * temp = head;
			Node * p = NULL;
			while(temp){
				if(temp->data == key) break;
				p = temp;
				temp = temp->next;
			}
			if (!temp) return;
			cout<<"\n-----Options----\n1. Add Before\n2. Add after\n";
			cout<<"Enter your choice (1 or 2): ";
			cin>>c2;
			
			if (c2==1){
				if (!p){
					insertAtBeginning(val2);
					return;
				}
				p->next = newNode2;
				newNode2->next = temp;
				return;
			}
			else if (c2==2){
				newNode2->next = temp->next;
				temp->next = newNode2;
			}
			else{
				return;
			}
		}
		
	}

	void deleteFromBeginning()
	{
		if (!head)
		{
			cout << "Empty List\n";
			return;
		}
		Node *temp = head;
		head = head->next;
		delete temp;
	}

	void deleteFromEnd()
	{
		if (!head)
		{
			cout << "Empty List\n";
			return;
		}
		Node *temp = head;
		Node *p = nullptr;
		while (temp->next)
		{
			p = temp;
			temp = temp->next;
		}
		p->next = temp->next;
		delete temp;
	}

	void delEle(int key){
		if(!head) return;
		
		if(head->data==key){
			head = head->next;
			return;
		}
		else{
			Node * temp = head;
			while(temp->next){
				if (temp->next->data==key){
					temp->next = temp->next->next;
				}
				temp = temp->next;
			}
		}
		
	}

	void display()
	{
		if (head == NULL)
			return;
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}

	void search(int value)
	{
		if (!head)
		{
			cout << "Empty List\n";
			return;
		}
		Node *temp = head;
		while (temp)
		{
			if (temp->data == value)
			{
				cout << "Number Found\n";
				return;
			}
			temp = temp->next;
		}
		cout << "Number Not Found\n";
		return;
	}

	void reverse()
	{
		Node *p = head, *q, *r = NULL;
		while (p)
		{
			q = p;
			p = p->next;
			q->next = r;
			r = q;
		}
		head = q;
	}

	void bubblesort()
	{
		if (!head)
			return;
		int swapped;
		Node *current;
		Node *last = NULL;
		do
		{
			swapped = 0;
			current = head;
			while (current->next != last)
			{
				if (current->data > current->next->data)
				{
					int temp = current->data;
					current->data = current->next->data;
					current->next->data = temp;
					swapped = 1;
				}
				current = current->next;
			}
			last = current;
		} while (swapped);
	}
};

int main(void)
{
	LinkedList l;
	int c,val;
	cout << "Linked List Operations\n";
	do
	{
		cout << "-----------------------\n";
		cout << "1. Insert at the beginning\n";
		cout << "2. Insert at the end\n";
		cout <<"3. Insert at any position\n";
		cout << "4. Delete from Beginning\n";
		cout << "5. Delete from End\n";
		cout<< "6. Delete an element\n";
		cout << "7. Display\n";
		cout << "8. Search\n";
		cout << "9. Reverse\n";
		cout << "10. Bubble Sort\n";
		cout << "11. Exit\n";
		cout << "-----------------------\n";
		cout << "Enter Your choice: ";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Enter the data: ";
			cin >> val;
			l.insertAtBeginning(val);
			break;
		case 2:
			
			cout << "Enter the data: ";
			cin >> val;
			l.insertAtEnd(val);
			break;
		case 3:
			cout<<"Enter the element: ";
			cin>>val;
			l.insertAtAny(val);
			break;
		case 4:
			l.deleteFromBeginning();
			break;
		case 5:
			l.deleteFromEnd();
			break;
		case 6:
			cout<<"Enter the data to delete: ";
			cin>>val;
			l.delEle(val);
			break;
		case 7:
			cout << "Displaying the linked list: ";
			l.display();
			break;
		case 8:
			int key1;
			cout << "Enter the key to search : ";
			cin >> key1;
			l.search(key1);
			break;
		case 9:
			cout << "Before Reverse: \n";
			l.display();
			cout << endl;
			l.reverse();
			cout << "After Reverse: \n";
			l.display();
			break;

		case 10:
			cout << "Before Sorting: \n";
			l.display();
			l.bubblesort();
			cout << "After Sorting: \n";
			l.display();
			break;
		case 11:
			break;
		default:
			cout << "Invalid choice\n";
			break;
		}
	} while (c != 11);

	return 0;
}
