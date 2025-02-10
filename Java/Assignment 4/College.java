import java.util.Scanner;

public class College {
    private int totalStudents;
    private int branches;
    private double resultPercentage;
    
    public College(int students, int branches, double result) {
        this.totalStudents = students;
        this.branches = branches;
        this.resultPercentage = result;
    }
    
    public static College inputCollegeData(Scanner scanner) {
        System.out.println("Enter college details:");
        
        System.out.print("Total number of students: ");
        int students = scanner.nextInt();
        
        System.out.print("Number of branches: ");
        int branches = scanner.nextInt();
        
        System.out.print("Result percentage: ");
        double result = scanner.nextDouble();
        
        return new College(students, branches, result);
    }
    
    public static void compareColleges(College college1, College college2) {
        System.out.println("\nCollege with better result:");
        
        if (college1.resultPercentage > college2.resultPercentage) {
            displayCollegeData(college1);
        } else if (college2.resultPercentage > college1.resultPercentage) {
            displayCollegeData(college2);
        } else {
            System.out.println("Both colleges have equal results");
            System.out.println("\nCollege 1 data:");
            displayCollegeData(college1);
            System.out.println("\nCollege 2 data:");
            displayCollegeData(college2);
        }
    }
    
    private static void displayCollegeData(College college) {
        System.out.println("Total Students: " + college.totalStudents);
        System.out.println("Number of Branches: " + college.branches);
        System.out.println("Result Percentage: " + college.resultPercentage + "%");
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter data for first college:");
        College college1 = inputCollegeData(scanner);
        
        System.out.println("\nEnter data for second college:");
        College college2 = inputCollegeData(scanner);
        
        compareColleges(college1, college2);
        
        scanner.close();
    }
}