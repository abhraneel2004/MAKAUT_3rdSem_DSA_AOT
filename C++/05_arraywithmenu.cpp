#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 100
class Array
{
    int arr[MAX];
    int size;
    public:
    void read();
    void insert(int,int); 
    void deleteval(int);
    void deletePos(int);
    int searchele(int);
    void update(int,int);
    void display();
    int valid(int);
};
int Array::valid(int p)
{
    if(p<0 || p>size)
    {
        cout<<"Invalid position.";
        return 0;
    }
    return 1;
}
void Array::read()
{
    cout<<"Enter the size of the array :";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter Element - "<<i+1<<" :";
        cin>>arr[i];
    }
}

void Array::insert(int pos,int ele)
{
    if(valid(pos))
    {
        if(size==pos)
        {
            size++;
            arr[pos]=ele;
            return;
        }
        else
        {
            for(int i=size;i<=pos;i--)
            {
                arr[i+1]=arr[i];
            }
            arr[pos]=ele;
            size++;
            return;
        }
    }
}

void Array::deleteval(int val)
{
    int pos=searchele(val);
    if(pos!=-1 && pos<=size)
    {
        deletePos(pos);
        return;
    }
    return;
}

void Array::deletePos(int pos)
{
    for(int i=pos+1;i<=size;i++)
    {
        arr[i-1]=arr[i];
    }
    size--;
}

int Array::searchele(int ele)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==ele)
        {
            cout<<"The element is found at index :"<<i<<endl;
            return i;
        }
    }
    cout<<"The element is not found.";
    return -1;
}

void Array::update(int pos,int ele)
{
    if(valid(pos))
    {
        arr[pos]=ele;
        cout<<"Updation is completed.";
        return;
    }
    else
    {
        cout<<"Invalid index value.";
        return;
    }
}

void Array::display()
{
    cout<<"The elements of the array are :";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main (void)
{
    Array a;
    int choice;
    a.read();
    while(choice)
    {
        cout<<"\n\n";
        cout<<"-------------------------------------"<<endl;
        cout<<"      ::Array Operations::"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"1. Show Array"<<endl;
        cout<<"2. Search element"<<endl;
		cout<<"3. Insert element"<<endl;
        cout<<"4. Delete element by Index"<<endl;
		cout<<"5. Delete element by value"<<endl;
		cout<<"6. Update element"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"Enter Your Choice: ";
		cin>>choice;
		cout<<"\n";
        switch (choice)
        {
        case 1:
            a.display();
            break;
        case 2:
            int num;
            cout<<"Enter an element to search :";
            cin>>num;
            a.searchele(num);
            break;
        case 3:
            int pos,ele;
            cout<<"Enter the position to insert :";
            cin>>pos;
            cout<<"Enter an element to insert :";
            cin>>ele;
            if(a.valid(pos))
                a.insert(pos,ele);
            break;
        case 4:
            int pos1;
            cout<<"Enter the position to delete :";
            cin>>pos1;
            if(a.valid(pos))
                a.deletePos(pos1);
            break;
        case 5:
            int ele1;
            cout<<"Enter an value to delete :";
            cin>>ele1;
            a.deleteval(ele1);
            break;
        case 6:
            int pos2,ele2;
            cout<<"Enter the position to update :";
            cin>>pos2;
            cout<<"Enter an element to update :";
            cin>>ele2;
            if(a.valid(pos))
                a.update(pos2,ele2);
            break;
        case 7:
            cout<<"Exiting the program";
            exit(1);
            break;
        default:
            cout<<"Invalid choice.";
            break;
        }
    }
    return 0;
}