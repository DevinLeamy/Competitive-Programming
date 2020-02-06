import java.io.*;
import java.util.*;

public class ProblemA {
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer line = new StringTokenizer(in.readLine());
        int W = Integer.parseInt(line.nextToken());
        int H = Integer.parseInt(line.nextToken());
        int remainder = H - W;
        if (remainder == 1) {
            System.out.println("Dr. Chaz will have " + "1" + " piece of chicken left over!");
        } else if (remainder >= 0)
        {
            System.out.println("Dr. Chaz will have " + remainder + " pieces of chicken left over!");
        } else if (remainder == -1)
        {
            System.out.println("Dr. Chaz needs 1 more piece of chicken!");
        } else {
            System.out.println("Dr. Chaz needs " + Math.abs(remainder) + " more pieces of chicken!");
        }
    }
}
