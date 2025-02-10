class Forest {
    double area_in_sq_cm;
    int count_of_animals;

    Forest(double area_in_sq_cm, int count_of_animals) {
        this.area_in_sq_cm = area_in_sq_cm;
        this.count_of_animals = count_of_animals;
    }

    double spacePerAnimal() {
        return area_in_sq_cm / count_of_animals;
    }

    void display() {
        System.out.println("Area: " + area_in_sq_cm + " sq cm, Animals: " + count_of_animals);
    }

    public static void main(String[] args) {
        Forest f1 = new Forest(1000000, 200);
        Forest f2 = new Forest(500000, 150);

        f1.display();
        f2.display();

        Forest lessSpace = f1.spacePerAnimal() < f2.spacePerAnimal() ? f1 : f2;
        System.out.println("Forest with Less Space per Animal:");
        lessSpace.display();
    }
}