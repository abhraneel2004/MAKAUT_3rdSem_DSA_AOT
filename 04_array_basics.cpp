#include <iostream>
using namespace std;
#define MAX 100

class Array{
	
	int arr[MAX];
	int len;
	public:
	void readArray();
	void show();
	int searchElement(int);
	void insertElement(int, int);
	void deletePos(int);
	void deleteVal(int);
	void update(int, int);
	
};

int validint(int a){
	if (a<0 || a>MAX){
		cout<<"Invalid"<<endl;
		return 0;
	}
	return 1;
}

int main(void){
	Array a;
	a.readArray();
	a.show();
	
	/// Searching ///
	cout<<"\n\nSearching\n";
	int n;
	cout<<"Enter an element to search: ";
	cin>>n;
	a.searchElement(n);
	
	///Insertion ///
	cout<<"\n\nInsertion\n";
	int pos,ele;
	cout<<"Enter the element to insert: ";
	cin>>ele;
	cout<<"Enter the position: ";
	cin>>pos;
	if (validint(pos)){
		a.insertElement(ele, pos);
		a.show();
	}
	
	/// Delete from Index ///
	cout<<"\n\nDelete from Index\n";
	int d1;
	cout<<"Enter position to delete: ";
	cin>>d1;
	if (validint(pos)){
		a.deletePos(d1);
	
		a.show();
	}
	
	/// Delete from value ///
	cout<<"\n\nDelete from Value\n";
	int val;
	cout<<"Enter a value to delete : ";
	cin>>val;
	a.deleteVal(val);
	
	a.show();
	
	//update
	cout<<"\n\nUpdate element\n";
	int key,value;
	cout<<"Enter Key : ";
	cin>>key;
	cout<<"Enter Value : ";
	cin>>value;
	if(validint(key)){
		a.update(key, value);
		a.show();
	}
	
	return 0;
}

void Array::readArray(){
	cout<<"Enter len: ";
	cin>>len;
	for(int i = 0; i<len; i++){
		cout<<"Enter Element "<<i+1<<": ";
		cin>>arr[i];
	}
}

void Array::show(){
	for(int i = 0; i<len; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int Array::searchElement(int n){
	
	for(int i = 0; i<len; i++){
		if (arr[i]==n){
			cout<<"Found at position : "<<i<<endl;
			return i;
		}
	}
	cout<<"Not Found";
	return -1;
}

void Array::insertElement(int ele, int pos){
	if (pos>len){
		cout<<"Invalid position for insertion"<<endl;
		return;
	}
	else if(pos==len){
		len++;
		arr[pos] = ele;
		return;
	}
	else{
		//shifting
		for(int i = len;i>=pos;i--){
			arr[i+1] = arr[i];
		}
		//changing
		arr[pos] = ele;
		len++;
		return;
	}
}

void Array::deletePos(int x){
	for(int i = x+1;i<len;i++){
		arr[i-1]=arr[i];
	}
	len--;
	return;
}

void Array::deleteVal(int val){
	int pos = searchElement(val);
	if (pos!=-1 && pos<=len){
		deletePos(pos);
		return;
	}
	return;
}

void Array::update(int key, int v3){
	if (key>len-1){
		cout<<"Invalid key"<<endl;
		return;
	}
	else{
		arr[key] = v3;
		return;
	}
}



