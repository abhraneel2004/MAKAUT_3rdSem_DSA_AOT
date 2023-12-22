#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void enqueue(int data)
{
    struct Node *temp, *ptr;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Insufficient Memory!!\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;

    if (!head)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display()
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

void dequeue()
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

int main(void)
{
    int ch, val, key;
    do
    {
        printf("\n\n---------Queue Operations---------\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n-------------------\n");
        printf("Enter Your choice:  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Data to insert: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n-->\tExiting the Program\t<--\n\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (ch != 4);
    return 0;
}