import java.util.Scanner;

public class Main {

public static void main(String[] args) {

    Scanner input = new Scanner (System.in);
    
    System.out.println("Digite a temperadura em Graus  Centígrados: ");
    double graus = input.nextFloat();
    double fahrenheit= (9 * graus + 160) / 5;
    System.out.printf("\nA temperadura em Fahrenheit é %.1f ºF", fahrenheit);
    }
}
