package lamama;

public class primos {
	
	    public static void main(String[] args) {
	       
	        for (int i = 1; i <= 50; i++) {
	            if (esPrimo(i)) {
	                System.out.println(i + " es numero primo");
	            }
	            else {
	            	 System.out.println(i);
	            }
	        }
	    }

	   
	    public static boolean esPrimo(int numero) {
	        
	        if (numero <= 1) {
	            return false;
	        }
	        
	       
	        for (int i = 2; i <= Math.sqrt(numero); i++) {
	            if (numero % i == 0) {
	                return false; 
	            }
	        }
	        
	        return true; 
	    }
}
