#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeg(int data)
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

void insertAtEnd(int data)
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

void insertAtany(int key, int data){
    struct Node * temp, *ptr, *parent;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if(!temp){
        printf("Insufficient Memory!!");
        return;
    }
    ptr = head;
    if (!ptr) {
        printf("Empty Linked List\n");
        return;}
    parent = NULL;
    while(ptr && ptr->data!=key){
            parent = ptr;
            ptr = ptr->next;
    }
    if (!ptr){
        printf("Item not present in the List\n");
        return;
    }
    int c2;
    printf("\nOptions:\n1. Add Before\n2. Add After\nEnter your Choice (1/2):  ");
    scanf("%d", &c2);
    if (c2==1){
        if (ptr==head){
            insertAtBeg(data);
            return;
        }
        temp->data = data;
        parent->next = temp;
        temp->next = ptr;
    }
    if (c2==2){
        temp->data = data;
        temp->next = ptr->next;
        ptr->next = temp;
        return;
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

void delBeg()
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

void delEnd()
{
    if (!head)
    {
        printf("Empty Linked List\n");
        return;
    }
    struct Node *ptr, *parent;
    parent = NULL;
    ptr = head;
    while (ptr->next)
    {
        parent = ptr;
        ptr = ptr->next;
    }
    parent->next = ptr->next;
    free(ptr);
    return;
}

void delItem(int item){
    if(!head){
        printf("Empty Linked List\n");
        return;
    }
    struct Node *ptr, *parent;
    ptr = head;
    parent = NULL;
    if(ptr->data==item){
        delBeg();
        return;
    }
    while(ptr && ptr->data!=item){
        parent = ptr;
        ptr = ptr->next;
    }
    if(!ptr){
        printf("Item not found in the List\n");
        return;
    }
    parent->next = ptr->next;
    free(ptr);
}


void bubbleSort(){
    if (!head || !head->next)return;
    struct Node *lptr, *tptr;
    int c;
    lptr = NULL;
    do{
        tptr = head;
        c=0;
        while(tptr->next!=lptr){
            if (tptr->data > tptr->next->data){
                int temp = tptr->data;
                tptr->data = tptr->next->data;
                tptr->next->data = temp;
                c=1;
            }
            tptr = tptr->next;
        }
        lptr = tptr;
    }while(c);
    return;
}

void reverse(){
    if(!head|| !head->next) return;
    struct Node *p =head, *r=NULL, *q;
    while(p){
        q = p;
        p = p->next;
        q->next = r;
        r = q;
    }
    head = q;
}

void search(int key){
    if (!head){
        printf("Item Not Found\n");
        return;
    }
    struct Node * temp = head;
    while(temp){
        if (temp->data == key){
            printf("Item Found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Item not found\n");
    return;
}

int main(void)
{
    int ch, val,key;
    do
    {
        printf("\n\n---------Linked List Operations---------\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Any Position\n4. Display\n5. Delete from Beginning\n6. Delete from End\n7. Delete Item\n8. Search\n9. Reverse\n10. Bubble Sort\n11. Exit\n-------------------\n");
        printf("Enter Your choice:  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Data to insert: ");
            scanf("%d", &val);
            insertAtBeg(val);
            break;
        case 2:
            printf("Enter the Data to insert: ");
            scanf("%d", &val);
            insertAtEnd(val);
            break;
        case 3:
            
            printf("Enter Position (item in linked list): ");
            scanf("%d", &key);
            printf("Enter the Data to insert: ");
            scanf("%d", &val);
            insertAtany(key, val);
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
            printf("Enter Item in linked list: ");
            scanf("%d", &key);
            delItem(key);
            break;
        case 8:
            printf("Enter Item in linked list: ");
            scanf("%d", &key);
            search(key);
            break;
        case 9:
            reverse();
            break;
        case 10:
            bubbleSort();
            break;
        case 11:
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (ch != 11);
    return 0;
}