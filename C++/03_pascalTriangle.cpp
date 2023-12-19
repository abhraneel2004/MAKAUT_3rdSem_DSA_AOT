#include <iostream>
using namespace std;

int main(void){
	int n, coeff;
	cout<<"Enter no. of rows: ";
	cin>>n;
	for (int i =0; i<n; i++){
		if(i%2==1)cout<<"\t";
		for (int k =0; k<((n-i)/2); k++)
			cout<<"\t\t";
		for (int j = 0; j<=i; j++){
			if (i==0|| j==0){
				coeff=1;
			}
			else{
				coeff = coeff*(i-j+1)/j;
			}
			cout<<"\t%d\t", coeff;
			
		}
		cout<<"\n";
	}
	return 0;
}
