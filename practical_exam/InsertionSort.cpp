#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int j;
    for(int i = 1; i<n;i++){
        int key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(void){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: \n";

    for (int i =0 ; i<n; i++){
        cout<<"Enter Element "<<i<<": ";
        cin>>arr[i];
    }

    cout<<"Array Before Sort: \n";
    for (int i =0 ; i<n; i++){
        
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    insertionSort(arr,n);
    cout<<"Array After Sort: \n";
    for (int i =0 ; i<n; i++){
        
        cout<<arr[i]<<"\t";
    }
    return 0;
}