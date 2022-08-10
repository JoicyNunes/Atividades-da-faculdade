import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner (System.in);
        
        System.out.println("Digite a altura (cm) da lata de oleo: ");
        double altura = input.nextDouble();
        System.out.println("Digite o numero do raio (cm): ");
        double raio = input.nextDouble();
        double volume = 3.14159 * (raio*raio) * altura;
        System.out.printf("\nO volume da lata de oleo e %.1f ", volume);
    }
}
