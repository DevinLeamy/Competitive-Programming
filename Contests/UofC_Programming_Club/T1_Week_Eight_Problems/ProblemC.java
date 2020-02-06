import java.util.*;
import java.io.*;

public class ProblemC {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int id = 1;
        outer: while (true) {
            String string = in.readLine();
            if (string.equals("END")) {
                return;
            }

            int space = 0;
            int prevSpace = -1;
            for (int i = 1; i < string.length(); i++) {
                if (string.charAt(i) == '.') {
                    space++;
                } else {
                    if (prevSpace == -1) {
                        prevSpace = space;
                    }
                    if (space != prevSpace) {
                        System.out.println(id + " NOT EVEN");
                        id++;
                        continue outer;
                    }
                    space = 0;
                }
            }
            System.out.println(id + " EVEN");
            id++;
        }
    }
}
