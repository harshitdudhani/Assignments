// Implementing different types of inheritance in Java

// 1. Single Inheritance Example
class Animal {
    void eat() {
        System.out.println("Animal is eating...");
    }
}
class Dog extends Animal {
    void bark() {
        System.out.println("Dog is barking...");
    }
}

// 2. Multilevel Inheritance Example
class Machine {
    void start() {
        System.out.println("Machine is starting...");
    }
}
class Computer extends Machine {
    void compute() {
        System.out.println("Computer is computing...");
    }
}
class Laptop extends Computer {
    void portable() {
        System.out.println("Laptop is portable...");
    }
}

// 3. Hierarchical Inheritance Example
class Vehicle {
    void run() {
        System.out.println("Vehicle is running...");
    }
}
class Car extends Vehicle {
    void drive() {
        System.out.println("Car is driving...");
    }
}
class Bike extends Vehicle {
    void ride() {
        System.out.println("Bike is riding...");
    }
}

// 4. Multiple Inheritance using Interfaces
interface Flyer {
    void fly();
}
interface Swimmer {
    void swim();
}
class Duck implements Flyer, Swimmer {
    public void fly() {
        System.out.println("Duck is flying...");
    }
    public void swim() {
        System.out.println("Duck is swimming...");
    }
}

public class InheritanceExample {
    public static void main(String[] args) {
        // Testing Single Inheritance
        Dog myDog = new Dog();
        myDog.eat();
        myDog.bark();

        // Testing Multilevel Inheritance
        Laptop myLaptop = new Laptop();
        myLaptop.start();
        myLaptop.compute();
        myLaptop.portable();

        // Testing Hierarchical Inheritance
        Car myCar = new Car();
        myCar.run();
        myCar.drive();

        Bike myBike = new Bike();
        myBike.run();
        myBike.ride();

        // Testing Multiple Inheritance
        Duck myDuck = new Duck();
        myDuck.fly();
        myDuck.swim();
    }
}