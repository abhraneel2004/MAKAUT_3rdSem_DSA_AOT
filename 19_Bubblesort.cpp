#include <iostream>
using namespace std;


void swap(int * ptr, int i, int j){
    *(ptr + i) = *(ptr+i) ^ *(ptr + j);
    *(ptr + j) = *(ptr+i) ^ *(ptr + j);
    *(ptr + i) = *(ptr+i) ^ *(ptr + j);
}
int main(void){
    int n,c;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: \n";
    for (int i = 0; i<n ; i++)
        cin>>arr[i];
    cout<<"Before Sorting the array is :\n";
    for (int i = 0; i<n ; i++)
        cout<<arr[i]<<"\t";
    
    cout<<"\n\n~~~~~~~~~Bubble Sort~~~~~~~~~\n\n";

    for (int i = 0; i<n-1; i++){
        c = 0;
        for (int j = 0; j<n-i-1; j++){
            if (arr[j]>arr[j+1]){
                c++;
                swap(arr, j, j+1);
            }
        }
        if (!c) break;
    }
    
    cout<<"After Sorting the array is :\n";
    for (int i = 0; i<n ; i++)
        cout<<arr[i]<<"\t";
    cout<<"\n";
    

    return 0;
}