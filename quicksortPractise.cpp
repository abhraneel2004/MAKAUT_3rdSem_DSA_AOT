#include <iostream>
using namespace std;

void swap(int *a, int i, int j){
    *(a+i) = *(a+i)^*(a+j);
    *(a+j) = *(a+i)^*(a+j);
    *(a+i) = *(a+i)^*(a+j);
}

int Partition(int * a, int low, int high){
    int pivot, i, j;
    pivot = *(a+low);
    j = low;
    for ( i = low+1; i<= high; i++){
        if (*(a+i) < pivot){
            j++;
            if (i!=j)
                swap(a, i,j);
        }
    }
    if (low!=j)
        swap(a, j,low);
    return j;
}

void Quicksort (int * a, int low, int high){
    if (high> low){
        int p = Partition(a, low, high);
        Quicksort(a, 0, p-1);
        Quicksort(a, p+1,high);
    }
}

int main(void){
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: \n";
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Before Sorting the array is: \n";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
    
    Quicksort(arr, 0, n-1);

    cout<<"After Sorting the array is: \n";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
    
    return 0;
}