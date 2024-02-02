#include<iostream>
using namespace std;
#define MAX 10

class Queue1{
    int front, rear;
    int arr[MAX];
    public:
        Queue1(){
            front =-1;
            rear = -1;
        }
        int isFull(){
            return rear ==MAX-1;
        }
        int isEmpty(){
            return front == rear && rear ==-1;
        }
        void insert(int val){
            if(isFull()){
                cout<<"Queue Overflow\n";
                return;
            }
            arr[++rear]=val;
        }
        void delete_(){
            if(isEmpty()){
                cout<<"Queue Underflow\n";
                return;
            }
            front++;
            if (front==rear){
                front=-1;
                rear =-1;
            }
        }
        void display(){
            if(isEmpty()){
                cout<<"Queue Empty\n";
                return;
            }
            int temp = front+1;
            for(int i = front+1; i<=rear;i++){
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
};      

int main(void){
    Queue1 q;
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