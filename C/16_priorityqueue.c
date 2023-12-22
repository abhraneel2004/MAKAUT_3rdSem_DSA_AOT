#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int data, int prio)
{
    struct Node *temp, *ptr;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Insufficient memory\n");
        exit(0);
    }
    temp->data = data;
    temp->priority = prio;
    temp->next = NULL;
    if (!head || prio > head->priority)
    {
        printf("Here\n");
        temp->next = head;
        head = temp;
        return;
    }
    ptr = head;
    while (ptr->next && ptr->next->priority > prio)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return;
}

void display()
{
    if (!head)
    {
        printf("Empty Priority Queue\n");
        return;
    }
    struct Node *temp = head;
    while (temp)
    {
        printf("<%d, %d>->  ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

void delete_()
{
    if (!head)
    {
        printf("Empty Queue\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    return;
}

int main(void)
{
    int c, val, prio;
    do
    {
        printf("\n--- Priority Queue ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n-----------------\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &val);
            printf("Enter the priority: ");
            scanf("%d", &prio);
            insert(val, prio);
            break;
        case 2:
            delete_();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n-->  Exiting the program  <--\n\n");
            break;
        default:
            printf("Wrong Choice entered.\n");
            break;
        }
    } while (c != 4);

    return 0;
}