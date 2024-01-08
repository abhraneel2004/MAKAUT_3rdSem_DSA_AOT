package JavaPack;

public class CommandLineArguments_02 {
	//EXAMPLE COMMAND CMD or Linux_Shell
	//java -jar CommandLineArguments_02.jar name , surName , class , id , schoolName
	public static void main(String[] args) {
		
		int argCount = args.length;
		
		System.out.println("argc = "+argCount);
		
		for(int i = 0 ; i < argCount ; i++) {
			System.out.println(args[i]+" ");
		}
		
	}
		
}
