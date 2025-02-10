import java.util.Scanner;

public class BestTwoAverage {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter marks for Test 1: ");
        int test1 = scanner.nextInt();
        System.out.print("Enter marks for Test 2: ");
        int test2 = scanner.nextInt();
        System.out.print("Enter marks for Test 3: ");
        int test3 = scanner.nextInt();
        
        int smallest = Math.min(test1, Math.min(test2, test3));

        int bestTwoSum = test1 + test2 + test3 - smallest;

        double bestTwoAverage = bestTwoSum / 2.0;

        System.out.println("The average of the best two marks is: " + bestTwoAverage);

        scanner.close();
    }
}
