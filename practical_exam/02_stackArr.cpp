#include <iostream>
using namespace std;
#define MAX 10

class Stack1{
    int arr[MAX];
    int top;
    public:
    Stack1(){
        top = -1;
    }
    int isFull(){
        return top==MAX-1;
    }
    int isEmpty(){
        return top==-1;
    }
    int peek(){
        return arr[top];
    }
    void push(int val){
        if(isFull()){
            cout<<"Stack is Full 1\n";
            return;    
        }
        arr[++top]=val;
        return;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty 1\n";
            return;
        }
        cout<<"Deleted Item: "<<arr[top--];
        return;
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is Empty\n";
            return;
        }
        int temp = top;
        while(temp>=0){
            cout<<arr[temp]<<"\t";
            temp--;
        }
        cout<<endl;
    }
};

int main(void){
    Stack1 s;
    int key,c;
    do{
        cout<<"\n--------------\nStack Operation\n----------------\n";
        cout<<"1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n\nEnter your Choice: ";
        cin>>c;
        switch(c){
            case 1:
                cout<<"Enter the value to be inserted: ";
                cin>>key;
                s.push(key);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout<<"Stack Top Element is: "<<s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout<<"Exiting the Program.\n";
                break;
            default:
                cout<<"Invalid Choice\n";
                break;
                
        }
    }while (c!=5);
    return 0;
}