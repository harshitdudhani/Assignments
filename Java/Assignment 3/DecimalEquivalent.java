public class DecimalEquivalent {
    public static void main(String[] args) {
        System.out.println("Decimal equivalents of fractions from 1/2 to 1/10:");

        for (int i = 2; i <= 10; i++) {
            double decimalEquivalent = 1.0 / i; // Calculate the decimal equivalent
            System.out.println("1/" + i + " = " + decimalEquivalent);
        }
    }
}