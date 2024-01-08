package JAVA.Linked_List;
/*
* Linked List:
* -> Insert at front.
* -> Insert at back.
* -> Insert at any position.
* -> Delete at front.
* -> Delete at back.
* -> Delete at any position.
* -> Reverse.
* */
import java.util.Scanner;
class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
}

class Linkedlist{
    public static Node insert_at_front(Node root,int data){
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
    public static Node insert_at_back(Node root,int data){
        Node temp=new Node(data);
        if(root==null){
            root=temp;
            return root;
        }temp.next=root;
        root=temp;
        return root;
    }
    public static void display(Node root){
        Node ptr=root;
        while (ptr!=null){
            System.out.print(ptr.data+"\t");
            ptr=ptr.next;
        }System.out.println();
    }
    public static Node insert_at_any(Node root,int data,int pos){
        Node temp=new Node(data);
        if(pos==1){
            temp.next=root;
            root=temp.next;
        }else {
            Node ptr = root;
            for (int i = 1; i <= pos - 2 && ptr != null; i++) {
                ptr = ptr.next;
            }
            if (ptr == null) {
                System.out.println("Invalid Position");
                return root;
            }temp.next=ptr.next;
            ptr.next=temp;
        }return root;
    }
    public static Node delete_front(Node root){
        Node ptr=root;
        Node prev=ptr;
        if(ptr==null){
            System.out.println("Nothing to delete.");
            return root;
        }
        while (ptr.next!=null){
            prev=ptr;
            ptr=ptr.next;
        }prev.next=null;
        return root;
    }
    public static Node delete_back(Node root){
        if(root==null){
            System.out.println("Nothing to delete.");
            return root;
        }root=root.next;
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
            ptr=ptr.next;
            if(ptr==null){
                System.out.println("Invalid Position");
                return root;
            }
        }prev.next=ptr.next;
        return root;
    }
    public static Node reverse(Node root){
        Node prev,curr,next;
        curr=root;
        prev=null;
        next = curr.next;
        while (curr.next!=null){
            curr.next=prev;
            prev=curr;
            curr=next;
            next=curr.next;
        }curr.next=prev;
        root=curr;
        return root;
    }
}
public class LL {
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
            System.out.println("7.To reverse the Linked List");
            System.out.println("8.To display the LL");
            System.out.println("9.To exit the application\n");
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
                    root=Linkedlist.reverse(root);
                    break;
                case 8:
                    Linkedlist.display(root);
                    break;
                case 9:
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
