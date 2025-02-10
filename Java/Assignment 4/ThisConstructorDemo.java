class ThisConstructorDemo {
    ThisConstructorDemo() {
        this(100);
        System.out.println("No-Argument Constructor.");
    }

    ThisConstructorDemo(int value) {
        System.out.println("Value Constructor: " + value);
    }

    public static void main(String[] args) {
        new ThisConstructorDemo();
    }
}
