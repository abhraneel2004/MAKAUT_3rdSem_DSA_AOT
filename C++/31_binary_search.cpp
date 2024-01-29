#include<iostream>
using namespace std;

int Partition(int * ptr, int low, int high){
    int pivot, i,j;
    pivot = *(ptr+low);
    j = low;
    for (i = low+1; i<=high;i++){
        if(*(ptr+i)<pivot){
            j++;
            if (i!=j){
                *(ptr+i) = *(ptr+i)^*(ptr+j);
                *(ptr+j) = *(ptr+i)^*(ptr+j);
                *(ptr+i) = *(ptr+i)^*(ptr+j);
            }
        }
    }
    if (low!=j){
        *(ptr+low) = *(ptr+low)^*(ptr+j);
        *(ptr+j) = *(ptr+low)^*(ptr+j);
        *(ptr+low) = *(ptr+low)^*(ptr+j);
        
    }
    return j;
}

void Quicksort(int * ptr, int low, int high){
    if (high > low){
        int p = Partition(ptr, low, high);
        Quicksort(ptr,0, p-1);
        Quicksort(ptr,p+1, high);
    }
}

int binarySearch(int arr[],int n,int key){
    int i;
    for (i=0;i<n;i++){
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: \n";
    for (int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Before sorting the array is:    \n";
    for (int i = 0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
    
    Quicksort(arr,0, n-1);
    cout<<"After sorting the array is:      \n";
    for (int i = 0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";

    int key, idx;
    cout<<"Enter the element to search: ";
    cin>>key;
    idx = binarySearch(arr,n, key);
    if(idx==-1)
        cout<<"Element not found in the list\n";
    else
        cout<<"Element found at index: "<<idx<<endl;
    return 0;
}