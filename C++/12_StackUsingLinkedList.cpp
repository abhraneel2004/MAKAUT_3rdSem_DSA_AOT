#include <iostream>
using namespace std;

// structure of a node in C++

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// single linked list creation

class StackLL
{
    Node *head;

public:
    StackLL()
    {
        head = NULL;
    }
    void push(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if (!head)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node * temp = head;
        head = head->next;
        delete temp;
        return;
    }

    void peek()
    {
        if (!head)
        {
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        cout << temp->data << endl;
    }

    void display()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL \n";
    }
};

int main(void)
{
    StackLL l;
    int c;
    cout << "Stack Operations\n";
    do
    {
        cout << "-----------------------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "-----------------------\n";
        cout << "Enter Your choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            int val;
            cout << "Enter the data: ";
            cin >> val;
            l.push(val);
            break;
        case 2:
            l.pop();
            break;
        case 3:
            l.peek();
            break;
        case 4:
            cout << "Displaying the Stack: ";
            l.display();
            cout << "\n";
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (c != 5);

    return 0;
}
