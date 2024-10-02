package oooaaa;
import javax.swing.JOptionPane;
public class ejercicio9 {
	public static void main (String [] args) {
		
		String texto= JOptionPane.showInputDialog("pon algun numero");
		
		int divisible = Integer.parseInt(texto);
		
		if(divisible % 2 == 0) {
			System.out.println("el numero es divisible por dos");
		}else {
			System.out.println("el numero no es divisible por dos");
		}
			
	}
}
