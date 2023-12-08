#include <iostream>
using namespace std;

/*
void merge(int A[], int n, int B[], int m, int C[]){
	int i = 0, j = 0, k = 0;
	while (i<n && j<m){
		if(A[i]<B[j])
			C[k++] = A[i++];
		else
			C[k++] = B[j++];
	}
	while(i<n) C[k++] = A[i++];
	while(j<m) C[k++] = B[j++];
}

*/

void merge(int A[], int low, int mid, int high){
	int B[1000];
	int i = low;
	int j = mid+1;
	int k = low;
	while (i<=mid && j<=high){
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	while (i<=mid) B[k++] = A[i++];
	while (j<= high) B[k++] = A[j++];
	for (i = low; i<=high; i++){
		A[i] = B[i];
	}
}

void mergeSort(int A[], int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(A, low, mid);
		mergeSort(A, mid+1, high);
		merge(A, low, mid, high);
	}
}

int partition( int arr[], int low, int high){
	int pivot = arr[high];
	int i = low-1;
	int j;
	for (j = low; j<=high-1; j++){
		if(arr[j] <pivot){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		
	}
	int temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return i+1;
}

void Quicksort(int arr[], int low, int high){
	if( low<high){
		int j = partition(arr, low, high);
		Quicksort(arr, low, j-1);
		Quicksort(arr, j+1, high);
	}
}

void heapify(int arr[], int n, int i){
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if(left<n && arr[left]>arr[largest]) largest = left;
	if(right<n && arr[right]>arr[largest]) largest = right;
	if(largest!=i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr,n, largest);
	}
}

void heapsort(int arr[], int n){
	for (int i = n/2-1; i>=0; i--){
		heapify(arr, n, i);
	}
	for (int i = n-1; i>0; i--){
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		heapify(arr, i, 0);
	}
}




int main(void){
	int choice, n;
	

	int arr2[1000];

	
	
	
	do{
		cout<<"\n Menu \n";
		cout<<"1. Merge Sort \n";
		cout<<"2. Quick Sort \n";
		cout<<"3. Heap Sort\n";
		cout<<"4. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the number of elements: ";
				cin>>n;
				cout<<"Enter array elements: \n";
				for (int i = 0; i<n; i++)
					cin>>arr2[i];

				cout<<"Given Array: \n";
				for (int i = 0; i<n; i++)
					cout<<arr2[i]<<" ";
				cout<<endl;
				mergeSort(arr2, 0, n-1);
				cout<<"Merge Sort Completed\n";
				for (int i = 0; i<n; i++){
					cout<<arr2[i]<<" ";
				}
				cout<<endl;
				break;
			case 2:
				cout<<"Enter the number of elements: ";
				cin>>n;
				cout<<"Enter array elements: \n";
				for (int i = 0; i<n; i++)
					cin>>arr2[i];

				cout<<"Given Array: \n";
				for (int i = 0; i<n; i++)
					cout<<arr2[i]<<" ";
				cout<<endl;
				Quicksort(arr2, 0, n-1);
				cout<<"Quick Sort Completed\n";
				for (int i = 0; i<n; i++){
					cout<<arr2[i]<<" ";
				}
				cout<<endl;
				break;
			case 3:
				cout<<"Enter the number of elements: ";
				cin>>n;
				cout<<"Enter array elements: \n";
				for (int i = 0; i<n; i++)
					cin>>arr2[i];

				cout<<"Given Array: \n";
				for (int i = 0; i<n; i++)
					cout<<arr2[i]<<" ";
				cout<<endl;
				heapsort(arr2, n);
				cout<<"Heap Sort Completed\n";
				for (int i = 0; i<n; i++){
					cout<<arr2[i]<<" ";
				}
				cout<<endl;
				break;
			case 4:
				cout<<"Task Finished Succesfully";
				break;
			default:
				cout<<"Invalid Choice\n";
		}
	}while(choice !=4);

	return 0;
}
