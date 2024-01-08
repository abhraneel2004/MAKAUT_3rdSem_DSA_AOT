/*Code for Stack using JAVA
* Author :: Ayandip Pal
* This Code is the implementation of stack[Containing Int vals] in JAVA Using ArrayList*/
import java.util.Scanner;
import java.util.ArrayList;
class StaCk{
    ArrayList<Integer> array=new ArrayList<>();
    public void display(){
        if(array.isEmpty())
            System.out.println("The stack is Empty");
        else
            System.out.println(array);
    }
    public int peek(){
        return array.get(array.size()-1);
    }
    public boolean isEmpty(){
        return array.isEmpty();
    }
    public void push(int item){
        array.add(item);
        System.out.println("An item was Successfully inserted in the stack;");
    }
    public int pop(){
        int top= array.get(array.size()-1);
        array.remove(array.size()-1);
        return top;
    }
}
class Test{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        StaCk stack= new StaCk();

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
                    stack.push(item);
                    break;
                case 2:
                    System.out.println("The poped item was:"+stack.pop());
                    break;
                case 3:
                    stack.display();
                    break;
                case 4:
                    if(stack.isEmpty())
                        System.out.println("Stack is Empty");
                    else
                        System.out.println("Stack is not empty");
                    break;
                case 5:
                    System.out.println("The top element of the stack is :"+stack.peek());
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