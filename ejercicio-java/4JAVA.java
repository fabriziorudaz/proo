import java.util.Scanner;

public class calculadora {
	public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double num1, num2;
        char operador;
        double resultado;

        // Solicitar el primer numero
        System.out.print("Introduce el primer número: ");
        num1 = scanner.nextDouble();

        // Solicitar el operador
        System.out.print("Introduce el operador (+, -, *, /): ");
        operador = scanner.next().charAt(0);

        // Solicitar el segundo numero
        System.out.print("Introduce el segundo número: ");
        num2 = scanner.nextDouble();

        // Realiza el cálculo según el operador
        switch (operador) {
            case '+':
                resultado = num1 + num2;
                break;
            case '-':
                resultado = num1 - num2;
                break;
            case '*':
                resultado = num1 * num2;
                break;
            case '/':
                // Verificar si el divisor es cero para evitar división por cero
                if (num2 == 0) {
                    System.out.println("Error: División por cero.");
                    return;
                }
                resultado = num1 / num2;
                break;
            default:
                System.out.println("Error: Operador no válido.");
                return;
        }

        // Mostrar el resultado
        System.out.println("El resultado de " + num1 + " " + operador + " " + num2 + " es: " + resultado);
    }
	}
