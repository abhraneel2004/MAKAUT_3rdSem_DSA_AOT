#include<stdio.h>
#include<stdlib.h>
#define Max 100

int arr[Max];
int n, top = -1;

void push(int data){
    if (top==n-1){
        printf("Stack Overflow\n");
        return;
    }
    arr[++top] = data;
}

void pop(){
    if (top==-1){
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void peek(){
    if (top==-1){
        printf("Stack Underflow\n");
        return;
    }
    printf("Stack top: %d\n",arr[top-1]);
}

void printStack(){
    if (top==-1){
        printf("Stack Underflow\n");
        return;
    }
    int temp = top;
    while(temp>=0){
        printf("%d-> ",arr[temp--]);
    }
    printf("NULL\n");
}


int main(void){
    
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int ch,val;
    do{
        printf("\n--------Stack Operations--------\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                printStack();
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
    
}