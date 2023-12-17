#include<stdio.h>
#include<string.h>

int isdigit1( char x){
	if (x>='0' && x<= '9')
		return 1;
	return 0;
}

int isnum1( char inp[]){
int i =0;
	while(inp[i]!='\0'){
		if (isdigit1(inp[i])){
			i++;
			continue;
		}
		return 0;
	}
	return 1;
}

int conv( char inp[]){
	int i = 0, res = 0;
	while(inp[i]!='\0'){
		res=10*res+(inp[i]-'0');
		i++;
	}
	return res;
}

int isfloat1( char inp[]){
	int i = 0, dot =0;
	while (inp[i]!='\0'){
		if (isdigit1(inp[i]))
			i++;
		else if (inp[i]=='.' && dot==0){
			dot++;
			i++;
		}
		else
			return 0;
	}
	return 1;
}

int isnegative1(char inp[]){
	if (inp[0]=='-'){
		int i =1;
		while (inp[i]!='\0'){
			if (isdigit1(inp[i])){
				i++;
				continue;
			}
			return 0;
		}
		return 1;
	}
}

int isstring1(char inp[]){
	if (isnum1(inp) || isfloat1(inp) || isnegative1(inp)){
		return 0;
	}
	return 1;
}



int main(void){
	char input[8];
	printf("Enter String: ");
	gets(input);
	
	if (isnum1(input)){
		printf("%s is an integer\n",input);
		printf("The number is %d\n", conv(input));
	}
	
	if (isfloat1(input)){
		printf("%s is a floating point number\n", input);
	}
	
	if (isstring1(input)){
		printf("%s is a string\n", input);
	}
	
	if (isnegative1(input)){
		printf("%s is a negative number\n", input);
	}
	
	else{
		printf("Invalid Input\n");
	}
	
	return 0;
}
