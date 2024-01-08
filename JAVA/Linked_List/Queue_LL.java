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

class MyQueue{
    public static Node insert(Node root,int data){
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
    public static Node delete(Node root){
        Node ptr=root;
        Node prev=ptr;
        if(ptr==null){
            System.out.println("Nothing to Remove.");
            return root;
        }if(ptr.next==null){
            System.out.println(root.data+"\twas popped");
            root=null;
            return root;
        }
        System.out.println(ptr.data+"\twas deleted.");
        root=root.next;
        return root;
    }
}
class Queue_LL{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        MyQueue queue=new MyQueue();
        Node top=null;
        do{
            System.out.println("\n============================================\n");
            System.out.println("Please Enter you'r Choice::");
            System.out.println("1.To Insert an element.");
            System.out.println("2.To Delete an element");
            System.out.println("3.To display all the elements");
            System.out.println("4.To exit the application.");
            System.out.print("Enter you'r choice :: ");
            int choice=sc.nextInt();
            System.out.println();
            switch (choice){
                case 1:
                    System.out.print("Enter the element you want to insert::");
                    int item=sc.nextInt();
                    top=queue.insert(top,item);
                    break;
                    //Value not returning.
                case 2:
                    top=queue.delete(top);
                    break;
                case 3:
                    queue.display(top);
                    break;
                case 4:
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