package JAVA.stack;

import java.util.Scanner;
import java.util.Stack;
class Parenthesis{
    public static boolean check(String str){
        Stack<Character> stack=new Stack<>();
        boolean check=false;

        for(Character par:str.toCharArray()){
            if(par=='(' || par=='{' || par=='[') stack.push(par);
            if(stack.isEmpty()) return false;
            switch (par){
                case ')':
                    if(stack.pop()!='(') return false;
                    break;
                case '}':
                    if(stack.pop()!='{') return false;
                    break;
                case ']':
                    if(stack.pop()!='[') return false;
                    break;
            }
        }return true;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String str;
        System.out.print("Enter the string:");
        str= sc.nextLine();
        if(check(str)) System.out.println("Valid Expression");
        else System.out.println("In-Valid Expression");
    }
}