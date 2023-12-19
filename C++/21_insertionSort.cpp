#include<iostream>
using namespace std;

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
    cout<<"Enter array size: ";
    cin >> n;
    int arr[n];
    cout<<"Enter array element: \n";
    for( i = 0; i < n; i++){
        cout<<"Enter element "<<i<<" : ";
        cin>>arr[i];
    }
    cout<<"Array before sorting: ";
    for( i = 0; i < n-1; i++){
        cout<<arr[i]<<", ";
    }
    cout<<arr[i]<<endl;
    InsertionSort(arr, n);
    cout<<"Insertion Sort done\n";
    cout<<"Array after sorting: ";
    for(i = 0; i < n-1; i++){
        cout<<arr[i]<<", ";
    }
    cout<<arr[i]<<endl;
    return 0;
}