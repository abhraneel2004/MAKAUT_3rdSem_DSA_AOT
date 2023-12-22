#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBegin(int data)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    head = temp;
    return;
}

void insertAtEnd(int data)
{
    struct Node *temp, *ptr;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (!head)
    {
        temp->prev = NULL;
        head = temp;
        return;
    }
    ptr = head;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
    return;
}
void insertAtAny(int key, int data)
{
    if (!head)
    {
        printf("No Nodes present. Exiting from the function\n");
        return;
    }

    int c2;
    struct Node *newNode, *temp, *parent;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    temp = head;
    parent = NULL;

    while (temp)
    {
        if (temp->data == key)
        {
            printf("\n---Options----\n1. Add Before\n2. Add After\n-------\n");
            printf("Enter your choice: ");
            scanf("%d", &c2);

            if (c2 == 1)
            {
                if (parent)
                {
                    parent->next = newNode;
                }
                newNode->prev = parent;
                newNode->next = temp;
                temp->prev = newNode;
                if (parent == NULL)
                {
                    head = newNode; // Update head if the insertion is at the beginning
                }
                return;
            }
            else if (c2 == 2)
            {
                if (temp->next)
                {
                    newNode->next = temp->next;
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                newNode->prev = temp;
                return;
            }
        }
        parent = temp;
        temp = temp->next;
    }

    printf("Key not found in the list\n");
}

void display()
{
    struct Node *ptr;
    ptr = head;
    while (ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return;
}

void delBeg()
{
    if (!head)
    {
        printf("Empty list \n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    return;
}

void delEnd()
{
    if (!head)
    {
        printf("Empty List\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp = temp->prev;
    free(temp->next);
    temp->next = NULL;
    return;
}

void delItem(int key)
{
    if (!head)
    {
        printf("Empty List\n");
        return;
    }
    if (head->data == key)
    {
        delBeg();
        return;
    }
    struct Node *temp = head, *parent;
    while (temp && temp->data != key)
    {
        temp = temp->next;
    }
    parent = temp->prev;
    parent->next = temp->next;
    free(temp);
    return;
}

int main(void)
{
    int c, val, key;
    do
    {
        printf("\n\n-----Operations -----\n");
        printf("1. Insert at Beginning\n2. Insert At end\n3. Insert At Any Position\n4. Display\n5. Delete from Beginning\n6. Delete from End\n7.Delete Item\n8. Exit\n---------------\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &val);
            insertAtBegin(val);
            break;
        case 2:
            printf("Enter the data to be inserted: ");
            scanf("%d", &val);
            insertAtEnd(val);
            break;

        case 3:
            printf("Enter the key in the list: ");
            scanf("%d", &key);
            printf("Enter the data to be inserted: ");
            scanf("%d", &val);
            insertAtAny(key, val);
            break;
        case 4:
            display();
            break;
        case 5:
            delBeg();
            break;

        case 6:
            delEnd();
            break;
        case 7:
            printf("Enter the key to delete from the list: ");
            scanf("%d", &key);
            delItem(key);
            break;
        case 8:
            printf("\n-->\tExiting the Program\t<--\n");
            break;
        default:
            printf("Invalid choice given\n");
            break;
        }

    } while (c != 8);
}