#include<iostream>
#define MAX 100
using namespace std;

class Array1{
    int arr[MAX];
    int len;
    public:
        Array1(){
            this->len = 0;
        }
        void readArr(){
            cout<<"Enter the length of Array (<100): ";
            cin>>len;
            if (len>MAX){
                cout<<"Exceeded maximum limit"<<endl;
                return;
            }
            for(int i = 0; i<len; i++){
                cout<<"Enter element"<<i+1<<": ";
                cin>>arr[i];
            }
        }
        void showArr(){
            if(!len){
                cout<<"Empty array"<<endl;
                return;
            }
            for(int i = 0; i<len; i++){
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
        int searchEle(int val){
            if(!len){
                cout<<"Empty array"<<endl;
                return -1;
            }
            for(int i = 0; i<len; i++){
                if (arr[i]==val){
                    cout<<"Element found at index "<<i<<endl;
                    return i;
                }
            }
            cout<<"Element NOT found"<<endl;
            return -1;
        }
        void insertIdx(int idx, int val){
            if (!len || idx>len-1){
                arr[len++]=val;
                return;
            }
            if((idx<0)){
                cout<<"Invalid Index"<<endl;
                return;
            }
            for(int i = len-1; i>=idx; i--){
                arr[i+1]=arr[i];
            }
            len++;
            arr[idx]=val;
            return;
        }
        void updateIdx(int idx, int nval){
            if(!len){
                cout<<"Empty array"<<endl;
                return;
            }
            if((idx<0 || idx>len-1)){
                cout<<"Invalid Index"<<endl;
                return;
            }
            arr[idx] = nval;
        }
        void removeEle(int val){
            int idx = searchEle(val);
            if (idx==-1){
                return;
            }
            cout<<"Deleted Element: "<<arr[idx]<<endl;
            for (int i = idx; i<len;i++){
                arr[i]=arr[i+1];
            }
            
            len--;
        }
};

int main(void){
    Array1 a;
    int c,val,idx,nval,key;
    do{
        cout<<"\n-----------------\n    Array Operatations      \n";
        cout<<"1. Read Array\n2. Update\n3. Search\n4. Insert\n5. Remove\n6. Display\n7. Exit.\n-------------\n";
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c){
            case 1:
                a.readArr();
                break;
            case 2:
                cout<<"Enter the Index:";
                cin>>idx;
                cout<<"Enter the new Value: ";
                cin>>nval;
                a.updateIdx(idx, nval);
                break;
            case 3:
                cout<<"Enter the element to search: ";
                cin>>val;
                a.searchEle(val);
                break;
            case 4:
                cout<<"Enter Position: ";
                cin>>idx;
                cout<<"Enter the element to Insert: ";
                cin>>val;
                a.insertIdx(idx, val);
                break;
            case 5:
                cout<<"Enter element to remove: ";
                cin>>val;
                a.removeEle(val);
                break;
            case 6:
                cout<<"Array :";
                a.showArr();
                break;
            case 7:
                cout<<"Exiting the program\n";
                break;
            default:
                cout<<"Invalid Choice given\n";
                break;                
        }
    }while(c!=7);
    return 0;
}

/*
1,2,3,4,7,8,9,10,13,16,17,21
*/