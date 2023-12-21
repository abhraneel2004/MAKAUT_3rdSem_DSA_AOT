#include<iostream>
using namespace std;

void merge(int arr[], int si, int mid, int ei){
    int merged[ei-si+1];

    int x = 0, idx1 = si, idx2 = mid+1;
    while(idx1<=mid && idx2<=ei){
        if (arr[idx1] >arr[idx2])
            merged[x++] = arr[idx2++];
        else
            merged[x++] = arr[idx1++];
    }

    while(idx1<=mid)
        merged[x++] = arr[idx1++];
    while( idx2<=ei)
        merged[x++] = arr[idx2++];
    
    for (int i = 0; i <= ei - si; i++)
        arr[si + i] = merged[i];
}

void mergeSort(int arr[], int si, int ei){
    if(si>=ei) return;
    int mid = si+ (ei-si)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    merge(arr, si, mid, ei);
}

int main(void){
    int i, n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Array Before Sort: \n";
    for(i = 0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    mergeSort(arr, 0, n-1);

    cout<<"Array After Sort: \n";
    for(i = 0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}