package JAVA.sorting;
import java.util.Scanner;

class insertion{
    public static int[] insertion_sort(int[] arr){
        for(int i=1;i<arr.length;i++) {
            int item = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > item) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = item;
        }return arr;
    }
    public static void main(String[] args){
        System.out.println("==============INSERTION SORT==================");
        System.out.println("Enter the number of element to be sorted::");
        Scanner sc=new Scanner(System.in);
        int len=sc.nextInt();
        int[] arr=new int[len];
        System.out.println("Enter the elements:");
        for(int i=0;i<len;i++){
            System.out.print(i+1+".");
            arr[i]= sc.nextInt();
        }
        insertion_sort(arr);
        System.out.println("Array after sorting:");
        for(int i:arr)
            System.out.print(i+"\t");
        System.out.println();
        System.out.println("============================================");
    }
}