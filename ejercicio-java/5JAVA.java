import java.util.Random;
public class for_each {
	public static void main(String[] args) {
        Random random = new Random();
        int suma = 0;
        int cantidadN = 10;
        
        int[] numero= new int[cantidadN];
	
	for(int i = 0; i < numero.length; i++) {
		numero[i] = random.nextInt(100);
		  System.out.print("Números aleatorios generados: " + numero[i]);
		  System.out.print("\n");
	}	
	
	
     for (int numeros : numero) {
         suma+=numeros;
     }
     System.out.println("La suma de los números es: " + suma);
     
	}
}
