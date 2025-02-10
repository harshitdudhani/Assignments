class Air {
    double per_of_oxygen, per_of_nitrogen, humidity;

    Air() {
        this(21, 78, 50);
    }

    Air(double per_of_oxygen, double per_of_nitrogen, double humidity) {
        this.per_of_oxygen = per_of_oxygen;
        this.per_of_nitrogen = per_of_nitrogen;
        this.humidity = humidity;
    }

    void display() {
        System.out.println("Oxygen: " + per_of_oxygen + "%, Nitrogen: " + per_of_nitrogen + "%, Humidity: " + humidity + "%");
    }

    public static void main(String[] args) {
        Air air1 = new Air(21, 78, 70);
        Air air2 = new Air(19, 80, 65);

        air1.display();
        air2.display();

        System.out.println("Higher Humidity: " + (air1.humidity > air2.humidity ? "Air1" : "Air2"));
    }
}