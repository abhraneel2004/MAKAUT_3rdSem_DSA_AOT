#include<iostream>
using namespace std;


// structure of a node in C++


class Node{
	public:
		int data;
		Node * next;
		
		Node(int value){
			data = value;
			next = nullptr;
		}
};



// single linked list creation

class LinkedList{
	Node * head;
	public:
			LinkedList(){
				head = NULL;
			}
			void insertAtBeginning(int value){
				Node* newNode = new Node(value);
				newNode-> next = head;
				head = newNode;
				cout<<"Inserted "<<value<<" at the beginning.\n";
			}
			
			void display(){
				if (head==NULL) return;
				Node * temp = head;
				while (temp!=NULL){
					cout<<temp-> data<<"  ";
					temp = temp-> next;
				}
				cout<<endl;
			}
};

int main(void){
	LinkedList l;
	int c;
	cout<<"Linked List Operations\n";
	do{
		cout<<"-----------------------\n";
		cout<<"1. Insert at the beginning\n";
		cout<<"2. Display\n";
		cout<<"3. Exit\n";
		cout<<"-----------------------\n";
		cout<<"Enter Your choice: ";
		cin>>c;
		switch(c){
			case 1:
				int val;
				cout<<"Enter the data: ";
				cin>>val;
				l.insertAtBeginning(val);
				break;
			case 2:
				cout<<"Displaying the linked list: ";
				l.display();

				break;
			case 3:
				break;
			default:
				cout<<"Invalid choice\n";
				break;
		}
	}while (c!=3);
	
	
	return 0;
}


