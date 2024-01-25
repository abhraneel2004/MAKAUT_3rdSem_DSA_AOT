import java.util.Scanner;

class TOH{
    public static void towerOfHanoi(int n, char from_, char to, char aux){
        if(n==1){
            System.out.println(from_+"------>"+to);
            return;
        }
        towerOfHanoi(n-1, from_, aux, to);
        System.out.println(from_+"------>"+to);
        towerOfHanoi(n-1, aux, to, from_);

    }
    public static void main(String[] args){
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of disks: ");
        n = sc.nextInt();
        sc.close();
        towerOfHanoi(n, 'A', 'B', 'C');

    }
}