#include<stdio.h>

void towerOfHanoi(int n, char from, char aux, char to){
    if(n==1){
        printf("%c ------> %c\n", from, to);
        return;
    }
    towerOfHanoi(n-1, from, to, aux);
    printf("%c ------> %c\n", from, to);
    towerOfHanoi(n-1, aux, from, to);
    return;
}

int main(void){
    int n;
    printf("Enter the number of Disks: ");
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}