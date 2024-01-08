package JAVA.Linked_List;

import java.util.Scanner;
/*
 * Doubly Linked List:
 * -> Insert at front.
 * -> Insert at back.
 * -> Insert at any position.
 * -> Delete at front.
 * -> Delete at back.
 * -> Delete at any position.
 * */
class Node{
    int data;
    Node right;
    Node left;
    Node(int data){
        this.data=data;
        this.right=null;
        this.left=null;
    }
}

class Linkedlist{
    public static Node insert_at_front(Node root,int data){
        Node temp=new Node(data);
        if(root==null) {
            root = temp;
            return root;
        }Node ptr=root;
        while (ptr.right!=null)
            ptr=ptr.right;
        ptr.right=temp;
        temp.left=ptr;
        return root;
    }
    public static Node insert_at_back(Node root,int data){
        Node temp=new Node(data);
        if(root==null){
            root=temp;
            return root;
        }temp.right=root;
        root.left=temp;
        root=temp;
        return root;
    }
    public static void display(Node root){
        Node ptr=root;
        while (ptr!=null){
            System.out.print(ptr.data+"\t");
            ptr=ptr.right;
        }System.out.println();
    }
    public static Node insert_at_any(Node root,int data,int pos){
        Node temp=new Node(data);
        if(pos==1){
            root=Linkedlist.insert_at_back(root,data);
        }else {
            Node ptr = root;
            for (int i = 1; i <= pos - 2 && ptr != null; i++) {
                ptr = ptr.right;
            }
            if (ptr == null) {
                System.out.println("Invalid Position");
                return root;
            }temp.right=ptr.right;
            ptr.right=temp;
            temp.left=ptr;
            temp.right.left=temp;
        }return root;
    }
    public static Node delete_front(Node root){
        Node ptr=root;
        Node prev=ptr;
        if(ptr==null){
            System.out.println("Nothing to delete.");
            return root;
        }
        while (ptr.right!=null){
            prev=ptr;
            ptr=ptr.right;
        }prev.right=null;
        ptr.left=null;
        return root;
    }
    public static Node delete_back(Node root){
        if(root==null){
            System.out.println("Nothing to delete.");
            return root;
        }root=root.right;
        root.left=null;
        return root;
    }
    public static Node delete_any(Node root,int pos){
        if(root==null){
            System.out.println("Nothing to Delete");
            return root;
        }Node prev=null;
        Node ptr=root;
        for(int i=1;i<pos ;i++){
            prev=ptr;
            ptr=ptr.right;
            if(ptr==null){
                System.out.println("Invalid Position");
                return root;
            }
        }prev.right=ptr.right;
        ptr.right.left=prev;
        ptr.right=null;
        ptr.left=null;
        return root;
    }
}
class Doubly_LL {
    public static void main(String[] args) {
        System.out.println("======Welcome To LinkedList===========");
        Node root = null;
        int data, pos;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Enter you'r choice");
            System.out.println("1.Insert an element at the front end of the LL");
            System.out.println("2.Insert am element at the back end of the LL");
            System.out.println("3.Insert an elemet at any position of the LL");
            System.out.println("4.Delete an element from the fromat");
            System.out.println("5.Delete an element from the back");
            System.out.println("6.Delete an element from any position");
            System.out.println("7.To display the LL");
            System.out.println("8.To exit the application\n");
            System.out.print("Entre the choice:");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Entre the element you want to insert:");
                    data = sc.nextInt();
                    root = Linkedlist.insert_at_front(root, data);
                    break;
                case 2:
                    System.out.print("Entre the element you want to insert:");
                    data = sc.nextInt();
                    root = Linkedlist.insert_at_back(root, data);
                    break;
                case 3:
                    System.out.print("Entre the element you want to insert:");
                    data = sc.nextInt();
                    System.out.print("Entre the position::");
                    pos = sc.nextInt();
                    root = Linkedlist.insert_at_any(root, data, pos);
                    break;
                case 4:
                    root = Linkedlist.delete_front(root);
                    break;
                case 5:
                    root = Linkedlist.delete_back(root);
                    break;
                case 6:
                    System.out.print("Enter the position:");
                    pos = sc.nextInt();
                    root = Linkedlist.delete_any(root, pos);
                    break;
                case 7:
                    Linkedlist.display(root);
                    break;
                case 8:
                    System.out.println("Thanks for using the application.");
                    System.out.println("===================================");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Wrong choice! Try again.");
            }
        } while (true);
    }
}