package JAVA.Tree; //Comment this line out at the time of using.
/*
 * Tree RECURSSIVE approach [Author: Ayandip Pal]
 * This code has::
 * 1.The Tree Creation
 * 2.The Pre-Order traversal
 * 3.The In-order Traversal
 * 4.The Post-Order Traversal
 * 5.The BFS algo
 * 6.Deletion from Binary Tree.
 * 6.The DFS algo == Post Order Traversal
 * */

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class MyBinaryTree{
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
            if(root==null)
                root=new TreeNode(data);
            else if(root.data > data)
                root.left=BulidTree(root.left,data);
            else if(root.data<data)
                root.right=BulidTree(root.right,data);
            else
                System.out.println("The Value is alredy inserted.");
            return root;
        }
        //Deletion::
        public static int In_Suc(TreeNode root){
            TreeNode ptr=root;
            int ptr_val=0;
            while (ptr!=null){
                ptr_val=ptr.data;
                ptr=ptr.left;
            }return ptr_val;
        }
        public static TreeNode delete(TreeNode root,int data){
            if(root==null) return root;
            if(data< root.data) root.left = delete(root.left,data);
            else if(data> root.data) root.right=delete(root.right,data);
            else{
                if(root.left==null) return root.right;
                else if(root.right==null) return root.left;

                root.data=In_Suc(root.right);
                root.right=delete(root.right,root.data);
            }return root;
        }
        //Traversing the tree
        //PreOrder
        public static void Pre_order_Treaversal(TreeNode root){
            if(root!=null){
                System.out.print(root.data+"\t");
                Pre_order_Treaversal(root.left);
                Pre_order_Treaversal(root.right);
            }}
        //InOrder
        public static void In_order_traversal(TreeNode root){
            if (root!=null) {
                In_order_traversal(root.left);
                System.out.print(root.data + "\t");
                In_order_traversal(root.right);
            }
        }
        //PostOrder
        public static void Post_order_traversal(TreeNode root){
            if(root!=null) {
                Post_order_traversal(root.left);
                Post_order_traversal(root.right);
                System.out.print(root.data + "\t");
            }
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
            System.out.println("6.To delete an element.");
            System.out.println("7.To exit the application.");
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
                    System.out.print("Enter the data you want to delete::");
                    int data=sc.nextInt();
                    root=BinaryTree.delete(root,data);
                    break;
                case 7:
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