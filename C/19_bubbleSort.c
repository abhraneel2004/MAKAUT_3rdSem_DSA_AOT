#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *a, int n){
    int i, j, c =0, temp;
    for (i = 0; i<n-1; i++){
        for(j = 0 ; j<n-i-1; j++){
            if (*(a+j)> *(a+j+1)){
                temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
                c=1;
            }
        }
        if(!c)
            break;
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
    bubbleSort(a,n);
    printf("Array After Sorting: \n");
    for(i = 0; i < n; i++)
        printf("%d\t", *(a+i));
    printf("\n");
    return 0;

}