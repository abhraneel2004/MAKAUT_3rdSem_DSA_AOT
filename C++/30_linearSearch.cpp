#include<iostream>
using namespace std;

int linearSearch(int arr[], int key, int n){
    int i;
    for(i = 0; i < n; i++){
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main(void){
    int key, n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: \n";
    for(int i = 0; i < n; i++){
        cout<<"Enter element "<<i<<": ";
        cin>>arr[i];
    }

    cout<<"Enter element to search: ";
    cin>>key;
    int idx = linearSearch(arr, key, n);
    if (idx==-1)
        cout<<"Element not found in the array\n";
    else
        cout<<"Element found at index "<<idx<<endl;
    return 0;
}