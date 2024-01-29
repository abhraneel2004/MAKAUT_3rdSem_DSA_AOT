#include<stdio.h>

void merged(int arr[], int si, int mid, int ei){
    int merge[ei-si+1];
    int x = 0, i1 = si, i2 = mid+1;
    while(i1<=mid && i2<=ei){
        if(arr[i1]>arr[i2])
            merge[x++] = arr[i2++];
        else
            merge[x++] = arr[i1++];
    }

    while(i1<=mid)
        merge[x++] = arr[i1++];
    while(i2<=ei)
        merge[x++] = arr[i2++];

    for (int i = 0; i<=ei-si; i++){
        arr[si+i] = merge[i];
    }
}


void mergeSort(int arr[], int si, int ei){
    if (si>=ei) return;
    int mid = si + (ei-si)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    merged(arr, si, mid, ei);
}


int main(void){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: \n");
    for (int i = 0; i<n; i++){
        printf("Enter element %d:", i);
        scanf("%d",&arr[i]);
    }

    printf("Array Before Sorting: \n");
    for (int i = 0; i<n; i++){
        printf("%d\t", arr[i]);
    }

    mergeSort(arr, 0, n-1);

    printf("\nArray After Sorting: \n");
    for(int i = 0; i<n; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}