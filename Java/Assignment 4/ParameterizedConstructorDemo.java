class ParameterizedConstructorDemo {
    int value;

    ParameterizedConstructorDemo(int value) {
        this.value = value;
    }

    void display() {
        System.out.println("Value: " + value);
    }

    public static void main(String[] args) {
        ParameterizedConstructorDemo obj = new ParameterizedConstructorDemo(50);
        obj.display();
    }
}