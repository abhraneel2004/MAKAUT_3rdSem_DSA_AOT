#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    int c2=0;
    for(int i =0; i<n; i++){
        int c = 0;
        for (int j =0; j<n-i-1; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                c=1;
                
            }
            c2++;
        }
        if(!c)
            break;
    }
    cout<<"No of comparisons: "<<c2<<endl;
    return;
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
    bubbleSort(arr,n);
    cout<<"Array After Sort: \n";
    for (int i =0 ; i<n; i++){
        
        cout<<arr[i]<<"\t";
    }
    return 0;

}