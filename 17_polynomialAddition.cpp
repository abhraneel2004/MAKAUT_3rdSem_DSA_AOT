#include<iostream>
using namespace std;

struct Node{
	int coeff;
	int exp;
	Node * next;
};

class Poly{
	Node * head;
	public:
		Poly(){
			head = NULL;
		}
		void insert(int c, int e){
			Node * curr = new Node;
			curr -> coeff = c;
			curr-> exp = e;
			curr->next = NULL;
			if(!head){
				head = curr;
				return;
			}
			
			
			Node * temp = head;
			if (curr->exp>head->exp){
				curr->next = head;
				head = curr;
				return;
			}
			
			else{
				while(temp->next){
					if (curr->exp==temp->exp){
						temp->coeff = curr->coeff+temp->coeff;
						return;
					}
					temp = temp->next;
				}
				temp->next = curr;
				return;
			}
			return;
		}
		Poly operator + (Poly &p){
			Node * h1 = head;
			Node * h2= p.head;
			Poly result;
			while (h1 && h2){
				if(h1->exp > h2->exp){  
					result.insert(h1->coeff,h1->exp);
					h1 = h1->next;
					
				}
				else if(h2->exp > h1->exp){
					result.insert(h2->coeff,h2->exp);
					h2 = h2->next;
				}
				else if(h2->exp==h1->exp){
					result.insert(h1->coeff+h2->coeff, h1->exp);
					h1 = h1->next;
					h2 = h2->next;
				}
			}
			// when one of the polynomial ended 
			
			//if some terms of h1 still remained then it will be directly added to the result
			
			while (h1){
				result.insert(h1->coeff,h1->exp);
				h1 = h1->next;
			}
			
			//else if some terms of h2 still remained then it will be directly added to the result
			
			while (h2){
				result.insert(h2->coeff,h2->exp);
				h2 = h2->next;
			}
			return result;
		}
		
		void display(){
			Node * h = head;
			if (!h){
				cout<<0<<endl;
				return;
			}
			while(h->next){
				cout<<h->coeff<<"x^"<<h->exp;
				if(h->next->coeff>=0){
					cout<<"+";
				}
				h=h->next;
			}
			cout<<h->coeff<<"x^"<<h->exp<<endl;
		}
};

int main(void){
	Poly p1, p2, p3;
	char ch, ch2;
	cout<<"Polynomial 1:\n";
	do{
		int cf, ex;
		cout<<"Enter the coefficient: ";
		cin>>cf;
		cout<<"Enter the exponent: ";
		cin>>ex;
		p1.insert(cf,ex);
		cout<<"Do you want to enter more terms? (y/n) : ";
		cin>>ch;
	}while(ch!='n');
	
	cout<<"Polynomial 1: ";
	p1.display();
	cout<<endl;
	
	cout<<"Polynomial 2:\n";
	do{
		int cf, ex;
		cout<<"Enter the coefficient: ";
		cin>>cf;
		cout<<"Enter the exponent: ";
		cin>>ex;
		p2.insert(cf,ex);
		cout<<"Do you want to enter more terms? (y/n) : ";
		cin>>ch2;
	}while(ch2!='n');
	
	cout<<"Polynomial 2: ";
	p2.display();
	cout<<endl;
	
	p3 = p1+p2; //operator overloading
	cout<<"Polynomial 1 + Polynomial 2 = ";
	p3.display();
	cout<<endl;
	
	
	return 0;
}
