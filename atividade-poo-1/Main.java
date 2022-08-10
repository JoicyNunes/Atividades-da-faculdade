import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
	   
	    Scanner input = new Scanner (System.in);
	    
		System.out.println("Digite o nome produto: ");
		String produto = input.nextLine();
		System.out.println("Digite o valor unitario: ");
		double valor = input.nextDouble();
	    valor= valor*0.91;
		System.out.printf("\nValor de %s com desconto = R$ %.2f", produto, valor);
	}
}