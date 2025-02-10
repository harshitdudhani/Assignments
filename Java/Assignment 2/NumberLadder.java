import java.util.Scanner;

public class NumberLadder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows for the ladder: ");
        int rows = scanner.nextInt();

        generateLadder(rows);

        scanner.close();
    }

    public static void generateLadder(int rows) {
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
