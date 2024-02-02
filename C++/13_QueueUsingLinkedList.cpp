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

class QueueLL{
	Node * head;
	public:
			QueueLL(){
				head = NULL;
			}
			void insert(int value){
				Node* newNode = new Node(value);

                if(!head){
                    head = newNode;
                }
                
                else{
                    Node * temp = head;
                    while(temp->next) temp = temp->next;
                    temp->next = newNode;
                }
                
                
			}

            void delete_(){
                if(!head){
                    cout<<"Queue Underflow!"<<endl;
                    return;
                }
                else{
                    Node * temp = head;
                    head = head->next;
                    delete temp;
                    return;
                }

            }

			
			void display(){
				if (head==NULL) return;
				Node * temp = head;
				while (temp){
					cout<<temp-> data<<"-> ";
					temp = temp-> next;
				}
                cout<<"NULL \n";
			}
};

int main(void){
	QueueLL l;
	int c;
	cout<<"Queue Operations\n";
	do{
		cout<<"-----------------------\n";
		cout<<"1. Insert\n";
        cout<<"2. Delete\n";
		cout<<"3. Display\n";
		cout<<"4. Exit\n";
		cout<<"-----------------------\n";
		cout<<"Enter Your choice: ";
		cin>>c;
		switch(c){
			case 1:
				int val;
				cout<<"Enter the data: ";
				cin>>val;
				l.insert(val);
				break;
            case 2:
                l.delete_();
                break;

            case 3:
                cout<<"Displaying the Queue: ";
				l.display();
                cout<<"\n";
                break;
            case 4: break;
			default:
				cout<<"Invalid choice\n";
				break;
		}
	}while (c!=4);
	
	
	return 0;
}


