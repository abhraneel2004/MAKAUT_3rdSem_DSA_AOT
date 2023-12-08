#include <iostream>
using namespace std;

struct Node{

	int data;
	Node *lchild;
	Node *rchild;
	Node(int value){
		data = value;
		lchild = NULL;
		rchild = NULL;
	}
};

class BST{
	Node * root;
	public:
		BST(){
			root = NULL;
		}
		Node *getRoot(){
			return root;
		}
		void insert(int val){
			Node *ptr = new Node(val);
			if(!root) {root = ptr; return; } //root==NULL
			else{
				Node *currPtr = root;
				Node *parentPtr = NULL;
				while(currPtr){  //currPtr!=NULL
					parentPtr = currPtr;
					if(val<currPtr->data)
						currPtr=currPtr->lchild;
					else
						currPtr=currPtr->rchild;
				}
				if (val<parentPtr->data)
					parentPtr->lchild = ptr;
				else
					parentPtr->rchild = ptr;
			}
			return;
			
		}
		
		void inorderTraversal(Node *tree){
			if(tree){
				inorderTraversal(tree->lchild);
				cout<<tree->data<<" ";
				inorderTraversal(tree->rchild);
			}
			
		}
		void preorderTraversal(Node *tree){
			if(tree){
				cout<<tree->data<<" ";
				preorderTraversal(tree->lchild);
				preorderTraversal(tree->rchild);
			}
			
		}
		
		void postorderTraversal(Node *tree){
			if(tree){
				
				postorderTraversal(tree->lchild);
				postorderTraversal(tree->rchild);
				cout<<tree->data<<" ";
			}
			
		}
		
		void search(int key){
			if(!root){
				cout<<"Empty Tree";
				return;
			}
			Node *ptr=root;
			while(ptr){
				if(key<ptr->data) ptr=ptr->lchild;
				else if (key>ptr->data) ptr=ptr->rchild;
				else {
					cout<<"Element Found\n";
					return;
				}
			}
			cout<<"Element Not Found\n";
			return;
		}
		
		void findLargestele(Node * tree){          //sending root
			if(!tree){
				cout<<"Empty tree";
				return;
			}
			if(tree->rchild == NULL) 
				cout<<tree->data<<endl;
				return;
			findLargestele(tree->rchild);
		}
		
		void remove(int Key){
			it(!root) return;
			Node *x = root;
			Node *parent = NULL;
			while(x && x->data!=key){
				parent = x;
				if(key< x->data)
					x = x->lchild;
				else
					x = x->rchild;
			}
			if (!x){
				cout<<"Data Not present\n";
				return;
			}
			if(!x->lchild || !x->rchild){
				
			}
		}
		
		int hieght(Node * tree){
			int L,R;
			if (!tree) return 0;
			L = hieght(tree->lchild);
			R = hieght(tree->rchild);
			if (L>R)
				return L+1;
			return R+1;
		}
};

int main(void){
	BST tr;
	int ch;
	cout<<"---- BST Operations ----\n";
	cout<<"1. Insert\n";
	cout<<"2. Inorder Traversal\n";
	cout<<"3. Preorder Traversal\n";
	cout<<"4. Postorder Traversal\n";
	cout<<"5. Search\n";
	cout<<"6. Find largest element\n";
	cout<<"7. Element Remove\n";
	cout<<"8. Height of Tree\n";
	
	cout<<"10. Exit\n";
	do{
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
			case 1:
				int dat;
				cout<<"Enter the value: ";
				cin>>dat;
				tr.insert(dat);
				break;
			case 2:
				//point to remeber
				tr.inorderTraversal(tr.getRoot());
				cout<<endl;
				break;
			case 3:
				//point to remeber
				tr.preorderTraversal(tr.getRoot());
				cout<<endl;
				break;
			case 4:
				//point to remeber
				tr.postorderTraversal(tr.getRoot());
				cout<<endl;
				break;
			case 5:
				int k;
				cout<<"Enter the key: ";
				cin>>k;
				tr.search(k);
				cout<<endl;
				break;
			case 6:
				tr.findLargestele(tr.getRoot());
				break;
			case 8:
				cout<<"Height of the Tree is: "<<tr.hieght(tr.getRoot())<<endl;
				break;
			case 10:
				break;
			default:
				cout<<"Invalid choice please choose from the menu\n";
				break;
		}
	}while(ch!=10);
	return 0;
}
