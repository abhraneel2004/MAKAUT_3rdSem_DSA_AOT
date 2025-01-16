#include<iostream>
using namespace std;

class Node{
    public:
    Node * prev;
    int data;
    Node * next;
    Node(int d){
        prev = nullptr;
        data = d;
        next = nullptr;
    }
};

class DLL{
    Node * head;
    public:
    DLL(){
        head = NULL;
    }
    void insert_at_beginning(int value){
        Node * newnode = new node(value);
        if(!head){
            head = newnode;
            return;
        }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return; 
    }

    void insert_at_end(int value){
        Node * newnode = new Node(value);
        if (!head){
            newnode->next = head;
            head = newnode;
            return;
        }
        Node * temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        return;
    }

    void display(){
        
        if (!head){
            cout<<"Empty Doubly linked list\n";
            return;
        }
        Node * temp = head;
        while(temp->next){
            cout<<temp->data<<"-> ";
            temp = temp->next;
        }
        cout<<temp->data<<"\n";
        return;
    }
    void delBeg(){
        if (!head){
            cout<<"Empty Doubly linked list\n";
            return;
        }
        if (!head->next){
            delete head;
            head = NULL;
            return;
        }
        Node * temp = head;
        head = head->next;
        temp->next = nullptr;
        head->prev = nullptr;
        cout<<"Deleted : "<<temp->data<<endl;
        delete temp;
        return;
    }

    void delEnd(){
        if (!head){
            cout<<"Empty Doubly linked list\n";
            return;
        }
        if (!head->next){
            delete head;
            head = NULL;
            return;
        }
        Node * temp = head;
        while(temp->next->next){
            temp = temp->next;
        }
        Node * temp2 = temp->next;
        temp2->prev = nullptr;
        temp->next = nullptr;
        cout<<"Deleted : "<<temp2->data<<endl;
        delete temp2;
        return;
    }

    void delitem(int value){
        if(!head){
            cout<<"Empty Doubly linked list\n";
        }
        if (head->data == value) {
            delBeg();
            return;
        }
        Node * temp = head;
        while(temp && temp->data != value) {
            temp = temp->next;
        }
        if (temp){
            cout<<"Deleted : "<<temp->data<<endl;
            if(temp->next)
                temp->next->prev = temp->prev;
            if(temp->prev)
                temp->prev->next = temp->next;
            if(temp==head)
                head = temp->next;
        }else
            cout<<value<<" not found in the list"<<endl;
        delete temp;
        
        
        return;
    }

    
};

int main(void){
    //The main function can be done using menu but for the sake of simplicity, i am using static inputs

    DLL list;
    cout<<"New list created\nBefore Adding value: ";
    list.display();
    list.insert_at_beginning(50);
    list.insert_at_beginning(30);
    list.insert_at_beginning(60);
    list.insert_at_end(10);
    list.insert_at_end(40);
    cout<<"After all insertions: ";
    list.display();
    list.delBeg();
    list.delEnd();
    list.delitem(15);
    list.delitem(30);
    cout<<"After all deletions: ";
    list.display();
    return 0;
}
