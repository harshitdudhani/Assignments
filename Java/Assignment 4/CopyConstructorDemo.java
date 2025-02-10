class CopyConstructorDemo {
    int data;

    CopyConstructorDemo(int data) {
        this.data = data;
    }

    CopyConstructorDemo(CopyConstructorDemo obj) {
        this.data = obj.data;
    }

    void display() {
        System.out.println("Data: " + data);
    }

    public static void main(String[] args) {
        CopyConstructorDemo original = new CopyConstructorDemo(30);
        CopyConstructorDemo copy = new CopyConstructorDemo(original);
        copy.display();
    }
}