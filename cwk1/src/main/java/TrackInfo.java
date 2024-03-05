/**
 * Program to provide information on a GPS track stored in a file.
 *
 * @author Chenyu Wang
 */
import java.io.IOException; 

public class TrackInfo {
public static void main(String[] args) {
    if (args.length < 1) {
        System.out.println("Please provide the filename at run time.");
        System.exit(0);
    }

    String filename = args[0];
    try {
        Track track = new Track(filename);
        System.out.println(track.size() + " points in track");
        Point lowestPoint = track.lowestPoint();
        System.out.println("Lowest point is " + lowestPoint);
        Point highestPoint = track.highestPoint();
        System.out.println("Highest point is " + highestPoint);
        System.out.println("Total distance = " + String.format("%.3f", track.totalDistance()/ 1000) + " km");
        System.out.println("Average speed = " + String.format("%.3f", track.averageSpeed()) + " m/s");
    } catch (IOException e) {
        System.out.println("Error reading the file: " + e.getMessage());
        System.exit(1);
    } catch (GPSException e) {
        System.out.println("Error GPS data: " + e.getMessage());
        System.exit(1);
    }catch (Exception e) {
        System.out.println("An unexpected error occurred: " + e.getMessage());
        System.exit(1);
    }
    }
}


