import java.util.Scanner;

public class SwapFirstLast {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = scanner.nextLine();

        String result = swapFirstLast(input);
        System.out.println("Modified string: " + result);

        scanner.close();
    }

    public static String swapFirstLast(String str) {
        if (str.length() <= 1) {
            return str;
        }

        char first = str.charAt(0);
        char last = str.charAt(str.length() - 1);

        return last + str.substring(1, str.length() - 1) + first;
    }
}
