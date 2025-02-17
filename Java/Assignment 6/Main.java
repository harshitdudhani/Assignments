// Base class
class VideoTape {
    protected String title;
    protected int duration;
    protected boolean availability;

    public VideoTape(String title, int duration, boolean availability) {
        this.title = title;
        this.duration = duration;
        this.availability = availability;
    }

    public void display() {
        System.out.println("\nVideo Details:");
        System.out.println("Title: " + title);
        System.out.println("Duration: " + duration + " minutes");
        System.out.println("Available for rent: " + (availability ? "Yes" : "No"));
    }
}

// First derived class
class Film extends VideoTape {
    private String producer;
    private double boxOfficeCollection;

    public Film(String title, int duration, boolean availability,
                String producer, double boxOfficeCollection) {
        super(title, duration, availability);
        this.producer = producer;
        this.boxOfficeCollection = boxOfficeCollection;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Producer: " + producer);
        System.out.println("Box Office Collection: $" + boxOfficeCollection + " million");
    }
}

// Second derived class
class MusicClip extends VideoTape {
    private String bandName;
    private String genre;

    public MusicClip(String title, int duration, boolean availability,
                     String bandName, String genre) {
        super(title, duration, availability);
        this.bandName = bandName;
        this.genre = genre;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Band/Artist: " + bandName);
        System.out.println("Genre: " + genre);
    }
}

// Main class to test the implementation
public class Main {
    public static void main(String[] args) {
        // Create instances of each class
        VideoTape video = new VideoTape("Generic Video", 90, true);
        Film film = new Film("The Matrix", 136, false, "Joel Silver", 463.5);
        MusicClip musicClip = new MusicClip("Bohemian Rhapsody", 6, true, "Queen", "Rock");

        // Display using all three versions of display()
        System.out.println("1. Calling display() on VideoTape object:");
        video.display();

        System.out.println("\n2. Calling display() on Film object:");
        film.display();

        System.out.println("\n3. Calling display() on MusicClip object:");
        musicClip.display();
    }
}