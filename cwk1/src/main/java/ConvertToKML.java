/**
 * Program to general a KML file from GPS track data stored in a file,
 * for the Advanced task of COMP1721 Coursework 1.
 *
 * @author Chenyu Wang
 */

 import java.io.IOException;

 public class ConvertToKML {
  public static void main(String[] args) {
    if (args.length < 2) {
      System.out.println("Please provide the input CSV filename and output KML filename at run time.");
      System.exit(0);
  }

  String csvFilename = "data/walk.csv";
  String kmlFilename = "build/walk.kml";
  
  try {
      Track track = new Track(csvFilename);
      track.writeKML(kmlFilename);
  } catch (IOException e) {
      System.out.println("Error writing the KML file: " + e.getMessage());
      System.exit(1);
  } catch (Exception e) {
      System.out.println("An unexpected error occurred: " + e.getMessage());
      System.exit(1);
  }
  }
}