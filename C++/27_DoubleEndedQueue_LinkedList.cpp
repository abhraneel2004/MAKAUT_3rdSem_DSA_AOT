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

class DEQueueLL{
	Node * head;
	public:
			DEQueueLL(){
				head = NULL;
			}
			void insert_end(int value){
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

            void insert_front(int value){
                Node * newNode = new Node(value);
                if(!head){
                    head = newNode;
                }
                else{
                    newNode->next = head;
                    head = newNode;
                }
            }

            void delete_front(){
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

            void delete_end(){
                if (!head){
                    cout<<"Queue Underflow!"<<endl;
                    return;
                }
                else{
                    Node * temp = head;
                    Node * p = nullptr;
                    while(temp->next){
                        p = temp;
                        temp = temp->next;
                    }
                    p->next = temp->next;
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

void ipResDEqueue(){
    DEQueueLL l;
	int c;
	
	do{
		cout<<"\n\n----- Input Restricted Double Ended Queue Operations------\n";
		cout<<"1. Insert at End\n";
        cout<<"2. Delete from Front\n";
        cout<<"3. Delete from End\n";
		cout<<"4. Display\n";
		cout<<"5. Exit\n";
		cout<<"-----------------------\n";
		cout<<"Enter Your choice: ";
		cin>>c;
		switch(c){
			case 1:
				int val;
				cout<<"Enter the data: ";
				cin>>val;
				l.insert_end(val);
				break;
            case 2:
                l.delete_front();
                break;
            case 3:
                l.delete_end();
                break;
            case 4:
                cout<<"Displaying the Double Ended Queue: ";
				l.display();
                cout<<"\n";
                break;
            case 5: break;
			default:
				cout<<"Invalid choice\n";
				break;
		}
	}while (c!=5);
}

void opResDEqueue(){
    DEQueueLL l;
	int c;
	
	do{
		cout<<"\n\n----- Output Restricted Double Ended Queue Operations------\n";
		cout<<"1. Insert at Front\n";
        cout<<"2. Insert at End\n";
        cout<<"3. Delete from Front\n";
		cout<<"4. Display\n";
		cout<<"5. Exit\n";
		cout<<"-----------------------\n";
		cout<<"Enter Your choice: ";
		cin>>c;
		switch(c){
			case 1:
				int val;
				cout<<"Enter the data: ";
				cin>>val;
				l.insert_front(val);
				break;
            case 2:
				int val2;
				cout<<"Enter the data: ";
				cin>>val2;
				l.insert_end(val2);
				break;
            case 3:
                l.delete_front();
                break;
            case 4:
                cout<<"Displaying the Double Ended Queue: ";
				l.display();
                cout<<"\n";
                break;
            case 5: break;
			default:
				cout<<"Invalid choice\n";
				break;
		}
	}while (c!=5);
}

int main(void){
    int c1;
    do{
        cout<<"\n\n------- Double Ended Queue Options --------\n\n";
        cout<<"1. Input Restricted(End)\n2. Output Restricted(Front)\n3. Exit from Program\n--------------------\n";
        cout<<"Enter your choice: ";
        cin>>c1;
        switch(c1){
            case 1:
                ipResDEqueue();
                break;
            case 2:
                opResDEqueue();
                break;
            case 3:
                break;
            default:
                cout<<"Invalid Choice\n";
                break;
        }
    }while(c1!=3);
	
	
	
	return 0;
}


/*
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
                cout<<"Displaying the Stack: ";
				l.display();
                cout<<"\n";
                break;
            case 4: break;
			default:
				cout<<"Invalid choice\n";
				break;
		}
	}while (c!=4);
*/

