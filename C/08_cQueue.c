#include<stdio.h>
#define MAX 100

int n, front = -1, rear = -1;
int arr[MAX];



void insert(int data){
    if (front == (rear+1)%n){
        printf("Queue is Full");
        return;
    }
    if(front == -1)
        front = rear = 0;
    else
        rear = (rear + 1)%n;
    arr[rear] = data;
}

void remove_(){
    if (front==-1){
        printf("Queue Underflow\n");
        return;
    }
    if(front == rear)
        front = rear = -1;
    else
        front= (front+1)%n;
}


void peek(){
    if (front==-1){
        printf("Queue Underflow\n");
        return;
    }
    printf("Queue Front: %d\n", arr[front]);
}

void display(){
    int i;
    if (front==-1){
        printf("Queue Underflow\n");
        return;
    }
    
    if(front<=rear){
        //printf("\n%d---%d\n", temp,rear);
        for(i = front; i<=rear; i++)
            printf("%d -> ", arr[i]);
    }
    else{
        for(i = front; i<=n-1; i++)
            printf("%d -> ", arr[i]);
        for(i =0; i<=rear; i++)
            printf("%d\t", arr[i]);
    }
    printf("\n");
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