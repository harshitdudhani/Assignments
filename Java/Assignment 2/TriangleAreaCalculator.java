import java.util.Scanner;

public class TriangleAreaCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Select the type of triangle:");
        System.out.println("1. Right-angled triangle");
        System.out.println("2. Equilateral triangle");
        System.out.println("3. Scalene triangle");
        int choice = scanner.nextInt();

        switch (choice) {
            case 1:
                System.out.print("Enter the base of the triangle: ");
                double base = scanner.nextDouble();
                System.out.print("Enter the height of the triangle: ");
                double height = scanner.nextDouble();
                System.out.println("Area of the right-angled triangle: " + calculateRightTriangleArea(base, height));
                break;

            case 2:
                System.out.print("Enter the side length of the equilateral triangle: ");
                double side = scanner.nextDouble();
                System.out.println("Area of the equilateral triangle: " + calculateEquilateralTriangleArea(side));
                break;

            case 3:
                System.out.print("Enter the first side of the triangle: ");
                double a = scanner.nextDouble();
                System.out.print("Enter the second side of the triangle: ");
                double b = scanner.nextDouble();
                System.out.print("Enter the third side of the triangle: ");
                double c = scanner.nextDouble();
                System.out.println("Area of the scalene triangle: " + calculateScaleneTriangleArea(a, b, c));
                break;

            default:
                System.out.println("Invalid choice. Please select a valid triangle type.");
        }

        scanner.close();
    }

    public static double calculateRightTriangleArea(double base, double height) {
        return 0.5 * base * height;
    }

    public static double calculateEquilateralTriangleArea(double side) {
        return (Math.sqrt(3) / 4) * side * side;
    }

    public static double calculateScaleneTriangleArea(double a, double b, double c) {
        double s = (a + b + c) / 2; // Semi-perimeter
        return Math.sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
    }
}
