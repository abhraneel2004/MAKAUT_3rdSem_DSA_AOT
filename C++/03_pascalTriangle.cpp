#include <iostream>
using namespace std;

int main(void){
	int n, coeff;
	printf("Enter no. of rows: ");
	scanf("%d",&n);
	for (int i =0; i<n; i++){
		if(i%2==1)printf("\t");
		for (int k =0; k<((n-i)/2); k++)
			printf("\t\t");
		for (int j = 0; j<=i; j++){
			if (i==0|| j==0){
				coeff=1;
			}
			else{
				coeff = coeff*(i-j+1)/j;
			}
			printf("\t%d\t", coeff);
			
		}
		printf("\n");
	}
	return 0;
}
