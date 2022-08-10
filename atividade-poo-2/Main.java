import java.util.Scanner;

public class Main {

public static void main(String[] args) {

    Scanner input = new Scanner (System.in);
    
    System.out.println("Digite o valor do salario minimo: ");
    double minimo = input.nextDouble();
    System.out.println("Digite o valor do seu salario: ");
    double salario = input.nextDouble();
    minimo= salario/minimo;
    System.out.printf("\nO salário: %.2f \nEquivale a %.1f salários minimos", salario, minimo);
    }
}
