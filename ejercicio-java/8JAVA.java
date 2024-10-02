import javax.swing.JOptionPane;

public class ejercicio8 {
	public static void main( String[] args) {
		
		String texto= JOptionPane.showInputDialog ("introduzca un radio");
		
		double radio= Double.parseDouble (texto);
		
		double area = Math.PI*Math.pow(radio, 2);
		
		System.out.println("el area es igual a "+ area);
		
	}

}
