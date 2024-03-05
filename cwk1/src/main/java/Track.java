/**
 * Represents a point in space and time, recorded by a GPS sensor.
 *
 * @author Chenyu Wang
 */
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.time.ZonedDateTime;
import java.time.temporal.ChronoUnit;
import java.util.Collections;
import java.util.Comparator;
import java.io.PrintWriter;


public class Track {
  private ArrayList<Point> points;

  public Track() {
    points = new ArrayList<>();
  }

  public Track(String filename) throws IOException {
    this();
    readFile(filename);
  }

  public void readFile(String filename) throws IOException, GPSException {
    points.clear();
    File file = new File(filename);
    Scanner scanner = new Scanner(file);
    if(scanner.hasNextLine()) {
        scanner.nextLine();
    }
    while (scanner.hasNextLine()) {
        String line = scanner.nextLine();
        String[] data = line.split(",");
        if (data.length < 4) {
          scanner.close();
          throw new GPSException("Data file has fewer than 4 columns");
      }
        ZonedDateTime timestamp = ZonedDateTime.parse(data[0]);
        double latitude = Double.parseDouble(data[1]);
        double longitude = Double.parseDouble(data[2]);
        double elevation = Double.parseDouble(data[3]);
        Point point = new Point(timestamp, latitude, longitude, elevation);
        points.add(point);
    }
    scanner.close();
}


  public void add(Point point) {
    points.add(point);
  }

  public Point get(int index) throws GPSException {
    if (index < 0 || index >= points.size()) {
      throw new GPSException("Index out of bounds");
    }
    return points.get(index);
  }

  public int size() {
    return points.size();
  }

  public Point lowestPoint() throws GPSException {
    if (points.size() == 0) {
      throw new GPSException("Not enough points");
    }
    return Collections.min(points, Comparator.comparingDouble(Point::getElevation));
  }

  public Point highestPoint() throws GPSException {
    if (points.size() == 0) {
      throw new GPSException("Not enough points");
    }
    return Collections.max(points, Comparator.comparingDouble(Point::getElevation));
  }

  public double totalDistance() throws GPSException {
    if (points.size() < 2) {
        throw new GPSException("Not enough points to calculate.");
    }

    double totalDistance = 0.0;
    for (int i = 0; i < points.size() - 1; i++) {
        Point p = points.get(i);
        Point q = points.get(i + 1);
        totalDistance += Point.greatCircleDistance(p, q);
    }
    return totalDistance;
}

  public double averageSpeed() throws GPSException {
    if (points.size() < 2) {
      throw new GPSException("Not enough points to calculate speed");
    }
    Point start = points.get(0);
    Point end = points.get(points.size() - 1);
    long seconds = ChronoUnit.SECONDS.between(start.getTime(), end.getTime());
    if (seconds == 0) {
      throw new GPSException("Start and end times are the same");
    }
    return totalDistance() / seconds;
  }


  public void writeKML(String filename) throws IOException {
    try (PrintWriter pw = new PrintWriter(filename)) {
        pw.println("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
        pw.println("<kml xmlns=\"http://www.opengis.net/kml/2.2\">");
        pw.println("<Document>");
        pw.println("<name>Track</name>");
        for (Point point : this.points) {
            pw.printf("<Placemark><Point><coordinates>%f,%f</coordinates></Point></Placemark>\n",
                      point.getLongitude(), point.getLatitude());
        }

        pw.println("</Document>");
        pw.println("</kml>");
    }
}
  // TODO: Create a stub for the constructor

  // TODO: Create a stub for readFile()

  // TODO: Create a stub for add()

  // TODO: Create a stub for get()

  // TODO: Create a stub for size()

  // TODO: Create a stub for lowestPoint()

  // TODO: Create a stub for highestPoint()

  // TODO: Create a stub for totalDistance()

  // TODO: Create a stub for averageSpeed()
}
