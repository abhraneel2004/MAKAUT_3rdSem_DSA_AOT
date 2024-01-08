
package JAVA.Linked_List;
import java.util.Scanner;
class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
}

class StaCk{
    public static Node push(Node root,int data){
        Node temp=new Node(data);
        if(root==null) {
            root = temp;
            return root;
        }Node ptr=root;
        while (ptr.next!=null)
            ptr=ptr.next;
        ptr.next=temp;
        return root;
    }
    public static void display(Node root){
        if(root==null) {
            System.out.println("Stack is Empty");
            return;
        }
        Node ptr=root;
        while (ptr!=null){
            System.out.print(ptr.data+"\t");
            ptr=ptr.next;
        }System.out.println();
    }
    public static boolean isEmpty(Node root){
        if(root==null) return true;
        else return false;
    }
    //Not returning top element.
    public int peek(Node root){
        Node ptr=root;
        if(root==null) return -1;
        while (ptr.next!=null){
            ptr=ptr.next;
        }return ptr.data;
    }
    public static Node pop(Node root){
        Node ptr=root;
        Node prev=ptr;
        if(ptr==null){
            System.out.println("Nothing to Pop.");
            return root;
        }if(ptr.next==null){
            System.out.println(root.data+"\twas popped");
            root=null;
            return root;
        }
        while (ptr.next!=null){
            prev=ptr;
            ptr=ptr.next;
        }prev.next=null;
        System.out.println(ptr.data+"\twas popped");
        return root;
    }
}
class Stack_LL{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        StaCk stack= new StaCk();
        Node top=null;
        do{
            System.out.println("\n============================================\n");
            System.out.println("Please Enter you'r Choice::");
            System.out.println("1.To push an element on top of the stack.");
            System.out.println("2.To pop an element from the top of the stack.");
            System.out.println("3.To display all the elements in the stack.");
            System.out.println("4.To check if the Stack is empty");
            System.out.println("5.To see the top most element of the stak");
            System.out.println("6.To Exit the application");
            System.out.print("Enter you'r choice :: ");
            int choice=sc.nextInt();
            System.out.println();
            switch (choice){
                case 1:
                    System.out.print("Enter the element you want to insert::");
                    int item=sc.nextInt();
                    top=stack.push(top,item);
                    break;
                    //Value not returning.
                case 2:
                    top=stack.pop(top);
                    break;
                case 3:
                    stack.display(top);
                    break;
                case 4:
                    if(stack.isEmpty(top))
                        System.out.println("Stack is Empty");
                    else
                        System.out.println("Stack is not empty");
                    break;
                case 5:
                    System.out.println("The top element of the stack is :"+stack.peek(top));
                    break;
                case 6:
                    System.out.println("Thank you for using the application");
                    System.out.println("=========================================");
                    System.exit(0);
                    break;
                default:
                    System.out.println("\nWrong choice Please try again.\n");
            }
        }while (true);
    }
}