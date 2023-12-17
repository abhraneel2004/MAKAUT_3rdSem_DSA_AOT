#include<stdio.h>
#define MAX 100

int n,front = -1, rear = -1;
int arr[MAX];

void insert(int data){
    if (rear == n){
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front++; 
        rear++;
    }
    arr[rear++]= data;
}

void remove_(){
    if (front ==rear){
        printf("Queue Underflow\n");
        return;
    }
    front++;
}


void peek(){
    if (front==-1 || front ==rear){
        printf("Queue Underflow\n");
        return;
    }
    printf("Queue Front: %d\n", arr[front]);
}

void display(){
    if (front==-1 || front ==rear){
        printf("Queue Underflow\n");
        return;
    }
    int temp = front;
    
    while(temp<rear){
        //printf("\n%d---%d\n", temp,rear);
        printf("%d -> ", arr[temp++]);
    }
    printf("NULL\n");
}

int main(void){
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int ch,val;
    do{
        printf("\n--------Queue Operations--------\n1. Insert\n2. Delete\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                remove_();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                break;
            default: 
                printf("Invalid Choice");
                break;
        }
    }while(ch!=5);
    return 0;
}