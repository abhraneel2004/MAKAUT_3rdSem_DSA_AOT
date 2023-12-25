import java.util.Scanner;
import java.util.regex.Pattern;

public class programmingBasics_01 {
    
    public static boolean isDigit1(String input){ // rakam mi
        
        Pattern pattern = Pattern.compile("[0-9.,]+");
        
        if(pattern.matcher(input).matches()){
            return true;
        }
        return false;
    }
    
   public static String detectNegative_Int_Float(String input) {
        // NEGATIVE IS INTEGER OR FLOAT ?
        if (isNegative(input)) {
            String negative[] = input.split("-");
            if (negative.length > 1) {
                String numString = negative[1];
                try {
                    double numDouble = Double.parseDouble(numString.replace(',', '.'));
                    if (numDouble % 1 == 0) {
                        return "\n" + input + " is an integer and negative";
                    } else {
                        return "\n" + input + " is a float and negative";
                    }
                } catch (NumberFormatException e) {
                    return "\n" + input + " is not a valid number";
                }
            }
        }

        return "\nxyz";
    }

    
    public static boolean isNum1_IntOrFloat(String input , boolean isDigit){ //integer mi
        
        if(isDigit1(input)){
            //NEGATIVE IS INT OR FLOAT
         
            //
            
            int i = 0;
            for(char c : input.toCharArray()){
               if((c == '.' || c == ',') && i != input.length() - 1){
                   System.out.println(input+" is a float");
                   return false;
               }
               i++;
               
           }//for
            i = 0;
            for(char c : input.toCharArray()){
               if((c != '.' || c != ',') && i != input.length() - 1){
                   System.out.println(input+" is a Integer");
                   return true;
               }
               i++;
               
           }//for
               
       }
       String result = (!isNegative(input)) ? " is a not integer and float" : detectNegative_Int_Float(input);
       System.out.println(input+result);
       return isString(input);
    }
    
    public static boolean isNegative(String input){
     
        for (char c : input.toCharArray()) {
        if (c == '-') {
            return true;
        }
    }
     return false;   
    }
    public static boolean isString(String input){
        
        Pattern pattern = Pattern.compile("[a-zA-Z]+");
        
        if(pattern.matcher(input).matches()){
            System.out.println("This String ("+input+") consists of letters");
            return true;
        }
        
        return false;
    }
    
    
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter String : ");
        String input = scanner.nextLine();
        
        isNum1_IntOrFloat(input, isDigit1(input));
        
    }
}
