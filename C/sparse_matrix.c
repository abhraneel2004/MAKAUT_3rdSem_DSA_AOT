#include<stdio.h>
#define MAX 10

int sparseMatrix(int arr[MAX][MAX], int rows, int cols){
    int k= 0.66*(rows*cols);
    
    int count = 0;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if (arr[i][j]==0)
                count++;
            if (count>k)
                return 1;
        }
    }
    
    return 0;
}

int main(void){
    int r,c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    if(r>MAX || c>MAX){
        printf("the given number of rows/columns exceeded the maximum limit\n");
        return 1;
    }
    int array[MAX][MAX];
    printf("Enter the elements: ");
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            printf("Enter element (%d, %d): ", i,j);
            scanf("%d", &array[i][j]);
        }
    }
    printf("The given Matrix is: \n");
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            printf("%d\t",array[i][j]);
        }
        printf("\n\n");
    }
    if(sparseMatrix(array, r,c)){
        printf("\nThe given matrix is sparse\n");
    }
    else{
        printf("\nThe given matrix is NOT sparse\n");
    }
    return 0;
}