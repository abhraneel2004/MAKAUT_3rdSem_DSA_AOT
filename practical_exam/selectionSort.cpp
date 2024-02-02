#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int min = i;
        for(int j = i+1; j<n;j++){
            if (arr[min]>arr[j]){
                min = j;
            }
        }
        if (min!=i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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
    selectionSort(arr,n);
    cout<<"Array After Sort: \n";
    for (int i =0 ; i<n; i++){
        
        cout<<arr[i]<<"\t";
    }
    return 0;

}