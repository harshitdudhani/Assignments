class ConstructorOverloadingDemo {
    ConstructorOverloadingDemo() {
        System.out.println("Default Constructor.");
    }

    ConstructorOverloadingDemo(int a) {
        System.out.println("Parameterized Constructor: " + a);
    }

    public static void main(String[] args) {
        new ConstructorOverloadingDemo();
        new ConstructorOverloadingDemo(10);
    }
}