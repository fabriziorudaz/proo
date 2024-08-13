package lamama;
import java.util.Scanner; 

public class numero100 {
	
	public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numero;

        while (true) {
            System.out.print("Introduce un numero: ");
            numero = scanner.nextInt();

            
            if (numero > 100 && esPrimo(numero)) {
                System.out.println(numero + " es un numero primo mayor a 100");
                break; 
            } else {
                System.out.println("El número no cumple con las condiciones. Intenta de nuevo");
            }
        }

        scanner.close(); 

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
