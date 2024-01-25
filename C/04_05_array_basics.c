#include<stdio.h>
#define MAX 10

int arr[MAX];

void readArr(int n){
    for (int i=0; i<n; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void showArr(int n){
    for (int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}

void searchArr(int n, int val){
    if (n<=MAX){

        for (int i=0; i<n; i++){
    
            if (arr[i]==val){
        
                printf("Element found at index %d\t", i);
                return;
            }
                
        }

        printf("Element NOT found");
        return;
    }
}

int insertArr(int n, int val){
    if(n-1<9){
        arr[n]=val;
        return 1;
    }
    return 0;
}

int delArr(int n, int key){
    if(sizeof(arr)/sizeof(int)==0)
        return 0;
    for(int i = key; i < n; i++){
        arr[i]=arr[i+1];
    }
    return 1;
}

int delVal(int n,int val){
    if(sizeof(arr)/sizeof(int)==0)
        return 0;
    
    int idx = -1;
    for(int i = 0; i < n; i++){
        if (arr[i]==val){
            idx=i;
        }
    }
    if(idx==-1)
        return 0;
    else{
        int j;
        for( j= idx; j < n; j++){
            arr[j]=arr[j+1];
        }
        arr[j]=0;
        return 1;
    }
}

void updateArr(int n, int key, int val){
    int i;
    // printf("key:%d, val:%d",key,val);
    for(i=0; i<n; i++){
        // printf("Here 1\n");
        if(arr[i]==key){

            arr[i] = val;
            return;
        }
    }
}

int main(void){
    int n,c,key,val;
    printf("Enter the size of array <=10: ");
    scanf("%d",&n);
    if(n<0 || n>MAX){
        printf("size must be under 0 - 10:");
        return -1;
    }
    do{
        printf("\n----------\nArray Operations:\n1. Read Array\n2. Show Array\n3. Search Element\n4. Insert Element\n5. Delete Postition\n6. Delete Value\n7. Update Value\n8. Exit\n---------\nEnter your choice: ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            readArr(n);
            break;
        case 2:
            showArr(n);
            break;
        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &val);
            searchArr(n,val);
            break;
        case 4:
            printf("Enter element to insert: ");
            scanf("%d", &val);
            if(insertArr(n,val))
                n++;
            break;
        case 5: 
            printf("Enter the position of the element to delete: ");
            scanf("%d", &key);
            if(delArr(n,key))
                n--;
            break;
        case 6:
            printf("Enter the value you want to delete: ");
            scanf("%d", &val);
            if(delVal(n,val))
                n--;
            break;
        case 7:
            printf("Enter the element you want to update: ");
            scanf("%d", &key);
            printf("Enter the value you want to change with: ");
            scanf("%d", &val);
            updateArr(n,key,val);
            break;
        case 8:
            printf("Exiting from the program");
            break;
        default:
            break;
        }

    }while(c!=8);
    return 0;
}