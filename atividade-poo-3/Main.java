import java.util.Scanner;

public class Main {

public static void main(String[] args) {

    Scanner input = new Scanner (System.in);
    
    System.out.println("Digite o primeiro valor: ");
    float primeiro = input.nextFloat();
    System.out.println("Digite o segundo valor: ");
    float segundo = input.nextFloat();
    float media= primeiro/segundo;
    System.out.printf("\nA media de %.1f e %.1f e igual a %.1f", primeiro, segundo, media);
    }
}
