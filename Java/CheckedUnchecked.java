import java.io.FileReader;

import java.io.FileNotFoundException;
public class CheckedUnchecked {
    public static void main(String[] args) throws FileNotFoundException {
        // readFile("myFile.txt");
        // readFile2("myFile.tt");

        String name = "Theseus";
        printLength(name);
        printLength(null);
    }

    private static void readFile (String filename) {
        try {
            FileReader reader = new FileReader(filename);
        } catch(FileNotFoundException fnfe) {
            System.out.println("That file doesn't exist!");
        }
    }

    private static void readFile2(String filename) throws FileNotFoundException {
        FileReader reader = new FileReader(filename);
    }

    private static void printLength(String myString) {
        System.out.println(myString.length());
    }
}