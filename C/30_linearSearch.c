#include<stdio.h>

int linearSearch(int arr[], int key, int n){
    int i;
    for(i = 0; i<n;i++){

        if (arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(void){
    int n, key, i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr1[n];
    printf("Enter the elements: \n");
    for(i = 0; i < n; i++){
        printf("Enter element %d: ", i);
        scanf("%d",&arr1[i]);
    }
    printf("Enter the elements to search : ");
    scanf("%d", &key);
    int idx = linearSearch(arr1, key, n);
    if (idx==-1)
        printf("Element NOT found in the list\n");
    else
        printf("Element found at index %d",i);
    return 0;
}