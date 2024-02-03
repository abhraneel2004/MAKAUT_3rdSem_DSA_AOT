#include<iostream>
using namespace std;

void maxHeap(int a[], int i, int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l<n && a[l]>a[largest]){
        largest = l;
    }
    if(r<n && a[r]>a[largest]){
        largest = r;
    }
    if(largest!=i){
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        maxHeap(a, largest,n);
    }
}

void heapify(int a[], int n){
    int i;
    for(i=n/2-1; i>=0; i--){
        maxHeap(a, i, n);
    }
}

void heapSort(int a[], int n){
    heapify(a,n);
    int i, temp;
    for(i = n-1; i>=1; i--){
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        maxHeap(a, 0,i);
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
    heapSort(arr,n);
    cout<<"Array After Sort: \n";
    for (int i =0 ; i<n; i++){
        
        cout<<arr[i]<<"\t";
    }
    return 0;

}