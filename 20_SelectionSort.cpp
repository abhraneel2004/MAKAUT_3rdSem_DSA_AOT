#include <iostream>
using namespace std;

void swap(int *a, int i, int j){
    *(a+i) = *(a+i)^*(a+j); 
    *(a+j) = *(a+i)^*(a+j); 
    *(a+i) = *(a+i)^*(a+j); 
}

int main(void){
    int n; 
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Before Sorting the Array: \n";
    for (int i = 0; i<n; i++)
        cout<<arr[i]<<"\t";

    cout<<"\n\n~~~~~~~~~Selection Sort~~~~~~~~~\n\n";

    for (int i = 0; i<n-1; i++){
        int min = i;
        for (int j = i+1; j<n; j++){
            if (arr[min]>arr[j])
                min = j;
        }
        if (min!=i)
            swap(arr, i, min);
    }

    cout<<"After Sorting the Array: \n";
    for (int i = 0; i<n; i++)
        cout<<arr[i]<<"\t";
       
    return 0;
}