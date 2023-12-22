#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Insufficient Memory!!\n");
        return;
    }
    temp->data = data;
    temp->next = head;
    head = temp;
}


void display_()
{
    struct Node *ptr;
    if (!head)
    {
        printf("Empty Linked List\n");
        return;
    }
    ptr = head;
    while (ptr)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return;
}

void pop()
{
    if (!head)
    {
        printf("Empty Linked List\n");
        return;
    }
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return;
}

void peek_(){
    if(!head){
        printf("Empty Linked List\n");
        return;
    }
    else{
        printf("Stack Top: %d\n", head->data);
        return;
    }
}


int main(void)
{
    int ch, val, key;
    do
    {
        printf("\n\n---------Stack Operations---------\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n-------------------\n");
        printf("Enter Your choice:  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Data to push: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display_();
            break;
        case 4:
            peek_();
            break;
        case 5:
            printf("\n-->\tExiting the Program\t<--\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (ch != 5);
    return 0;
}