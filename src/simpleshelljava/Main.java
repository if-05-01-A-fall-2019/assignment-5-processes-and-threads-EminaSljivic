package simpleshelljava;

import java.io.InputStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Commands: ");
        String input = scanner.nextLine();
        String[] parts = input.split("&");

        for (String part: parts) {
            try {
                Process process = Runtime.getRuntime().exec(part);
                process.waitFor();
                InputStream stream = process.getInputStream();
                int output = stream.read();
                while (output != -1) {
                    System.out.print((char) output);
                    output = stream.read();
                }
                System.out.println();
            }
            catch (Exception e)
            {
                throw new IllegalArgumentException("An error occurred!");
            }

        }
    }
}
