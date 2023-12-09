#include<iostream>
using namespace std;

class Node{
    
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = NULL;
        }
};

class CQueueLL{
    public:
    Node * head;
    CQueueLL(){
        head=NULL;
    }

    void insert(int value){
        Node * newnode = new Node(value);
        if (!head){
            head = newnode;
            newnode->next = head;
            return;
        }
        else if (head->next == head){
            head->next = newnode;
            newnode->next = head;
            return;
        }
        else{
            Node * temp = head;
            while(temp->next != head) temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
            return;
        }
    }

    void delete_(){
        if (!head){
            cout<<"Queue Underflow\n";
            return;
        }
        if (head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        else{
            Node * t1 = head;
            Node * t2 = head;
            while(t1->next!=head) t1 = t1->next;
            t1->next = head->next;
            head = head->next;
            delete t2;
            return;
        }
    }

    void display(){
        if (!head){
            cout<<"Empty Queue\n";
            return;
        }
        else{
            Node * temp = head;
            while(temp->next != head){
                cout<<temp->data<<"-> ";
                temp = temp->next;
            }
            cout<<temp->data<<"-> "<<head->data<<endl;
            return;
        }
    }


};


int main(void){

    CQueueLL q;
    int c;
    do{
        cout<<"\n\n--------- Circular Queue Operations----------\n\n";
        cout<<"1. Insert\n2. Delete\n3. Display\n4. Exit\n-----------------\n";
        cout<<"Enter Your Choice: ";
        cin>>c;
        switch(c){
            case 1:
                int v;
                cout<<"Enter the data: ";
                cin>>v;
                q.insert(v);
                break;
            case 2:
                q.delete_(); break;
            case 3:
                q.display(); break;
            case 4:
                break;
            default:
                cout<<"Invalid Choice\n"<<endl;
                break;
        }
    }while(c!=4);
    return 0;
    
}