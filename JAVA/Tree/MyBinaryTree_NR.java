package JAVA.Tree;//comment out this line
/*
* Tree NON-Recurssively Coding [Author: Ayandip Pal]
* This code has::
* 1.The Tree Creation
* 2.The Pre-Order traversal
* 3.The In-order Traversal [Not behaveing Properly]
* 4.The Post-Order Traversal
* 5.The BFS algo
* */
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class MyBinaryTree_NR {
    static class TreeNode{
        int data;
        TreeNode left;
        TreeNode right;
        TreeNode(int data){
            this.data=data;
            this.right=null;
            this.left=null;
        }
    }
    static class BinaryTree{
        //Building The tree
        public static TreeNode BulidTree(TreeNode root,int data){
            TreeNode temp,ptr,par=null;
            ptr=root;
            while (ptr!=null){
                par=ptr;
                if(data< ptr.data)
                    ptr=ptr.left;
                else if(ptr.data<data)
                    ptr=ptr.right;
                else{
                    System.out.println("Duplicate data");
                    return root;
                }
            }
            temp=new TreeNode(data);
            if(par==null)
                root=temp;
            else if(data < par.data)
                par.left=temp;
            else
                par.right=temp;
            return root;
        }
        //Traversing the tree
        //PreOrder
        public static void Pre_order_Treaversal(TreeNode root){
            Stack<TreeNode> stack = new Stack<>();
            stack.push(root);
            while (!stack.isEmpty()){
                TreeNode temp=stack.pop();
                if(temp.right!=null) stack.push(temp.right);
                if(temp.left!=null) stack.push(temp.left);
                System.out.print(temp.data+"\t");
            }
        }
        //InOrder [Error needs to be fixed]
        public static void In_order_traversal(TreeNode root){
            TreeNode ptr=root;
            Stack <TreeNode> stack = new Stack<>();
            do {
                while (ptr.left!=null){
                    stack.push(ptr);
                    ptr=ptr.left;
                }while (ptr.right==null){
                    System.out.print(ptr.data+'\t');
                    if(stack.isEmpty())
                        return;
                    ptr=stack.pop();
                }
                System.out.print(ptr.data+"\t");
                ptr=ptr.right;
            }while(true);
        }
        //PostOrder
        public static void Post_order_traversal(TreeNode root){
            TreeNode q=root;
            Stack<TreeNode> stack = new Stack<>();
            do{
                while (root.left!=null){
                    stack.push(root);
                    root=root.left;
                }while (root.right==null || root.right==q){
                    System.out.print(root.data+"\t");
                    q=root;
                    if(stack.isEmpty()) return;
                    root=stack.pop();
                }stack.push(root);
                root=root.right;
            }while(true);
        }
        public static void BFS_Tree(TreeNode root){
            Queue<TreeNode> queue = new LinkedList<>();
            if(root==null){
                System.out.println("Nothing to show");
                return;
            }
            queue.add(root);
            while (!queue.isEmpty()){
                int size= queue.size();
                for (int i=0;i< size;i++) {
                    if (queue.peek().left != null) queue.add(queue.peek().left);
                    if (queue.peek().right != null) queue.add(queue.peek().right);
                    System.out.print(queue.remove().data+"\t");
                }
            }
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        TreeNode root=null;
        int choice,item;
        System.out.println("==========Welcome to Tree DS===================");
        while (true){
            System.out.println("\nEnter you'r choice ::");
            System.out.println("1.To insert an element.");
            System.out.println("2.To see the Pre-order Traversal of the tree.");
            System.out.println("3.To see the In-order Traversal of the tree.");
            System.out.println("4.To see the Post-Order Traversal of the tree.");
            System.out.println("5.Breadth First Search[BFS].");
            System.out.println("6.To exit the application.");
            System.out.print("You'r choice::");
            choice=sc.nextInt();
            switch (choice){
                case 1:
                    System.out.print("Enter the value you want to insert ::");
                    item=sc.nextInt();
                    root=BinaryTree.BulidTree(root,item);
                    break;
                case 2:
                    if(root==null)
                        System.out.println("Nothing to print");
                    else
                        BinaryTree.Pre_order_Treaversal(root);
                    break;
                case 3:
                    if(root==null)
                        System.out.println("Nothing to print");
                    else
                        BinaryTree.In_order_traversal(root);
                    break;
                case 4:
                    if(root==null)
                        System.out.println("Nothing to print");
                    else
                        BinaryTree.Post_order_traversal(root);
                    break;
                case 5:
                    //In this algo we are going to use collection Frameworks Queue
                    BinaryTree.BFS_Tree(root);
                    break;
                case 6:
                    System.out.println("==========Thanks for using the application=========");
                    System.out.println("*****************************************************");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Wrong Choice,Please try again");
            }
        }
    }    
}
