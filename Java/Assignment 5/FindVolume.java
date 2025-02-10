public class FindVolume {
    private static final double PI = 3.14159;
    private static int objectCount = 0;
    
    private double volume;
    
    public FindVolume() {
        this.volume = 0;
        objectCount++;
    }
    
    public double FindVolume(double side) {
        volume = side * side * side;
        return volume;
    }
    
    public double FindVolume(double radius, double height) {
        volume = (1.0/3.0) * PI * radius * radius * height;
        return volume;
    }
    
    public double FindVolume(double radius, double height, String shape) {
        if (shape.equalsIgnoreCase("cylinder")) {
            volume = PI * radius * radius * height;
        }
        return volume;
    }
    
    public double FindVolume(double radius, boolean isSphere) {
        if (isSphere) {
            volume = (4.0/3.0) * PI * radius * radius * radius;
        }
        return volume;
    }
    
    public static int getObjectCount() {
        return objectCount;
    }
    
    public static void main(String[] args) {
        FindVolume calc = new FindVolume();
        
        double cubeVolume = calc.FindVolume(5);
        System.out.println("Volume of cube: " + cubeVolume);
        
        double coneVolume = calc.FindVolume(3, 7);
        System.out.println("Volume of cone: " + coneVolume);
        
        double cylinderVolume = calc.FindVolume(4, 8, "cylinder");
        System.out.println("Volume of cylinder: " + cylinderVolume);
        
        double sphereVolume = calc.FindVolume(6, true);
        System.out.println("Volume of sphere: " + sphereVolume);
        
        System.out.println("Total objects created: " + FindVolume.getObjectCount());
    }
}