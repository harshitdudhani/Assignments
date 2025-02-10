import java.util.Scanner;

public class RightTriangleCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first side: ");
        int a = scanner.nextInt();
        System.out.print("Enter the second side: ");
        int b = scanner.nextInt();
        System.out.print("Enter the third side: ");
        int c = scanner.nextInt();

        if (a > b && a > c) {
            int temp = c; c = a; a = temp;
        } else if (b > c) {
            int temp = c; c = b; b = temp;
        }

        if (c * c == a * a + b * b) {
            System.out.println("The triangle is a right triangle.");
        } else {
            System.out.println("The triangle is NOT a right triangle.");
        }

        scanner.close();
    }
}
