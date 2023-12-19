#include<stdio.h>
#include<stdlib.h>

void InsertionSort(int* arr, int n){
    for(int i = 1; i<n; i++){
        int key = *(arr+i);
        int j = i-1;

        while (j>=0 && *(arr+j) > key){
            *(arr+j+1) = *(arr+j);
            j--;
        }
        *(arr+j+1) = key;

    }
}  

int main(void){
    int n,i;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array element: \n");
    for( i = 0; i < n; i++){
        printf("Enter element %d:",i);
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting: ");
    for( i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
    
    InsertionSort(arr, n);
    printf("\nInsertion Sort done\n");
    printf("Array after sorting: ");
    for( i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}