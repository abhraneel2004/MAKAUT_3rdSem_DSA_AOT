#include<iostream>
using namespace std;

const int MAX = 10;

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
    cout<<"Enter the number of rows: ";
    cin>>r;
    cout<<"Enter the number of columns: ";
    cin>>c;
    if(r>MAX || c>MAX){
        cout<<"the given number of rows/columns exceeded the maximum limit\n";
        return 1;
    }
    int array[MAX][MAX];
    cout<<"Enter the elements: ";
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cout<<"Enter element ("<<i<<","<<j<<") : ";
            cin>>array[i][j];
        }
    }
    cout<<"The given Matrix is: \n";
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cout<<array[i][j]<<"\t";
        }
        cout<<"\n\n";
    }
    if(sparseMatrix(array, r,c)){
        cout<<"\nThe given matrix is sparse\n";
    }
    else{
        cout<<"\nThe given matrix is NOT sparse\n";
    }
    return 0;
}