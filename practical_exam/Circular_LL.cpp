#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node * next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class CLL{
    public:
    Node * last;
    CLL(){
        last = NULL;
    }
    
    void insertAtBegin(int data){
        Node * temp = new Node(data);
        if(!last){
            last = temp;
        }
        else{
            temp->next = last->next;
        }

        last->next = temp;
    }

    void insertAtEnd(int data){
        Node * temp = new Node(data);
        if(!last){
            last = temp;
            last->next = temp;
        }
        else{
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }

    void display(){
        if(!last){
            cout<<"Empty List\n";
            return;
        }
        Node * temp = last->next;
        while(temp!=last){
            cout<<temp->data<<"-> ";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }

    void delBeg(){
        if(!last){
            cout<<"Empty List\n";
            return;
        }
        if (last->next == last){
            last = NULL;
            return;
        }
        Node * temp = last->next;
        cout<<"Deleted Data: "<<temp->data<<endl;
        last->next = temp->next;
        delete temp;
    }
    void delEnd(){
        if(!last){
            cout<<"Empty List\n";
            return;
        }
        if (last->next == last){
            last = NULL;
            return;
        }
        Node * temp = last;
        while(temp->next!=last){
            temp = temp->next;
        }
            
        cout<<"Deleted Data: "<<temp->next->data<<endl;
        temp->next = last->next;
        last = temp;

    }
};


int main(void){
    CLL cl;
    int c,data;
    do{
        cout<<"\n---------\n1. Insert At begin\n2. Insert At end\n3. Display\n4. Delete from begin\n5. Delete from End\n6. Exit\n-------\n";
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c){
            case 1:
                cout<<"Enter the data: ";
                cin>>data;
                cl.insertAtBegin(data);
                break;
            case 2:
                cout<<"Enter the data: ";
                cin>>data;
                cl.insertAtEnd(data);
                break;
            case 3:
                cl.display();
                break;
            case 4:
                cl.delBeg();
                break;
            case 5:
                cl.delEnd();
                break;
            case 6:
                cout<<"Exiting the program\n";
                break;
        }
    }while(c!=6);
    return 0;
}