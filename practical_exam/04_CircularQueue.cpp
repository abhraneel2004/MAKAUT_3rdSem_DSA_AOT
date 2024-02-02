#include<iostream>
using namespace std;
#define MAX 100

class CQueue{
    int arr[MAX];
    int front, rear;
    public:
    CQueue(){
        front = -1;
        rear = -1;
    }
    int isFull(){
        return front == (rear+1)%MAX;
    }
    int isEmpty(){
        return front==-1;
    }
    void insert(int data){
        if (isFull()){
            cout<<"Queue Overflow\n";
            return;
        }
        if (front==-1){
            front=0;
            rear = 0;
        }
        else{
            rear = (rear+1)%MAX;
        }
        arr[rear]=data;
    }

    void delete_(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        if(front==rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%MAX;
        }
    }
    void display(){
        if (isEmpty()){
            cout<<"Queue is Empty\n";
            return;
        }
        if (front<=rear){
            for (int i = front; i<=rear; i++){
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
        else{
            for (int i = front; i<MAX;i++){
                cout<<arr[i]<<"\t";
            }
            for (int i = 0; i<=rear;i++){
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
    }
};

int main(void){
    CQueue q;
    int key,c;
    do{
        cout<<"\n--------------\nQueue Operation\n----------------\n";
        cout<<"1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter your Choice: ";
        cin>>c;
        switch(c){
            case 1:
                cout<<"Enter the value to be inserted: ";
                cin>>key;
                q.insert(key);
                break;
            case 2:
                q.delete_();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout<<"Exiting the Program.\n";
                break;
            default:
                cout<<"Invalid Choice\n";
                break;
                
        }
    }while (c!=4);
    return 0;
}