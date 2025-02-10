class Sanitarium {
    private String name;
    private int capacity;
    private int totalRooms;

    private static int totalSanitariums = 0;

    public Sanitarium(String name, int capacity, int totalRooms) {
        this.name = name;
        this.capacity = capacity;
        this.totalRooms = totalRooms;
        totalSanitariums++;
    }

    public int personsPerRoom() {
        if (totalRooms == 0) {
            System.out.println("No rooms available.");
            return 0;
        }
        return capacity / totalRooms;
    }

    public static int getTotalSanitariums() {
        return totalSanitariums;
    }

    public void displayDetails() {
        System.out.println("Sanitarium Name: " + this.name);
        System.out.println("Capacity: " + this.capacity);
        System.out.println("Total Rooms: " + this.totalRooms);
        System.out.println("Persons per Room: " + this.personsPerRoom());
    }

    public static void main(String[] args) {
        Sanitarium san1 = new Sanitarium("Green Valley", 100, 20);
        Sanitarium san2 = new Sanitarium("Blue Hills", 150, 30);

        san1.displayDetails();
        san2.displayDetails();

        System.out.println("Total Sanitariums: " + Sanitarium.getTotalSanitariums());
    }
}
