#include <iostream>
using namespace std;

struct Node
{

	int data;
	Node *lchild;
	Node *rchild;
	Node(int value)
	{
		data = value;
		lchild = NULL;
		rchild = NULL;
	}
};

class BST
{
	Node *root;

public:
	BST()
	{
		root = NULL;
	}
	Node *getRoot()
	{
		return root;
	}
	void insert(int val)
	{
		Node *ptr = new Node(val);
		if (!root)
		{
			root = ptr;
			return;
		} // root==NULL
		else
		{
			Node *currPtr = root;
			Node *parentPtr = NULL;
			while (currPtr)
			{ // currPtr!=NULL
				parentPtr = currPtr;
				if (val < currPtr->data)
					currPtr = currPtr->lchild;
				else
					currPtr = currPtr->rchild;
			}
			if (val < parentPtr->data)
				parentPtr->lchild = ptr;
			else
				parentPtr->rchild = ptr;
		}
		return;
	}

	void inorderTraversal(Node *tree)
	{
		if (tree)
		{
			inorderTraversal(tree->lchild);
			cout << tree->data << " ";
			inorderTraversal(tree->rchild);
		}
	}
	void preorderTraversal(Node *tree)
	{
		if (tree)
		{
			cout << tree->data << " ";
			preorderTraversal(tree->lchild);
			preorderTraversal(tree->rchild);
		}
	}

	void postorderTraversal(Node *tree)
	{
		if (tree)
		{

			postorderTraversal(tree->lchild);
			postorderTraversal(tree->rchild);
			cout << tree->data << " ";
		}
	}

	void search(int key)
	{
		if (!root)
		{
			cout << "Empty Tree";
			return;
		}
		Node *ptr = root;
		while (ptr)
		{
			if (key < ptr->data)
				ptr = ptr->lchild;
			else if (key > ptr->data)
				ptr = ptr->rchild;
			else
			{
				cout << "Element Found\n";
				return;
			}
		}
		cout << "Element Not Found\n";
		return;
	}

	void findLargestele(Node *tree)
	{ // sending root
		if (!tree)
		{
			cout << "Empty tree";
			return;
		}
		if (tree->rchild == NULL)
			cout << "Largest element: " << tree->data << endl;
		return;
		findLargestele(tree->rchild);
		return;
	}

	void findSmallestele(Node *tree)
	{
		// cout<<"here 1\n";
		if (!tree)
		{
			cout << "Empty Tree\n";
			return;
		}
		// cout<<"here 2\n";
		if (tree->lchild == NULL)
		{
			cout << "Smallest element: " << tree->data << "\n";
			return;
		}
		// cout<<tree->data<<" Recursive call to "<<tree->lchild<<endl;
		findSmallestele(tree->lchild);
		return;
	}

	int countNodes(Node *tree)
    {
        if (!tree)
            return 0;
        return 1 + countNodes(tree->rchild) + countNodes(tree->rchild);
    }

    int countInternalNodes(Node *tree)
    {
        if (!tree || (tree->lchild == nullptr && tree->rchild == nullptr))
            return 0;
        return 1 + countInternalNodes(tree->lchild) + countInternalNodes(tree->rchild);
    }

    int countExternalNode(Node *tree)
    {
        if (!tree)
            return 0;
        if (!tree->lchild && !tree->rchild)
            return 1;
        return countExternalNode(tree->lchild) + countExternalNode(tree->rchild);
    }

	void remove(int key)
	{
		if (!root)
			return;
		Node *x = root;
		Node *parent = NULL;
		while (x && x->data != key)
		{
			parent = x;
			if (key < x->data)
				x = x->lchild;
			else
				x = x->rchild;
		}
		if (!x)
		{
			cout << "data is not present\n";
			return;
		}
		if (!x->lchild || !x->rchild)
		{ // external Node
			Node *ptr;
			if (!x->lchild)
				ptr = x->rchild;
			else
				ptr = x->lchild;
			if (!parent)
			{
				delete root;
				root = ptr;
				return;
			}
			if (x == parent->lchild)
				parent->lchild = ptr;
			else
				parent->rchild = ptr;
			delete x;
			return;
		}
		else
		{
			Node *succ = x->rchild;
			Node *pSucc = NULL;
			while (succ->lchild)
			{
				pSucc = succ;
				succ = succ->lchild;
			}
			x->data = succ->data;
			if (!pSucc)
				x->rchild = succ->rchild;
			else
				pSucc->lchild = succ->lchild;
			delete succ;
			return;
		}
	}

	int height(Node *tree)
	{
		int L, R;
		if (!tree)
			return 0;
		L = height(tree->lchild);
		R = height(tree->rchild);
		if (L > R)
			return L + 1;
		return R + 1;
	}
};

int main(void)
{
	BST tr;
	int ch;

	do
	{
		cout << "\n\n---- BST Operations ----\n";
		cout << "1. Insert\n";
		cout << "2. Inorder Traversal\n";
		cout << "3. Preorder Traversal\n";
		cout << "4. Postorder Traversal\n";
		cout << "5. Search\n";
		cout << "6. Find largest element\n";
		cout << "7. Find Smallest element\n";
		cout << "8. Height of Tree\n";
		cout << "9. Element Remove\n";
		cout << "10. Count Total Nodes\n";
		cout << "11. Count Internal Nodes\n";
		cout << "12. Count External Nodes\n";
		cout << "13. Exit\n\n";
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			int dat;
			cout << "Enter the value: ";
			cin >> dat;
			tr.insert(dat);
			break;
		case 2:
			// point to remeber
			tr.inorderTraversal(tr.getRoot());
			cout << endl;
			break;
		case 3:
			// point to remeber
			tr.preorderTraversal(tr.getRoot());
			cout << endl;
			break;
		case 4:
			// point to remeber
			tr.postorderTraversal(tr.getRoot());
			cout << endl;
			break;
		case 5:
			int k;
			cout << "Enter the key: ";
			cin >> k;
			tr.search(k);
			cout << endl;
			break;
		case 6:
			tr.findLargestele(tr.getRoot());
			break;
		case 7:
			tr.findSmallestele(tr.getRoot());
			break;
		case 8:
			cout << "Height of the Tree is: " << tr.height(tr.getRoot()) << endl;
			break;
		case 9:
			int k1;
			cout << "Enter the element to remove: ";
			cin >> k1;
			tr.remove(k1);
			break;
		case 10:
			cout<<"Total No. of Nodes: "<<tr.countNodes(tr.getRoot())<<endl;
			break;
		case 11:
			cout<<"Total No. Internal of Nodes: "<<tr.countInternalNodes(tr.getRoot())<<endl;
			break;
		case 12:
			cout<<"Total No. External of Nodes: "<<tr.countExternalNode(tr.getRoot())<<endl;
			break;
		case 13:
			cout<<"Exiting the Program\n";
			break;
		default:
			cout << "Invalid choice please choose from the menu\n";
			break;
		}
	} while (ch != 13);
	return 0;
}
