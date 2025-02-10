class Department {
    String name_of_hod;
    int total_students;
    double per_of_result;

    Department(String name_of_hod, int total_students, double per_of_result) {
        this.name_of_hod = name_of_hod;
        this.total_students = total_students;
        this.per_of_result = per_of_result;
    }

    void display() {
        System.out.println("HOD: " + name_of_hod + ", Students: " + total_students + ", Result: " + per_of_result + "%");
    }

    public static void main(String[] args) {
        Department[] departments = new Department[5];
        departments[0] = new Department("Dr. Smith", 50, 75.5);
        departments[1] = new Department("Dr. John", 40, 60.0);
        departments[2] = new Department("Dr. Alice", 45, 80.0);
        departments[3] = new Department("Dr. Emma", 55, 90.0);
        departments[4] = new Department("Dr. Brown", 35, 55.0);

        Department worst = departments[0];
        for (Department dept : departments) {
            if (dept.per_of_result < worst.per_of_result) {
                worst = dept;
            }
        }

        System.out.println("Worst Average Result:");
        worst.display();
    }
}
