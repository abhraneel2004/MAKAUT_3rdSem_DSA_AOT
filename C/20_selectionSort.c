#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *a, int n){
    int i, j, minidx, temp;
    for(i = 0; i<n-1; i++){
        minidx = i;
        for(j = i+1; j < n; j++){
            if (*(a+minidx) > *(a+j))
                minidx = j;
        }
        if (minidx!=i){
            temp= *(a+minidx);
            *(a+minidx) = *(a+i);
            *(a+i) = temp;
        }
    }
}

int main(void){
    int n,i;
    printf("Enter the size of Array: ");
    scanf("%d",&n);
    int *a = (int *)malloc(n*sizeof(int));
    printf("Enter the elements: \n");
    for(i = 0; i < n; i++)
        scanf("%d",a+i);
    printf("Array: Before Sorting: \n");
    for(i = 0; i< n; i++)
        printf("%d\t", *(a+i));
    printf("\n");
    selectionSort(a,n);
    printf("Array After Sorting: \n");
    for(i = 0; i < n; i++)
        printf("%d\t", *(a+i));
    printf("\n");
    return 0;

}