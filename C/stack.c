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
    
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    push(3);
    push(7);
    push(9);
    printStack();
    peek();
    pop();
    printStack();
    
}