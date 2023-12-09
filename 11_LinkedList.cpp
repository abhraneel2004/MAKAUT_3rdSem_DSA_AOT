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

			void insertAtEnd(int value){
				Node * newNode = new Node(value);
				Node * temp = head;
				while(temp->next) temp = temp->next;
				temp->next = newNode;
				cout<<"Inserted "<<value<<" at the End.\n";
			}
			
			void deleteFromBeginning(){
				if(!head){
					cout<<"Empty List\n";
					return;
				}
				Node * temp = head;
				head = head->next;
				delete temp;
			}

			void deleteFromEnd(){
				if (!head){
					cout<<"Empty List\n";
					return;
				}
				Node * temp = head;
				Node * p = nullptr;
				while(temp->next){
					p = temp;
					temp = temp->next;
				}
				p->next = temp->next;
				delete temp;
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

			void search(int value){
				if(!head){
					cout<<"Empty List\n";
					return;
				}
				Node * temp = head;
				while(temp){
					if (temp->data==value){
						cout<<"Number Found\n";
						return;
					}
					temp = temp->next;
				}
				cout<<"Number Not Found\n";
				return;
			}

			void reverse(){
				Node * p = head, *q, *r = NULL;
				while(p){
					q = p;
					p = p->next;
					q->next = r;
					r = q;
				}
				head = q;
			}

			void bubblesort(){
				if (!head) return;
				int swapped;
				Node * current;
				Node * last = NULL;
				do{
					swapped = 0;
					current = head;
					while(current->next != last){
						if(current->data> current->next->data){
							int temp = current->data;
							current->data = current->next->data;
							current->next->data = temp;
							swapped =1;
						}
						current = current->next;
					}
					last = current;
				}while(swapped);
			}

			void delete_item(int key){
				if(!head){
					cout<<"Empty List\n";
					return;
				}
				Node * temp = head;
				while(temp->next){
					if (temp->next->data==key){
						temp->next = temp->next->next;
						return;
					}
				}
				return;
			}
};

int main(void){
	LinkedList l;
	int c;
	cout<<"Linked List Operations\n";
	do{
		cout<<"-----------------------\n";
		cout<<"1. Insert at the beginning\n";
		cout<<"2. Insert at the end\n";
		cout<<"3. Delete from Beginning\n";
		cout<<"4. Delete from End\n";
		cout<<"5. Display\n";
		cout<<"6. Search\n";
		cout<<"7. Reverse\n";
		cout<<"8. Delete Item\n";
		cout<<"9. Bubble Sort\n";
		cout<<"10. Exit\n";
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
				int val2;
				cout<<"Enter the data: ";
				cin>>val2;
				l.insertAtEnd(val2);
				break;
			case 3:
				l.deleteFromBeginning();
				break;
			case 4:
				l.deleteFromEnd();
				break;

			case 5:
				cout<<"Displaying the linked list: ";
				l.display();
				break;
			case 6:
				int key1;
				cout<<"Enter the key to search : ";
				cin>>key1;
				l.search(key1);
				break;
			case 7:
				cout<<"Before Reverse: \n";
				l.display();
				cout<<endl;
				l.reverse();
				cout<<"After Reverse: \n";
				l.display();
				break;

			case 8:
				int key2;
				cout<<"Enter Item to delete: ";
				cin>>key2;
				l.delete_item(key2);
				break;
			case 9:
				cout<<"Before Sorting: \n";
				l.display();
				l.bubblesort();
				cout<<"After Sorting: \n";
				l.display();
				break;
			case 10:
				break;
			default:
				cout<<"Invalid choice\n";
				break;
		}
	}while (c!=10);
	
	
	return 0;
}


