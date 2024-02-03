#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild, *rchild;
    Node(int data)
    {
        this->data = data;
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
    void insertion(int data)
    {
        Node *newNode = new Node(data);
        if (!root)
        {
            root = newNode;
        }
        else
        {
            Node *curr = root;
            Node *parent = NULL;
            while (curr)
            {
                parent = curr;
                if (newNode->data > curr->data)
                {
                    curr = curr->rchild;
                }
                else if (newNode->data < curr->data)
                {
                    curr = curr->rchild;
                }
            }
            if (newNode->data < parent->data)
            {
                parent->lchild = newNode;
            }
            else
            {
                parent->rchild = newNode;
            }
        }
    }

    void inorderTraversal(Node *tree)
    {
        if (tree)
        {
            inorderTraversal(tree->lchild);
            cout << tree->data << "\t";
            inorderTraversal(tree->rchild);
        }
    }

    void postorderTraversal(Node *tree)
    {
        if (tree)
        {
            cout << tree->data << "\t";
            postorderTraversal(tree->lchild);
            postorderTraversal(tree->rchild);
        }
    }

    void preorderTraversal(Node *tree)
    {
        if (tree)
        {
            preorderTraversal(tree->lchild);
            preorderTraversal(tree->rchild);
            cout << tree->data << "\t";
        }
    }

    void findLargestElement(Node *tree)
    {
        if (!tree)
        {
            cout << "Empty Tree\n";
            return;
        }
        if (!tree->rchild)
        {
            cout << "Largest Element : " << tree->data << endl;
            return;
        }
        findLargestElement(tree->rchild);
    }

    void findSmallestElement(Node *tree)
    {
        if (!tree)
        {
            cout << "Empty Tree";
            return;
        }
        if (!tree->lchild)
        {
            cout << "Smallest Element: " << tree->data << endl;
            return;
        }
        findSmallestElement(tree->lchild);
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

    int height(Node *tree)
    {
        if (!tree)
            return 0;
        int l, r;
        l = height(tree->lchild);
        r = height(tree->rchild);
        return min(l, r) + 1;
    }

    Node *getroot()
    {
        return root;
    }

    void deleteEle(int key){
        if(!root)
            return;
        Node * curr = root;
        Node * parent = NULL;
        while(curr){
            parent = curr;
            if(curr->data<key){
                curr = curr->lchild;
            }
            else{
                curr = curr->rchild;
            }
        }
        if(!curr){
            cout<<"Element Not Found\n";
            return;
        }
        if(!curr->lchild || !curr->rchild){
            //external node
            Node * ptr;
            if(!curr->lchild){
                ptr = curr->rchild;
            }
            else{
                ptr = curr->lchild;
            }
            if(!parent){
                delete root;
                root = ptr;
                return;
            }
            else if(curr==parent->lchild){
                parent->lchild = ptr;
            }
            else if(curr==parent->rchild){
                parent->rchild = ptr;
            }
            delete curr;
            return;
        }
        else{
            Node *succ = curr->rchild;
            Node *pSucc = nullptr;
            while(succ->lchild){
                pSucc = succ;
                succ = succ->lchild;
            }
            curr->data = succ->data;
            if(!pSucc){
                curr->rchild = succ->rchild;
            }
            else{
                pSucc->lchild = succ->lchild;
            }
            delete succ;
            return;
        }
    }
};

int main(void)
{
    BST b;
    int c, data;
    do
    {
        cout << "\n----BST Operation-----\n";
        cout << "1. Insert\n";
        cout << "2. InorderTraversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Largest Element\n";
        cout << "6. Smallest Element\n";
        cout << "7. Count Nodes\n";
        cout << "8. Count Internal Nodes\n";
        cout << "9. Count External Nodes\n";
        cout << "10. Height of the Tree\n";
        cout << "11. Deletion\n";
        cout << "12. Exit\n---------------------\n";
        cout << "Enter your choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter the data to be inserted: ";
            cin >> data;
            b.insertion(data);
            break;
        case 2:
            b.inorderTraversal(b.getroot());
            break;
        case 3:
            b.preorderTraversal(b.getroot());
            break;
        case 4:
            b.postorderTraversal(b.getroot());
            break;
        case 5:
            b.findLargestElement(b.getroot());
            break;
        case 6:
            b.findSmallestElement(b.getroot());
            break;
        case 7:
            cout << "Total Nodes" << b.countNodes(b.getroot()) << endl;
            break;
        case 8:
            cout << "Total Internal Nodes" << b.countInternalNodes(b.getroot()) << endl;
            break;
        case 9:
            cout << "Total External Nodes" << b.countExternalNode(b.getroot()) << endl;
            break;
        case 10:
            cout << "Height of the Tree is: " << b.height(b.getroot()) << endl;
            break;
        case 11:
            cout<<"Enter a tree element to delete: ";
            cin>>data;
            b.deleteEle(data);
            break;
        case 12:
            cout << "Exiting the Program" << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (c != 12);
}