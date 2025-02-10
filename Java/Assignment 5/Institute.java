class Institute {
    private int totalStudents;
    private int branches;
    private double resultPercentage;

    public Institute(int totalStudents, int branches, double resultPercentage) {
        this.totalStudents = totalStudents;
        this.branches = branches;
        this.resultPercentage = resultPercentage;
    }

    public double getResultPercentage() {
        return this.resultPercentage;
    }

    public void displayInstituteDetails() {
        System.out.println("Total Students: " + this.totalStudents);
        System.out.println("Branches: " + this.branches);
        System.out.println("Result Percentage: " + this.resultPercentage + "%");
    }

    public static Institute betterResult(Institute inst1, Institute inst2) {
        return inst1.getResultPercentage() > inst2.getResultPercentage() ? inst1 : inst2;
    }

    public static void main(String[] args) {
        Institute inst1 = new Institute(500, 5, 89.5);
        Institute inst2 = new Institute(600, 6, 92.3);

        System.out.println("Details of Institute with Better Result:");
        Institute betterInstitute = Institute.betterResult(inst1, inst2);
        betterInstitute.displayInstituteDetails();
    }
}
