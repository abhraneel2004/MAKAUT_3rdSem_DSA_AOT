#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class CLL{
    public:
    Node * head;
    CLL(){
        head = nullptr;
    }

    void insert_at_begining(int data){
        Node * newnode = new Node(data);
        if (!head){
            head = newnode;
            head->next = head;
        }
        else{
            Node * temp = head;
            while(temp->next !=head) temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    void insert_at_end(int data){
        Node * newnode = new Node(data);
        if (!head){
            head = newnode;
            head->next = head;
        }
        if (head->next==head){
            head->next = newnode;
            newnode->next = head;
        }
        else{
            Node * temp = head;
            while(temp->next!=head) temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
        }
    }

    void display(){
       
        if (!head){
            cout<<"Empty List\n";
            return;
        }
        else if(head->next == head)cout<<head->data<<"\n";
        else{
            Node * temp = head;
            while(temp->next!=head){
                cout<<temp->data<<"-> ";
                temp = temp->next;
            }
            cout<<temp->data<<"->"<<head->data<<"\n";
            
        }
        
    }

    void delfront(){
        if (!head){
            cout<<"Empty list";
        }
        if (head->next==head){
            delete head;
            head = NULL;
        }
        else{
            Node * last = head;
            Node * temp = head;

            while(last->next!=head) last = last->next;
            last->next = head->next;
            head = head->next;
            delete temp;
        }
        
    }
    void delend(){
        if (!head){
            cout<<"Empty list";
        }
        if (head->next==head){
            delete head;
            head = NULL;
        }
        else{
            Node * last = head;
            while(last->next->next!=head) last = last->next;
            Node * temp = last->next;
            last->next = head; 
            delete temp;
        }
        
    }
};

int main(void){
    //The main function can be done using menu but for the sake of simplicity, i am using static inputs

    CLL list;
    cout<<"New list created\nBefore Adding value: ";
    list.display();
    list.insert_at_begining(50);
    list.insert_at_begining(30);
    list.insert_at_begining(60);
    list.insert_at_end(10);
    list.insert_at_end(40);
    cout<<"After all insertions: ";
    list.display();
    list.delfront();
    list.delend();
    cout<<"After all deletions: ";
    list.display();
}