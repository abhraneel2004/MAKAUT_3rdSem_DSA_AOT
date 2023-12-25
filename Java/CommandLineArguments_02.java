package ilkProje;

public class CommandLineArguments_02 {

	public static void main(String[] args) {
		
		int argCount = args.length;
		
		System.out.println("argc = "+argCount);
		
		for(int i = 0 ; i < argCount ; i++) {
			System.out.println(args[i]+" ");
		}
		
	}
		
}
