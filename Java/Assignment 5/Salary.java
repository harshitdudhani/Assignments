class Salary {
    private double basicPay;
    private double ta;
    private double da;
    private double hra;

    private static int employeeCount = 0;

    public Salary(double basicPay, double ta, double da, double hra) {
        this.basicPay = basicPay;
        this.ta = ta;
        this.da = da;
        this.hra = hra;
        employeeCount++;
    }

    public double calculateTotalSalary() {
        return this.basicPay + this.ta + this.da + this.hra;
    }

    public void displaySalaryDetails() {
        System.out.println("Basic Pay: " + this.basicPay);
        System.out.println("TA: " + this.ta);
        System.out.println("DA: " + this.da);
        System.out.println("HRA: " + this.hra);
        System.out.println("Total Salary: " + this.calculateTotalSalary());
    }

    public static int getEmployeeCount() {
        return employeeCount;
    }

    public static void main(String[] args) {
        Salary emp1 = new Salary(30000, 2000, 4000, 5000);
        Salary emp2 = new Salary(40000, 3000, 5000, 7000);

        emp1.displaySalaryDetails();
        emp2.displaySalaryDetails();

        System.out.println("Total Employees: " + Salary.getEmployeeCount());
    }
}
