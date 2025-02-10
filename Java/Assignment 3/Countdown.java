import java.util.Scanner;

public class Countdown {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number to start the countdown: ");
        int number = scanner.nextInt();

        System.out.println("Countdown:");
        while (number >= 0) {
            System.out.println(number);
            number--;
        }

        scanner.close();
    }
}
