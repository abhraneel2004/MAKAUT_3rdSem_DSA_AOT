package JAVA.Linked_List;

import java.util.Scanner;
/*
 * Circular Linked List:
 * -> Insert at front.
 * -> Insert at back.
 * -> Insert at any position.
 * -> Delete at front.
 * -> Delete at back.
 * -> Delete at any position.
 * */
class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
}

class Linkedlist{
    public static Node insert_at_front(Node last,int data){
        Node temp=new Node(data);
        if(last==null)
            temp.next=temp;
        else{
            temp.next=last.next;
            last.next=temp;
        }
        last=temp;
        return last;
    }
    public static Node insert_at_back(Node last,int data){
        Node temp=new Node(data);
        if(last==null)
            last=temp;
        else{
            temp.next=last.next;
            last.next=temp;
        }
            return last;
    }
    public static void display(Node last){
        Node ptr=last.next;
        if(last==null) return;
        while (ptr!=last){
            System.out.print(ptr.data+"\t");
            ptr=ptr.next;
        }System.out.println(ptr.data+"\n");
    }
    public static Node insert_at_any(Node last,int data,int pos){
       Node temp=new Node(data);
       Node ptr;
       if(pos==1){
           if(last==null)
               last=temp;
           else
               temp.next=last.next;
           last=temp;
       }
       else{
           if(last==null){
               System.out.println("Invalid Position.");
               return last;
           }ptr=last.next;
           for(int i=1;i<pos-1;i++){
               ptr=ptr.next;
               if (ptr==last.next){
                   System.out.println("Invalid Position");
                   return last;
               }
           }
           temp.next=ptr.next;
           ptr.next=temp;
           if(ptr==last)
               last=temp;
       }return last;
    }
    public static Node delete_front(Node last){
        if(last==null){
            System.out.println("Deletion Not possible");
            return last;
        }Node ptr=last.next;
        if(last.next==last)
            last=null;
        else{
            while (ptr.next!=last)
                ptr=ptr.next;
            ptr.next=last.next;
            last=ptr;
        }return last;
    }
    public static Node delete_back(Node last){
        if(last==null) {
            System.out.println("Deletion is not possible[No elements]");
            return last;
        }
        if(last.next==last)
            last=null;
        else
            last.next=last.next.next;
        return last;
    }
    public static Node delete_any(Node last,int pos){
        Node prev=last.next;
        if(last==null){
            System.out.println("Nothing to delete");
            return last;
        }Node ptr=last.next;
        if(pos==1){
            if(last==last.next)
                last=null;
            else
                last.next=ptr.next;
        }else{

            for(int i=1;i<=pos-1;i++){
                prev=ptr;
                ptr=ptr.next;
                if(ptr==last.next){
                    System.out.println("Invalid Position");
                    return last;
                }
            }
            prev.next=ptr.next;
            if(ptr==last){
                last=prev;
            }
        }
        return last;
    }
}
class Circular_LL {
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
