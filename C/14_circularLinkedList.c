#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * last = NULL;

void insertBeg(int data) {
    struct Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	if(temp==NULL){
		printf("Insufficient Memory");
		exit(0);
	}
	temp->data=data;
	if(last==NULL){/*Node Inserted as first Node*/
		last=temp;
	}
	else{
		/*Node inserted as any other node*/
		temp->next=last->next;
	}
    last->next=temp;
}


void insertEnd(int data){
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    if(!temp){
        printf("Insufficient memory\n");
        exit(0);
    }
    temp->data = data;
    if(!last){
        temp->next = temp;
    }
    else{
        temp->next = last->next;
        last->next = temp;
    }
    last = temp;
}

void insertAny(int key,int data){
    int c2;
    if (!last){
        printf("Empty list. No Nodes Found.\n");
        return;
    }
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *temp, *parent;
    temp = last->next;
    parent = last;
    do{
        
        if(temp->data==key){
            printf("\n---Options----\n1. Add Before\n2. Add After\n-------\n");
            printf("Enter your choice (1 or 2):");
            scanf("%d",&c2);
            if (c2==1){
                newNode->next = temp;
                parent->next = newNode;
                return;
            }
            else if (c2==2){
                newNode->next = temp->next;
                temp->next = newNode;
                if(temp==last)
                    last = newNode;
                return;
            }
            else{
                printf("Invalid Option given. Returning from the function.\n");
                return;
            }
        }

        parent = temp;
        //printf("%d-> ", temp->data);
        temp = temp->next;
    }while(temp!=last->next);
    if(temp==last)
        printf("\nNode not found in the list.\n");
    return;
}


void delBeg(){
    if(!last){
        printf("Empty List\n");
        return;
    }

    struct Node * temp = last->next;
    if(last->next== last){
        last = NULL;
    }
    else{
        last->next = temp->next;
    }
    free(temp);
    temp = NULL;
}

void delEnd(){
    if(!last){
        printf("Empty List\n");
        return;
    }
    if(last->next==last){
        last = NULL;
        return;
    }
    struct Node * temp = last;
    while(temp->next!=last){
        temp = temp->next;
    }
    temp->next = last->next;
    free(last);
    last = temp;

}

void delItem(int key){
    if(!last){
        printf("Empty List\n");
        return;
    }
    struct Node *temp, *parent;
    temp = last->next;
    parent = last;
    do{
        if (temp->data == key){
            parent->next = temp->next;
            if(temp==last)
                last = parent;
            return;
        }
        parent = temp;
        temp = temp->next;
    }while(temp!=last->next);
    if(temp==last->next){
        printf("Node Not Found\n");
        return;
    }
    return;
}

void display(){
    struct Node *ptr;
	if(last==NULL){
		printf("No Node in Linked List to Display");
		return;
	}
	ptr=last->next;
	while(ptr!=last){
		printf("%d ->",ptr->data);
		ptr=ptr->next;
	}
	printf("%d ->",ptr->data);
    printf("\n");
}

int main(void){
    int c,i, val, key;
    do{
        printf("\n\n----Circular Linked List Operations---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Any\n4. Delete from Beginning\n5. Delete from End\n6. Delete Item\n7. Display\n8. Exit\n-----------------\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c)
            case 1:
                printf("Enter the data: ");
                scanf("%d", &val);
                insertBeg(val);
                break;
            case 2: 
                printf("Enter the data: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 3:
                printf("Enter the key in the linked list: ");
                scanf("%d", &key);
                printf("Enter the data to be inserted: ");
                scanf("%d", &val);
                insertAny(key, val);
                break;
            case 4:
                delBeg();
                break;
            case 5:
                delEnd();
                break;
            case 7:
                display();
                break;
            case 6:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                delItem(key);
                break;
            case 8:
                break;
            default:
                printf("Invalid choice\n");
                break;
        
    }while(c!=8);

    return 0;
}
